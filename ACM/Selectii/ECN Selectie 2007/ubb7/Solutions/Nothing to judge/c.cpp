#include <fstream>
#include <iostream>
using namespace std;

void main()
{
	ifstream fin("c.in");
	int test;
	fin>>test;
	while (test--)
	{
		int a,b,c;
		fin>>a>>b>>c;
		if (a<b-c) cout<<"advertise"<<endl;
		else if (a==b-c) cout<<"does not matter"<<endl;
		else cout<<"do not advertise"<<endl;
	}
}