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

//ifstream fin ("C-small-attempt0.in");
//ofstream fout ("C-small.out");
ifstream fin ("C-large-practice.in");
ofstream fout ("C-large-practice.out");

int N, N2 = 1;
// Welcome to Code Jam
int m[32][512];
char str[512];
char gcj[20];

void print()
{
	for(int i=0; i<strlen(gcj); i++)
	{
		for(int j=0; j<strlen(str); j++)
			fout << m[i][j] << " ";
		fout << endl;
	}
	//system("pause");
}

int main()
{
	strcpy_s(gcj, "welcome to code jam");
	fin >> N;
	fin.getline(str, 501, '\n');
	while( N2<=N )
	{
		memset(m, 0, sizeof(m));
		fin.getline(str, 501, '\n');
		
		//cout << gcj << "_\n" << str << "_\n";

		for(int i=0; i<strlen(gcj); i++)
		{
			for(int j=0; j<strlen(str); j++)
				if( gcj[i]==str[j] )
				{
					if( i==0 && j==0 )	m[i][j] = 1;
					else if( i==0 )		m[i][j] = (m[i][j-1]+1)%10000;
					else 
					{
						//if( m[i-1][j-1] )
						//{
							m[i][j] = m[i][j-1];
							if( j )
								m[i][j] = (m[i][j-1] + m[i-1][j-1])%10000;
						//}
					}
				}
				else if(j)
				{
					m[i][j] = m[i][j-1];
				}
		}
		//if( N2==3 ) print();
		int res = m[18][strlen(str)-1];
		/*for(int i=0; i<strlen(gcj); i++)
			res = (res*m[i][strlen(str)-1])%10000;*/
			
		fout << "Case #" << N2 << ": ";
		if( res<10 ) fout << "000" << res;
		else if( res<100 ) fout << "00" << res;
		else if( res<1000 ) fout << "0" << res;
		else fout << res;
		if( N2!=N) fout << "\n";
		N2++;
	}

	return 0;
}
