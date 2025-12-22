#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/cglm.h>

void mainloop(GLFWwindow* window, int vao)
{
    while(!glfwWindowShouldClose(window))
    {
            // transformations
        mat4 trans;
        glm_mat4_identity(trans);
        glm_translate(trans, (vec3){0.5f, -0.5f, 0.0f});
        glm_rotate(trans, (float)glfwGetTime(), (vec3){0.0, 0.0, 1.0f});
        int currentProgramId;
        glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgramId);
        glUniformMatrix4fv(glGetUniformLocation(currentProgramId, "transform"), 1, GL_FALSE, (float*)trans);


        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glm_mat4_identity(trans);
        glm_translate(trans, (vec3){-0.5f, 0.5f, 0.0f});
        glm_rotate(trans, (float)glfwGetTime(), (vec3){0.0, 0.0, 1.0f});
        glUniformMatrix4fv(glGetUniformLocation(currentProgramId, "transform"), 1, GL_FALSE, (float*)trans);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}