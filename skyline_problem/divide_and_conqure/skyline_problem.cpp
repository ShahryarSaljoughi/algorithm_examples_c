//written by shahryar saljoughi
#include<iostream>
using namespace std;

struct skyscraper{
	int x1;
	int h;
	int x2;
};

struct strip{ //was named point_s in the brute and force approach!
	int x;
	int h;
};

void combine(strip s[], int low, int mid, int high);

void solve(skyscraper s[], int low, int high, strip result[]){ // result will be saved in result array!
	cout<<"solving s["<<low<<" .. "<<high<<"]"<<endl;
	if(high>low){
		int mid = (low+high)/2;
		solve(s, low, mid, result);
		solve(s, mid+1, high, result);
		combine(result, low*2, mid*2+1, high*2+1); // i --> i*2 | i*2+1
		
	}else{ // there is only one skyscraper! : low=high
		strip a = {s[low].x1, s[low].h};
		strip b = {s[low].x2, 0};
		result[low*2]   = a;
		result[low*2+1] = b;
		cout<<"new strip:  "<<a.x<<","<<a.h<<"  added to result["<<low*2<<"]"<<endl;
		cout<<"new strip:  "<<b.x<<","<<b.h<<"  added to result["<<low*2+1<<"]"<<endl;
	}
}

void combine(strip s[], int low, int mid, int high){
	int h1 = 0, h2= 0; // current height of left part and right part
	int k = 0; // index of temp array.
	int i = low; // index of left part.
	int j = mid+1; //index of right part
	
	strip temp[high-low +1];
	
	while(i<=mid && j<=high){
		strip new_strip;
		// set x of new strip:
		if (s[i].x<=s[j].x){
			new_strip.x = s[i].x;
			h1 = s[i].h;
			i++;
		}else{
			new_strip.x = s[j].x;
			h2 = s[j].h;
			j++;
		}
		
		// set h of new strip: strip.h=max(h1,h2)
		if(h1>h2){
			new_strip.h=h1;
		}else{
			new_strip.h=h2;
		}
		//strore strip somewhere
		temp[k] = new_strip;
		k++;
	}
	while(i<=mid){
		temp[k]=s[i];i++; k++;
	}
	while(j<=high){
		temp[k]=s[j];j++; k++;
	}
	
	//save temp back in s[]:
	for(int l=low; l<=high; l++){s[l+low] = temp[l];}
}

int main(){
	skyscraper a[]={
		{1, 11, 5},
		{2, 6, 7}	
	};
	
	skyscraper b[]={{1, 11, 5}};
	int input_size = sizeof(a)/sizeof(a[0]); //number of skyscrapers
	strip result[2*input_size];
	solve(a, 0, input_size-1, result);
	cout<<"input size : "<< input_size<<endl;
	//print result
	for(int i=0; i<2*input_size; i++){
		cout<<"point "<<i<<"   ("<<result[i].x<<", "<<result[i].h<<")"<<endl;
	}
	return 0;
}
