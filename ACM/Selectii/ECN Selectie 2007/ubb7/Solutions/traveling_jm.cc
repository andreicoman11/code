#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Edge {
	int x1,y1,z1,x2,y2,z2;
	
	Edge(int a1, int b1, int c1, int a2, int b2, int c2) {
		if ((a1<a2) || (a1==a2 && b1<b2) || (a1==a2 && b1==b2 && c1<=c2)) {
			x1=a1; y1=b1; z1=c1;
			x2=a2; y2=b2; z2=c2;
		} else {
			x1=a2; y1=b2; z1=c2;
			x2=a1; y2=b1; z2=c1;
		}
	}
		
	bool operator<(const Edge &e) const {
		if (x1!=e.x1) return x1<e.x1;
		if (y1!=e.y1) return y1<e.y1;
		if (z1!=e.z1) return z1<e.z1;
		if (x2!=e.x2) return x2<e.x2;
		if (y2!=e.y2) return y2<e.y2;
		if (z2!=e.z2) return z2<e.z2;
		return false;
	}
};

int main()
{
	int n,m,q,x,y,x1,y1,z1,x2,y2,z2,x3,y3,z3;
	cin >> n;
	while (n) {
		vector<vector<int> > nodes(n);
		map<Edge,int> edges;		
		for(int i=0;i<n;i++) {			
			cin >> m >> x1 >> y1 >> z1;
			x3=x1; y3=y1; z3=z1;			
			for(int k=0;k<m;k++) {
				if (k<m-1) {
					cin >> x2 >> y2 >> z2;
				} else {
					x2=x3; y2=y3; z2=z3;
				}					
				Edge e(x1,y1,z1,x2,y2,z2);			
				if (edges.find(e)!=edges.end()) {
					int j=edges[e];
					nodes[i].push_back(j);
					nodes[j].push_back(i);
				}
				else
					edges[e]=i;
				x1=x2; y1=y2; z1=z2;
			}
		}
		/*
		for(int i=0;i<n;i++) {
			cout << i << ": ";
			for(int j=0;j<nodes[i].size();j++)
				cout << nodes[i][j] << " ";
			cout << endl;
		}
		*/
		cin >> q;
		while (q--) {
			cin >> x >> y;
			x--; y--;
			vector<int> vis(n,-1);
			queue<int> cur;
			vis[x]=0;
			cur.push(x);			
			while (vis[y]==-1) {
				x=cur.front();
				cur.pop();
				for(int i=0;i<nodes[x].size();i++) {
					int z=nodes[x][i];
					if (vis[z]==-1) {
						vis[z]=vis[x]+1;
						cur.push(z);
					}
				}
			}
			cout << vis[y] << endl;
					
		}
		cin >> n;
	}
	return 0;
}
