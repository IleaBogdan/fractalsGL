#version 460
out vec4 FragColor;

in vec4 vertexColor;
uniform vec4 ourColor; 

void main(){
    FragColor=ourColor;
} 