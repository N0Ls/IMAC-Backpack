#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Sphere.hpp>

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(600, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //Loading shader files
    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/normals.fs.glsl");
    program.use();

    //Getting uniforms
    GLint uMVPMatrixLoc=glGetUniformLocation(program.getGLId(),"uMVPMatrix");
    GLint uMVMatrixLoc=glGetUniformLocation(program.getGLId(),"uMVMatrix");
    GLint uNormalMatrixLoc=glGetUniformLocation(program.getGLId(),"uNormalMatrix");

    glEnable(GL_DEPTH_TEST);


    //Creating sphere
    glimac::Sphere sphere(1,32,16);

    //Creating VBO
    GLuint vbo;
    glGenBuffers(1,&vbo);

    //Binding VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Creation of verticies
    glBufferData(GL_ARRAY_BUFFER,sphere.getVertexCount()*sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

    //Debinding VBO
    glBindBuffer(GL_ARRAY_BUFFER,0);

    //Creating VAO
    GLuint vao;
    glGenVertexArrays(1,&vao);

    //Binding VAO
    glBindVertexArray(vao);

    //Vertex attrib positions
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEXCOORD = 2;

    //Activating attributes
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    //Specifying attributes
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
      glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE,sizeof(ShapeVertex),(const GLvoid*) offsetof(ShapeVertex, position));
      glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE,sizeof(ShapeVertex),(const GLvoid*) offsetof(ShapeVertex, normal));
      glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE,sizeof(ShapeVertex),(const GLvoid*) offsetof(ShapeVertex, texCoords));
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    //Debinding VAO
    glBindVertexArray(0);

    //Creating matrices
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.0f, 0.1f, 100.f);
    glm::mat4 MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.0,0.0,-5.0));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


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

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Sending matrices to vertex shader
        glUniformMatrix4fv(uMVPMatrixLoc,1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(uMVMatrixLoc,1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrixLoc,1, GL_FALSE, glm::value_ptr(NormalMatrix));

        //Binding VAO
        glBindVertexArray(vao);

        //Draw call
        glDrawArrays(GL_TRIANGLES,0,sphere.getVertexCount());

        //Unbindign VAO
        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
