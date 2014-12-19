{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
var x,y,optim,nrelim,x1,x2,nrtest,rez,caz,i,j,k,l,m,n:longint;
    fi,fo,fc,fe:text;
    ce:integer;
    a,sir:array[0..3001]of real;
    sel:array[0..3001]of integer;

procedure eroare(s:string;p:integer);
var g:text;
begin
  Assign(g,paramstr(4)); ReWrite(g);
  writeln(g,'PCT=',p,' ',s);
  close(g);
  halt;
end;

procedure readdata;
begin
  assign(fi,paramstr(1));
  assign(fo,paramstr(2));
  assign(fc,paramstr(3));
  assign(fe,paramstr(4));
  val(paramstr(5),nrtest,ce);

  reset(fi);
  readln(fi,n);
  for i:=1 to n do
      read(fi,a[i]);
  close(fi);
  reset(fc);
  readln(fc,optim);
  close(fc);
end;


procedure solve;
begin
  {$i-}
  reset(fo);
  {$i+}
  if ioresult<>0 then
     eroare('Fisier inexistent',0);

  {$i-}
  readln(fo,nrelim);
  {$i+}
  if ioresult<>0 then
     eroare('Caractere ilegale in fisier',0);

  for i:=1 to nrelim do
      begin
        {$i-}
        read(fo,j);
        sel[j]:=1;
        {$i+}
        if ioresult<>0 then
           eroare('Caractere ilegale in fisier',0);
      end;
  close(fo);


  if optim<>nrelim then
     eroare('Solutie neoptima',0);

  m:=0;
  for i:=1 to n do
      if sel[i]=0 then
         begin
           inc(m);
           sir[m]:=a[i];
         end;
  n:=m;

  x:=0;
  y:=n;
  sir[n+1]:=0;
  sir[0]:=10000;

  for i:=1 to n do
      begin
        if sir[i+1]<=sir[i] then
           x:=i;
      end;

  for i:=n downto 1 do
      begin
        if sir[i-1]<=sir[i] then
           y:=i;
      end;
  if y-x>2 then
     eroare('Soldatii ramasi nu respecta conditia din enunt',0);
  eroare('Corect',10);
end;

begin
  readdata;
  solve;
end.