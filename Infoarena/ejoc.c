#include <stdio.h>

unsigned long long int a,b,c;

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    if( y==0 ) return x;
    if( x<y ) return gcd(y, x);
    else      return gcd(y, x%y);
}

int main()
{
    FILE* fin = fopen("ejoc.in","r");
    FILE* fout = fopen("ejoc.out","w");
    
    int n;
    fscanf(fin, "%d", &n);
    while( n-- )
    {
        fscanf(fin, "%lld", &a);
        fscanf(fin, "%lld", &b);
        
        c = gcd(a,b);
        a /= c;
        b /= c;
        if( a<b ) a = b;

        if( a%2==0 ) fprintf(fout, "Denisa\n");
        else fprintf(fout, "Dalila\n");
    }

    fclose(fin);
    fclose(fout);
    //system("pause");
    return 0;
}
