{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O+,P+,Q-,R-,S-,T-,V+,X+,Y+}
{$M 16384,0,655360}
var
    fok,fout,fin:text;
    ok_file,out_file,in_file,fe:string;
    s1,s2:longint;
    n,m,k,q,a,b,c,d,best,b1,c1,d1:longint;
    dom,money,ppl:array[1..100] of longint;
    sol:array[1..100] of byte;
    x,y:integer;
    p:real;
    test:word;


function int2str(n:integer):string;
var s:string;
begin
str(n,s);
int2str:=s;
end;

procedure eroare(s:string;p:real);
var g:text;
 begin
  close(fin);
  close(fout);
  close(fok);
  writeln(s);
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
assign(fok,ok_file);
reset(fok);
assign(fout,out_file);
reset(fout);
if ioresult<>0 then eroare('No output file!',0);
read(fin,test);
while test>0 do
begin
     dec(test);
     read(fin,n,m,k);
     for q:=1 to n do read(fin,dom[q],money[q],ppl[q]);

     read(fok,a,best);

     
     read(fout,a,b,c,d);
     if ioresult<>0 then eroare('Invalid numeric format in first line!',0);
     if (a<0) or (a>n) then eroare('Invalid interval for first number!',0);
     if (b<best) then eroare('Non-optimal solution!',0);
     if (b>best) then eroare('Better solution than mine??',0);
     if (c<0) or (c>m) then eroare('Invalid interval for third number!',0);
     if (d<0) or (d>k) then eroare('Invalid interval for fourth number!',0);

     b1:=0;
     c1:=0;
     d1:=0;
     for q:=1 to a do
     begin
          read(fout,sol[q]);
          if ioresult<>0 then eroare('Invalid numeric format in second line!',0);
          if (sol[q]<0) or (sol[q]>n) then eroare('Invalid interval on second line!',0);
          inc(b1,dom[sol[q]]);
          inc(c1,money[sol[q]]);
          inc(d1,ppl[sol[q]]);
     end;
     if (b1<>b) then eroare('Domino number does not match!',0);
     if (c1<>c) then eroare('Money count does not match!',0);
     if (d1<>d) then eroare('People count does not match!',0);

     if ioresult<>0 then eroare('Invalid numeric format in second line!',0);

     readln(fok); readln(fok);
     
end;
if (not seekeof(fout)) then eroare('Invalid output file!',0);
eroare('Accepted',0);
end.