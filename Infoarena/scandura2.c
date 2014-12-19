#include <stdio.h>
#include <stdlib.h>

unsigned long long int list[1000000];

unsigned long long int sumt = 0, sumv = 0, lastv = 0;

int first = 0, last = 0;

void push_back(long long val)
{
    if( last==0 )
    {
        last = 1;
        list[first] = val;
    }
    else
    {
        list[last++] = val;
    }
}

void pop()
{
    first++;
}

int main()
{
    FILE* fin = fopen("scandura.in", "r");
    int n, m;
    fscanf(fin, "%d %d", &n, &m);
    int i = 0;
    int pos = 0;

    int r = (n-1)%(m-1);
    if( r )
    {
		pos = m - 1 - r;
	}

    fscanf(fin, "%lld", &lastv);
    i = 1;

    do
    {
        while( lastv!=0 && (first==last || lastv<list[first]) )
        {
            sumv += lastv;
            pos++;
            if( i<n ) fscanf(fin, "%lld", &lastv);
            else lastv = 0;
            i++;
            if( pos==m )
            {
                //printf("new node %lld\n", sumv);
                push_back(sumv);
                sumt += sumv;
                sumv = pos = 0;
            }
        }

        while( first!=last && list[first] <= lastv )
        {
            sumv += list[first];
            pop();
            pos++;
            if( pos==m )
            {
                //printf("new node %lld\n", sumv);
                push_back(sumv);
                sumt += sumv;
                sumv = pos = 0;
            }
        }

    }while( lastv!=0 );
    //printf("first %d, last %d, sumv %lld\n", first, last, sumv);
    while( first<last-1 || sumv>0 )
    {
        while( pos<m )
        {
            sumv += list[first];
            pop();
            pos++;
        }
        push_back(sumv);
        sumt += sumv;
        sumv = pos = 0;
    }

    //printf("last node %lld\n", first->val);
    fclose(fin);
    FILE* fout;
    fout = fopen("scandura.out","w");
    fprintf(fout, "%lld\n", sumt);
    fclose(fout);
    //system("pause");
    return 0;
}
