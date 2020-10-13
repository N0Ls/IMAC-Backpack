#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>

using namespace glimac;

//Vertex2DColor possédant deux champs glm::vec2 position et glm::vec3 color.
struct Vertex2DColor {
        glm::vec2 position;
        glm::vec3 color;
        Vertex2DColor()
        {
        }
        Vertex2DColor(glm::vec2 positionSet,glm::vec3 colorSet):position(positionSet),color(colorSet)
        {
        }
};


int main(int argc, char** argv) {

    const  GLuint VERTEX_ATTR_POSITION =3;
    const  GLuint VERTEX_ATTR_COLOR =8;
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
                              applicationPath.dirPath() + "shaders/triangle.fs.glsl");
program.use();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //*******INIT*******//

    //Creation VBO
    GLuint vbo;
    glGenBuffers(1,&vbo);

    //Binding du VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Creation des vertices
    Vertex2DColor vertices[] = {
        Vertex2DColor(glm::vec2(-0.5, 0.5), glm::vec3(1, 0, 1)),
        Vertex2DColor(glm::vec2(0.5, 0.5), glm::vec3(1, 0, 1)),
        Vertex2DColor(glm::vec2(-0.5, -0.5), glm::vec3(0, 1, 1)),
        Vertex2DColor(glm::vec2(0.5, 0.5), glm::vec3(1, 0, 1)),
        Vertex2DColor(glm::vec2(0.5, -0.5), glm::vec3(1, 1, 0)),
        Vertex2DColor(glm::vec2(-0.5, -0.5), glm::vec3(0, 1, 1))
    };
    glBufferData(GL_ARRAY_BUFFER,6*sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);

    //Debind du vbo
    glBindBuffer(GL_ARRAY_BUFFER,0);

    //Creation du VAO
    GLuint vao;
    glGenVertexArrays(1,&vao);

    //Binding du VAO
    glBindVertexArray(vao);

    //Activation des attributs de vertex
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION); //position
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR); //couleur

    //Specification des attributs
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor),(const GLvoid*) (offsetof(Vertex2DColor,position)));
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor),(const GLvoid*) (offsetof(Vertex2DColor,color)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //Debinder le VAO
    glBindVertexArray(0);

    // Application loop:
    bool done = false;
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
        //Draw
        glDrawArrays(GL_TRIANGLES,0,6);
        //Debinder
        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
