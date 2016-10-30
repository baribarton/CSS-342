// sierpinski Class 
#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class sierpinski : Turtle {
public:
	sierpinski(float initX = 0.0, float initY = 0.0, float initAngle = 0.0);
	void leftCurve(int l, float d);  //draw a level-1 left curve with dist d
	void rightCurve(int l, float d); //draw a level-1 right curve with dist d
};
#endif