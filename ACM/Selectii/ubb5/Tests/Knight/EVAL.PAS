{$A+,B-,D+,E+,F-,G-,I-,L+,N-,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
var
    fok,fout,fin:text;
    ok_file,out_file,in_file,fe:string;
    s1,s2,q:longint;
    n,m,x0,y0,a,b,olda,oldb:longint;
    x,y:integer;
    was:array[1..500,1..500] of boolean;
    test:word;

const puncte:array[1..10] of Integer = (10,10,10,10,10,10,10,10,10,10);

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
assign(fout,out_file);
reset(fout);
if ioresult<>0 then eroare('No output file!',0);
read(fin,test);
while test>0 do
begin
     dec(test);
     read(fin,n);

     
     read(fout,b);
     if ioresult<>0 then eroare('Invalid numeric format in first line!',0);
     if (b<>0) and (b<>1) then eroare('Invalid interval for first number!',0);
     if (b<>1) then eroare('Wrong solution!',0);

     fillchar(was,sizeof(was),false);
     olda:=0;
     for q:=1 to n*n do
     begin
          read(fout,a,b);
          if ioresult<>0 then eroare('Invalid numeric format!',0);
          if (a<1) or (b<1) or (a>n) or (b>n) then eroare('Invalid coordinates!',0);
          if was[a][b] then eroare('Field already used!',0);
          was[a][b]:=true;
          if (olda=0) or
             (abs(a-olda)=1) and (abs(b-oldb)=2) or
             (abs(a-olda)=2) and (abs(b-oldb)=1)
          then
          else eroare('Wrong move!',0);
          olda:=a;
          oldb:=b;
     end;
     
end;

if (not seekeof(fout)) then eroare('Invalid output file!(too long)',0);
eroare('Accepted',puncte[x]);
end.