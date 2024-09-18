package main

import (
	"fmt"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
	"main/controllers"
	"main/models"
	"net/http"
)

func main() {
	dsn := "host=localhost user=postgres password=postgres dbname=ddd port=5432 sslmode=disable TimeZone=America/Sao_Paulo"
	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{})
	if err != nil {
		panic("Failed to connect database")
	}

	errDb := db.AutoMigrate(&models.User{}, &models.Project{})
	if errDb != nil {
		panic("Failed to migrate database")
	}

	r := chi.NewRouter()
	r.Use(middleware.Recoverer)
	r.Use(middleware.RequestID)
	r.Use(middleware.Logger)

	r.Mount("/users", controllers.UserRouter(db))

	fmt.Println("Server is running on http://localhost:3000")
	http.ListenAndServe(":3000", r)
}
