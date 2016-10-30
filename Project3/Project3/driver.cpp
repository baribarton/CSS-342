#include "sierpinski.h"
#include <iostream>
using namespace std;

int main() {
	// right sierpinski at level 5
	sierpinski sierp1(120, 120, 0);
	sierp1.rightCurve(5, 4);

	// left sierpinski at level 5
	sierpinski sierp2(400, 10, 0);
	sierp2.leftCurve(5, 4);

	// left sierpinski at level 4
	sierpinski sierp3(120, 240, 0);
	sierp3.leftCurve(4, 8);

	// right sierpinski at level 4
	sierpinski sierp4(400, 130, 0);
	sierp4.rightCurve(4, 8);

	// right sierpinski at level 3
	sierpinski sierp5(120, 360, 0);
	sierp5.rightCurve(3, 12);

	// left sierpinski at level 3
	sierpinski sierp6(400, 250, 0);
	sierp6.leftCurve(3, 12);

	// left sierpinski at level 2
	sierpinski sierp7(120, 480, 0);
	sierp7.leftCurve(2, 16);

	// right sierpinski at level 2
	sierpinski sierp8(400, 370, 0);
	sierp8.rightCurve(2, 16);

	// right sierpinski at level 1
	sierpinski sierp9(120, 600, 0);
	sierp9.rightCurve(1, 20);

	// left sierpinski at level 1
	sierpinski sierp10(400, 490, 0);
	sierp10.leftCurve(1, 20);

}