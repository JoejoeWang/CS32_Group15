#include <iostream>
#include "color.h"

/* simple data representation of an implicit ellipse */
class ellipse {
  public:
	ellipse() {centerX=0;centerY=0;radi1=0;radi2=0;}
	ellipse(double cX, double cY, double r1, double r2, color C) :  
		centerX(cX), centerY(cY), radi1(r1), radi2(r2), inC(C) {}

	double eval(double x, double y) {
		return ( ((centerX-x)*(centerX-x))/(radi1*radi1) + 
				((centerY-y)*(centerY-y))/(radi2*radi2) - 1.0f);
	}
	color getInC() const {return inC; }

  private:
	double centerX, centerY; //center point of ellipse
	double radi1, radi2; //radii of the ellipse
	color inC;
};