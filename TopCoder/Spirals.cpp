#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class  Spirals
{
  public:
  vector <string> draw(int w, int h, int sx, int sy)       
  {
   swap(sx,sy);
   
   vector<string> a(h, string(w,'.'));
   
   a[sx][sy]='0';

   int k=1;
   
   int p=1;
   
   int i=sx, j=sy;
   
   int t=1;
   
   while( t )
   {
   	
	for( int l=1;l<=k && t>0;l++)
   		{
   			if( j+l >=w ) t=0;
   			else
   			{
   			a[i][j+l]=p+int('0');
   			p++;
   			if(p==10) p=0;
   			}
   		}
   
   	j=j+k;
   	
   	for( int l=1;l<=k && t>0;l++)
   		{
   			if( i+l >=h ) t=0;
   			else
   			{
   			a[i+l][j]=p+int('0');
   			p++;
   			if(p==10) p=0;
   			}
   		}

	i=i+k;
	k++;
      
	for( int l=1;l<=k && t>0;l++)
   		{
   			if( j-l<0 ) t=0;
   			else
   			{
   			a[i][j-l]=p+int('0');
   			p++;
   			if(p==10) p=0;   
   			}
   		}
   	j=j-k;
   	
   	for( int l=1;l<=k && t>0;l++)
   		{
   			if( i-l<0 ) t=0;
   			else
   			{
   			a[i-l][j]=p+int('0');
   			p++;
   			if(p==10) p=0;
   			}
   		}

	i=i-k;
	
   	k++;
   } 	
   return a;
  }
};
