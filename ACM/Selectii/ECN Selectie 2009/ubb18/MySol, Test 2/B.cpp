#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

ifstream fin("B.dat");

char map[1000][1000];
int t[1000][1000];
int dx[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
int dy[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
int n,m;
vector<int> qx, qy, rx, ry;

void color(int,int,int);

int main()
{
	while(fin >> n >> m)
	{
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			fin >> map[i][j];

		int cases;
		fin >> cases;
		while( cases-- )
		{
			qx.clear();
			qy.clear();
			int a, b, x, y;
			fin >> a >> b >> x >> y;
			a--;
			b--;
			x--;
			y--;
			memset(t, -1, sizeof(t));
			t[a][b] = 0;
			int col = 0;			
			qx.push_back(a);
			qy.push_back(b);
			while( t[x][y]<0 )
			{
				for(int k=0; t[x][y]<0 && k<qx.size(); k++)
				{
					color(col, qx[k], qy[k]);
				}

				col++;

				for(int k=0; t[x][y]<0 && k<qx.size(); k++)
				{
					for(int p=0; p<8; p++)
					{
						int xx = qx[k] + dx[p];
						int yy = qy[k] + dy[p];
						rx.clear();
						ry.clear();
						if( xx>=0 && yy>=0 && xx<n && yy<m && t[xx][yy]<0 )
						{
							rx.push_back(xx);
							ry.push_back(yy);
							t[xx][yy] = col;
						}
					}
				}

				qx = rx;
				qy = ry;

				/*for(int i=0; i<n; i++)
				{
					for(int j=0; j<m; j++)
						cout << t[i][j];
					cout << endl;
				}
				system("pause");*/
			}
			cout << t[x][y] << endl;
		}
	}
	return 0;
}

void color(int cul, int a, int b)
{
	int c = (int)map[a][b] - int('0');
	int i = a + dx[ c ];
	int j = b + dy[ c ];
	//cout << a << " " << b << " " << map[a][b] << " " << i << " " << j << endl;
	while( i>=0 && j>=0 && i<n && j<m && t[i][j]<0 )
	{
		//cout << i << " " << j << endl;
		a = i;
		b = j;
		t[i][j] = cul;
		c = (int)map[a][b] - int('0');
		i = a + dx[ c ];
		j = b + dy[ c ];
		qx.push_back(a);
		qy.push_back(b);
	}
}