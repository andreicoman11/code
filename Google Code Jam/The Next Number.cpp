#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

vector<int> getNext(vector<int>);

int main()
{
  ifstream fin("B-large-practice.in");
  ofstream fout(".out");
  int runs;
	fin >> runs;
	for(int r = 1; r<=runs; r++)
	{
     string n;
     fin >> n;
     vector<int> v(n.size());
     for(int i=0; i<n.size(); i++)
       v[i] = int(n[i]) - int('0');
     v = getNext(v);
     fout << "Case #" << r << ": ";
     for(int i=0; i<v.size(); i++)
       fout << v[i];
     fout << "\n";
     	
	}
  return 0;
}

vector<int> getNext(vector<int> v)
{
  int idx = -1;
  for(int i=v.size()-1; i>0; i--)
    if( v[i-1]<v[i] )
    {
      idx = i;
      break;
    }

  if( idx==-1 )
  { // need to add '0'
    v.resize(v.size()+1);
    v[v.size()-1] = 0;
    sort(v.begin(), v.end());
    for(int i=1; i<v.size(); i++)
      if( v[i]>0 )
      {
        v[0] = v[i];
        v[i] = 0;
        break;
      }
  }
  else
  {
    vector<int>::iterator it = v.begin();
    int idx2 = idx;
    while( idx2 )
    {
      idx2--;
      it++;
    }
    sort( it, v.end());
    for(int i=idx; i<v.size(); i++)
      if( v[i]>v[idx-1] )
      {
        int aux = v[i];
        v[i] = v[idx-1];
        v[idx-1] = aux;
        break;
      }
  }
  return v;
}