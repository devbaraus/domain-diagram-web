package controllers

import (
	"encoding/json"
	"github.com/go-chi/chi/v5"
	"github.com/gorilla/websocket"
	"gorm.io/gorm"
	"log"
	"main/middlewares"
	"main/models"
	"main/utils"
	"net/http"
	"time"
)

type ProjectResponse struct {
	ID      uint   `json:"id"`
	Name    string `json:"name"`
	Markup  string `json:"markup"`
	Diagram string `json:"diagram"`
}

// WebSocket Upgrader para gerenciar a conexão WebSocket
var upgrader = websocket.Upgrader{
	CheckOrigin: func(r *http.Request) bool {
		// Permitir qualquer origem, ou adicionar lógica de verificação
		return true
	},
}

func ProjectRouter(db *gorm.DB) http.Handler {
	r := chi.NewRouter()
	r.Use(middlewares.JWTAuthMiddleware(db))

	r.Post("/", func(w http.ResponseWriter, r *http.Request) {
		CreateProject(w, r, db)
	})

	r.Get("/", func(w http.ResponseWriter, r *http.Request) {
		ListProjects(w, r, db)
	})

	r.Get("/{id}", func(w http.ResponseWriter, r *http.Request) {
		GetProject(w, r, db)
	})

	r.Get("/{id}", func(w http.ResponseWriter, r *http.Request) {
		UpdateProject(w, r, db)
	})

	// Rota para WebSocket
	r.Get("/ws", func(w http.ResponseWriter, r *http.Request) {
		SocketProject(w, r, db)
	})

	return r
}

// Função para criar um projeto
func CreateProject(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	user := utils.GetUserFromContext(r)
	if user == nil {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	project := models.Project{}
	response := ProjectResponse{}
	json.NewDecoder(r.Body).Decode(&project)

	project.Members = append(project.Members, *user)

	db.Create(&project).Scan(&response)

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

// Função para listar projetos
func ListProjects(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	user := utils.GetUserFromContext(r)
	if user == nil {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	projects := []models.Project{}
	response := []ProjectResponse{}
	db.Joins("JOIN project_members ON project_members.project_id = projects.id").
		Where("project_members.user_id = ?", user.ID).
		Find(&projects)

	for _, project := range projects {
		response = append(response, ProjectResponse{
			ID:      project.ID,
			Name:    project.Name,
			Markup:  project.Markup,
			Diagram: project.Diagram,
		})
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

// Função para obter um projeto específico
func GetProject(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	id := chi.URLParam(r, "id")
	response := ProjectResponse{}
	project := models.Project{}

	db.First(&project, id).Scan(&response)

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

func UpdateProject(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	id := chi.URLParam(r, "id")
	project := models.Project{}

	db.First(&project, id)

	json.NewDecoder(r.Body).Decode(&project)

	db.Save(&project)

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(project)
}

// Função WebSocket para enviar atualizações de projeto em tempo real
func SocketProject(w http.ResponseWriter, r *http.Request, db *gorm.DB) {
	// Atualizar a conexão HTTP para WebSocket
	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Println("Erro ao conectar WebSocket:", err)
		return
	}
	defer conn.Close()

	// Simulando um loop de envio de atualizações (você pode modificar conforme necessário)
	for {
		// Aqui você pode buscar os dados atualizados do projeto
		projects := []models.Project{}
		db.Find(&projects)

		// Enviar os projetos atualizados para o cliente WebSocket
		err := conn.WriteJSON(projects)
		if err != nil {
			log.Println("Erro ao enviar dados via WebSocket:", err)
			break
		}

		// Adicione algum tempo de espera para simular atualizações contínuas
		// ou conecte com eventos reais de atualização de projetos
		time.Sleep(5 * time.Second)
	}
}
