#version 460
layout (location = 0) in vec3 aPos;

out vec3 cords;

void main(){
    gl_Position=vec4(aPos,1.0);
    cords=aPos;
}