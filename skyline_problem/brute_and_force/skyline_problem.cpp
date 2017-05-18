
#include<iostream>
//#include "headers/structures.h"
using namespace std;

struct skyscraper{
	int x1;
	int height;
	int x2;
};

struct point_s{
	int x;
	int h; //=y
};

void insertion_sort_points(point_s array[], int n);


void skyscraperSolution(skyscraper s[], int n, point_s result[]){
	// n is the number of skyscrapers.
	//this func returens an array of points as result. 
	
	//get a list of critical points:
	point_s critical_points[2*n];
	for(int i=0; i<n; i++){
		critical_points[2*i+1].x = s[i].x2;
		critical_points[2*i+1].h = 0;
		
		critical_points[2*i].x = s[i].x1;
		critical_points[2*i].h = s[i].height;//s[i].height;
		
	}
	
	//let's sort critical points:
	insertion_sort_points(critical_points,2*n);
	
	for(int i=0;i<n;i++){ //for each rectangle
		for(int j=0; j<2*n; j++){ //for each critical point
			if (critical_points[j].x < s[i].x2 && critical_points[j].x >= s[i].x1){
				if (critical_points[j].h < s[i].height){
					critical_points[j].h = s[i].height; // get the max!
				}
			}
		}
	}
	
	for(int j=0; j<2*n;j++){result[j]=critical_points[j];}
}

int main(){
	
	skyscraper input[] = {
			{1, 11, 5},
			{2, 6, 7},
			{3, 13, 9},
			{12, 7, 16},
			{14, 3, 25},
			{19, 18, 22},
			{23, 13, 29},
			{24, 4, 28},
		};
		
	int input_size = sizeof(input)/sizeof(input[0]); //number of skyscrapers
	point_s result[2*input_size];
	skyscraperSolution(input, input_size, result);
	for (int i=0; i< 2*input_size;i++){
		cout<<"point"<<i<<" "<<result[i].x<<", "<<result[i].h<<endl;
	}
	return 0;
}
void insertion_sort_points(point_s array[], int n){
	for(int i=0; i<n-1; i++){
		int j=i;
		point_s v=array[i+1];
		while(j>-1 && v.x<array[j].x){
			array[j+1]=array[j];
			j--;
		}
		j=j+1;
		array[j] = v;
	}
}
