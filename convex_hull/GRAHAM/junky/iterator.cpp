#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	vector<int>::iterator it = v.begin();
	it = it+1;
	
	for(it; it!=v.end(); it++){
		cout<<*it;
	}
	return 0;
}
