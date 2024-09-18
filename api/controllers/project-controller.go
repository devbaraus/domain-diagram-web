package controllers

import (
	"encoding/json"
	"github.com/go-chi/chi/v5"
	"gorm.io/gorm"
	"main/models"
	"net/http"
)

func ProjectRouter(db *gorm.DB) http.Handler {
	r := chi.NewRouter()

	r.Post("/", func(w http.ResponseWriter, r *http.Request) {
		CreateProject(w, r, db)
	})

	r.Get("/", func(w http.ResponseWriter, r *http.Request) {
		ListProjects(w, r, db)
	})

	r.Get("/{id}", func(w http.ResponseWriter, r *http.Request) {
		GetProject(w, r, db)
	})

	return r
}

func CreateProject(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	project := models.Project{}

	json.NewDecoder(r.Body).Decode(&project)

	db.Create(&project)

	json.NewEncoder(w).Encode(project)
}

func ListProjects(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	users := []models.User{}

	db.Find(&users)

	json.NewEncoder(w).Encode(users)
}

func GetProject(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	id := chi.URLParam(r, "id")

	project := models.Project{}

	db.First(&project, id)

	json.NewEncoder(w).Encode(project)
}
