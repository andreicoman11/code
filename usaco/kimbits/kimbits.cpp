/*
ID: andreic4
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
unsigned long long int cmb(int,int);

int main()
{
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
    
    unsigned long long int doi[31];
    doi[1]=1;
    
    for(int i=2; i<31; i++)
        doi[i] = 2*doi[i-1];
    
    int N,L;
    unsigned long long int I;
    fin >> N >> L >> I;
    I--;
    
    for(int n=N; n; n--)
    {
        unsigned long long int nr=1;
        //cout << "n si L si I " << n << " " << L << " " << I << "\n";
        
        if( n==2 ) nr = 2;
        else if( n==1 ) nr=1;
        else for(int i=1; i<=min(n-1,L); i++)
                nr += cmb(n-1,i);
        
        if( nr==I )
        {
            fout << "1";
            n--;
            while( n )
            {
                fout << "0";
                n--;
            }
            fout << "\n";
            return 0;       
        }
        if( nr<I )
        {
            fout << "1";
            L--;
            I -= nr;
        }
        else if( nr>I )
        {
            fout << "0";
        }
        
        //cout << nr << " " << I << "\n";
        //system("pause");
    }

    fout << "\n";    
    //system("pause");
    return 0;
}

unsigned long long int cmb(int n, int l)
{
    unsigned long long int nr = 1;
    
    l = min(l,n-l);
    
    for( int i=n-l+1,j=1; i<=n || j<=l; i++,j++)
    {
        nr *= i;
        nr /= j;
        //cout << nr << " ";
    }
    //cout << "\n"; system("pause");
    
    //for(int i=2; i<=l; i++)
    //    nr /= i;
    
    //cout << "cmb " << n << " si " << l << " = " << nr << " "; system("pause");
    return nr;
}
