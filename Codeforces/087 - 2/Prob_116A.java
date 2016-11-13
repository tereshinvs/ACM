import java.io.*;

public class Prob_116A {

	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

	static int readInt() throws IOException {
		in.nextToken();
		return (int)in.nval;
		}

	public static void main(String[] args) throws IOException {
		int n = readInt(), res = 0, current = 0;
		for (int i = 0; i < n; i++)
			res = (res < (current += -readInt() + readInt()) ? current : res);
		System.out.println(res);
		}

	}