cmake_minimum_required(VERSION 3.12)

project(glad)

add_library(glad STATIC 
	includes/glad/glad.h
	src/glad.c
)

target_include_directories(glad PUBLIC includes)