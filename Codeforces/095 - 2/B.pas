var
	a: array[-10..10] of int64;
	i, x, n: longint;
	res: int64;

begin
	for i := -10 to 10 do
		a[i] := 0;
	read(n);
	for i := 1 to n do begin
		read(x);
		a[x] := a[x] + 1;
	end;
	res := 0;
	for i := -10 to -1 do
		res := res + a[i] * a[-i];
	res := res + a[0] * (a[0] - 1) div 2;
	writeln(res);
end.