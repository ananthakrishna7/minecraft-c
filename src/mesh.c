#include <mc/mesh.h>
#include <stdlib.h>

mesh* create_mesh(float* vertices, int len)
{
    mesh* new_mesh = calloc(1, sizeof(mesh));
    new_mesh->verts = vertices;
    new_mesh->verts_len = len;

    glGenVertexArrays(1, &(new_mesh->vao));  
    glBindVertexArray(new_mesh->vao);

    unsigned int VBO;
    glGenBuffers(1, &(new_mesh->vbo));
    glBindBuffer(GL_ARRAY_BUFFER, new_mesh->vbo); 
    glBufferData(GL_ARRAY_BUFFER, len, vertices, GL_STATIC_DRAW);
    
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8* sizeof(float), (void*)0);
    // glEnableVertexAttribArray(0);  
    // glVertexAttribPointer(1, 3, GL_FLOAT,GL_FALSE, 8*sizeof(float), (void*)(3* sizeof(float)));
    // glEnableVertexAttribArray(1);
    // glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
    // glEnableVertexAttribArray(2);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 

    glGenBuffers(1, &(new_mesh->ebo));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, new_mesh->ebo);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void destroy_mesh(mesh* mesh)
{
    glDeleteBuffers(1, &(mesh->ebo));
    glDeleteBuffers(1, &(mesh->vbo));
    glDeleteBuffers(1, &(mesh->vao));

    free(mesh->verts);
    free(mesh);
}