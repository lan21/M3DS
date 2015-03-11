#include <math.h>
#include "Car.h"
#include "GLTool.h"
#include "GLRender.h"

using namespace p3d;
using namespace std;

/**
  *@author Raktoarivony
  *
  * */
// ************************************************************
Car::~Car() {
}

Car::Car() {
  _orientation.setIdentity();
  _position.set(0,0,0);
  _steering=0;
  _rotateWheel=0;
  _acceleration=0;
  _velocity=0;
}

// ******************************************************************
// méthodes à compléter lors du TP
void Car::drawRim() {
    float angle = 45;
    p3d::modelviewMatrix.push();
    for (int i=0;i<8;i++){
        p3d::modelviewMatrix.rotate(i*angle,1,0,0);
        drawCylinderRim();
    }
    p3d::modelviewMatrix.pop();
}

void Car::drawCylinderRim(){
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
}

void Car::drawWheel() {
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.scale(2.2,2.2,2.2);
    p3d::diffuseColor=Vector3(0,0,1);
    drawTorus();
    p3d::modelviewMatrix.pop();

    p3d::modelviewMatrix.push();
    p3d::diffuseColor=Vector3(1,0,0);
    p3d::modelviewMatrix.rotate(90,0,1,0);
    drawRim();
    p3d::modelviewMatrix.pop();
}

void Car::drawAxle() {
    float length = 6;
    p3d::modelviewMatrix.push();
    p3d::diffuseColor=Vector3(0,1,0);
    p3d::modelviewMatrix.scale(0.2,0.2,length/2);
    drawCylinder();
    p3d::modelviewMatrix.rotate(180,0,1,0);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.translate(0,0,-length/2);
    drawWheel();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.translate(0,0,length);
    drawWheel();
    p3d::modelviewMatrix.pop();

}

void Car::drawBody() {
    p3d::modelviewMatrix.push();
    p3d::diffuseColor=Vector3(1,0,1);
    p3d::modelviewMatrix.scale(1,2,1);
    drawCube();
    p3d::modelviewMatrix.translate(0,-0.5,2);
    p3d::modelviewMatrix.scale(1,0.5,2);
    drawCube();
    p3d::modelviewMatrix.pop();

}

void Car::draw() {
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.scale(2,2,2);
    p3d::modelviewMatrix.translate(0,2,0);
    p3d::modelviewMatrix.rotate(180,0,1,0);
    drawBody();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(90,0,1,0);
    p3d::modelviewMatrix.rotate(-_rotateWheel/6,0,0,1);
    drawAxle();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.translate(0,0,-7);
    p3d::modelviewMatrix.rotate(90,0,1,0);
    p3d::modelviewMatrix.rotate(_steering,0,1,0);
    p3d::modelviewMatrix.rotate(-_rotateWheel/6,0,0,1);
    drawAxle();
    p3d::modelviewMatrix.pop();
}


void Car::drawWorld() {

  p3d::modelviewMatrix.push();
<<<<<<< HEAD
  modelviewMatrix.translate(_position);
  modelviewMatrix.rotate(_orientation);
=======
  modelviewMatrix.rotate(_orientation);
  modelviewMatrix.translate(_position);
>>>>>>> 597ccc6622bd9b614a49fa0956ec62b385fe073b
  draw(); // tracé de la voiture dans son repère local
  p3d::modelviewMatrix.pop();
}

void Car::move() {
  _acceleration+=-_velocity/50;
  _velocity+=_acceleration;
  _rotateWheel+=_velocity*20;
  _steering-=_steering/10*fabs(_velocity);

<<<<<<< HEAD
  _orientation.rotate(_steering*_velocity/(1.0+fabs(_velocity)),Vector3(0,1,0)); // le /100 est déterminé par essai/erreur
  Vector3 uneDirection = _orientation * Vector3 (0,0,-1)*_velocity*0.5;//direction dans le repère local
  p3d::modelviewMatrix.transformDirection(uneDirection);
  _position = _position + uneDirection;

=======
  _orientation.rotate(_steering*_velocity/(1.0+fabs(_velocity)/3),Vector3(0,1,0)); // le /100 est déterminé par essai/erreur
  Vector3 uneDirection = Vector3 (0,0,-1);//direction dans le repère local
  p3d::modelviewMatrix.transformDirection(uneDirection);
  _position = _position + uneDirection*_velocity*0.1;
>>>>>>> 597ccc6622bd9b614a49fa0956ec62b385fe073b

}


void Car::accelerate() {
  _acceleration=0.05;

}

void Car::decelerate() {
  _acceleration=0;
}

void Car::brake() {
  _acceleration=-0.02;

}

void Car::turnLeft() {
  _steering+=0.5;
  if (_steering>35) _steering=35;
}

void Car::turnRight() {
  _steering-=0.5;
  if (_steering<-35) _steering=-35;
}





