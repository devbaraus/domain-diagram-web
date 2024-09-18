package middlewares

import (
	"context"
	"gorm.io/gorm"
	"main/models"
	"main/utils"
	"net/http"
)

func JWTAuthMiddleware(db *gorm.DB) func(next http.Handler) http.Handler {
	return func(next http.Handler) http.Handler {
		fn := func(w http.ResponseWriter, r *http.Request) {
			// Verificar se o cabeçalho Authorization está presente
			authHeader := r.Header.Get("Authorization")
			if authHeader == "" {
				http.Error(w, "Unauthorized", http.StatusUnauthorized)
				return
			}

			// Extrair o token do cabeçalho Authorization
			token := authHeader[7:]

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
			db.First(&user, userID)

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
}
