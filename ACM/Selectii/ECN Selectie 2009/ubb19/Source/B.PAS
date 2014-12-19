{$A+,B-,D+,E+,F+,G+,I+,L+,N+,O+,P+,Q+,R+,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
type matr=array[0..100,0..100] of single;
var test:word;
    k,l,q,w:byte;
    team1,team2:^matr;
    ans,pa,pb,pa1,pb1,pa2,pb2:single;
begin
     new(team1);
     new(team2);
     assign(input,'b.dat');
     reset(input);
     read(test);
     while test>0 do
     begin
          dec(test);
          read(pa,pb,k,l);
          pa:=pa*0.01;
          pb:=pb*0.01;

          fillchar(team1^,sizeof(team1^),0);
          fillchar(team2^,sizeof(team2^),0);
          team1^[0][0]:=1;
          team2^[0][0]:=0;
          for q:=0 to l-1 do
              for w:=0 to l-1 do
              begin
                   if q>0
                   then
                   begin
                        team1^[q][w]:=team2^[q-1][w]*(1-pb);
                        team2^[q][w]:=team1^[q-1][w]*pa;
                   end;
                   if w>0
                   then
                   begin
                        team1^[q][w]:=team1^[q][w]+team2^[q][w-1]*pb;
                        team2^[q][w]:=team2^[q][w]+team1^[q][w-1]*(1-pa);
                   end;
              end;
          for q:=0 to l-1 do
          begin
               team1^[l][q]:=team2^[l-1][q]*(1-pb);
               team2^[l][q]:=team1^[l-1][q]*pa;
               team1^[q][l]:=team2^[q][l-1]*pb;
               team2^[q][l]:=team1^[q][l-1]*(1-pa);
          end;
          pa1:=0;
          pb1:=0;
          for q:=0 to l-1 do
          begin
               pa1:=pa1+team1^[l][q]+team2^[l][q];
               pb1:=pb1+team1^[q][l]+team2^[q][l];
          end;

          fillchar(team1^,sizeof(team1^),0);
          fillchar(team2^,sizeof(team2^),0);
          team1^[0][0]:=0;
          team2^[0][0]:=1;
          for q:=0 to l-1 do
              for w:=0 to l-1 do
              begin
                   if q>0
                   then
                   begin
                        team1^[q][w]:=team2^[q-1][w]*(1-pb);
                        team2^[q][w]:=team1^[q-1][w]*pa;
                   end;
                   if w>0
                   then
                   begin
                        team1^[q][w]:=team1^[q][w]+team2^[q][w-1]*pb;
                        team2^[q][w]:=team2^[q][w]+team1^[q][w-1]*(1-pa);
                   end;
              end;
          for q:=0 to l-1 do
          begin
               team1^[l][q]:=team2^[l-1][q]*(1-pb);
               team2^[l][q]:=team1^[l-1][q]*pa;
               team1^[q][l]:=team2^[q][l-1]*pb;
               team2^[q][l]:=team1^[q][l-1]*(1-pa);
          end;
          pa2:=0;
          pb2:=0;
          for q:=0 to l-1 do
          begin
               pa2:=pa2+team1^[l][q]+team2^[l][q];
               pb2:=pb2+team1^[q][l]+team2^[q][l];
          end;

          fillchar(team1^,sizeof(team1^),0);
          fillchar(team2^,sizeof(team2^),0);
          team1^[0][0]:=0.5;
          team2^[0][0]:=0.5;
          for q:=0 to k-1 do
              for w:=0 to k-1 do
              begin
                   if q>0
                   then
                   begin
                        team1^[q][w]:=team2^[q-1][w]*pa2;
                        team2^[q][w]:=team1^[q-1][w]*pa1;
                   end;
                   if w>0
                   then
                   begin
                        team1^[q][w]:=team1^[q][w]+team2^[q][w-1]*pb2;
                        team2^[q][w]:=team2^[q][w]+team1^[q][w-1]*pb1;
                   end;
              end;
          for q:=0 to k-1 do
          begin
               team1^[k][q]:=team2^[k-1][q]*pa2;
               team2^[k][q]:=team1^[k-1][q]*pa1;
               team1^[q][k]:=team2^[q][k-1]*pb2;
               team2^[q][k]:=team1^[q][k-1]*pb1;
          end;
          ans:=0;
          for q:=0 to k-1 do ans:=ans+team1^[k][q]+team2^[k][q];
          writeln(ans*100:1:1);
     end;
     close(input);
end.