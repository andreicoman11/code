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

//ifstream fin ("A-small-attempt1.in");
//ofstream fout ("A-small.out");
ifstream fin ("A-large.in");
ofstream fout ("A-large.out");
int l, d, N;
char dic[5000][16];

int main()
{
	memset( dic, 0, sizeof(dic));
	fin >> l >> d >> N;
	for(int i=0; i<d; i++)
	{
		fin >> dic[i];
		//cout << dic[i] << endl;
	}
	
	for(int i=1; i<=N; i++)
	{
		string w;
		fin >> w;
		//cout << w << endl;
		int pos = 0;
		
		for(int j=0; j<d; j++)
		{
			int c = 0;
			bool ok = 1;
			for(int k=0; k<l && ok; k++)
			{
				//cout << k << " " << c << endl;
				if( isalpha(w[c]) )
				{
					//cout << "here";
					if( w[c]!=dic[j][k] ) ok = 0;
					else c++;
				}
				else
				{
					//cout << "here2";
					// w[c] == '('
					c++;
					bool exists = false;
					while( w[c]!=')' )
					{
						if( w[c]==dic[j][k] )
							exists = true;
						c++;
					}
					c++;
					if( !exists ) ok = false;
				}
			}
			if( ok ) pos++;
		}
	
		fout << "Case #" << i << ": ";
		fout << pos;
		//cout << pos; system("pause");
		if( i!=N ) fout << "\n";
	}

	return 0;
}
