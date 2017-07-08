#ifndef POLAR
#define POLAR

#include <math.h>
#include "points.h"

double polar_angle(point base, point p){
	double y = p.y - base.y;
	double x = p.x - base.x;
	double result = atan2(y, x);
	
	// I want the range to be : [0, 2pi] instead of [-pi, +pi]
	if ( result < 0 ){
		result = result + 2 * M_PI;
	}
	return result;
}

#endif
