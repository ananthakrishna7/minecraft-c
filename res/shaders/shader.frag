#version 330 core

in vec3 Colour;
in vec2 TexCoord;
out vec4 FragColour;
uniform sampler2D Texture;

void main() {
    FragColour = texture(Texture, TexCoord);
}