// know this is not a fractal, but I saw a video on yt with it and looked kinda cool
// I know it doesn't look that good now, but I am learning 
#version 460
out vec4 FragColor;

in vec3 cords;
uniform vec2 offset;
uniform float alpha;
uniform float time;

vec3 calc_color(float h){ // pulsing red-green color calculator
    return vec3(h+sin(time)*0.1,sqrt(h)*sin(time),0);
}

void main(){
    // z is the 3d coord so we can ignore it
    vec2 c=cords.xy+offset;
    vec2 tmp=c*2;
    c.x=tmp.x*cos(alpha)-tmp.y*sin(alpha);
    c.y=tmp.x*sin(alpha)+tmp.y*cos(alpha);
    // foruma: (x^2+y^2-1)^3-x^2*y^3<=0
    // FragColor=vec4(vec3(pow(c.x*c.x+c.y*c.y-1,3)-c.x*c.x*pow(c.y,3)<=0?1:0),1.0); // black and white
    FragColor=vec4(calc_color(pow(c.x*c.x+c.y*c.y-1,3)-c.x*c.x*pow(c.y,3)<=0?1:0),1.0);
} 