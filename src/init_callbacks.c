#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <mc/shader.h>
#include <shaders/shader.frag.h>
#include <shaders/shader.vert.h>
GLFWkeyfun keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (key == GLFW_KEY_F4 && action == GLFW_RELEASE)
    {
        int count;
        GLFWmonitor* monitor = glfwGetWindowMonitor(window);
        GLFWmonitor** monitors = glfwGetMonitors(&count);

        // lets do just 2 monitors for now 
        //TODO:Support More monitors BUT do we really need that
        if (count > 1){
            printf("KEY RELEASED!\n");
        int idx = 0;
        if (monitor == monitors[0])
            idx = 1;
        printf("Index: %d\n", idx);
        const GLFWvidmode* mode = glfwGetVideoMode(monitors[idx]);
        glfwSetWindowMonitor(window, monitors[idx], mode -> width / 2, mode -> height / 2, mode -> width, mode -> height, mode -> refreshRate);
   
        }
        else{
            printf("No other monitors!\n");
        }
         }
}

GLFWmonitorfun monitorCallback(GLFWmonitor* monitor, int event)
{
    if (event == GLFW_CONNECTED)
    {
        //probably write to a config file
        printf("New monitor Detected!\n");
    }
    else if (event == GLFW_DISCONNECTED)
    {
        printf("Monitor Disconencted!\n");
    }
}

GLFWcursorposfun cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    // printf("Cursor pos: (%0.2f, %0.2f)\n", xpos, ypos);
}

GLFWmousebuttonfun mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        printf("LEFT MOUSE!\n");
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        printf("RIGHT MOUSE!\n");
    }
    else if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE)
    {
        printf("MIDDLE MOUSE!\n");
    }
}
GLFWscrollfun scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    printf("Scroll: (%0.2f, %0.2f)\n", xoffset, yoffset);
}
GLFWwindow* init()
{
    if (!glfwInit())
    {
        perror("glfwInit");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	GLFWwindow* window = glfwCreateWindow(mode -> width, mode -> height, "MinecraftC", glfwGetPrimaryMonitor(), NULL);

    if (window == NULL)
    {
        perror("windowInit");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		perror("gladInit");
        exit(EXIT_FAILURE);
	}

    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

    // set cursor starting position
    glfwSetCursorPos(window, mode -> width / 2, mode -> height / 2);

    /*CALLBACKS*/

    glfwSetKeyCallback(window, (void*)keyCallback);
    glfwSetMonitorCallback((void*)monitorCallback);
    glfwSetCursorPosCallback(window, (void*)cursorPosCallback);
    glfwSetMouseButtonCallback(window, (void*)mouseButtonCallback);
    glfwSetScrollCallback(window, (void*)scrollCallback);

    /* SHADER INIT*/
    GLuint program = compileProgram(&__res_shaders_shader_vert, &__res_shaders_shader_vert_len, &__res_shaders_shader_frag, &__res_shaders_shader_frag_len);
    glUseProgram(program);
    glDeleteProgram(program);
    return window;
}