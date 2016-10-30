#include "Dragon.h"

//Constructor. Calls the constructor from Turtle
Dragon::Dragon(float initX, float initY, float initAngle)
	: Turtle(initX, initY, initAngle) {
}

//------------------------------ leftCurve ----------------------------------
// draw a level-n left curve with distance d
void Dragon::leftCurve(int level, float d) {
	if (level > 0) {
		leftCurve(level - 1, d);
		turn(90);
		rightCurve(level - 1, d);
		turn(90);
	}
	else
		draw(d);
}

//------------------------------ rightCurve ---------------------------------
// draw a level-n right curve with distance d
void Dragon::rightCurve(int level, float d) {
	if (level > 0) {
		turn(-90);
		leftCurve(level - 1, d);
		turn(-90);
		rightCurve(level - 1, d);
	}
	else
		draw(d);
}