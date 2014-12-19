#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

//ifstream fin ("B-small-practice.in");
//ofstream fout ("B-small-practice.out");
ifstream fin ("B-large-practice.in");
ofstream fout ("B-large-practice.out");

int N, N2 = 1;
bool map[20001][10001][4];
int minx, miny, maxx, maxy, x, y;

void print()
{
	cout << minx << " " << maxx << endl;
	cout << miny << " " << maxy << endl;
	for(int k=0;k<4; k++)
	{
		for(int i=maxx; i>=minx; i--)
		{
			for(int j=miny; j<=maxy; j++)
				cout << map[i][j][k] << " ";
			cout << endl;
		}
		cout<<endl;
	}
	system("pause");
}
int main()
{
	fin >> N;
	while(N2<=N)
	{
		minx = miny = maxx = maxy = 10000;
		x = y = 10000;
		memset( map, false, sizeof(map));
		string path;
		fin >> path;
		//cout << path << endl;
		int dir = 2;
		map[x][y][2] = 1;
		//print();
		if( x<minx ) minx = x;
		if( y<miny ) miny = y;
		if( x>maxx ) maxx = x;
		if( y>maxy ) maxy = y;
		for(int i=1; i<path.size()-1; i++)
		{
			//cout << x << " " << y << " " << dir << endl;
			if( path[i]=='L' )	dir = (dir-1+4)%4;
			else if( path[i]=='R' )	dir = (dir+1)%4;
			else if( path[i]=='W' ) 
			{
				if( dir==0 ) x++;
				if( dir==1 ) y++;
				if( dir==2 ) x--;
				if( dir==3 ) y--;
				map[x][y][dir] = 1;
				if( x<minx ) minx = x;
				if( y<miny ) miny = y;
				if( x>maxx ) maxx = x;
				if( y>maxy ) maxy = y;
			}
		}
		//print();
		// opposite path
		dir = (dir+2)%4;
		fin >> path;
		//cout << path << endl;
		map[x][y][dir] = 1;
		for(int i=1; i<path.size()-1; i++)
		{
			if( path[i]=='L' )	dir = (dir-1+4)%4;
			else if( path[i]=='R' )	dir = (dir+1)%4;
			else if( path[i]=='W' ) 
			{
				if( dir==0 ) x++;
				if( dir==1 ) y++;
				if( dir==2 ) x--;
				if( dir==3 ) y--;
				map[x][y][dir] = 1;
				if( x<minx ) minx = x;
				if( y<miny ) miny = y;
				if( x>maxx ) maxx = x;
				if( y>maxy ) maxy = y;
			}
		}
		//print();
		fout << "Case #" << N2 << ":\n";
		for(int i=maxx; i>=minx; i--)
		{
			for(int j=miny; j<=maxy; j++)
			{
				int nr = 0;
				if( map[i][j][3] ) nr+=8;
				if( map[i][j][1] ) nr+=4;
				if( map[i][j][0] ) nr+=2;
				if( map[i][j][2] ) nr+=1;

				//fout << nr << " ";
				if( nr<10 ) fout << nr;
				else fout << char(int('a') + nr - 10);
			}
			fout << endl;
		}
		cout << N2 << endl;
		N2++;
	}
return 0;
}