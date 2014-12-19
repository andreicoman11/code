/*
ID: andreic4
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int minim = 500,n=3;
int minx=-5,miny=-5,minz=-5,mint=-5;
int v[3]={0};
int x[3],y[3],z[3],t[3];

void search(int);

int main()
{
    ofstream fout ("ratios.out");
    ifstream fin ("ratios.in");
        
    fin >> t[0] >> t[1] >> t[2];
    fin >> x[0] >> x[1] >> x[2];
    fin >> y[0] >> y[1] >> y[2];
    fin >> z[0] >> z[1] >> z[2];
        
    search(0);
    
    if( mint==-5 ) fout << "NONE\n";
    else fout << minx << " " << miny << " " << minz << " " << mint << "\n";
    //system("pause");
    return 0;
}

void search(int i)
{
    if( i>=n )
    {
        if( v[0]+v[1]+v[2]<minim )
        {
            int a = v[0]*x[0] + v[1]*y[0] + v[2]*z[0];
            int b = v[0]*x[1] + v[1]*y[1] + v[2]*z[1];
            int c = v[0]*x[2] + v[1]*y[2] + v[2]*z[2];
            int c1=0,c2=0,c3=0,r1=0,r2=0,r3=0;
            
            if( a+t[0]==0 ) { c1=-1; }
            else if( t[0]==0 || a==0 ) { r1=1; }
            else { r1 = a%t[0]; c1 = a/t[0]; }
            
            if( b+t[1]==0 ) { c2=-1; }
            else if( t[1]==0 || b==0 ) { r2=1; }
            else { r2 = b%t[1]; c2 = b/t[1]; }
            
            if( c+t[2]==0 ) { c3=-1; }
            else if( t[2]==0 || c==0  ) { r3=1; }
            else { r3 = c%t[2]; c3 = c/t[2]; }
            
            //cout << v[0] << " " << v[1] << " " << v[2] << "\n";
            //cout << a << " " << b << " " << c << "\n";
            //cout << c1 << " " << c2 << " " << c3 << "\n";
            //cout << r1 << " " << r2 << " " << r3 << "\n";
            //system("pause");
            
            if( r1==0 && r2==0 && r3==0 )
            {
                if( c1==c2 && c1==c3 )
                {
                    minx = v[0];
                    miny = v[1];
                    minz = v[2];
                    mint = c1;
                    minim = minx + miny + minz;
                }
                
                if( ( c1==-1 && c2==c3 ) || ( c2==-1 && c1==c3 ) || ( c3==-1 && c1==c2 ) )
                {
                    minx = v[0];
                    miny = v[1];
                    minz = v[2];
                    mint = c1;
                    if( mint==-1 ) mint=c2;
                    if( mint==-1 ) mint=c3;
                    minim = minx + miny + minz;
                }
                
                if( c1+c2==-2 || c1+c3==-2 || c2+c3==-2 )
                {
                    minx = v[0];
                    miny = v[1];
                    minz = v[2];
                    mint = c1;
                    if( mint==-1 ) mint=c2;
                    if( mint==-1 ) mint=c3;
                    minim = minx + miny + minz;
                }
            }
        }
    }
    else
    {
        for(int j=0; j<100; j++)
            {
                v[i] = j;
                search(i+1);
                v[i] = 0;   
            }
    }
}
