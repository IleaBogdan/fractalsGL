#include"shader.h"

unsigned int shader::get_program(void)const{
    return this->program_id;
}

void shader::init(const std::string&vertex_shader_path,const std::string&fragment_shader_path){
    const std::string vertex_shader_code_loader=this->load_shader(vertex_shader_path);
    const char*vertex_shader_code=vertex_shader_code_loader.c_str();
    unsigned int vertex_shader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader,1,&vertex_shader_code, NULL);
    glCompileShader(vertex_shader);
    check::shaderError(vertex_shader);

    const std::string fragment_shader_code_loader=this->load_shader(fragment_shader_path);
    const char*fragment_shader_code=fragment_shader_code_loader.c_str();
    unsigned int fragment_shader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader,1,&fragment_shader_code, NULL);
    glCompileShader(fragment_shader);
    check::shaderError(fragment_shader);

    this->program_id=glCreateProgram();
    glAttachShader(this->program_id, vertex_shader);
    glAttachShader(this->program_id, fragment_shader);
    glLinkProgram(this->program_id);
    check::programError(this->program_id);

    glUseProgram(this->program_id);

    // we no longer need the shaders now
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);  
    // end of shader loading (thank god)
}

const std::string shader::load_shader(const std::string&shader_path){
    std::ifstream file;
    file.open(shader_path);
    if(!file){
        std::cerr<<"Failed to open file or file not found!\n";
        exit(-1);
    }
    return std::string((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>()); // oneliner to read the file
}