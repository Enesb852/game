#pragma once

#include <GL/glew.h>

// GET the file content 
const char * getShaderSource(const char* filepath);

// creates a shader program and returns it
GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath);