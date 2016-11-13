import java.util.*;
import java.io.*;

public class D {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s1 = in.readLine(), s2[] = in.readLine();
		System.out.println("reading end");
		int n1 = s1.length, n2 = s2.length;
		for (int i = 0; i < n1; i++)
			s[i] = s1[i];
		for (int i = 0; i < n2; i++)
			s[i + n1] = s2[i];
		int cmp[] = new int[200000], n = n1 + n2;
		cmp[0] = 0;
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r)
				cmp[i] = (r-i+1) < cmp[i-l] ? (r - i + 1) : cmp[i - l];
			while (i + cmp[i] < n && s[cmp[i]] == s[i + cmp[i]])
				++cmp[i];
			if (i + cmp[i] - 1 > r)
				l = i;  r = i + cmp[i] - 1;
		}
		System.out.println("cmp end");
		int res = 0;
		for (int i = 1; i <= n1 && i <= n2; i++) {
			if (n1 % i != 0 || n2 % i != 0)
				continue;
			if (i + cmp[i] == n)
				res += 1;
		}
		System.out.println(res);
	}
}