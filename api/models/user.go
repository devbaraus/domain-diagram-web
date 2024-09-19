package models

import (
	"golang.org/x/crypto/bcrypt"
	"gorm.io/gorm"
)

type User struct {
	gorm.Model
	ID       uint
	Name     string
	Email    string `gorm:"unique"`
	Password string
	Super    bool `gorm:"default:false"`
	Active   bool `gorm:"default:true"`
}

func (u *User) SetPassword() (string, error) {
	bytes, err := bcrypt.GenerateFromPassword([]byte(u.Password), 14)
	return string(bytes), err
}
