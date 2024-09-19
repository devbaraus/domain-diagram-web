package controllers

import (
	"encoding/json"
	"fmt"
	"github.com/go-chi/chi/v5"
	"github.com/gorilla/websocket"
	"log"
	"main/database"
	"main/models"
	"main/utils"
	"net/http"
)

type ProjectCreateRequest struct {
	Name    string `json:"name"`
	Markup  string `json:"markup"`
	Diagram string `json:"diagram"`
}

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

func ProjectRouter() http.Handler {
	r := chi.NewRouter()
	//r.Use(middlewares.JwtMiddleware)

	r.Post("/", func(w http.ResponseWriter, r *http.Request) {
		CreateProject(w, r)
	})

	r.Get("/", func(w http.ResponseWriter, r *http.Request) {
		ListProjects(w, r)
	})

	r.Get("/{id}", func(w http.ResponseWriter, r *http.Request) {
		GetProject(w, r)
	})

	r.Put("/{id}", func(w http.ResponseWriter, r *http.Request) {
		UpdateProject(w, r)
	})

	// Rota para WebSocket
	r.Get("/{id}/ws", func(w http.ResponseWriter, r *http.Request) {
		SocketProject(w, r)
	})

	return r
}

// Função para criar um projeto
func CreateProject(w http.ResponseWriter, r *http.Request) {
	user := utils.GetUserFromContext(r)
	if user.ID == 0 {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	body := ProjectCreateRequest{}
	response := ProjectResponse{}
	json.NewDecoder(r.Body).Decode(&body)

	project := models.Project{
		Name:    body.Name,
		Markup:  body.Markup,
		Diagram: body.Diagram,
	}

	project.Members = append(project.Members, models.ProjectMember{
		UserID: user.ID,
		Role:   models.Owner,
	})

	database.Conn.Create(&project).Scan(&response)

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

// Função para listar projetos
func ListProjects(w http.ResponseWriter, r *http.Request) {
	user := utils.GetUserFromContext(r)
	if user.ID == 0 {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	projects := []models.Project{}
	response := []ProjectResponse{}

	database.Conn.Joins("JOIN project_members ON project_members.project_id = projects.id").
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
func GetProject(w http.ResponseWriter, r *http.Request) {
	user := utils.GetUserFromContext(r)
	if user.ID == 0 {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	id := chi.URLParam(r, "id")
	response := ProjectResponse{}

	database.Conn.Joins("JOIN project_members ON project_members.project_id = projects.id").
		Where("project_members.user_id = ?", user.ID).First(&models.Project{}, id).Scan(&response)

	if response.ID == 0 {
		http.Error(w, "Project not found", http.StatusNotFound)
		return
	}

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(response)
}

func UpdateProject(w http.ResponseWriter, r *http.Request) {
	user := utils.GetUserFromContext(r)
	if user.ID == 0 {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	id := chi.URLParam(r, "id")
	body := ProjectCreateRequest{}
	json.NewDecoder(r.Body).Decode(&body)

	project := models.Project{}

	database.Conn.First(&project, id)

	project.Name = body.Name
	project.Markup = body.Markup
	project.Diagram = body.Diagram

	database.Conn.Save(&project)

	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(project)
}

// Função para atualizar um projeto via WebSocket
func SocketProject(w http.ResponseWriter, r *http.Request) {
	//id := chi.URLParam(r, "id")
	//user := utils.GetUserFromContext(r)
	//project := models.Project{}
	//
	//database.Conn.Joins("JOIN project_members ON project_members.project_id = projects.id").
	//	Where("project_members.user_id = ?", user.ID).First(&project, id)
	//
	//if project.ID == 0 {
	//	http.Error(w, "Project not found", http.StatusNotFound)
	//	return
	//}

	// Atualizar a conexão HTTP para WebSocket
	ws, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Println("Erro ao conectar WebSocket:", err)
		return
	}
	defer ws.Close()

	log.Println("Client Connected")
	err = ws.WriteMessage(1, []byte("Hi Client!"))
	if err != nil {
		log.Println(err)
	}

	reader(ws)
}

func reader(conn *websocket.Conn) {
	for {
		// read in a message
		messageType, p, err := conn.ReadMessage()
		if err != nil {
			log.Println(err)
			return
		}
		// print out that message for clarity
		fmt.Println(string(p))

		if err := conn.WriteMessage(messageType, p); err != nil {
			log.Println(err)
			return
		}

	}
}
