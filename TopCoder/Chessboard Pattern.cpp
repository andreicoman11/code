#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class ChessboardPattern{
  public:
  vector <string> makeChessboard(int rows, int columns)
  {
    vector <string> a(rows);
    if(columns!=1)
    for(int i=0;i<rows;i++)
      {  
        int j=0;
        if( (rows-i)%2==0 ) while(j<columns-1) { a[i] += "X.";j+=2; }
        else while(j<columns-1) { a[i] += ".X";j+=2; }
        if(columns%2==1) if( (rows-i)%2==0 ) a[i]+= "X";
              else a[i] += ".";
      }
    else 
    for(int i=0;i<rows;i++)
      {  
        if( (rows-i)%2==0 ) a[i]+= "X";
        else a[i] += ".";
      }
    return a;
  }
};
