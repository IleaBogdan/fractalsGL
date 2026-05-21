#version 460
out vec4 FragColor;

in vec3 cords;
uniform vec2 offset;
uniform float alpha;

vec2 complex_multiplication(vec2 a, vec2 b){
    return vec2(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
float complex_abs(vec2 z){
    return sqrt(z.x*z.x+z.y*z.y);
}

void main(){
    // z is the 3d coord so we can ignore it
    vec2 c=cords.xy+offset;
    vec2 tmp=c;
    c.x=tmp.x*cos(alpha)-tmp.y*sin(alpha);
    c.y=tmp.x*sin(alpha)+tmp.y*cos(alpha);
    int max_iterations=64;
    vec2 z=vec2(0,0);
    for(int i=0;i<max_iterations;++i){
        // z -> z^2 +c
        z=complex_multiplication(z,z)+c;
    }
    if(complex_abs(z)<=2.0)FragColor=vec4(0.2,0.4,0.2,1.0);
    else FragColor=vec4(0.0,0.0,0.0,1.0);
} 