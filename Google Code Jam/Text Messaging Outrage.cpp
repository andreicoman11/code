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

//ifstream fin ("A-small-practice.in");
//ofstream fout ("A-small.out");
ifstream fin ("A-large-practice.in");
ofstream fout ("A-large.out");

int N, N2 = 1;
int p, k, l;
long long int presses;

int main()
{
	fin >> N;
	while( N2<=N )
	{
		fin >> p >> k >> l;
		vector<long long int> freq(l);
		for(int i=0; i<l; i++)
			fin >> freq[i];
		sort( freq.begin(), freq.end());
		long long int key_pos = 1;
		int keys = k;
		presses = 0;
		for(int i=l-1; i>=0; i--)
		{
			presses += key_pos * freq[i];
			keys--;
			if( !keys )
			{
				keys = k;
				key_pos++;
			}
			//cout << freq[i] << " " << i << " " << key_pos << " " << presses << "\n";
			//system("pause");
		}

		fout << "Case #" << N2 << ": ";
		fout << presses << "\n";
		N2++;
	}

	return 0;
}
