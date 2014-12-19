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

ifstream fin ("A-large-practice.in");
ofstream fout ("A-large.out");

unsigned long long int n;
string no, sl, tl, res;

int main()
{
	int N, N2 = 1;
	fin >> N;
	while( N2<=N )
	{
		fin >> no >> sl >> tl;

		n = 0;
		for(int i=0; i<no.size(); i++)
		{
			n *= (sl.size());
			for(int j=0; j<sl.size(); j++)
				if( sl[j]==no[i] )
				{
					n += j;
					break;
				}
		}
		cout << no << " " << sl << "\t" << n << endl;
		
		res = "";
		while(n)
		{
                int nr = n%tl.size();
                res = tl[nr] + res;
                n /= tl.size();
        }
        
        fout << "Case #" << N2++ << ": " << res;
        if( N+1!=N2 ) fout << "\n";
	}

	return 0;
}
