cmake_minimum_required(VERSION 3.14)
project(mcc VERSION 1.0.0)

include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

FetchContent_Declare(
    cglm
    GIT_REPOSITORY https://github.com/recp/cglm.git
    GIT_TAG v0.9.6
)

FetchContent_MakeAvailable(glfw cglm)

include_directories(include)

add_executable(mcc src/main.c src/glad.c src/init_callbacks.c src/mainloop.c src/destroyer.c src/shader.c src/stb_init.c src/texture.c src/mesh.c)

target_compile_features(mcc PRIVATE c_std_11)
target_link_libraries(mcc PRIVATE glfw cglm_headers ${CMAKE_DL_LIBS})

if(NOT WIN32)
    target_link_libraries(mcc PRIVATE m)
endif()
