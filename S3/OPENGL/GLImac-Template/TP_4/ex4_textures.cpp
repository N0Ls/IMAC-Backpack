#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>


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
    Program program = loadProgram(applicationPath.dirPath() + "shaders/tex2D_ex4.vs.glsl", applicationPath.dirPath() + "shaders/tex2D_ex4.fs.glsl");
    program.use();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //Loading texture
    std::unique_ptr<Image> pImage = loadImage("/home/nils/Documents/IMAC-Backpack/S3/OPENGL/GLImac-Template/assets/textures/triforce.png");

    if(pImage == NULL) {
      std::cerr << "Error during texture loading. Exiting program." << std::endl;
      return EXIT_FAILURE;
    }

    //Creating Texture Object
    GLuint texture;
    glGenTextures(1,&texture);

    //Binding texture
    glBindTexture(GL_TEXTURE_2D,texture);

    //Creating texture with Image
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,pImage->getWidth(),pImage->getHeight(),0,GL_RGBA,GL_FLOAT,pImage->getPixels());

    //Texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //debind textures
    glBindTexture(GL_TEXTURE_2D,0);

    //
    //GLint tmpsLoc=glGetUniformLocation(program.getGLId(),"uTime");
    GLint uModelMatrixLoc=glGetUniformLocation(program.getGLId(),"uModelMatrix");
    GLint uTextureLoc=glGetUniformLocation(program.getGLId(),"uTexture");

    //Creation VBO
    GLuint vbo;
    glGenBuffers(1,&vbo);

    //Binding du VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Creation des vertices
    Vertex2DUV vertices[] = {
        Vertex2DUV(glm::vec2(-1, -1), glm::vec2(0, 1)),
        Vertex2DUV(glm::vec2(1, -1), glm::vec2(1, 1)),
        Vertex2DUV(glm::vec2(0, 1), glm::vec2(0.5, 0)),
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
        glBindTexture(GL_TEXTURE_2D,texture);

          glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(0.5, 0.5) * scale(0.25, 0.25) * rotate(clockwise)));
          glUniform1i(uTextureLoc,0);
          glDrawArrays(GL_TRIANGLES,0,3);

        // //Second triangle

          glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(0.5, -0.5) * scale(0.25, 0.25) * rotate(anticlockwise)));
          glUniform1i(uTextureLoc,0);
          glDrawArrays(GL_TRIANGLES,0,3);

        // //Third triangle

          glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(-0.5, 0.5) * scale(0.25, 0.25) * rotate(anticlockwise)));
          glUniform1i(uTextureLoc,0);
          glDrawArrays(GL_TRIANGLES,0,3);

        // //Fourth triangle

          glUniformMatrix3fv(uModelMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotate(clockwise/4) * translate(-0.5, -0.5) * scale(0.25, 0.25) * rotate(clockwise)));
          glUniform1i(uTextureLoc,0);
          glDrawArrays(GL_TRIANGLES,0,3);

        glBindTexture(GL_TEXTURE_2D,0);

        //Rotation update
        anticlockwise -= 0.05;
        clockwise += 0.05;

        //Debinder
        glBindVertexArray(0);


        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);
    glDeleteTextures(1,&texture);

    return EXIT_SUCCESS;
}
