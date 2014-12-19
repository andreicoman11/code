#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

ifstream fin ("B-small-practice.in");
ofstream fout ("B-small.out");
//ifstream fin ("B-large.in");
//ofstream fout ("B-large.out");

int N, N2 = 1;
string n;
long long int pos;
int nn[50];

bool verif(vector<int> v)
{
	int no = nn[0];
	int c = 0;
	while( c<v.size() && v[c]==0 )
	{
		no = no*10 + nn[++c];
	}
	int new_no = 0;
	int sign = 0;
	//cout << "c = " << c << endl;
	//cout << "new no = " << no << "\n";
	while( c<v.size() )
	{
		sign = v[c++];
		//if( sign==1 )	cout << "   +\n";
		//else			cout << "   -\n";
		new_no = nn[c];
		while( c<v.size() && v[c]==0 )
		{
			new_no = new_no*10 + nn[++c];
		}
		
		//if( c==v.size() && v[c-1]==0 ) new_no = new_no*10 + n[c+1] - int('0');
		//cout << "new no = " << new_no << "\n";
		if( sign==1 ) no += new_no;
		else no -= new_no;
	}
	
	//cout << "no=" << no << endl;
	//system("pause");
	if( no%2==0 || no%3==0 || no%5==0 || no%7==0 )
		return true;
	return false;
}

void calc(int i, vector<int> v)
{
	if( i==v.size() )
	{
		/*for(int k=0; k<v.size(); k++)
		{
			cout << v[k] << " ";
		}
		cout << "\n\n";*/
		
		if(verif(v)) pos++;
	}
	else
		for(int j=0; j<3; j++)
		{
			v[i] = j;
			calc(i+1, v);
		}
}

int main()
{
	fin >> N;
	while( N2<=N )
	{
		cout << N2 << "\n";
		fin >> n;
		for(int i=0; i<n.size(); i++)
			nn[i] = n[i] - int('0');
		pos = 0;

		fout << "Case #" << N2 << ": ";
		N2++;
		vector<int> v(n.size()-1);
		calc(0, v);
		fout << pos << "\n";
	}

	return 0;
}
