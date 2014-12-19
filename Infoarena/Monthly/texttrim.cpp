#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define pb push_back
#define sz size()
#define INFILE "texttrim.in" 
#define OUTFILE "texttrim.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

LL w[32], s;
string buf;

LL getnr(char c)
{
	if( c==' ' ) return w[0];
	return w[int(c) - int('a') + 1];
}

int main()
{
	for(int i=0; i<27; i++)
		fin >> w[i];
	getline(fin, buf);
	getline(fin, buf);
	fin >> s;

	int i = 0;
	for(; s>=0 && i<buf.sz; i++)
	{
		LL width = getnr(buf[i]);
		s -= width;
	}

	if( s>=0 ) {
		fout << buf;
	} else {
		
		while( s<3 ) {
			i--;
			LL width = getnr(buf[i]);
			s += width;
		}
		fout << buf.substr(0, i) << "...";
	}

	return 0;
}