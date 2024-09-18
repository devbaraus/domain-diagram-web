package models

import (
	"gorm.io/gorm"
)

type Project struct {
	gorm.Model
	ID      uint
	Name    string
	Markup  string
	Diagram string
	Members []User `gorm:"many2many:project_members;"`
}
