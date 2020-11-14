#pragma once

#include <vector>

#include "common.hpp"

class TrackballCamera {

public:
  TrackballCamera():m_fDistance(-5.0f), m_fAngleX(0.0f), m_fAngleY(0.0f){}
  ~TrackballCamera(){}

  void moveFront(float delta);
  void rotateLeft(float degrees);
  void rotateUp(float degrees);
  glm::mat4 getViewMatrix() const;


private:
  float m_fDistance;
  float m_fAngleX;
  float m_fAngleY;
};
