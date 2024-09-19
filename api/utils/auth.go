package utils

import (
	"github.com/golang-jwt/jwt/v5"
	"golang.org/x/crypto/bcrypt"
	"main/models"
	"net/http"
	"os"
	"strconv"
	"time"
)

type contextKey string

const UserContextKey = contextKey("user")

type TokenPayloadResponse struct {
	AccessToken string `json:"access_token"`
	ExpiresAt   int64  `json:"expires_at"`
}

func CreateToken(user *models.User) (TokenPayloadResponse, error) {
	secretKey := os.Getenv("JWT_SECRET")
	exp := time.Now().Add(time.Hour * 8).Unix()
	aud := "member"

	if user.Super == true {
		aud = "admin"
	}

	// Create a new JWT token with claims
	claims := jwt.NewWithClaims(jwt.SigningMethodHS256, jwt.MapClaims{
		"sub": strconv.Itoa(int(user.ID)), // Subject (user identifier)
		"iss": "dddiagram",                // Issuer
		"aud": aud,                        // Audience (user role)
		"exp": exp,                        // Expiration time
		"iat": time.Now().Unix(),          // Issued at
	})

	tokenString, err := claims.SignedString([]byte(secretKey))
	if err != nil {
		return TokenPayloadResponse{}, err
	}

	return TokenPayloadResponse{
		AccessToken: tokenString,
		ExpiresAt:   exp,
	}, nil
}

func DecodeToken(tokenString string) (jwt.MapClaims, error) {
	secretKey := os.Getenv("JWT_SECRET")

	// Parse the token
	token, err := jwt.Parse(tokenString, func(token *jwt.Token) (interface{}, error) {
		return []byte(secretKey), nil
	})
	if err != nil {
		return jwt.MapClaims{}, err
	}

	claims, ok := token.Claims.(jwt.MapClaims)
	if !ok || !token.Valid {
		return jwt.MapClaims{}, err
	}

	return claims, nil
}

func GetUserFromContext(r *http.Request) *models.User {
	user, ok := r.Context().Value(UserContextKey).(*models.User)
	if !ok {
		return nil
	}
	return user
}

func CheckPasswordHash(password, hash string) bool {
	err := bcrypt.CompareHashAndPassword([]byte(hash), []byte(password))
	return err == nil
}
