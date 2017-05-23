#include <iostream>
#include "Graham.h"
#include <vector>

using namespace std;
int main()
{
	vector<point> input= {
		{1, 1},
		{2, 2},
		{3, 3},
		{1, 3}
	};
	
	vector<point> input2 = {
		{4.4, 14},
		{6.7, 15.25}, 
		{6.9, 12.8}, 
		{2.1, 11.1}, 
		{9.5, 14.9}, 
		{13.2, 11.9}, 
		{10.3, 12.3}, 
		{6.8, 9.5}, 
		{3.3, 7.7}, 
		{0.6, 5.1}, 
		{5.3, 2.4}, 
		{8.45, 4.7}, 
		{11.5, 9.6}, 
		{13.8, 7.3}, 
		{12.9, 3.1}, 
		{11, 1.1}
	};
	
	
	vector<point> result(graham_solution(input2));
	for(point p: result){
		cout<<"("<<p.x<<", "<<p.y<<")"<<endl;
	}
	return 0;
}
