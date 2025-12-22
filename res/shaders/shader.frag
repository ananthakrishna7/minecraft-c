#version 330 core

in vec3 Colour;
in vec2 TexCoord;
out vec4 FragColour;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
    FragColour = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
}