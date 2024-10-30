#pragma once

#include <GL/glew.h>

typedef struct
{
    GLuint VAO;
    GLuint VBO;

} VertexArray;

void initVertexArray(VertexArray* vertexArray, GLfloat* vertices, GLsizeiptr size)
{
    glGenVertexArrays(1, &vertexArray->VAO);
    glBindVertexArray(vertexArray->VAO);

    glGenBuffers(1, &vertexArray->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArray->VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 *sizeof(float), (void*)0 );
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


// vertex array nesnesini sil
void deleteVertexArray(VertexArray* vertexArray)
{
    glDeleteVertexArrays(1, &vertexArray->VAO);
    glDeleteBuffers(1, &vertexArray->VBO);
}