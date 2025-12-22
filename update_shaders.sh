#!/usr/bin/bash
xxd -i ./res/shaders/shader.frag > ./include/shaders/shader.frag.h
xxd -i ./res/shaders/shader.vert > ./include/shaders/shader.vert.h
xxd -i ./res/textures/container.jpg > ./include/textures/container.h
xxd -i ./res/textures/awesomeface.png > ./include/textures/awesomeface.h