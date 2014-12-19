{
ID: andreic4
PROG: packrec
LANG: PASCAL
}
Program packrec;

function min(x, y: integer): integer;
  begin
    if x < y then
      min := x
    else
      min := y
  end;

function max(x, y: integer): integer;
  begin
    if x > y then
      max := x
    else
      max := y
  end;

function max3(x, y, z: integer): integer;
  begin
    max3 := max(max(x, y), z);
  end;

procedure swapinteger(var i1,i2 : integer);
  var h : integer;
  begin
    h  := i1;
    i1 := i2;
    i2 := h;
  end;

type
  rectangle  = array[1..2] of integer;
  rectangles = array[1..4] of rectangle;

procedure readrectangles(var rects: rectangles);
  var
    k : integer;
    t : text;
  begin
    assign(t, 'packrec.in');
    reset(t);
    for k := 1 to 4 do
      read(t, rects[k][1], rects[k][2]);
    close(t);
  end;

procedure swaprectangles(var r1, r2: rectangle);
  var h : rectangle;
  begin
    h  := r1;
    r1 := r2;
    r2 := h;
  end;

var scorelist : record
                  minarea    : integer;
                  numofrects : integer; 
                  rects      : array[1..1920] of rectangle;
                end;

procedure outputscores;
  var t : text;
  var k : integer;
  begin
    assign(t,'packrec.out');
    rewrite(t);
    with scorelist do
    begin
      writeln(t, minarea);
      for k := 1 to numofrects do
        writeln(t, rects[k][1], ' ', rects[k][2]);
    end;
    close(t);
  end;

procedure insert(short, long: integer);
  var k, j: integer;
  begin
    with scorelist do
    begin
      rects[numofrects + 1][1] := maxint;
      k := 1;
      while rects[k][1] < short do 
        k := k + 1;
      if rects[k][1] > short then
      begin
        for j := numofrects downto k do
          rects[j + 1] := rects[j];
        rects[k][1] := short;
        rects[k][2] := long;
        numofrects  := numofrects + 1;
      end;
    end;
  end;
                
procedure process(h, v: integer);
  var area, long, short : integer;
  begin
    long  := max(h,v);    
    short := min(h,v);
    area  := long * short;
    with scorelist do
      if area < minarea then
      begin
        minarea := area;
        numofrects := 1;
        rects[1][1] := short;
        rects[1][2] := long;
      end
      else 
      if area = minarea then
        insert(short, long);    
  end;

procedure layouts(var rect: rectangles);
  var 
    h,  v  : integer;
    x1, y1,
    x2, y2,
    x3, y3,
    x4, y4 : integer;
  begin
    x1 := rect[1][1]; y1 := rect[1][2];
    x2 := rect[2][1]; y2 := rect[2][2];
    x3 := rect[3][1]; y3 := rect[3][2];       
    x4 := rect[4][1]; y4 := rect[4][2];       

    h := x1 + x2 + x3 + x4;
    v := max(max(y1, y2), max(y3, y4));
    process(h,v);

    h := max(x1 + x2 + x3, x4);
    v := max3(y1, y2, y3) + y4;
    process(h,v);    

    h := max (x1 + x2, x4) + x3;
    v := max (max(y1, y2) + y4, y3);
    process(h,v);    

    h := x1 + x4 + max (x3, x2);
    v := max3(y1, y4, y2 + y3);
    process(h,v);

    h := max3(x1 + x2, x2 + x3, x3 + x4);
    v := max3(y1 + y3, y1 + y4, y2 + y4);
    process(h,v);
  end;

procedure orient(k : integer; rect: rectangles);
  begin
    if k = 0 then
      layouts(rect)
    else
    begin
      orient(k-1, rect);
      swapinteger(rect[k][1],rect[k][2]);
      orient(k-1,rect)
    end;
  end;

procedure permute(k: integer; rect: rectangles);
  var i : integer;
  begin
    if k = 0 then
      orient(4, rect)
    else
      for i := k downto 1 do
      begin
        swaprectangles(rect[i], rect[k]);
        permute(k - 1, rect);
      end;
  end;

var rect: rectangles;

begin
  with scorelist do
  begin
    minarea := maxint;
    numofrects := 0
  end;
  
  readrectangles(rect);
  permute(4, rect);
  outputscores
end.