#ifndef COLOR_H
#define COLOR_H

#include <cmath>
#include <iostream>

#include "util.h"

using std::sqrt;

/* A color for a PPM file is red, greem blue amounts as whole numbers 0-255 */
class color {
	public:
		color() {red=0; green=0; blue=0;}
		color(int r, int g, int b) : red(r), green(g), blue(b) {}
		// {
		// 	red = r;
		// 	green = g;
		// 	blue = b;
		// }
		int r()
		{
			return red;
		}
		int g()
		{
			return green;
		}
		int b()
		{
			return blue;
		}
		color& operator=(const color &Inc)
		{
			red = Inc.red;
			green = Inc.green;
			blue = Inc.blue;
			return *this;
		}
	private:
		int green;
		int red;
		int blue;
};


#endif
