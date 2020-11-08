#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

using namespace glimac;

struct Vertex2DUV {
        glm::vec2 position;
        glm::vec2 texture;
        Vertex2DUV()
        {
        }
        Vertex2DUV(glm::vec2 positionSet,glm::vec2 texSet):position(positionSet),texture(texSet)
        {
        }
};

glm::mat3 translate(float tx, float ty){
  return glm::mat3(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(tx, ty, 1));
}

glm::mat3 scale(float tx, float ty){
  return glm::mat3(glm::vec3(tx, 0, 0), glm::vec3(0, ty, 0), glm::vec3(0, 0, 1));
}

glm::mat3 rotate(float a){
  float angle = glm::radians(a);
  return glm::mat3(glm::vec3(cos(angle),sin(angle), 0), glm::vec3(-sin(angle),cos(angle), 0), glm::vec3(0, 0, 1));
}


const GLuint VERTEX_ATTR_POSITION = 0;
const GLuint VERTEX_ATTR_TEXTURE = 1;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(600, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/tex2D.vs.glsl", applicationPath.dirPath() + "shaders/tex2D.fs.glsl");
    program.use();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //GLint tmpsLoc=glGetUniformLocation(program.getGLId(),"uTime");
    GLint uModelMatrixLoc=glGetUniformLocation(program.getGLId(),"uModelMatrix");
    GLint uColorLoc=glGetUniformLocation(program.getGLId(),"uColor");

    //Creation VBO
    GLuint vbo;
    glGenBuffers(1,&vbo);

    //Binding du VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Creation des vertices
    Vertex2DUV vertices[] = {
        Vertex2DUV(glm::vec2(-1, -1), glm::vec2(0, 0)),
        Vertex2DUV(glm::vec2(1, -1), glm::vec2(0, 0)),
        Vertex2DUV(glm::vec2(0, 1), glm::vec2(0, 0)),
    };
    glBufferData(GL_ARRAY_BUFFER,3*sizeof(Vertex2DUV), vertices, GL_STATIC_DRAW);

    //Debind du vbo
    glBindBuffer(GL_ARRAY_BUFFER,0);

    //Creation du VAO
    GLuint vao;
    glGenVertexArrays(1,&vao);

    //Binding du VAO
    glBindVertexArray(vao);

    //Activation des attributs de vertex
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION); //position
    glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);
    //Specification des attributs
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV),(const GLvoid*) (offsetof(Vertex2DUV,position)));
    glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV),(const GLvoid*) (offsetof(Vertex2DUV,texture)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //Debinder le VAO
    glBindVertexArray(0);

    // Application loop:
    bool done = false;
    float anticlockwise = 0;
    float clockwise = 0;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        //Clear window
        glClear(GL_COLOR_BUFFER_BIT);
        //Bind vao
        glBindVertexArray(vao);

        //--------Draw calls---------

        //First triangle
        glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(0.5, 0.5) * scale(0.25, 0.25) * rotate(clockwise)));
        glUniform3f(uColorLoc,0.0,1.0,0.0);
        glDrawArrays(GL_TRIANGLES,0,3);

        //Second triangle
        glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(0.5, -0.5) * scale(0.25, 0.25) * rotate(anticlockwise)));
        glUniform3f(uColorLoc,0.0,0.0,1.0);
        glDrawArrays(GL_TRIANGLES,0,3);

        //Third triangle
        glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(-0.5, 0.5) * scale(0.25, 0.25) * rotate(anticlockwise)));
        glUniform3f(uColorLoc,0.5,0.8,0.4);
        glDrawArrays(GL_TRIANGLES,0,3);

        //Fourth triangle
        glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(-0.5, -0.5) * scale(0.25, 0.25) * rotate(clockwise)));
        glUniform3f(uColorLoc,0.6,0.15,0.7);
        glDrawArrays(GL_TRIANGLES,0,3);

        //Rotation update
        anticlockwise -= 0.05;
        clockwise += 0.05;

        //Debinder
        glBindVertexArray(0);


        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
