#include <iostream>
#include <vector>
#include "points.h"
#include "sort_points.h"

using namespace std;

int main()
{

	vector<point> s{{-7, 0}, {16, 1},  {15, 20}, {8, 25}, {-1, 3}, {15, -7}, {18, -4}};
	point p = {12, -10};
	vector<point> result (sort(s, 0, s.size()-1, p));
	for (point p: result){
		cout<<"("<<p.x<<","<<p.y<<")"<<endl;
	}
	return 0;
}
