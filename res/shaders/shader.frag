#version 330 core

in vec3 frag_col;
out vec4 FragColour;

void main() {
    FragColour = vec4(frag_col, 1.0f);
}