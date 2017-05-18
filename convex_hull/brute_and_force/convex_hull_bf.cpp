// written by shahryar saljoughi
//this code uses c++11 features gets errors if compiled with older versions!

#include <vector>
#include <iostream>

using namespace std;

struct point{
	double x;
	double y;
};

bool operator==(const point& p1, const point& p2)
{
    if (p1.x==p2.x && p2.y==p1.y){return true;}
    return false;
}


double determinan(const point &p1,const point &p2,const point &p3)
{
	return ((p2.x*p3.y - p3.x*p2.y) +
		   (p3.x*p1.y - p1.x*p3.y)  +
		   (p1.x*p2.y - p2.x*p1.y));
}

vector<point> sort_points(const point &p1,const point &p2, const point &p3){
	//sorts clockwise
	
	vector<point> result;
	result.resize(3);
	result.at(0) = p1;
	double d = determinan(p1, p2, p3); 
	if (d<0){ // p3 is on the right side of <p1, p2> arrow
		result.at(1) = p2;
		result.at(2) = p3;
	}
	else{
		result.at(1) = p3;
		result.at(2) = p2;
	}
	return result;
}

bool is_inside(const point &pc, const point &p1, const point &p2, const point &p3)
{
	//first we have to sort vertices!
/*
	cout<<"is_inside begins ... points before sort :"<<endl;
	cout<<"		p1("<<p1.x<<","<<p1.y<<")"<<endl;
	cout<<"		p2("<<p2.x<<","<<p2.y<<")"<<endl;
	cout<<"		p3("<<p3.x<<","<<p3.y<<")"<<endl;
*/
	
	vector<point> vertices = sort_points(p1, p2, p3);
	
	bool result = true; 
	
	if (determinan(vertices.at(0), vertices.at(1),pc) > 0){
		result = false;
	}else if (determinan(vertices.at(1), vertices.at(2),pc) > 0){
		result = false;
	}else if (determinan(vertices.at(2), vertices.at(0),pc) > 0){
		result = false;
	}
	
	return result; 
}



void convex_hull(vector<point> &s, vector<point> &result)
{
	for (point pc: s){ //determine if it is a vertex or not.
		cout<<"processing pc("<<pc.x<<","<<pc.y<<")"<<endl;
		bool pc_is_vertex = true;
		for (point pi: s){
			if (pi==pc){continue;}
			for (point pj : s){
				if (pj==pc or pj==pi ){continue;}
				for (point pk : s){
					if (pk==pc or pk==pi or pk==pj ){continue;}
					// here we should check if pc is inside triangle(pi,pj,pk) or not!
					bool is_inside_triangle = is_inside(pc, pi, pj, pk);
					if(is_inside_triangle){
						pc_is_vertex=false;
					}
				}
			}
		}
		if (pc_is_vertex){
			
			result.resize(result.size() + 1);
			result.at(result.size()-1)=pc;
		}
	}
}

int main()
{
	cout<<"started ... "<<endl;
	vector<point> s= {{0, 0},{1, 12},{4, 20},{3, -3},{2, 2}};
	vector<point> result;
	
	convex_hull(s, result);
	cout<<"input size is : "<<s.size()<<endl;
	cout<<"result size is : "<<result.size()<<endl;
	for(point i : result){
		cout<<i.x<<", "<<i.y<<endl;
	}
	return 0;
}


