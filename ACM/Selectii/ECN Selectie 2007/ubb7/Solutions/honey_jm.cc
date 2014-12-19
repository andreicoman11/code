#include <iostream>

using namespace std;

int main()
{
	int dx[]={1,1,0,-1,-1,0};
	int dy[]={1,0,-1,-1,0,1};
	int ways[29][29][15];
		
	for(int t=0;t<=14;t++)
		for(int y=0;y<29;y++)
			for(int x=0;x<29;x++)				
				if (!t)
					ways[y][x][t]=x==14&&y==14?1:0;
				else {
					int sum=0;
					for(int d=0;d<6;d++) {
						int nx=x+dx[d],ny=y+dy[d];
						if (nx>=0 && ny>=0 && nx<29 && ny<29)
							sum+=ways[ny][nx][t-1];
					}
					ways[y][x][t]=sum;
				}			
	
	int n,N;
	cin >> N;
	while (N--) {
		cin >> n;
		cout << ways[14][14][n] << endl;
	}
		
	return 0;
}
