var
	s1, s2: string;
	a: array[0..100000, 'a'..'z'] of longint;
	b: array[0..100000] of longint;
	c: array['a'..'z'] of longint;
	res, i, need: longint;
	flag: boolean;
	ci: char;

begin
	readln(s1);
	readln(s2);
	for ci := 'a' to 'z' do
		a[0][ci] := 0;
	b[0] := 0;
	for i := 1 to length(s1) do begin
		for ci := 'a' to 'z' do
			a[i][ci] := a[i - 1][ci];
		b[i] := b[i - 1];
		if s1[i] = '?' then
			inc(b[i])
		else
			inc(a[i][s1[i]]);
	end;
	for ci := 'a' to 'z' do
		c[ci] := 0;
	for i := 1 to length(s2) do
		inc(c[s2[i]]);
	res := 0;
	for i := length(s2) to length(s1) do begin
		flag := true;
		need := 0;
		for ci := 'a' to 'z' do
			if c[ci] < a[i][ci] - a[i - length(s2)][ci] then
			begin
				flag := false;
				break;
			end else
				inc(need, c[ci] - (a[i][ci] - a[i - length(s2)][ci]));
		if (flag) and (need = b[i] - b[i - length(s2)]) then
			inc(res);
	end;
	writeln(res);
end.