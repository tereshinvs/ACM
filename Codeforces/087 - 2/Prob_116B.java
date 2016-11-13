import java.util.Scanner;

public class Prob_116B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt(), res = 0;
		char field[][] = new char[n][m];
		in.nextLine();
		for (int i = 0; i < n; i++)
			field[i] = in.nextLine().toCharArray();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (field[i][j] != 'P') continue;
				if (i > 0 && field[i-1][j] == 'W') {
					res++;
					field[i-1][j] = '.';
					}
				if (j > 0 && field[i][j-1] == 'W') {
					res++;
					field[i][j-1] = '.';
					}
				if (i < n-1 && field[i+1][j] == 'W') {
					res++;
					field[i+1][j] = '.';
					}
				if (j < m-1 && field[i][j+1] == 'W') {
					res++;
					field[i][j+1] = '.';
					}
				}
		System.out.println(res);
		}

	}