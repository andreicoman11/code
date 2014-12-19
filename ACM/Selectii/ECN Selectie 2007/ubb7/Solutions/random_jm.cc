#include <iostream>
#include <vector>

using namespace std;

double prob[101][1024];

int main()
{
	int k,n,e,x,y;
	cin >> k >> n >> e;
	while (k) {
		vector<vector<int> > nodes(1<<n);
		for(int i=0;i<e;i++) {
			cin >> x >> y;
			nodes[x].push_back(y);
			nodes[y].push_back(x);
		}
		memset(prob,0,sizeof(prob));
		bool good=true;
		for(int j=0;j<(1<<n);j++)
			prob[1][j]=1.0/(1<<n);

		for(int i=2;i<=k && good;i++) {
			for(int j=0;j<(1<<n);j++) {
				for(int t=0;t<nodes[j].size();t++) {
					x=nodes[j][t];
					prob[i][j]+=prob[i-1][x]/nodes[x].size();
				}
			}
			for(int m=0;m<n;m++) {
				double s=0;
				for(int j=0;j<(1<<n);j++)
					if ((1<<m)&j)
						s+=prob[i][j];
				if (s<=0.25 || s>=0.75)
					good=false;
			}
		}

		if (good)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		cin >> k >> n >> e;
	}
	return 0;
}
