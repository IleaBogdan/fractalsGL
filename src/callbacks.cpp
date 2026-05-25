#include"main.h"

void set_callbacks(GLFWwindow*&window){
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback); // resize window function set to window 
}

void framebuffer_size_callback(GLFWwindow*window,int width,int height){
    glViewport(0,0,width,height);
}  

float dist=.01f,rotate_speed=.03f,zoom_inc=.01f;
void key_callback(GLFWwindow*window,int key,int scancode,int action,int mods){
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
    move_key(window);
    zoom_key(window);
}

void zoom_key(GLFWwindow*window){
    if(glfwGetKey(window,GLFW_KEY_Z)){
        zoom+=zoom_inc;
    }
    if(glfwGetKey(window,GLFW_KEY_X)){
        zoom-=zoom_inc;
    }
}
void move_key(GLFWwindow*window){
    if(glfwGetKey(window,GLFW_KEY_D)){
        global_horizontal_offset+=dist;
    }
    if(glfwGetKey(window,GLFW_KEY_A)){
        global_horizontal_offset-=dist;
    }
    if(glfwGetKey(window,GLFW_KEY_W)){
        global_vertical_offset+=dist;
    }
    if(glfwGetKey(window,GLFW_KEY_S)){
        global_vertical_offset-=dist;
    }
    if(glfwGetKey(window,GLFW_KEY_Q)){
        alpha-=rotate_speed;
    }
    if(glfwGetKey(window,GLFW_KEY_E)){
        alpha+=rotate_speed;
    }
}