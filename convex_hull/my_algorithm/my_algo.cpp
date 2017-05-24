#include <iostream>
#include <vector>
#include "points.h"
#include <math.h>

using namespace std;

//overloading operator != for point struct
bool operator!=(const point& p1, const point& p2)
{
    if (p1.x==p2.x && p2.y==p1.y){return false;}
    return true;
}


point get_P0(const vector<point> &, int&);
point find_next_vertex(const point & p0, const vector<point> points, int &index);
double polar_angle(point base, point p);

vector<point> my_algo(vector<point> &points){
	
	vector<point> result;
	
	int p0_index;
	point p0 = get_P0(points, p0_index);
	result.push_back(p0);
	points.erase(points.begin() + p0_index);
	
	int p1_index;
	point p1 = find_next_vertex(p0, points, p1_index);
	result.push_back(p1);
	points.erase(points.begin() + p1_index);
	
	point temp_p0;
	while(p1 != p0){
		 temp_p0 = p1;
		 p1 = find_next_vertex(temp_p0, points, p1_index);
		 result.push_back(p1);
		 points.erase(points.begin() + p1_index);
	}
	return result;
	
}


point get_P0(const vector<point> &points, int &index){
	int j = -1;
	
	point P0 = points.at(0);	
	
	for(point i : points){
		j++ ;
		if (i.y<P0.y){
			P0 = i;
			index = j;
		}else if(i.y==P0.y && i.x<P0.x){
			P0 = i;
			index = j;
		}
	}
	return P0;
}

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

point find_next_vertex(const point & p0, const vector<point> points, int &index){
	point next = points.at(0);
	int j = -1;
	for (point p : points){
		j++;
		if ( polar_angle(p0, p) < polar_angle(p0, next) ){
			next = p;
			index = j;
		}
	}
	return next;
}
