var a, b, md, i, j: longint;
	res: string;
	temp: int64;

function min(t1, t2: longint): longint;
	begin
		if t1 < t2 then exit(t1) else exit(t2);
	end;

begin
	readln(a, b, md);
	if b >= md then
		begin
			writeln(2);
			exit;
		end;
	for i := 1 to min(md - 1, a) do
		begin
			temp := i * int64(1000000000);
			if temp mod md = 0 then continue;
			if md - temp mod md > b then
				begin
					write(1, ' ');
					str(i, res);
					for j := 1 to 9-length(res) do
						write(0);
					writeln(res);
					exit;
				end;
		end;                 	
	writeln(2);
end.