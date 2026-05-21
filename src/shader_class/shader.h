#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<type_traits>
#include<numeric>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

namespace check{
    void shaderError(const unsigned int&shader);
    void programError(const unsigned int&program);
};

class shader{
private:
    unsigned int program_id;
    const std::string load_shader(const std::string&shader_path);
public:
    shader()=default;
    void init(const std::string&vertex_shader_path,const std::string&fragment_shader_path);
    unsigned int get_program(void)const;
};

/** @brief
 * Vertex Object (or VO for short) has the VAO and VBO of a vertex 
*/
class vertex_object{
private:
    bool inited=false;
    std::vector<int>attribute_sizes;
    std::vector<float>verts;
    unsigned int VAO,VBO;
public:
    vertex_object()=default;
    void init(const std::vector<float>&_verts,const std::vector<int>&_attribute_sizes);
    int get_stride(void)const;
    int get_offset(int attribute_index)const;
    size_t shape_size(void)const;
    unsigned int get_VBO(void)const;
    unsigned int get_VAO(void)const;
};