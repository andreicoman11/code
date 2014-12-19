#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
using namespace std;

//ifstream fin ("B-small-attempt0.in");
//ofstream fout ("B-small.out");
ifstream fin ("B-large.in");
ofstream fout ("B-large.out");

int N, N2 = 1;
int map[110][110];
int alt[110][110];
int h,w;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int color(int i, int j, int cul)
{
	int min_alt = alt[i][j];
	int ix = -1;
	int jy = -1;
	for(int k=0; k<4; k++)
	{
		int x = i+dx[k];
		int y = j+dy[k];	
		if( x>=0 && x<h && y>=0 && y<w && alt[x][y]<min_alt )
		{
			min_alt = alt[x][y];
			ix = x;
			jy = y;
		}
	}
	
	if( ix==-1 || jy==-1 )
	{
		// sink
		if( map[i][j]==0 )
		{
			map[i][j] = cul;
			return cul;
		}
		else
		{
			return map[i][j];
		}
	}
	else
	{
		map[i][j] = color(ix, jy, cul);
		return map[i][j];
	}
}

void print_map(bool m)
{
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
			if( m ) cout << map[i][j] << " ";
			else    cout << alt[i][j] << " ";
		cout << endl;
	}
	system("pause");
}

void print()
{
	for(int i=0; i<h; i++)
	{
		fout << endl;
		for(int j=0; j<w; j++)
			fout << char(int('a') - 1 + map[i][j]) << " ";
	}
}

int main()
{
	fin >> N;
	while( N2<=N )
	{
		fin >> h >> w;
		for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			fin >> alt[i][j];
		//print_map(0);
		
		memset( map, 0, sizeof(map));
		int cul = 1;
		for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			if( map[i][j]==0 )
			{
				map[i][j] = color(i,j,cul);
				if( map[i][j]==cul ) cul++;
				//print_map(1);
			}

		if( N2>1 ) fout << "\n";
		fout << "Case #" << N2 << ":";
		N2++;
		print();
	}

	return 0;
}
