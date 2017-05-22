//written by shahryar saljoughi , may-2017

#include <vector>
#include <iostream>
#include <stack>
#include "sort_points.h"


using namespace std;

struct point{
	double x;
	double y;
};

point get_P0(vector<point> &points);

vector<point> sort(vector<point> &points, int low, int high, const point &P0);

vector<point> graham_solution(vector<point> points){
	// first we need to choose a point as P0! (check the docs to see what P0 is):
	point P0 = get_P0(points);
	
	// let's sort points by their polar angles (based on P0) :
	
}



point get_P0(vector<point> &points){
	
	point P0 = points.at(0);	
	
	for(point i : points){
		if (i.y<P0.y){
			P0 = i;
		}else if(i.y==P0.y && i.x<P0.x){
			P0 = i;
		}
	}
	return P0;
}

