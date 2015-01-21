#version 130
        
in vec3 position;
in vec4 color;//attribut des couleur de sommet

out vec4 fColor;

        
void main() {
    gl_Position=vec4(position,1.0);
    fColor = color;
}
