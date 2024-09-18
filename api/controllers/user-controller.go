package controllers

import (
	"encoding/json"
	"github.com/go-chi/chi/v5"
	"gorm.io/gorm"
	"main/models"
	"net/http"
)

type UserResponse struct {
	ID        uint   `json:"id"`
	Name      string `json:"name"`
	Email     string `json:"email"`
	CreatedAt string `json:"created_at"`
	UpdatedAt string `json:"updated_at"`
}

func UserRouter(db *gorm.DB) http.Handler {
	r := chi.NewRouter()

	r.Post("/", func(w http.ResponseWriter, r *http.Request) {
		CreateUser(w, r, db)
	})
	r.Get("/", func(w http.ResponseWriter, r *http.Request) {
		ListUsers(w, r, db)
	})
	r.Get("/{id}", func(w http.ResponseWriter, r *http.Request) {
		GetUser(w, r, db)
	})

	return r
}

func CreateUser(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	user := models.User{}
	json.NewDecoder(r.Body).Decode(&user)

	existingUser := models.User{}
	db.Where("email = ?", user.Email).First(&existingUser)

	if existingUser.ID != 0 {
		http.Error(w, "User already exists", http.StatusConflict)
		return
	}

	pass, err := user.HashPassword()
	if err != nil {
		http.Error(w, "Error hashing password", http.StatusInternalServerError)
		return
	}

	user.Password = pass
	db.Create(&user).Scan(&user)

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

func ListUsers(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	users := []models.User{}
	db.Find(&users)

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

func GetUser(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	id := chi.URLParam(r, "id")
	user := models.User{}
	response := UserResponse{}
	db.Where("id = ?", id).First(&user).Scan(&response)

	if user.ID == 0 {
		http.Error(w, "User not found", http.StatusNotFound)
		return
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}
