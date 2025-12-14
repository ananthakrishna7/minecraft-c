#include <mc/init.h>
#include <mc/mainloop.h>
#include <mc/destroyer.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/call.h>
#include <assert.h>

int main()
{
    GLFWwindow* window = init();
    assert(window != NULL);

    // setup code, to be moved

   float vertices[] = {
     0.0f,  0.25f, 0.0f,  // top right
     1.0f,  0,0,
     0.0f, -0.25f, 0.0f,  // bottom right
     0,1.0f,0,
    -0.25f, -0.25f, 0.0f,  // bottom left
    0,0,1.0f,
    -0.25f,  0.25f, 0.0f,   // top left
    0,0,0
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};



unsigned int VAO;
glGenVertexArrays(1, &VAO);  
glBindVertexArray(VAO);
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
    glVertexAttribPointer(1, 3, GL_FLOAT,GL_FALSE, 6*sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
    unsigned int EBO;
glGenBuffers(1, &EBO);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    mainloop(window, VAO);
    destroy();
}