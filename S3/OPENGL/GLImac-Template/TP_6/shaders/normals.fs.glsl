#version 300 es
precision mediump float;

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords;

out vec3 fFragColor;

void main() {
    fFragColor = normalize(vNormal_vs);
}
