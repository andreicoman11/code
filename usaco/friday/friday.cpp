/*
ID: andreic4
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    
    int v[7] = {0};
    int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
    int year = 1900;
    int day = 1;
    
    int N;
    
    fin >> N;
    
    for( ; N ; N-- )
    {
        for(int j=0; j<12; j++)
        {
            v[ (day+12)%7 ] ++;
            //cout << (day+12)%7 << " ";
            day = (day+months[j])%7;
            
            if( j==1 )
            {
                if( year%400==0 ) day++;
                else if( year%4==0 && year%100 ) day++;
                    day = day%7;
            }
            
            //cout << day << "\n";
        }
     
        year++;
        cout<< "\t" << year << "\n";
    }
    
    fout << v[6] ;
    for(int i=0; i<6; i++)
        fout << " " << v[i];
    fout << "\n";
    
    
    //system("pause");
    return 0;
}
