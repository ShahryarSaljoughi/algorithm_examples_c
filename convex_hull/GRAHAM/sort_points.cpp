#include <iostream>
#include <math.h>
#include <vector>
#include "points.h"

using namespace std;



//declarations:
double polar_angle(point , point );
double distance(point , point);

vector<point> combine(vector<point>&, vector<point>&, const point&);

vector<point> sort(vector<point> points, int low, int high, const point &P0){
	// unlike other sorts! result of sorting points is not
	// the same size as input ! some points are not included in result!
	// (we notice during sorting that these points are inner points not vertices! )
	
	if (high>low){
		int mid = (low+high)/2;
		vector<point> a = sort(points, low, mid, P0);
		vector<point> b = sort(points, mid+1, high, P0);
		vector<point> c = combine(a, b, P0);
		
		return c;
	}
	else{
		vector<point> c;
		c.resize(1);
		c.at(0) = points.at(low); //or high
		
		return c;
	}
}

vector<point> combine(vector<point> &a, vector<point> &b, const point &P0){
	int i = 0; // a[i]
	int j= 0;  // b[j]
	int k=0;   // result[k]
	
	vector<point> result;
	
	while(i<a.size() && j<b.size()){
		if ( polar_angle(P0, a.at(i)) < polar_angle(P0, b.at(j)) ){
			result.resize(result.size()+1);
			result.at(k) = a.at(i);
			i++;k++;
		}
		else if ( polar_angle(P0, a.at(i)) == polar_angle(P0, b.at(j)) ){
			if (distance(P0, a.at(i)) < distance(P0, b.at(j))){
				result.resize(result.size()+1);
				result.at(k) = b.at(j);
				k++; j++;
				i++; // points[i] is omitted ! (it is not a vertex!!!) ----> pay attention
			}
			else{
				result.resize(result.size()+1);
				result.at(k) = a.at(i);
				k++; 
				i++;
				j++; // we know that points[j] is an inner point not a vertex! 
			}
		}
		else{ // polar_angle(j) is smaller
			result.resize(result.size()+1);
			result.at(k) = b.at(j);
			k++;
			j++;
		}
	}
	
	while(i<a.size()){
		result.resize(result.size()+1);
		result.at(k) = a.at(i);
		i++;k++;
	}
	while(j<b.size()){
		result.resize(result.size()+1);
		result.at(k) = b.at(j);
		j++;k++;
	}
	return result;
}


double polar_angle(point p0, point p1){
	double result;
	if (p0.x==p1.x && p0.y==p1.y){
		result = -3.1415926538 - 1;  // sth smaller than -PI
		return result;
	}
	result = atan2(p1.y-p0.y, p1.x-p0.x);  // -PI<reuslt<+PI
	return result;
}

double distance(point p0, point p1){
	double result = sqrt( pow(p1.y-p0.y, 2.0) + pow(p1.x-p0.x, 2.0) );
	return result;
}
