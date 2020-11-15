#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>
#include <glimac/FreeflyCamera.hpp>

using namespace glimac;

struct EarthProgram {
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uEarthTexture;
    GLint uCloudTexture;

    EarthProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uEarthTexture = glGetUniformLocation(m_Program.getGLId(), "uEarthTexture");
        uCloudTexture = glGetUniformLocation(m_Program.getGLId(), "uCloudTexture");
    }
};

struct MoonProgram {
    Program m_Program;

    GLint uMVPMatrixLoc;
    GLint uMVMatrixLoc;
    GLint uNormalMatrixLoc;
    GLint uTextureLoc;

    MoonProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/tex3D.fs.glsl")) {
        uMVPMatrixLoc = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrixLoc = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrixLoc = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTextureLoc = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};

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
    EarthProgram earthProgram(applicationPath);
    MoonProgram moonProgram(applicationPath);


    glEnable(GL_DEPTH_TEST);

    //Loading texture
    std::unique_ptr<Image> pImage = loadImage("/home/nils/Documents/IMAC-Backpack/S3/OPENGL/GLImac-Template/assets/textures/EarthMap.jpg");
    std::unique_ptr<Image> moonImage = loadImage("/home/nils/Documents/IMAC-Backpack/S3/OPENGL/GLImac-Template/assets/textures/MoonMap.jpg");
    std::unique_ptr<Image> cloudImage = loadImage("/home/nils/Documents/IMAC-Backpack/S3/OPENGL/GLImac-Template/assets/textures/CloudMap.jpg");

    if(pImage == NULL || moonImage==NULL || cloudImage==NULL ) {
      std::cerr << "Error during texture loading. Exiting program." << std::endl;
      return EXIT_FAILURE;
    }

    //Create TrackballCamera
    FreeflyCamera camera;

    // Number of textures used
   unsigned int texturesCount = 3;

   // Generate textures
   GLuint *textures = new GLuint[texturesCount];
   glGenTextures(texturesCount, textures);

   // Bind the first texture
   glBindTexture(GL_TEXTURE_2D, textures[0]);
   glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,pImage->getWidth(),pImage->getHeight(),0,GL_RGBA,GL_FLOAT,pImage->getPixels());
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   // Unbind
   glBindTexture(GL_TEXTURE_2D, 0);

   // Bind the second texture
   glBindTexture(GL_TEXTURE_2D, textures[1]);
   glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,moonImage->getWidth(),moonImage->getHeight(),0,GL_RGBA,GL_FLOAT,moonImage->getPixels());
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   // Unbind
   glBindTexture(GL_TEXTURE_2D, 0);

   // Bind the third texture
   glBindTexture(GL_TEXTURE_2D, textures[2]);
   glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,cloudImage->getWidth(),cloudImage->getHeight(),0,GL_RGBA,GL_FLOAT,cloudImage->getPixels());
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   // Unbind
   glBindTexture(GL_TEXTURE_2D, 0);

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
    SDL_EnableKeyRepeat(300, 10);
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            if(e.type == SDL_KEYDOWN) {
              if(e.key.keysym.sym==SDLK_z){
                camera.moveFront(0.1);
              }
              if(e.key.keysym.sym==SDLK_s){
                camera.moveFront(-0.1f);
              }
              if(e.key.keysym.sym==SDLK_q){
                camera.moveLeft(0.1f);
              }
              if(e.key.keysym.sym==SDLK_d){
                camera.moveLeft(-0.1f);
              }
            }
            if(e.type == SDL_MOUSEMOTION) {
              if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT)) {
                     if (e.motion.xrel != 0) {
                         camera.rotateUp(e.motion.xrel / 5.f);
                     }
                     if (e.motion.yrel != 0) {
                         camera.rotateLeft(e.motion.yrel / 5.f);
                    }
              }
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Tell OpenGL to use the earthProgram
        earthProgram.m_Program.use();

        glUniform1i(earthProgram.uEarthTexture, 0);
        glUniform1i(earthProgram.uCloudTexture, 1);

        glm::mat4 globalMVMatrix = camera.getViewMatrix();
        glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.0f, 0.1f, 100.f);

        // Planet Earth transformations
        glm::mat4 earthMVMatrix = glm::rotate(globalMVMatrix, windowManager.getTime(), glm::vec3(0, 1, 0)); // Translation * Rotation

        // Send matrices to the GPU
        glUniformMatrix4fv(earthProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(earthMVMatrix));
        glUniformMatrix4fv(earthProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(earthMVMatrix))));
        glUniformMatrix4fv(earthProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * earthMVMatrix));

        // Bind the VAO
        glBindVertexArray(vao);

        // Bind the planet earth texture on the GL_TEXTURE0 unit
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        // Bind the cloud texture on the GL_TEXTURE1 unit
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, textures[2]);

        // Drawing call
        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        // Unbind the VAO
        glBindVertexArray(0);

        // Bind the VAO
        glBindVertexArray(vao);

        // Unbind of GL_TEXTURE1
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);

        // Tell OpenGL to use the moonProgram
        moonProgram.m_Program.use();

        for (int i = 0; i < moonsNumber; ++i) {
            // Moons transformation
            glm::mat4 moonMVMatrix = glm::rotate(globalMVMatrix,(1 + randomRotationAxis[i][0]+randomRotationAxis[i][1]+randomRotationAxis[i][2])/3 * windowManager.getTime(),randomRotationAxis[i]);
            moonMVMatrix = glm::translate(moonMVMatrix, glm::vec3(-2.0, 0, 0)); // Translation * Rotation * Translation
            moonMVMatrix = glm::scale(moonMVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale

            // Send matrices to the GPU
            glUniformMatrix4fv(moonProgram.uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(moonMVMatrix));
            glUniformMatrix4fv(moonProgram.uNormalMatrixLoc, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(moonMVMatrix))));
            glUniformMatrix4fv(moonProgram.uMVPMatrixLoc, 1, GL_FALSE, glm::value_ptr(ProjMatrix * moonMVMatrix));

            // Bind the moon texture on the GL_TEXTURE0 unit
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, textures[1]);

            // Drawing call
            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        }

        // Unbind of GL_TEXTURE0 unit
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);

        // Unbind the VAO
        glBindVertexArray(0);
        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
