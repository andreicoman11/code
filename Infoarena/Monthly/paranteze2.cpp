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
#define INFILE "paranteze2.in" 
#define OUTFILE "paranteze2.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

char buf[1000010];
int para[500000];
LL rez = 0;

int main()
{
	fin.getline(buf, 1000010);
	int len = strlen(buf);
	memset(para, 0, sizeof(para));
	int curlvl = 0;
	for(int i=0;i<len; i++)
		if( buf[i]=='(' ) {
			curlvl++;
			para[curlvl] = 0;
		} else {
			if(curlvl==0 ) para[0] = 0;
			else {
				curlvl--;
				para[curlvl]++;
				rez += (LL)para[curlvl];
			}
		}

	fout << rez << endl;

	return 0;
}