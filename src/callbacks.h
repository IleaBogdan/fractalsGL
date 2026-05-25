#pragma once
#include"main.h"

void key_callback(GLFWwindow*window,int key,int scancode,int action,int mods);
void framebuffer_size_callback(GLFWwindow*window,int width,int height);
void set_callbacks(GLFWwindow*&window);
void move_key(GLFWwindow*window);
void zoom_key(GLFWwindow*window);