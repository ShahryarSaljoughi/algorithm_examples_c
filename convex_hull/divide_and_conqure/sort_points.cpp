#include <iostream>
#include <math.h>

using namespace std;


//declaration . it is implemented somewhere else:
struct point;
//declarations:
double polar_angle(point , point );
double distance(point , point);
vector<point> combine(vector<point>&, vector<point>&, const point&);

vector<point> sort(vector<point> points, int low, int high, const point &P0){
	// unlike other sorts! result of sorting points is not
	// the same size as input ! some points are not included in result!
	// (we notice during sorting that these points are inner points not vertices! )
	
	if (high>low){
		mid = (low+high)/2;
		vector<point> a = sort(points, low, mid);
		vector<point> b = sort(points, mid+1, high);
		vector<point> c = combine(a, b, P0);
		return c;
	}
	else{
		return points;
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
			if distance(P0, a.at.(i)) < distance(P0, b.at(j)){
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
		result.at(k) = points.at(i);
		i++;k++;
	}
	while(j<b.size()){
		result.resize(result.size()+1);
		result.at(k) = points.at(j);
		j++;k++;
	}
	return result;
}


double polar_angle(point p0, point p1){
	double result = atan2(p1.y-p0.y, p1.x-p0.x);  // -PI<reuslt<+PI
	return result;
}

double distance(point p0, point p1){
	double result = sqrt( pow(p1.y-p0.y, 2.0) + pow(p1.x-p0.x, 2.0) );
	return result;
}
