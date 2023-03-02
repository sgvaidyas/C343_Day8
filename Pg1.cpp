#include<iostream>
#include<vector>

using namespace std;


int main()
{
	vector<int> v(4);
	
	v.at(0) = 11;
	v.at(1) = 22;
	v.at(2) = 33;
	v.at(3) = 44;
	//the below statement throws out of range error
//	v.at(4)=999;
	
	cout<<"\n vector data = \n";
	for(int i=0;i<v.size();i++)
		cout<<v.at(i)<<endl;
	return 0;
	
}
