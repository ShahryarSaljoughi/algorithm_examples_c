
#include <iostream>
#include <vector>
#include "points.h"
#include <math.h>
#include <list>

using namespace std;

//overloading operator != for point struct
bool operator!=(const point& p1, const point& p2)
{
    if (p1.x==p2.x && p2.y==p1.y){return false;}
    return true;
}

bool operator==(const point& p1, const point& p2)
{
    if (p1.x==p2.x && p2.y==p1.y){return true;}
    return false;
}


point get_P0(const vector<point> &);
point find_next_vertex(const point & p0, const list<point> points, bool const &falling);
double polar_angle(point base, point p);


vector<point> my_algo(vector<point> &input){
	
	vector<point> result;
	list<point> points ;
	for(point p: input) points.push_back(p);
	
	point p0 = get_P0(input);
	result.push_back(p0); //p0 is a vertex
	
	bool falling = false;
	point p1 = find_next_vertex(p0, points, falling);
	result.push_back(p1);
	points.remove(p1);
	
	point temp_p0;
	while(p1 != p0){
		 temp_p0 = p1;
		 p1 = find_next_vertex(temp_p0, points, falling);
		 result.push_back(p1);
		 points.remove(p1);
		 
		 if (p1.y < temp_p0.y){falling=true; cout<<"started falling"<<endl;}
	}
	return result;
}


point get_P0(const vector<point> &points){
	
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

point find_next_vertex(const point & p0, const list<point> points, bool const &falling){
	list<point>::const_iterator it = points.begin();
	
	if (falling){
		while((it->y > p0.y) and (it!=points.end())){
			++it;
		}
	}
	point next = *it;
		
	for (point p : points){
		if (falling){ //there is an extra constraint in this case : p.y<p0.y
			if ((p0 != p) && (polar_angle(p0, p) < polar_angle(p0, next)) && (p.y < p0.y)){next=p;}
		}else{
			if ((p0 != p) && (polar_angle(p0, p) < polar_angle(p0, next))){next=p;}
		}
	}
	return next;
}
