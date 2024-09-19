package controllers

import (
	"encoding/json"
	"github.com/go-chi/chi/v5"
	"main/database"
	"main/middlewares"
	"main/models"
	"main/utils"
	"net/http"
)

type UserRequest struct {
	Name     string `json:"name"`
	Email    string `json:"email"`
	Password string `json:"password"`
}

type UserResponse struct {
	ID        uint   `json:"id"`
	Name      string `json:"name"`
	Email     string `json:"email"`
	CreatedAt string `json:"created_at"`
	UpdatedAt string `json:"updated_at"`
}

func UserRouter() http.Handler {
	r := chi.NewRouter()

	r.Use(middlewares.JwtMiddleware)

	//r.Get("/", ListUsers)
	//r.Get("/{id}", GetUser)
	r.Get("/me", GetProfile)

	return r
}

func ListUsers(w http.ResponseWriter, r *http.Request) {
	users := []models.User{}
	database.Conn.Find(&users)

	userResponses := []UserResponse{}
	for _, user := range users {
		userResponses = append(userResponses, UserResponse{
			ID:        user.ID,
			Name:      user.Name,
			Email:     user.Email,
			CreatedAt: user.CreatedAt.String(),
			UpdatedAt: user.UpdatedAt.String(),
		})
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(userResponses)
}

func GetUser(w http.ResponseWriter, r *http.Request) {
	id := chi.URLParam(r, "id")
	user := models.User{}
	response := UserResponse{}
	database.Conn.Where("id = ?", id).First(&user).Scan(&response)

	if user.ID == 0 {
		http.Error(w, "User not found", http.StatusNotFound)
		return
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

func GetProfile(w http.ResponseWriter, r *http.Request) {
	user := utils.GetUserFromContext(r)
	if user.ID == 0 {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	response := UserResponse{}

	database.Conn.Where("id = ?", user.ID).First(&models.User{}).Scan(&response)

	if user.ID == 0 {
		http.Error(w, "User not found", http.StatusNotFound)
		return
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

func CreateUser(w http.ResponseWriter, r *http.Request) {
	body := UserRequest{}
	json.NewDecoder(r.Body).Decode(&body)

	existingUser := models.User{}
	database.Conn.Where("email = ?", body.Email).First(&existingUser)

	if existingUser.ID != 0 {
		http.Error(w, "User already exists", http.StatusConflict)
		return
	}

	user := models.User{
		Name:     body.Name,
		Email:    body.Email,
		Password: body.Password,
	}

	pass, err := user.SetPassword()
	if err != nil {
		http.Error(w, "Error hashing password", http.StatusInternalServerError)
		return
	}

	user.Password = pass
	database.Conn.Create(&user).Scan(&user)

	response := UserResponse{
		ID:        user.ID,
		Name:      user.Name,
		Email:     user.Email,
		CreatedAt: user.CreatedAt.String(),
		UpdatedAt: user.UpdatedAt.String(),
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}
