/*
ID: andreic4
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    
    int n;
    fin >> n;
    
    int v[200];
    for(int i=1; i<n; i++)
        v[i]=n;
    
    fout << "0/1\n";
    
    double last = 0;
    
    while( last < 1 )
    {
        double min = 1;
        int ii=0;
        for( int i=1; i<n; i++)
            if( double(i)+0.00000000000001 < double(v[i]) * min )
            {
                min = double(i)/double(v[i]);
                cout << min << "\n";
                ii = i;
            }
        
        if( min > last && min!=1 ) fout << ii << "/" << v[ii] << "\n";
        
        last = min;
        v[ii]--;
        
        /*
        cout << last << "\t";
        for(int j=1; j<n; j++)
            cout << v[j] << " ";
        cout << "\n";  */
        //system("pause");      
    }
    
    fout << "1/1\n";
    
    //system("pause");
    return 0;
}
