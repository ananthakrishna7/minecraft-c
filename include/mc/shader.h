#ifndef MC_SHADER
#define MC_SHADER
GLuint compileShader(const char* shader_source, const GLint* shader_len, const GLuint type);
GLuint compileProgram(const char* vert_shader_source, const GLint* v_len, const char* frag_shader_source, const GLint* f_len);
#endif