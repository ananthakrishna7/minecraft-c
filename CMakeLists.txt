cmake_minimum_required(VERSION 3.10)
project(mcc VERSION 1.0.0)

include_directories(include)

add_executable(mcc src/main.c src/glad.c src/init_callbacks.c src/mainloop.c src/destroyer.c src/shader.c src/stb_init.c src/texture.c)

target_link_libraries(mcc glfw cglm m)
