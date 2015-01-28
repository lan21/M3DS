#version 130
        
in vec3 position;
in vec4 color;//attribut des couleur de sommet
in vec2 texCoord;

uniform float coeff; //question 21

out vec4 fColor;
out vec2 fTexCoord;

        
void main() {
    vec3 newPosition = position;
    newPosition = position*coeff;
    gl_Position=vec4(newPosition,1.0);
    fColor = color;
    fTexCoord = texCoord;
}
