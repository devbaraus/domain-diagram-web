package middlewares

import (
	"context"
	"main/database"
	"main/models"
	"main/utils"
	"net/http"
)

func JwtMiddleware(next http.Handler) http.Handler {
	fn := func(w http.ResponseWriter, r *http.Request) {
		// Verificar se o cabeçalho Authorization está presente
		authHeader := r.Header.Get("Authorization")
		authQuery := r.URL.Query().Get("access_token")
		var token string

		if authHeader == "" && authQuery == "" {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}

		// Extrair o token do cabeçalho Authorization
		if authHeader != "" {
			token = authHeader[7:]
		} else {
			token = authQuery
		}

		// Decodificar o token JWT
		claims, err := utils.DecodeToken(token)
		if err != nil {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}

		// Obter o ID do usuário a partir das claims do token
		userID, err := claims.GetSubject() // Assumindo que `sub` contém o ID do usuário
		if err != nil {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}

		// Procurar o usuário no banco de dados
		var user models.User
		database.Conn.First(&user, userID)

		// Se o usuário não for encontrado
		if user.ID == 0 {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}

		// Adicionar o usuário ao contexto da requisição
		ctx := context.WithValue(r.Context(), utils.UserContextKey, &user)
		r = r.WithContext(ctx)

		// Passar para o próximo handler
		next.ServeHTTP(w, r)
	}

	return http.HandlerFunc(fn)
}
