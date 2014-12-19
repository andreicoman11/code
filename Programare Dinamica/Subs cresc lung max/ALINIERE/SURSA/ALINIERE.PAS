{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S-,T-,V+,X+,Y+}
{$M 16384,0,655360}
var optim,x1,x2,rez,caz,i,j,k,l,m,n:longint;             {long int optim, x1, ...; }
    fi,fo:text;
    a:array[1..2048]of longint;                          { long int a[2048]; }
    r:real;                                             { float r; }  
    left,right,t1,t2,sel:array[1..2048]of integer;      { int left[2048], right[2048], t1[2048] }
    tl2:longint absolute $0:$46c;            { nu e nevoie }

procedure readdata;                                    { void readdata() }
begin
  assign(fi,'aliniere.in');             { ifstream fin("aliniere,in"); }
  assign(fo,'aliniere.out');
  reset(fi);   { deschide pt citire }
  readln(fi,n);   { fi >> n; }
  for i:=1 to n do
      begin
      read(fi,r);         { fin >> r;
      a[i]:=round(r*100000);  // a[i] = r*100000;
      end;
  close(fi);                                                { fi.close(); }      
end;

procedure subsir1;    { void subsir()     metode inapoi}
begin
  for i:=1 to n do
      begin
        left[i]:=1;   { lung celui mai lung subsir cresc care se sfarseste la a[i] }
        t1[i]:=0;     { t1 - sirul indicilor din sirul crescator din stanga }
        for j:=1 to i-1 do
            if (a[j]<a[i])and(left[j]+1>left[i]) then
                  begin
                    left[i]:=left[j]+1;
                    t1[i]:=j; { tata lui i este j - urmatorul dupa j este i }
                  end;
      end;
end;

procedure subsir2;
begin
  for i:=n downto 1 do            { for ( i = n; i .= 1; i-- ) }
      begin
        right[i]:=1; { lung celui mai lung subsir descresc care incepe la a[i] }
        t2[i]:=0;     { tata lui i este 0 }
        for j:=i+1 to n do
            if (a[j]<a[i])and(right[j]+1>right[i]) then { (right[j]+1>right[i])--> cel ma lung subsir care incepe pe poz j + 1 > c. m. l. s. care incepe pa poz i }
                  begin
                    right[i]:=right[j]+1;
                    t2[i]:=j;
                  end;
      end;
      
      
end;

procedure check;
begin
  optim:=0;x1:=0;x2:=0;caz:=0; 
  for i:=1 to n do
      for j:=i to n do
          if a[i]=a[j] then
             begin
               rez:=left[i]+right[j]; { lung sub cresc care se termina pe sold i+ ls desccresc care incepe pe sold j }
               if i=j then            { ^ }
                  rez:=rez-1;
               if rez>optim then
                  begin
                    x1:=i;        { retinem pozitiile celor 2 soldati }
                    x2:=j;
                    optim:=rez;   { retine maximul }
                    if i=j then caz:=1;
                  end;
             end;
end;

procedure afis;
begin
  rewrite(fo); { deschide pentru scriere (ofstream fo("
  writeln(fo,n-optim);

  repeat           { selecteaza sodatii din subsirul cresc maxim, din stanga }
   sel[x1]:=1;      { do }
   x1:=t1[x1];
  until x1=0;       { while ( x1 != 0); }

  repeat          {  selecteaza soldatii din subsirul descresc maxim, din dreapta}
   sel[x2]:=1;
   x2:=t2[x2];
  until x2=0;

  for i:=1 to n do
      if sel[i]=0 then  { daca sel[i] = 0 atunci, soldatul i trebuie scos din formatie}
         write(fo,i,' ');  { fo << i << " "; }
  writeln(fo);             { fo << endl; }   
  close(fo);
end;

procedure solve;
begin
  subsir1;    { calculeaza sirul left[] }
  subsir2;    { calc sirul right[] }

  check;
  afis;
end;

begin                                     { int main() }
  writeln(tl2); { nu e obligatoriu }
  readdata;
  solve;
  writeln(tl2);
end.
