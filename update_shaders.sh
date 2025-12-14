#!/usr/bin/bash
xxd -i ./res/shaders/shader.frag > ./include/shaders/shader.frag.h
xxd -i ./res/shaders/shader.vert > ./include/shaders/shader.vert.h