#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <vector>

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

    //para cercles
    const uint nb_triangles=200;
    const uint rayon=1;

    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");

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

    std::vector<Vertex2DColor> vertices;
    vertices.push_back(Vertex2DColor(glm::vec2(0, 0), glm::vec3(1, 1, 1)));
    for (size_t i = 0; i <= nb_triangles; i++) {
      vertices.push_back(Vertex2DColor(glm::vec2(rayon*glm::cos(((2*glm::pi<float>())/ nb_triangles)*i), rayon*glm::sin(((2*glm::pi<float>())/ nb_triangles)*i)), glm::vec3(1, 1, 1)));
    }
    glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

    //Debind du vbo
    glBindBuffer(GL_ARRAY_BUFFER,0);


    //Creation IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);

        // => On bind sur GL_ELEMENT_ARRAY_BUFFER, cible reservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // => Tableau d'indices: ce sont les indices des sommets à dessiner
    uint32_t indices[3*nb_triangles];
    indices[0]=0;
    indices[1]=1;
    indices[2]=2;
    for (size_t i = 1; i < nb_triangles; i++) {
      indices[i*3]=0;
      indices[i*3+1]=i+1;
      indices[i*3+2]=i+2;
    }


    // => On remplit l'IBO avec les indices:
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nb_triangles*3* sizeof(uint32_t), indices, GL_STATIC_DRAW);

    // => Comme d'habitude on debind avant de passer à autre chose
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //Creation du VAO
    GLuint vao;
    glGenVertexArrays(1,&vao);

    //Binding du VAO
    glBindVertexArray(vao);

    // => On bind l'IBO sur GL_ELEMENT_ARRAY_BUFFER; puisqu'un VAO est actuellement bindé,
    // cela a pour effet d'enregistrer l'IBO dans le VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

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
        glDrawElements(GL_TRIANGLES, (nb_triangles)*3, GL_UNSIGNED_INT, 0);
        //Debinder
        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1,&vbo);
    glDeleteBuffers(1,&ibo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
