#include <stdio.h>
#include <stdlib.h>

#include "shader.h"

/* void checkShaderCompilation(GLuint shader)
{
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        fprintf(stderr, "Shader compilation error: %s\n", infoLog);
        fflush(stderr);
    }
}

void checkProgramLinking(GLuint program)
{
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLchar infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        fprintf(stderr, "Program linking error: %s\n", infoLog);
        fflush(stderr);
    }
} */

const char * getShaderSource(const char* filepath)
{
   FILE* fp;

   fp = fopen(filepath,"r" );

   if(!fp){fprintf(stderr, "Could not be opened file: %s\n", filepath);
   fflush(stderr);}

   fseek(fp, 0, SEEK_END);
   long file_size = ftell(fp);
   fseek(fp, 0, SEEK_SET);

   char *buffer= (char *)malloc(file_size +1);

   fread(buffer, 1, file_size, fp);
   buffer[file_size] = '\0';

   return buffer;
}

GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath)
{
    const char* vertexShaderSource = getShaderSource(vertexPath);
    const char* fragmentShaderSource = getShaderSource(fragmentPath); 
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    return shaderProgram;
}