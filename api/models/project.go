package models

import (
	"gorm.io/gorm"
)

type Role string

const (
	Owner  Role = "owner"
	Member Role = "member"
	Viewer Role = "viewer"
)

type ProjectMember struct {
	UserID    uint `gorm:"primaryKey"`
	ProjectID uint `gorm:"primaryKey"`
	Role      Role `gorm:"type:varchar(255)"`
}

type Project struct {
	gorm.Model
	ID      uint
	Name    string
	Markup  string
	Diagram string
	Members []ProjectMember `gorm:"foreignKey:ProjectID"`
}
