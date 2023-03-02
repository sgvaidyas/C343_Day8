#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n = 5;
	vector<int> v(n,-1);
	
	cout<<"\n vector data = \n";
	for(int i=0;i<v.size();i++)
		cout<<v.at(i)<<endl;
		
		
	for(int i=0;i<n;i++)
	{
		cout<<"\n Please enter data: ";
		cin>>v.at(i);
	}
	
	cout<<"\n vector data = \n";
	for(int i=0;i<v.size();i++)
		cout<<v.at(i)<<endl;
	return 0;
	
}
