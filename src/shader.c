#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/call.h>
#include <assert.h>
#include <string.h>

GLuint compileShader(const char* shader_source, const GLint* shader_len, const GLuint type){
    GLuint shader = glCreateShader(type);
    assert(shader != NULL);
    glShaderSource(shader, 1, &shader_source, shader_len);
    glCompileShader(shader);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    // assert(success==GL_TRUE);
    if (!success)
    {
        int logLen;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
        char* log = calloc(1, logLen);
        glGetShaderInfoLog(shader, 512, NULL, log);
        printf("Shader error: %s", log);
        exit(EXIT_FAILURE);
    }
    return shader;
}

GLuint compileProgram(const char* vert_shader_source, const GLint* v_len, const char* frag_shader_source, const GLint* f_len)
{
    GLuint vecShader = compileShader(vert_shader_source, v_len, GL_VERTEX_SHADER);
    GLuint fragShader = compileShader(frag_shader_source, f_len, GL_FRAGMENT_SHADER);
    GLuint prog = glCreateProgram();
    glAttachShader(prog, vecShader);
    glAttachShader(prog, fragShader);
    glLinkProgram(prog);
    int success;
    glGetProgramiv(prog, GL_LINK_STATUS, &success);
    assert(success == GL_TRUE);
    glDeleteShader(vecShader);
    glDeleteShader(fragShader);
    return prog;
}
