#include <cstdio>
#include <string>
#include <stdio.h>
using namespace std;

bool done;

double doit() {
  char ch;
  do {ch = getchar();} while (isspace(ch));
  if (ch == ')') exit(0);
  if (ch == '(') {
    double p;
    scanf("%lf", &p);
    return doit() + (p-(1-p)) * doit();
  } else {
    string s;
    while (!isspace(ch)) {s += ch; ch = getchar();}
    return atoi(s.c_str());
  }
}

main() {
  freopen("b.in","r",stdin);
  for(;;) {printf("%.2lf\n", doit()); fflush(stdout);}
}
