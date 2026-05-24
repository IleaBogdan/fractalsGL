#version 460
out vec4 FragColor;

in vec3 cords;
uniform vec2 offset;
uniform float alpha;
uniform float time;

vec2 complex_multiplication(vec2 a, vec2 b){
    return vec2(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
float complex_abs(vec2 z){
    return sqrt(z.x*z.x+z.y*z.y);
}

// pseudo random function from stack overflow
float rand(vec2 co){
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}

vec3 calc_color(float h){ // pulsing blue-green color calculator
    return vec3(0,h+sin(time)*0.1,sqrt(h)*sin(time));
}
void main(){
    // z is the 3d coord so we can ignore it
    vec2 c=cords.xy+offset;
    vec2 tmp=c;
    c.x=tmp.x*cos(alpha)-tmp.y*sin(alpha);
    c.y=tmp.x*sin(alpha)+tmp.y*cos(alpha);
    int max_iterations=32;
    float color_diff=8.0;
    vec2 z=vec2(0,0);
    float l=0.0,h=0.0;
    for(int j=0;j<color_diff;++j){
        for(int i=0;i<max_iterations;++i){
            // z -> z^2 +c
            z=complex_multiplication(z,z)+c;
            l=(length(z)>4.0?i:l); // checking for excaping
        }
        h+=(float(l)/max_iterations)/color_diff;
    }
    // FragColor=vec4(vec3(h),1.0); // black and white
    FragColor=vec4(calc_color(h),1.0); 
} 