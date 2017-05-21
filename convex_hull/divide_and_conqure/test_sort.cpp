#include <iostream>
#include <vector>
#include "points.h"
#include "sort_points.h"

int mian()
{
	using namespace std;
	vecotr<point> s{{16, 1}, {12, -10}, {15, 20}, {8, 25}, {-1, 3}};
	point p = {12, -10};
	vector<point> result = sort(s, 0, s.size()-1, p);
	for (point p: result){
		cout<<"("<<p.x<<","<<p.y<<")"<<endl;
	}
	return 0;
}
