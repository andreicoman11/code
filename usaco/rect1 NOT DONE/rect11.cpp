/*
ID: andreic4
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("rect1.out");
    ifstream fin ("rect1.in");
    
    unsigned int rect[10000][5];
    int A,B,N,n=1;
    rect[0][0]=1;
    rect[0][1]=0;
    rect[0][2]=0;
    rect[0][3]=A;
    rect[0][4]=B;
    
    fin >> A >> B >> N;
    
    for(int i=0; i<N; i++)
    {
        fin >> rect[n][1] >> rect[n][2] >> rect[n][3] >> rect[n][4] >> rect[n][0];
        int a=rect[n][1], b=rect[n][2], c=rect[n][3], d=rect[n][4], cul=rect[n][0];
        n++;
        for(int j=0; j<i; j++)
        {
            int x=rect[j][1], y=rect[j][2], z=rect[j][3], t=rect[j][4];
            if( a<=x && b<=y && c=>z && d=>t  )
            {
                for(int k=0; k<5; k++)
                    rect[j][k] = rect[n][k];
                   n--;                
            }
            else if 
        }
    }
    
    
    
    
    return 0;
}
