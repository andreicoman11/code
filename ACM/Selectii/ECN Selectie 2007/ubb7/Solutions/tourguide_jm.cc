#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Person
{
	double x,y,vx,vy,v;
};

int main()
{
	int n;
	cin >> n;
	while (n) {
		double v,a;
		cin >> v;
		vector<int> order(n);
		vector<Person> person(n);
		for(int i=0;i<n;i++) {
			order[i]=i;
			cin >> person[i].x >> person[i].y >> person[i].v >> a;
			person[i].vx=cos(a)*person[i].v;
			person[i].vy=sin(a)*person[i].v;
		}
		
		double best=99999999;
		do {
			double last=0,t=0,cx=0,cy=0;
			for(int i=0;i<n;i++) {
				Person &p=person[order[i]];
				double ex=p.x+t*p.vx-cx,ey=p.y+t*p.vy-cy;
				double a=p.vx*p.vx+p.vy*p.vy-v*v;
				double b=2*ex*p.vx+2*ey*p.vy;
				double c=ex*ex+ey*ey;
				b/=a;
				c/=a;
				double d=-b/2;
				double e=sqrt(b*b/4-c);
				double f=99999999;
				if (d+e>=-1e-9 && d+e<f)
					f=d+e;				
				t+=f;
				cx=p.x+p.vx*t;
				cy=p.y+p.vy*t;
				double home=t+sqrt(cx*cx+cy*cy)/p.v;
				if (home>last)
					last=home;
			}
			if (last<best)
				best=last;
		} while (next_permutation(order.begin(),order.end()));
		cout << round(best) << endl;
		
		cin >> n;
	}
	return 0;
}
