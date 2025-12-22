#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef struct 
{
    float* verts;
    int verts_len;
    int indices;
    int indices_len;
    unsigned int vbo;
    unsigned int vao;
    unsigned int ebo;
} mesh;

mesh* create_mesh(float* verts, int len); // malloc here
void destroy_mesh(mesh* mesh); // free here
