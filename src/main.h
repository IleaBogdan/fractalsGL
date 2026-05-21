#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"vars.h"
#include"callbacks.h"
#include"shader_class/shader.h"

void init(GLFWwindow*&window,const std::string&window_name,const bool&primariy_monitor=false);