#include <glimac/SDLWindowManager.hpp>
#include "glimac/FreeflyCamera.hpp"


void FreeflyCamera::computeDirectionVectors() {
	m_FrontVector=glm::vec3(glm::cos(m_fTheta)*glm::sin(m_fPhi),glm::sin(m_fTheta),glm::cos(m_fTheta)*glm::cos(m_fPhi));
	m_LeftVector=glm::vec3(glm::sin(m_fPhi+glm::half_pi<float>()),0,glm::cos(m_fPhi+glm::half_pi<float>()));
	m_UpVector=glm::cross(m_FrontVector,m_LeftVector);
}

void FreeflyCamera::moveLeft(float t){
	m_Position+=t*m_LeftVector;
	computeDirectionVectors();
}

void FreeflyCamera::moveFront(float t){
	m_Position+=t*m_FrontVector;
	computeDirectionVectors();
}

void FreeflyCamera::rotateLeft(float degrees){
	m_fTheta+=glm::radians(degrees);
	computeDirectionVectors();
}

void FreeflyCamera::rotateUp(float degrees){
	m_fPhi+=glm::radians(degrees);
	computeDirectionVectors();
}

glm::mat4 FreeflyCamera::getViewMatrix() {
	return glm::lookAt(m_Position,m_Position+m_FrontVector,m_UpVector);
}
