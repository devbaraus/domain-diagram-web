package controllers

import (
	"encoding/json"
	"github.com/go-chi/chi/v5"
	"main/database"
	"main/models"
	"main/utils"
	"net/http"
)

func AuthRouter() http.Handler {
	r := chi.NewRouter()

	r.Post("/login", LoginUser)

	r.Post("/register", CreateUser)

	return r
}

type LoginRequest struct {
	Email    string `json:"email"`
	Password string `json:"password"`
}

func LoginUser(w http.ResponseWriter, r *http.Request) {
	body := LoginRequest{}

	json.NewDecoder(r.Body).Decode(&body)

	user := models.User{}
	database.Conn.Where("email = ?", body.Email).First(&user)

	isValid := utils.CheckPasswordHash(body.Password, user.Password)

	if !isValid {
		http.Error(w, "Credentials invalid", http.StatusUnauthorized)
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
