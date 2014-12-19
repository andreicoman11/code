#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

ifstream fin ("infasuratoare.in");

int N, ip;
double X[120000],Y[120000];
int ind[120000], st[120000];

bool comp(int i, int j)
{
	return (X[i]-X[ip]) * (Y[j]-Y[ip]) < (X[j]-X[ip]) * (Y[i]-Y[ip]);
}

bool ok(int i, int j, int k)
{
	return X[i]*Y[k]+X[j]*Y[i]+X[k]*Y[j] > X[i]*Y[j]+X[j]*Y[k]+X[k]*Y[i];
}

int main()
{
	FILE* fout;
	fout = fopen("infasuratoare.out", "w");
	fin >> N;
	fin >> X[0] >> Y[0];
	ip = 0;
	for(int i=1; i<N; i++)
	{
		fin >> X[i] >> Y[i];
		if( X[i]<X[ip] || (X[i]==X[ip] && Y[i]<Y[ip]) ) ip = i;
	}
	//cout << ip << endl;
	//system("pause");
	for(int i=0; i<N; i++)
		ind[i] = i;
	ind[ip] = ind[N-1];
	sort(ind, ind+N-1, comp);
	/*for(int i=0; i<N-1; i++)
		cout << X[ind[i]] << " " << Y[ind[i]] << endl;
	system("pause");*/
	int sts = 2;
	st[0] = ip;
	st[1] = ind[0];
	for(int i=1; i<N-1; i++)
	{
		int j = i;
		while( sts>=2 && (!ok(st[sts-2],st[sts-1],ind[j])) )	sts--;
		st[sts++] = ind[j];
	}
	fprintf(fout, "%d\n",sts);
	//for(int i=0; i<sts; i++)
	//	cout << X[st[i]] << " " << Y[st[i]] << "\n";
	for(int i=sts-1; i>=0; i--)
		fprintf(fout, "%lf %lf\n",X[st[i]], Y[st[i]]);
fclose(fout);
return 0;
}


