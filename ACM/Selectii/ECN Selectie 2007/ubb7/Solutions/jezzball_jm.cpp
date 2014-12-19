#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double MAX_TIME = 10000;
const double EXTEND_SPEED = 200;
const int XSIZE = 1024;
const int YSIZE = 768;

double calc(int rx, int ry, vector<int> &ax, vector<int> &ay,
	vector<int> &avx, vector<int> &avy, int xsize, int ysize)
{
	vector<pair<double,bool> > ival;
	
	double et=(ry>?(ysize-ry))/EXTEND_SPEED;
	int n=ax.size();
	for(int i=0;i<n;i++) {
		double ray=rx,atom=ax[i],d[2];
		if (avx[i]<0) { ray=xsize-ray; atom=xsize-atom; }
		if (atom<=ray) {
			d[0]=ray-atom;
			d[1]=d[0]+2*(xsize-ray);
		} else {
			d[0]=2*xsize-atom-ray;
			d[1]=d[0]+ray*2;
		}
		bool stop=false;
		while (!stop)
			for(int k=0;k<2;k++) {
		 		double t=d[k]/abs(avx[i]);
		 		if (t>MAX_TIME) stop=true;
		 		double y=fmod(ay[i]+avy[i]*t,2*ysize);
		 		if (y<0) y+=2*ysize;
		 		if (y>=ysize) y=2*ysize-y;
		 		double ct=fabs(y-ry)/EXTEND_SPEED;
		 		if (et>=ct+1e-9 && t>=ct-1e-9) {
		 			ival.push_back(make_pair(t-et,true));
		 			ival.push_back(make_pair(t-ct,false));
		 		}
				d[k]+=xsize*2;
			}
	}
	sort(ival.begin(), ival.end());
	if (ival.size()==0 || ival[0].first>=-1e-9) return 0;
	int cnt=0;
	for(int i=0;i<ival.size();) {
		double x=ival[i].first;		
		while (i<ival.size() && ival[i].first-x<1e-9)
			cnt+=ival[i++].second?1:-1;
		if (cnt==0)
			return ival[i-1].first;
	}	
	return MAX_TIME;
}

bool solve()
{
	int n,rx,ry;
	cin >> n;
	if (n==0)
		return false;
	cin >> rx >> ry;
	vector<int> ax(n), ay(n), avx(n), avy(n);
	for(int i=0;i<n;i++) cin >> ax[i] >> ay[i] >> avx[i] >> avy[i];
	
	double t1=calc(rx,ry,ax,ay,avx,avy,XSIZE,YSIZE);
	double t2=calc(ry,rx,ay,ax,avy,avx,YSIZE,XSIZE);
	double t=t1<?t2;
	if (t>MAX_TIME)
		printf("Never\n");
	else
		printf("%0.5lf\n",t);	
	return true;
}

int main()
{
	while (solve());
	return 0;
}
