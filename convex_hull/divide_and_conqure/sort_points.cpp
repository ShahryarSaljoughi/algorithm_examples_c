#include <iostream>
#include <math.h>

using namespace std;


//declaration . it is implemented somewhere else:
struct point;
//declarations:
double polar_angle(point , point );
double distance(point , point);
void combine(vector<point>&, int , int , int );

vector<point> sort(vector<point> points, int low, int high, const point &P0){
	// unlike other sorts! result of sorting points is not
	// the same size as input ! some points are not included in result!
	// (we notice during sorting that these points are inner points not vertices! )
	
	if (high>low){
		mid = (low+high)/2;
		vector<point> a = sort(points, low, mid);
		vector<point> b = sort(points, mid+1, high);
		vector<point> c = combine(points, low, mid, high, P0);
	}
}

void combine(vector<point> points, int low, int mid, int high, const point &P0){
	int i = low;
	int j= mid+1;
	int k=0;
	
	vector<point> result;
	//result.resize(high - low + 1);
	
	while(i<=mid && j<=high){
		if ( polar_angle(P0, points.at(i)) < polar_angle(P0, points.at(j)) ){
			result.resize(result.size()+1);
			result.at(k) = points.at(i);
			i++;k++;
		}
		else if ( polar_angle(P0, points.at(i)) == polar_angle(P0, points.at(j)) ){
			if distance(P0, points.at.(i)) < distance(P0, points.at(j)){
				result.resize(result.size()+1);
				result.at(k) = points.at(j);
				k++; j++;
				i++; // points[i] is omitted ! (it is not a vertex!!!) ----> pay attention
			}
			else{
				result.resize(result.size()+1);
				result.at(k) = points.at(i);
				k++; 
				i++;
				j++; // we know that points[j] is an inner point not a vertex! 
			}
		}
		else{ // polar_angle(j) is smaller
			result.resize(result.size()+1);
			result.at(k) = points.at(j);
			k++;
			j++;
		}
	}
	
	while(i<=mid){
		result.resize(result.size()+1);
		result.at(k) = points.at(i);
		i++;k++;
	}
	while(j<=high){
		result.resize(result.size()+1);
		result.at(k) = points.at(j);
		j++;k++;
	}
}
	
			
		




double polar_angle(point p0, point p1){
	double result = atan2(p1.y-p0.y, p1.x-p0.x);  // -PI<reuslt<+PI
	return result;
}

double distance(point p0, point p1){
	double result = sqrt( pow(p1.y-p0.y, 2.0) + pow(p1.x-p0.x, 2.0) );
	return result;
}
