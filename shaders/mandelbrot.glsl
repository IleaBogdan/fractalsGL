#version 460
out vec4 FragColor;

in vec3 cords;

vec2 complex_multiplication(vec2 a, vec2 b){
    return vec2(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}

void main(){
    // z is the 3d coord so we can ignore it
    vec2 c=cords.xy;
    int max_iterations=64;
    vec2 z=vec2(0,0);
    for(int i=0;i<max_iterations;++i){
        // z -> z^2 +c
        z=complex_multiplication(z,z)+c;
    }
    FragColor=vec4(z,cords.z,1.0);
} 