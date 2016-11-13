var s, res: string;
	tvl, vl: array['a'..'z'] of integer;
	flag:boolean;
	ci: char;
	i, j : longint;

procedure output(p:integer; c:char);
var j:longint;
begin
	setlength(res, length(s));
	j := p;   
	while j <= length(s) do begin
		res[j] := c;
		inc(j, p);
		end;
	vl[c] := vl[c] - length(s) div i;
	for j := 1 to length(s) do
		if j mod p <> 0 then
			for ci := 'a' to 'z' do
				if vl[ci] > 0 then begin
					res[j] := ci;
					dec(vl[ci]);
					break;
					end;			
	writeln('YES');
	writeln(res);
end;

begin
	readln(s);
	for ci := 'a' to 'z' do
		vl[ci] := 0;
	for i := 1 to length(s) do
		inc(vl[s[i]]);
	for i := 2 to length(s) do begin
		flag := true;
		for j := 2 to i - 1 do
			if i mod j <> 0
			then
				begin
				flag := false;
				break;
				end;
		if not flag then continue;
		for ci := 'a' to 'z' do
			if vl[ci] >= length(s) div i then begin output(i, ci); exit; end;
		end;
	writeln('NO');
end.