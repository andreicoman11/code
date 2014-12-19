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
#define INFILE "shift.in" 
#define OUTFILE "shift.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

string s;
char l[32][2];
int pos[32][2], c[32][2];

int getint(char c) {
	return int(c)-int('a');
}

int dist(int x, int y) {
	return abs(x-y);
}

int main()
{
	fin >> s;
	for(int i=0; i<26; i++)
		fin >> l[i][0] >> l[i][1];

	for(int i=0; i<26; i++)	{
		int x, y;
		fin >> x >> y;

		int l1 = getint(l[i][0]);
		int idx = 0;
		if( c[l1][idx] ) idx++;

		pos[l1][idx] = i;
		c[l1][idx] = x;

		int l2 = getint(l[i][1]);
		idx = 0;
		if( c[l2][idx] ) idx++;

		pos[l2][idx] = i;
		c[l2][idx] = y;
	}

	int pos1=0, pos2=0, cost1=0, cost2=0;
	for(int i=0; i<s.size(); i++) {
		int posx = pos[getint(s[i])][0];
		int posy = pos[getint(s[i])][1];

		int costx = c[getint(s[i])][0] + 
						min( cost1 + dist(pos1, posx),
							cost2 + dist(pos2, posx));

		int costy = c[getint(s[i])][1] + 
						min( cost1 + dist(pos1, posy),
							cost2 + dist(pos2, posy));
									
		pos1 = posx;
		pos2 = posy;
		cost1 = costx;
		cost2 = costy;
	}
	fout << min(cost1, cost2);

	return 0;
}
