/*
ID: andreic4
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");
    
    int maxstamps, nrstamps;
    int stamps[51];
    
    fin >> maxstamps >> nrstamps;
    
    for(int i=0; i<nrstamps; i++)
        fin >> stamps[i];
    
    short int vals[1000000]={0};
    
    unsigned long long int i=0;
    unsigned long long int verif = i;
    while( vals[ verif ]<=maxstamps )
    {
        i++;
        int min = maxstamps + 10;
        
        for(int j=0; j<nrstamps; j++)
            if( stamps[j]<=i )
            {
                unsigned long long int k = i-stamps[j];
                if( k>999999 ) k -= 999999;       
                if( min > vals[ k ]+1 )
                    min = 1 + vals[ k ];
            }
        if( i>999999 )  { vals[ i-999999 ] = min; verif = i-999999; }
        else { vals[ i ] = min; verif = i; }
        //if( i<=999999 ) ;//cout << i << " " << (int)vals[i] << "\n";
        //else cout << i << " " << (int)vals[ i-999999 ] << "\n";
        //if( i>999900 ) system("pause");
    }
    
    fout << i-1 << "\n";
    //system("pause");
    return 0;
}
