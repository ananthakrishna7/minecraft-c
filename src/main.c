#include <mc/init.h>
#include <mc/mainloop.h>
#include <mc/destroyer.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/call.h>
#include <assert.h>
#include <mc/texture.h>
#include <textures/container.h>
#include <textures/awesomeface.h>
#include <mc/mesh.h>
#define SQUARE { \
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   \ 
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   \ 
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   \ 
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    \  
    }
/*LATER
Use quarternions for rotation to prevent Gimbal Lock
*/
int main()
{
    GLFWwindow* window = init();
    assert(window != NULL);

    // setup code, to be moved

   float vertices[] = SQUARE; // square, texture mapped, colour mapped

    unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    };

    mesh* mesh = create_mesh(&vertices, sizeof(vertices));
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8* sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
    glVertexAttribPointer(1, 3, GL_FLOAT,GL_FALSE, 8*sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    int texture1 = loadTexture(__res_textures_container_jpg, __res_textures_container_jpg_len, JPG);
    int texture2 = loadTexture(__res_textures_awesomeface_png, __res_textures_awesomeface_png_len, PNG);

    GLint currentProgramId;
    glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgramId);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glUniform1i(glGetUniformLocation(currentProgramId, "texture1"), 0);
    glUniform1i(glGetUniformLocation(currentProgramId, "texture2"), 1);


    mainloop(window, mesh->vao);
    destroy();
}