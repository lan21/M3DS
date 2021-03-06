
#version 130

in vec3 position; // Eye Coordinates
in vec3 color;

out vec3 fColor;

uniform mat4 projection;
uniform mat4 transform;

void main() {
  vec4 eyePosition=vec4(position,1); // passage en coordonnées homogènes
  eyePosition=transform*eyePosition;
  vec4 clipPosition=projection*eyePosition; // transformation par la matrice de projection

  fColor=color;

  gl_Position=clipPosition; // gl_Position doit être donné en clip coordinates
}
