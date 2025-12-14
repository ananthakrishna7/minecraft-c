#include <mc/init.h>
#include <mc/mainloop.h>
#include <mc/destroyer.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/call.h>
#include <assert.h>

int main()
{
    vec2 vector;
    glmc_vec2_zero(vector);
    printf("%f %f\n", vector[0], vector[1]);
    GLFWwindow* window = init();
    assert(window != NULL);
    mainloop(window);
    destroy();
}