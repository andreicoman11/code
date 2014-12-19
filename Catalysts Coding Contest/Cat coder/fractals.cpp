#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

unsigned long long int res, sum, p, it, l;

FILE * in = fopen(".in", "r");
FILE * out = fopen(".out", "w");

int main()
{		
	while(!feof(in))
	{
		fscanf(in, "tri Length=%lld Iterations=%lld\n", &l, &it);
		sum = 3*l;
		//p = 3*l; LVL 1
		p = 4 * l;
		while(it) 
		{
			/*if( it>1 ) p *= 2;
			p /= 3;
			sum += p;
			it--;*/
			//p = p * 4 / 3; LVL1
			p = p * 5 / 3;
			it--;
		}
		
		//res = sum;
		res = p;
		fprintf(out, "%lld\n", res);
	}
	return 0;
}
