#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

ofstream fout ("E.out");
ifstream fin  ("e.dat");
int N;
short int c[11000000];

int value(string,int);

int main()
{
	int n;
	fin >> N;
	while(N)
	{
		fin >> n;
		string f;
		getline(fin, f);

		f = f.substr(1, f.find('N')-2);		
		istringstream in(f);
		string aux="", total="";
		while( in >> aux )
			total = aux + " " + total;

		bool found = false;
		int period = 1;
		memset( c, 0, sizeof(c));

		while( !found )
		{
			n = value(total,n);
			if( c[n] )
			{
				found = true;				
				fout << period-c[n] << "\n";
			}
			else
				c[n] = period;
			period++;
		}

		fin >> N;
	}

	return 0;
}

int value(string f, int x)
{
	if( f[0]=='x' ) return x % N;
	if( isdigit(f[0]) ) return atoi(f.c_str()) % N;

	istringstream in(f + " ");
	string aux="", left="", right="";
	in >> aux;
	f = aux;
	int a=0;
	int b=0;
	while( a!=b+1 && in >> aux )
	{
		if( left=="" ) left = aux;
		else left = left + " " + aux;
		if( aux[0]=='+' || aux[0]=='*' )
			b++;
		else 
			a++;
	}
	while( in >> aux )
	{
		if( right=="" ) right = aux;
		else right = right + " " + aux;
	}
	
	long long int v1 = value(left,x)%N;
	long long int v2 = value(right,x)%N;

	if( f[0]=='+' )
	{
		return (v1 + v2)%N;
	}
	else
	{
		long long int rez = (v1 * v2)%N;
		return rez;
	}
}