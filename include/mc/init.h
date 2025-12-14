#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MC_INIT
#define MC_INIT

// GLFWkeyfun keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
GLFWwindow* init();
#endif