package controllers

import (
	"encoding/json"
	"github.com/go-chi/chi/v5"
	"gorm.io/gorm"
	"main/models"
	"main/utils"
	"net/http"
)

func AuthRouter(db *gorm.DB) http.Handler {
	r := chi.NewRouter()

	r.Post("/login", func(w http.ResponseWriter, r *http.Request) {
		LoginUser(w, r, db)
	})

	r.Post("/register", func(w http.ResponseWriter, r *http.Request) {
		CreateUser(w, r, db)
	})

	r.Get("/me", func(w http.ResponseWriter, r *http.Request) {
		GetProject(w, r, db)
	})

	return r
}

type AuthCredentialsRequest struct {
	Email    string `json:"email"`
	Password string `json:"password"`
}

func LoginUser(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	credentials := AuthCredentialsRequest{}

	json.NewDecoder(r.Body).Decode(&credentials)

	user := models.User{}
	db.Where("email = ?", credentials.Email).First(&user)

	isValid := models.CheckPasswordHash(credentials.Password, user.Password)

	if !isValid {
		http.Error(w, "Email or password is not valid", http.StatusUnauthorized)
		return
	}

	token, err := utils.CreateToken(&user)

	if err != nil {
		http.Error(w, "Error creating a token", http.StatusInternalServerError)
		return
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(token)
}
