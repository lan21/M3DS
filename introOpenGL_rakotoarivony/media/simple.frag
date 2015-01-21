#version 130

in vec4 fColor; //calculé par interpolation des valeurs affectées dans le vertex shading

out vec4 fragColor;
        
void main() {
    fragColor=fColor;
}
