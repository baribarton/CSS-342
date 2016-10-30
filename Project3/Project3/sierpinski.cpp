// sierpinski member function definitions
#include "sierpinski.h"

//------------------------- Sierpinski Arrowhead ----------------------------
sierpinski::sierpinski(float initX, float initY, float initAngle)
	: Turtle(initX, initY, initAngle) {
}

//------------------------------ leftCurve ----------------------------------
// draw a level-1 left curve with dist d
void sierpinski::leftCurve(int level, float d) {
	if (level > 0) {
		rightCurve(level - 1, d);
		turn(60);
		leftCurve(level - 1, d);
		turn(60);
		rightCurve(level - 1, d);
	}
	else
		draw(d);
}

//------------------------------ rightCurve ---------------------------------
// draw a level-1 right curve with dist d
void sierpinski::rightCurve(int level, float d) {
	if (level > 0) {
		leftCurve(level - 1, d);
		turn(-60);
		rightCurve(level - 1, d);
		turn(-60);
		leftCurve(level - 1, d);
	}
	else
		draw(d);
}