#version 330 core

in vec3 fCol;
out vec4 frag_col;

void main() {
    frag_col = vec4(fCol, 1.0f);
}