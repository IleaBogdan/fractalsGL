#include"main.h"

std::vector<int>square_attribute_sizes={3};
std::vector<float>square={
    -1.f,-1.f,0.f,
    -1.f,1.f,0.f,
    1.f,1.f,0.f,
    1.f,-1.f,0.f,
};

signed main(int argc,char*argv[]){
    init(main_window,"Fractals",true);
    int width,height;
    glfwGetWindowSize(main_window,&width,&height);
    glViewport(0,0,width,height);
    glfwSetInputMode(main_window,GLFW_CURSOR,GLFW_CURSOR_HIDDEN); // hide cursor

    set_callbacks(main_window);
    glfwSetKeyCallback(main_window,key_callback);

    shader main_shader;
    main_shader.init("shaders/vertex.glsl","shaders/mandelbrot.glsl");
    
    vertex_object vo;
    vo.init(square,square_attribute_sizes);

    glfwMakeContextCurrent(main_window);
    while(!glfwWindowShouldClose(main_window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        float time=glfwGetTime();
        float blueVal=(sin(time)/2.f)+.5f;

        int unsigned curr_program=main_shader.get_program();

        glUseProgram(curr_program);
        
        int offsetIdx=glGetUniformLocation(curr_program,"offset");
        glUniform2f(offsetIdx,global_horizontal_offset,global_vertical_offset);
        
        int alphaIdx=glGetUniformLocation(curr_program,"alpha");
        glUniform1f(alphaIdx,alpha);

        int timeIdx=glGetUniformLocation(curr_program,"time");
        glUniform1f(timeIdx,time);
        
        int zoomIdx=glGetUniformLocation(curr_program,"zoom");
        glUniform1f(zoomIdx,zoom);

        glBindVertexArray(vo.get_VAO());
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just the lines
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill inside the lines
        glDrawArrays(GL_TRIANGLE_FAN,0,vo.shape_size());

        glBindVertexArray(0);
        // end of render stuff

        glfwSwapBuffers(main_window);        
        glfwPollEvents();
    }
    end_program:
    glfwDestroyWindow(main_window);
    glfwTerminate();
    return 0;
}