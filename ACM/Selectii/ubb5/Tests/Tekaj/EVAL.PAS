{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
var
    fok,fout,fin:text;
    ok_file,out_file,in_file,fe:string;
    s1,s2:longint;
    q,a,b,c,d,val1,val2,n:longint;
    x,y:integer;
    p:real;
    test:word;
    aa:array[1..100000] of longint;

const puncte:array[1..10] of Integer = (5,5,5,5,5,5,10,20,20,20);

function int2str(n:integer):string;
var s:string;
begin
str(n,s);
int2str:=s;
end;

procedure eroare(s:string;p:real);
var g:text;
 begin
  close(fout);
  close(fin);
  Assign(g,fe); ReWrite(g);
  writeln(g,'<?xml version="1.0"?>');
  writeln(g,'<result outcome="',s,'" security="',fe,'"> string2 </result>');
  close(g);
  halt;
 end;

begin
in_file:=paramstr(1);
ok_file:=paramstr(3);
out_file:=paramstr(2);
fe:=paramstr(4);

assign(fin,in_file);
reset(fin);
read(fin,test);

assign(fout,out_file);
reset(fout);
if ioresult<>0 then eroare('No output file!',0);

while test>0 do
begin
     dec(test);
     read(fin,n);
     for q:=1 to n do read(fin,aa[q]);

     read(fout,a,b,c,d);
     if ioresult<>0 then eroare('Invalid numeric format!',0);
     if (a<>1) or (c<>1) then eroare('Non-optimal solution!',0);
     if (b<1) or (b>n) or
        (d<1) or (d>n) then eroare('Invalid interval!',0);


     val1:=aa[b];
     val2:=aa[d];

     if val2=0
     then eroare('Division by zero!',0);

     if (val1 mod val2)<>0
     then eroare('Numbers are not divisible!',0);
end;
if (not seekeof(fout)) then eroare('Invalid output file!',0);
eroare('Accepted',puncte[x]);
end.