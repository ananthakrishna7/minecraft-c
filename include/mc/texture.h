#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef enum {
    JPG,
    PNG
} imgType;

int loadTexture(unsigned char* tex, unsigned int tex_len, imgType type);