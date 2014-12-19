/*
ID: andreic4
PROG: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    
    string text;
    int a,b,n;
    int map[13][10000];
    fin >> a >> b >> n;
    
    while( !fin.eof() )
    {
        char temp[100];
        fin.getline( temp, 100, '\n' );
        text += temp;    
    }
    //cout << text << "\n"; system("pause");
    
    for(int i=a; i<=b; i++)
    for(int j=0; j<pow(2,double(i)); j++)
        map[i][j]=0;
    
    for( int i=0; i<=text.size()-a; i++)
    {
        int j=0, temp=0;   
        while( j<a )
        {
            temp = 2*temp + text[i+j] - int('0');
            j++;   
        }
        while( j<=b && i+j<=text.size() )
        {
            map[j][temp]++;
            //cout << j << " " << i << " " << temp << "\n"; system("pause");
            temp = 2*temp + text[i+j] - int('0');
            j++;
        }
    }
    
    /*for(int i=a; i<=b; i++)
    {
        for(int j=0; j<pow(2,double(i)); j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }
    system("pause");*/
        
    bool vals[200000] = {0};
    int max=0;
    
    for(int i=a; i<=b; i++)
    for(int j=0; j<pow(2,double(i)); j++)
    {
        vals[ map[i][j] ]=1;
        if( map[i][j]>max ) max = map[i][j];
    }
    
    /*for(int i=0; i<=23; i++)
        cout << vals[i] << " ";
    system("pause");*/
    
    int val=max;
    while ( n && val>0 )
    {
        fout << val << "\n";
        int afis=0;
        int t=1;
        for(int i=a; i<=b; i++)
        {
            t=0;
            for(int j=0; j<pow(2,double(i)); j++)
                if( map[i][j]==val )
                {
                   t=1;
                   afis++;
                   if( afis==7 ) { afis=1; fout << "\n"; }
                   int v[13]={0};
                   int k=i;
                   int nr=j;
                   while(k)
                   {
                        v[k] = nr%2;
                        nr = nr/2;
                        k--;
                   }
                   if( afis>1 ) fout << " ";
                   k++;
                   while( k<=i ) { fout << v[k]; k++; }
                   
                }            
        }
        val--;
        while( vals[val]==0 ) val--;
        n--; 
        fout << "\n";   
    }        
    
    
    //system("pause");
    return 0;
}
