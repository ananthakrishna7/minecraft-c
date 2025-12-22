#include <stb_image.h>
#include <mc/texture.h>
#include <assert.h>
#include <stdbool.h>
int loadTexture(unsigned char* tex, unsigned int tex_len, imgType type)
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);  
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int height, width, nrChannels;
    stbi_set_flip_vertically_on_load(true);  
    unsigned char* data = stbi_load_from_memory( // i think this is bad. should find a better way to pack textures.
        tex,
        tex_len,
        &width,
        &height,
        &nrChannels,
        0
    );
    assert(data != NULL);
    if(type == JPG)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    else if (type == PNG)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    return texture;
}