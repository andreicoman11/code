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
#define sortAll(x) sort(x.begin(), x.end())
#define INFILE "placute.in" 
#define OUTFILE "placute.out"
#define NMAX 1000010

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int cul[NMAX], n, k;
LL s=0;

int main()
{
	fin >> n >> k;
	for(int i=0; i<n; i++)
	{
		int g, c;
		fin >> g >> c;
		cul[g] = c;
	}

	int pos_max = NMAX-1;
	int last_cul = 0;
	for(int i=NMAX-1; i; i--)
		if( cul[i] )
		{
			if( last_cul!=cul[i] )
			{
				s += i;
				last_cul = cul[i];
				cul[i] = 0;
			}
			else 
			{
				while( pos_max && (cul[pos_max]==0 || cul[pos_max]==last_cul )) pos_max--;
				if( pos_max ) {
					s += pos_max;
					last_cul = cul[pos_max];
					cul[pos_max] = 0;
					i++;
				} else break;
			}
		}
	
	fout << s << "\n";
	return 0;
}