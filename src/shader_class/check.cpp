#include"shader.h"

void check::programError(const unsigned int&program){
    // program erro check
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr<<"ERROR::PROGRAM::FAILED\n"<<infoLog<<std::endl;
        exit(-1);
    }
}

void check::shaderError(const unsigned int&shader){
    // shader error checking
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr<<"ERROR::SHADER::COMPILATION_FAILED\n"<<infoLog<<std::endl;
        exit(-1);
    }
}