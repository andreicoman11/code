/*
ID: andreic4
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct offer{
    int nr;
    int price;
    int code[5];
    int nrprod[5];
};

offer of[100];
int cod[5] = {0};
int req[5] = {0};
int pre[5] = {0};
int nrof=0, nreq=0;
int vec[5]={0};
int prices[55556];

bool verif(int,int,int,int,int,int);
int val(int);

int main()
{
    ofstream fout ("shopping.out");
    ifstream fin ("shopping.in");
    
    fin >> nrof;
    
    for(int i=0; i<nrof; i++)
    {
        fin >> of[i].nr;
        for(int j=0; j<of[i].nr; j++)
            fin >> of[i].code[j] >> of[i].nrprod[j];
        fin >> of[i].price;
    }
    
    fin >> nreq;
    
    for(int i=0; i<nreq; i++)
        fin >> cod[i] >> req[i] >> pre[i];
  
    prices[0]=0;
    for(int i=1; i<55556; i++)
        prices[i] = 25000;
    
    
    for(int a=0; a<=5; a++)
    for(int b=0; b<=5; b++)
    for(int c=0; c<=5; c++)
    for(int d=0; d<=5; d++)
    for(int e=0; e<=5; e++)
    {
        //cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
        int temp = ((((a*10)+b)*10+c)*10+d)*10+e;
        //cout << temp << "\n";
                    
        for(int i=0; i<nreq; i++)
        {           
            int aux = temp - pow(10,double(4-i) );
            if( aux>=0 ) prices[temp] = min( prices[temp], prices[aux]+pre[i] );
            //if( a==1 ) cout << temp << " " << aux << " " << prices[aux] << " " << prices[temp] << "\n";
            //if( a==1 ) system("pause");
        }
        
        //cout << temp << " " << prices[temp] << "\n"; //system("pause");
            
        for(int i=0; i<nrof; i++)
            if( verif(i,a,b,c,d,e) )
            {
                int aux = val(i);
                //cout << i << " " << temp << " " << aux << "\n";                
                prices[temp] = min( prices[temp], of[i].price+prices[temp-aux] );
                //cout << prices[temp] << "\n";
                //system("pause");
            }            
    }
    
    /*for(int i=0; i<=5; i++)
    for(int j=0; j<=5; j++)
    {
        int aux = (i*10 + j)*1000;
        cout << i << " " << j << " " << prices[aux] << "\n";
    }*/
  
    int requi = (((req[0]*10+req[1])*10+req[2])*10+req[3])*10+req[4];
    fout << prices[requi] << "\n";
    
    //system("pause");
    return 0;
}

bool verif(int i, int a, int b, int c, int d, int e)
{
    int t=1;
    int aux[5] = {a,b,c,d,e};
    for(int j=0; j<5; j++)
    for(int k=0; k<of[i].nr; k++)
        if( cod[j]==of[i].code[k] )
            if( aux[j]<of[i].nrprod[k] ) t=0;
        
    return t;
}

int val(int i)
{
    int s=0;
    for(int k=0; k<5; k++)
    {
        int t=0;
        for(int j=0; j<of[i].nr; j++)
            if( cod[k]==of[i].code[j] ) { s = s*10 + of[i].nrprod[j]; t=1; }
        if( t==0 ) s*=10;
    }
    return s;
}
