#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int lens[17][17];
char d[15][10001];
long long rez;
int n;

void compute();
int common(char*,char*);
void back(int i, int len, int, int v[]);

int main()
{
	FILE* fin = fopen("H.dat", "r");
	fscanf(fin,"%d",&n);
	while(n>-1)
	{
		//memset(lens, 0, sizeof(lens));
		//memset(d, 0, sizeof(d));
		for(int i=0; i<n; i++)
		{
			fscanf(fin,"%s", d[i]);
			if( i && strlen(d[i])>strlen(d[i-1]) )
			{
				char a[10001];
				strcpy( a, d[i]);
				strcpy( d[i], d[i-1]);
				strcpy( d[i-1], a);
			}
			rez += strlen(d[i]);
		}
		compute();
		int v[15] = {0};
		back(0, 0, 0, v);
		cout << rez << endl;

		fscanf(fin,"%d",&n);
	}
	return 0;
}

void compute()
{
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		if( i!=j )
			lens[i][j] = common(d[i], d[j]);

	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << lens[i][j] << " ";
		cout << endl;
	}*/
}

int common(char* s,char* t)
{
	int i;
	if( strlen(s) <= strlen(t) ) i=1;
	else i = strlen(s)-strlen(t)+1;
	for(; i<strlen(s); i++)
	{
		bool ok = 1;

		for(int j=0; j<strlen(s)-i && ok; j++)
			if( s[i+j]!=t[j] )
				ok = false;

		if( ok ) return strlen(s)-i;
	}
	return 0;
}

void back(int i, int len, int last, int v[])
{
	//cout << i << " " << last << " " << len << endl;
	//system("pause");
	if( i==n )
	{
		if( len<rez ) rez = len;
	}
	else
	{
		for(int j=0; j<n; j++)
		{
			//cout << i << " " << j << " " << len + strlen(d[j]) - lens[last][j] << " " << rez << endl;
			if( v[j]==0 && ((i==0) || ( len + strlen(d[j]) - lens[last][j] < rez)) )
			{
				v[j] = 1;
				if(i) back(i+1, len + strlen(d[j]) - lens[last][j], j, v);
				else back(i+1, strlen(d[j]), j, v);
				v[j] = 0;
			}
		}
	}
}