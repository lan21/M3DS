#version 130

uniform sampler2D texUnit;

in vec4 fColor; //calculé par interpolation des valeurs affectées dans le vertex shading
in vec2 fTexCoord;

out vec4 fragColor;

        
void main() {
    fragColor=texture2D(texUnit,fTexCoord);
}
