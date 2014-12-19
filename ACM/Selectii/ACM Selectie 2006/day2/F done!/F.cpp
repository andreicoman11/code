#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ofstream fout ("F.out");
    ifstream fin  ("F.dat");
    
    int t=0;
    long long int n;
    while( fin>>n )
    {
        if(t) fout << "\n";
        fout << "TERM " << n << " IS ";
        long long int a = (int)sqrt(n);
        
        while( (a*(a+1))/2  <n ) a++;
        n -= a*(a-1)/2;
        //cout << n; system("pause");
        
        if( a%2==0 )
        {
            for(long long int i=1; i<=a; i++)
            {
                n--;
                if( n==0 ) fout << i << "/" << a+1-i;
            }
        }
        else
        {
            for(long long int i=a; i; i--)
            {
                n--;
                if( n==0 ) fout << i << "/" << a+1-i;
            }
        }
        t=1;
    }





 return 0;
}
