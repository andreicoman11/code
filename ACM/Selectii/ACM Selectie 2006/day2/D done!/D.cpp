#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ofstream fout ("D.out");
    ifstream fin  ("D.dat");
    
    string s1,s2;
    
    while( fin >> s1 >> s2 )
    {
        int m[2][10000];
        for(int i=0; i<10000; i++)
            m[0][i] = m[1][i] = 0;
       
        for(int i=0; i<s1.size(); i++)
        {
        for(int j=0; j<s2.size(); j++)
            if( s1[i]==s2[j] )
            {
                m[(i+1)%2][j+1] = m[i%2][j]+1;
                m[(i+1)%2][j+1] = max( m[(i+1)%2][j+1], m[i%2][j+1] );
                m[(i+1)%2][j+1] = max( m[(i+1)%2][j+1], m[(i+1)%2][j] );
            }
            else m[(i+1)%2][j+1] = max( m[i%2][j+1], m[(i+1)%2][j]);
        
        /*for(int k=0; k<s2.size();k++)
            cout << m[(i+1)%2][k+1]<<" ";
        cout << "\n";*/
        }
        //system("pause");
        fout << m[(s1.size())%2][s2.size()] << "\n";
    }
        





 return 0;
}
