#version 300 es
precision mediump float;

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

// Input matrices
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

// Shader's output
out vec3 vPosition_vs; // Vertex position in the view model
out vec3 vNormal_vs; // Normals of the vertex in the view model
out vec2 vTexCoords; // Texture coordinates for the vertex

void main() {
    vec4 vertexPosition = vec4(aVertexPosition, 1);
    vec4 vertexNormal = vec4(aVertexNormal, 0);

    // Computing outputs
    vPosition_vs = vec3(uMVMatrix * vertexPosition);
    vNormal_vs = vec3(uNormalMatrix * vertexNormal);
    vTexCoords = aVertexTexCoords;

    // Projected position output
    gl_Position = uMVPMatrix * vertexPosition;
}
