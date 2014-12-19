/*
ID: andreic4
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n,target;
int sums[800]={0};
int nums[800]={0};

void rec1(int,int);
void rec2(int,int);

int main()
{
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    
    fin >> n;
    if( (n*(n+1))%4 ) fout << "0\n";
    else
    {
        target = n*(n+1)/4;
        rec1( 1, 0);
        rec2( (n/2)+1, 0);    
    
        unsigned long int total=0;
        for(int i=0; i<=target; i++)
            total += sums[i]*nums[target-i];
        
        fout << total/2 << "\n";
    }
    /*
    for(int i=1; i<=target; i++)
        cout << sums[i] << " " << nums[i] << "\n";*/
    //system("pause");
    return 0;
}

void rec1(int i, int s)
{
    //cout << s << "\n";
    if( i>n/2 ) sums[s]++;
    else
    {
        rec1(i+1,s);
        if( s+i<=target ) rec1(i+1,s+i);
    }
}

void rec2(int i, int s)
{
    if( i>n ) nums[s]++;
    else
    {
        rec2(i+1,s);
        if( s+i<=target ) rec2(i+1,s+i);
    }
}
