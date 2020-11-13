#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>

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
    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl");
    program.use();

    //Getting uniforms
    GLint uMVPMatrixLoc=glGetUniformLocation(program.getGLId(),"uMVPMatrix");
    GLint uMVMatrixLoc=glGetUniformLocation(program.getGLId(),"uMVMatrix");
    GLint uNormalMatrixLoc=glGetUniformLocation(program.getGLId(),"uNormalMatrix");
    GLint uMainTextureLoc=glGetUniformLocation(program.getGLId(),"uEarthTexture");
    GLint uCloudTextureLoc=glGetUniformLocation(program.getGLId(),"uCloudTexture");


    glEnable(GL_DEPTH_TEST);

    //Loading texture
    std::unique_ptr<Image> pImage = loadImage("/home/nils/Documents/IMAC-Backpack/S3/OPENGL/GLImac-Template/assets/textures/EarthMap.jpg");
    std::unique_ptr<Image> moonImage = loadImage("/home/nils/Documents/IMAC-Backpack/S3/OPENGL/GLImac-Template/assets/textures/MoonMap.jpg");
    std::unique_ptr<Image> cloudImage = loadImage("/home/nils/Documents/IMAC-Backpack/S3/OPENGL/GLImac-Template/assets/textures/CloudMap.jpg");

    if(pImage == NULL || moonImage==NULL || cloudImage==NULL ) {
      std::cerr << "Error during texture loading. Exiting program." << std::endl;
      return EXIT_FAILURE;
    }

    //Creating Texture Object
    GLuint textures[3];
    glGenTextures(3,textures);

    //Binding texture
    glBindTexture(GL_TEXTURE_2D,textures[0]);

    //Creating texture with Image
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,pImage->getWidth(),pImage->getHeight(),0,GL_RGBA,GL_FLOAT,pImage->getPixels());

    //Texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //debind textures
    glBindTexture(GL_TEXTURE_2D,0);

    //Binding texture
    glBindTexture(GL_TEXTURE_2D,textures[1]);

    //Creating texture with Image
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,moonImage->getWidth(),moonImage->getHeight(),0,GL_RGBA,GL_FLOAT,moonImage->getPixels());

    //Texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //debind textures
    glBindTexture(GL_TEXTURE_2D,0);

    //Binding texture
    glBindTexture(GL_TEXTURE_2D,textures[2]);

    //Creating texture with Image
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,cloudImage->getWidth(),cloudImage->getHeight(),0,GL_RGBA,GL_FLOAT,cloudImage->getPixels());

    //Texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //debind textures
    glBindTexture(GL_TEXTURE_2D,0);



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

    //Randoms rotations
    uint moonsNumber = 32;
    std::vector<glm::vec3> randomRotationAxis;
    for (unsigned int i = 0; i < moonsNumber; i++){
          randomRotationAxis.push_back(glm::sphericalRand(5.f));
    }


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

        //Creating matrices
        glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.0f, 0.1f, 100.f);
        glm::mat4 MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.0,0.0,-5.0));
        glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        MVMatrix = glm::rotate(MVMatrix,(-1*windowManager.getTime())/2,glm::vec3(0,1,0));

        //Binding VAO
        glBindVertexArray(vao);

        //Bind texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, textures[1]);
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, textures[2]);


        //Sending matrices to vertex shader
        glUniformMatrix4fv(uMVPMatrixLoc,1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(uMVMatrixLoc,1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrixLoc,1, GL_FALSE, glm::value_ptr(NormalMatrix));

        //sending texture to shaders
        glUniform1i(uMainTextureLoc, 0);
        glUniform1i(uCloudTextureLoc, 2);
        //Draw call
        glDrawArrays(GL_TRIANGLES,0,sphere.getVertexCount());

        //Unbinding textures
        glBindTexture(GL_TEXTURE_2D,0);

          for (size_t i = 0; i < moonsNumber; i++) {
            //Appliying transformations
            MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.0,0.0,-5.0));
            MVMatrix = glm::rotate(MVMatrix,(1 + randomRotationAxis[i][0]+randomRotationAxis[i][1]+randomRotationAxis[i][2])/3 * windowManager.getTime(),randomRotationAxis[i]);
            MVMatrix = glm::translate(MVMatrix, glm::vec3(-2.0, 0, 0));
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2, 0.2, 0.2));

            //Sending matrices
            glUniformMatrix4fv(uMVPMatrixLoc,1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
            glUniformMatrix4fv(uMVMatrixLoc,1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(uNormalMatrixLoc,1, GL_FALSE, glm::value_ptr(NormalMatrix));
            glUniform1i(uMainTextureLoc,1);

            //Draw moon call
            glDrawArrays(GL_TRIANGLES,0,sphere.getVertexCount());
          }
        glBindTexture(GL_TEXTURE_2D,0);

        //Unbindign VAO
        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);
    glDeleteTextures(2,textures);

    return EXIT_SUCCESS;
}
