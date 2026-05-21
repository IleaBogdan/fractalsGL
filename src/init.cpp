#include"main.h"

void init(GLFWwindow*&window,const std::string&window_name,const bool&primary_monitor){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
    window=glfwCreateWindow(800,600,window_name.c_str(),primary_monitor?glfwGetPrimaryMonitor():nullptr,nullptr);
    if(!window){
        std::cerr<<"Failed to create window!\n";
        exit(-1);
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr<<"Failed to initialize GLAD"<<std::endl;
        exit(-1);
    }
}