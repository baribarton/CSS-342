
#ifndef DRAGON_H
#define DRAGON_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class Dragon : Turtle {
public:
	Dragon(float initX = 0.0, float initY = 0.0, float initAngle = 0.0);
	void leftCurve(int l, float d);  //draw a level-1 left curve with distance d
	void rightCurve(int l, float d); //draw a level-1 right curve with distance d
};
#endif