#pragma once

#include <vector>

#include "common.hpp"
#include <glm/gtc/constants.hpp>

class FreeflyCamera {

public:
  FreeflyCamera(){
    m_Position=glm::vec3(0,0,5.0);
    m_fPhi=glm::pi<float>();
    m_fTheta=0;
    computeDirectionVectors();
  }
  ~FreeflyCamera(){}

  void moveLeft(float t);
  void moveFront(float t);
  void rotateLeft(float degrees);
  void rotateUp(float degrees);
  glm::mat4 getViewMatrix();



private:
  glm::vec3 m_Position;
  float m_fPhi;
  float m_fTheta;
  glm::vec3 m_FrontVector;
  glm::vec3 m_LeftVector;
  glm::vec3 m_UpVector;

  void computeDirectionVectors();
};
