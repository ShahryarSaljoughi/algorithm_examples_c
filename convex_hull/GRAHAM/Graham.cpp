// written by shahryar saljoughi , may-2017
// Graham algorithm for convex hull problem . 

#include <vector>
#include <iostream>
#include <stack>
#include "sort_points.h"
#include "points.h"

using namespace std;

point get_P0(vector<point> &points);


//left_turn determines if these points constitute a left turn or a right turn.
bool left_turn(const point &p1, const point &p2,const point &p3);


vector<point> graham_solution(vector<point> points){
	// first we need to choose a point as P0! (check the docs to see what P0 is):
	point P0 = get_P0(points);
	
	// let's sort points by their polar angles (based on P0) :
	vector<point> sorted_points( sort(points, 0, points.size()-1, P0) );
	
	vector<point> Stack;
	Stack.push_back(sorted_points.at(0));
	Stack.push_back(sorted_points.at(1));
	Stack.push_back(sorted_points.at(2));
	
	// 'it' is a pointer to sorted_points elements!
	vector<point>::iterator it;
	it = sorted_points.begin();
	it = it + 3;
	for(it; it!=sorted_points.end(); it++){
		point pi = *it;
		point top = Stack.back();
		point next_to_top =  Stack.at(Stack.size()-2);
		
		while(!left_turn(next_to_top, top, pi)){
			Stack.pop_back();
			top = Stack.back();
			next_to_top = Stack.at(Stack.size()-2);
			}
		Stack.push_back(pi);
	}
	return Stack;
}


bool left_turn(const point &p1, const point &p2,const point &p3){
	bool result;
	
	double determinant = (
		(p2.x*p3.y - p3.x*p2.y) +
						 (p3.x*p1.y - p1.x*p3.y)  +
						 				 (p1.x*p2.y - p2.x*p1.y)
						 				 );
	//if determinant>0 , angle is a left-turn .
	result = (determinant>0);  					
	
	return result;
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
