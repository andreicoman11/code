{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
type str25=string[25];
var in_file,out_file,ok_file,rep_file:string;
        fin,fout:text;
        n,q:word;
        teams:array[1..1000] of str25;
        pairs:array[1..1000,1..2] of word;
        s1,s2:string;
        s:string;
        round,nTeams:word;
        plays:array[1..1000] of boolean;
        code:integer;
        aux:word;
        paratlan:boolean;
        was:array[1..1000] of boolean;
        i1,i2:word;
procedure error(s:string);
var frep:text;
begin
        assign(frep,rep_file);
        rewrite(frep);
        writeln(frep,'<?xml version="1.0"?>');
        writeln(frep,'<result outcome="',s,'" security="',rep_file,'"> ',s,' </result>');
        close(frep);
        halt;
end;
function ind(s:string):word;
var ans:word;
begin
        for ans:=1 to n do
                if teams[ans]=s
                then
                begin
                        ind:=ans;
                        exit;
                end;
        ind:=0;
end;
function indpair(x,y:word):word;
var ans:word;
begin
        for ans:=1 to n-1 do
                if (pairs[ans][1]=x) and (pairs[ans][2]=y) or
                   (pairs[ans][2]=x) and (pairs[ans][1]=y)
                then
                begin
                  indpair:=ans;
                  exit;
                end;
        indpair:=0;
end;
begin
  in_file:=paramstr(1);
  out_file:=paramstr(2);
  ok_file:=paramstr(3);
  rep_file:=paramstr(4);
  assign(fin,in_file);
  assign(fout,out_file);
  reset(fout);
  reset(fin);
  while not seekeof(fin) do
  begin
        readln(fin,n);
        if n=0
        then break;
        for q:=1 to n do readln(fin,teams[q]);
        for q:=1 to n-1 do
        begin
                readln(fin,s);
                s1:=copy(s,1,pos(' ',s)-1);
                s2:=copy(s,pos(' ',s)+1,255);
                pairs[q][1]:=ind(s1);
                pairs[q][2]:=ind(s2);
        end;
        round:=0;
        fillchar(plays,sizeof(plays),true);
        fillchar(was,sizeof(was),false);
        nTeams:=n;
        repeat
              inc(round);
              readln(fout,s);
              if copy(s,1,8)='Winner: '
              then
              begin
                   if (nTeams<>1)
                   then error('Remaining teams <> 1');
                   delete(s,1,8);
                   i1:=ind(s);
                   if i1=0
                   then error('Wrong winner index');
                   if not plays[i1]
                   then error('Wrong winner');
                   break;
              end;
              if copy(s,1,7)<>'Round #'
              then error('Round not found');
              delete(s,1,7);
              val(s,aux,code);
              if code<>0
              then error('Val error');
              if aux<>round
              then error('Round number error');
              if odd(nTeams)
              then paratlan:=true
              else paratlan:=false;
              for q:=1 to nTeams div 2 do
              begin
                   readln(fout,s);
                   s1:=copy(s,1,pos(' ',s)-1);
                   delete(s,1,pos('defeats',s)+7);
                   s2:=s;
                   i1:=ind(s1);
                   i2:=ind(s2);
                   if (i1=0) or (i2=0)
                   then error('Wrong index');
                   if not plays[i1]
                   then error('Winner team not in play');
                   if not plays[i2]
                   then error('Loser team not in play');
                   aux:=indpair(i1,i2);
                   if aux=0
                   then error('Pair index not found');
                   if was[aux]
                   then error('Pair already used');
                   was[aux]:=true;
                   plays[i2]:=false;
                   dec(nTeams);
              end;
              if paratlan
              then
              begin
                      readln(fout,s);
                      s1:=copy(s,1,pos(' ',s)-1);
                      i1:=ind(s1);
                      if (i1=0)
                      then error('Wrong index');
                      s2:=copy(s,pos(' ',s)+1,255);
                      if s2<>'advances with wildcard'
                      then error('Wildcard not found');
              end;
        until false;
        for q:=1 to n-1 do
                if not was[q]
                then error('Some matches left out');
        readln(fout);
  end;
  close(fin);
  close(fout);
  error('Accepted');
end.
