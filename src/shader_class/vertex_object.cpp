#include"shader.h"

int vertex_object::get_stride()const{
    if(!this->inited)throw("Using uninited Vertex Object!");
    // Total bytes from one vertex to the next
    return std::accumulate(this->attribute_sizes.begin(),this->attribute_sizes.end(),0)*sizeof(float);
}

int vertex_object::get_offset(int attribute_index)const{
    if(!this->inited)throw("Using uninited Vertex Object!");
    // Calculate offset for a specific attribute (in bytes)
    int offset=0;
    for(int i=0;i<attribute_index;++i){
        offset+=this->attribute_sizes[i];
    }
    return offset*sizeof(float);
}

void vertex_object::init(const std::vector<float>&_verts,const std::vector<int>&_attribute_sizes){
    this->inited=true;
    this->attribute_sizes=_attribute_sizes;
    std::copy(_verts.begin(),_verts.end(),std::back_inserter(this->verts));
    float vertices[verts.size()];
    std::copy(verts.begin(),verts.end(),vertices);
    
    glGenBuffers(1,&this->VBO);
    glGenVertexArrays(1,&this->VAO);
    
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER,this->VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    
    // Calculate stride once
    int stride=get_stride();
    
    // Setup each attribute with its specific size
    for(int attribute=0;attribute<this->attribute_sizes.size();++attribute) {
        int size=this->attribute_sizes[attribute];
        int offset=get_offset(attribute);
        
        glVertexAttribPointer(attribute,size,GL_FLOAT,GL_FALSE,stride,(void*)offset);
        glEnableVertexAttribArray(attribute);
    }
    glBindVertexArray(0);
}

size_t vertex_object::shape_size(void)const{
    if(!this->inited)throw("Using uninited Vertex Object!");
    // Total floats per vertex
    int floats_per_vertex=std::accumulate(this->attribute_sizes.begin(),this->attribute_sizes.end(),0);
    return this->verts.size()/floats_per_vertex;
}

unsigned int vertex_object::get_VBO(void)const{
    if(!this->inited)throw("Using uninited Vertex Object!");
    return this->VBO;
}
unsigned int vertex_object::get_VAO(void)const{
    if(!this->inited)throw("Using uninited Vertex Object!");
    return this->VAO;
}