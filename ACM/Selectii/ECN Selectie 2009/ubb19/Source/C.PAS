var s:string;
begin
     assign(input,'c.dat');
     reset(input);
     while not seekeof do
     begin
          readln(s);
          writeln(s);
     end;
     close(input);
end.