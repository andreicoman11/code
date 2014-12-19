/*
ID: andreic4
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    int N;
    fin >> N;
    
    int t[5000][2];
    
    for(int i=0; i<N; i++)
        fin >> t[i][0] >> t[i][1];
        
    int da=1;
    while( da )
    {
        da=0;
        for(int i=0; i<N-1; i++)
            if( t[i][0]>t[i+1][0] )
            {
                int aux = t[i][0];
                t[i][0] = t[i+1][0];
                t[i+1][0] = aux;
                aux = t[i][1];
                t[i][1] = t[i+1][1];
                t[i+1][1] = aux;
                da=1;
            }        
    }
    
    int max=0,min=0;
    int begin = t[0][0];
    int end = t[0][1];
    
    for(int i=0; i<N; i++)
    {
        if( t[i][0]<=end )
        {
            if( t[i][1]>end ) { end=t[i][1]; }
        }
        else
        {
            //cout<< "min " << min << " " << t[i][0] << " - " << end << "\n";
            if( t[i][0]-end > min ) { min = t[i][0]-end; }
            begin = t[i][0];
            end = t[i][1];        
        }
        //cout << "max " << max << " " << end << " - " << begin << "\n";
        if( end-begin > max ) { max=end-begin; }
    }
    
    
    fout << max << " " << min << "\n";
    //system("pause");
    return 0;
}
