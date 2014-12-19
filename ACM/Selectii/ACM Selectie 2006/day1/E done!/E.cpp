#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ofstream fout ("e.out");
    ifstream fin ("e.dat");
    
    
    int n;
    fin >> n;
    while( !fin.eof() )
    {
        int v[10001] = {0};
        
        for(int i=0; i<n; i++)
        {
            int price, time;
            fin >> price >> time;
            for(int j=time; j>0 && price; j--)
                if( v[j]<price ) 
                {
                    int aux = v[j];
                    v[j] = price;
                    price = aux;
                }
        }
        unsigned long long int sum = 0;
        for(int i=0; i<=10000; i++)
        {
            //cout << v[i] << " ";
            sum += v[i];
        }
        //cout << "\n" << sum << "\n";
        //system("pause");
        
        fout << sum << "\n";
        
        fin >> n;
    }





 return 0;
}
