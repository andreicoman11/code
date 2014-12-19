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

#define INFILE "egalitati.in" 
#define OUTFILE "egalitati.out"
#define NMAX 100010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

char buf[NMAX];

int main()
{
	fin.getline(buf, NMAX);
	int len = strlen(buf);

	bool good = 1;
	int par = 0;
	for(int i=0; i<len; i++)
	{
		switch(buf[i]) {
			case ';' :
				good &= (par==0);
				fout << good << "\n";
				par = 0;
				good = 1;
				break;
			case '.' :
				good &= (par==0);
				fout << good << "\n";
				break;
			case '=' :
				if(par) good = 0;
				break;
			case '(' :
				par++;
				break;
			case ')' : 
				par--;
				if(par<0 ) good = 0;
				break;
			default:
			break;
		}
	}

	return 0;
}