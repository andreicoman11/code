#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE ".in" 
#define OUTFILE ".out"
#define BMAX 16

struct block{
  bool or;
  int x1, y1, x2, y2;
};

bool completed;
int W, H, bno, curbs, m[1024][2] = {0};
block bs[BMAX], oldbs[1024][BMAX];

bool overlap(block a, block b)
{
  if( a.or==b.or )
  {
    if( a.or==1 )
      return (a.y1 == b.y1 && 
              ((a.x1<=b.x1 && b.x1<a.x2) ||
             (b.x1<=a.x1 && a.x1<b.x2)) );
    else
      return (a.x1 == b.x1 && 
              ((a.y1<=b.y1 && b.y1<a.y2) ||
             (b.y1<=a.y1 && a.y1<b.y2)) );
  }
  else
  {
    if( b.or==1 )
    {
      block c = b;
      b = a;
      a = c;
    }
    return (a.x1 <= b.x1) && (a.x2>=b.x2) && 
            (b.y1 <= a.y1) && (b.y2>=a.y2);
  }
}

void read_block()
{
  int i;
  cin >> i;
  char or;
  cin >> or;
  bs[i].or = (or=='h' ? 1 : 0);
  cin >> bs[i].x1 >> bs[i].y1;
  int len;
  cin >> len;
  if( or=='h' ) bs[i].y2 = bs[i].y1+1, bs[i].x2 = bs[i].x1+len;
  else bs[i].y2 = bs[i].y1+len, bs[i].x2 = bs[i].x1+1;
}

bool intoWall(int id)
{
  if( bs[id].x2>H || bs[id].y2>W ||
      bs[id].x1<1 || bs[id].y1<1 ) return 1;
  return 0;
}

void moveBlock(int id, int steps)
{
  if( bs[id].or )  bs[id].x1 += steps, bs[id].x2 += steps;
  else            bs[id].y1 += steps, bs[id].y2 += steps;
}

int blockCrash(int id)
{
  int crash = 0;
  if( intoWall(id) ) crash = 1;
  
  if( !crash )
    for(int i=0; i<bno; i++)
      if( i!=id && overlap(bs[id], bs[i]) )
          crash = 1;
  return crash;
}


bool verif()
{
  int steps = 0;
  while( intoWall(0)==0 )
  {
    moveBlock(0, 1);
    steps++;
    if( blockCrash(0) )
    {
      moveBlock(0, (-1)*steps);
      return 0;
    }
  }
  return 1;
}

bool seen()
{
  for(int i=0; i<curbs; i++)
  {
    bool eq = 1;
    for(int j=0; j<bno; j++)
      if( bs[j].x1!=oldbs[i][j].x1 ||
        bs[j].y1!=oldbs[i][j].y1 ||
        bs[j].x2!=oldbs[i][j].x2 ||
        bs[j].y2!=oldbs[i][j].y2)
          eq = 0;
  }
  return 0;        
}

void mem()
{
  memcpy(oldbs[curbs], bs, sizeof(bs));
  curbs++;
}

void back(int i)
{
  if( completed ) return;
  mem();
  if( verif() )
  {
    completed = 1;
    cout << verif() << "\t";
    for(int k=0; k<i; k++)
      cout << m[k][0] << " " << m[k][1] << " ";
  }
  else
  {
    for(int j=0; j<bno && !completed; j++)
    {
      moveBlock(j, 1);
      m[i][0] = j;
      m[i][1] = 1;
      
      if( !blockCrash(j) && !seen() )  back(i+1);

      moveBlock(j, -2);
      m[i][1] = -1;
      if( !blockCrash(j) && !seen() )  back(i+1);

      moveBlock(j, 1);
    }
  }
}

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  for(int runs = 0; runs<1; runs++)
  {
    memset(bs, 0, sizeof(bs));
    curbs = 0;
    cin >> H >> W >> bno;
    W++; H++;
    for(int i=0; i<bno; i++)
    {
      read_block();
    }

    completed = 0;
    back(0);
    cout << completed << "\n";
  }


	
	return 0;
}
