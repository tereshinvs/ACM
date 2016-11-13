import java.util.Scanner;

public class A
	{
		public static void main(String[] args)
			{
				String s = new Scanner(System.in).nextLine(), glas[] = { "a", "e", "o", "i", "u", "y", "A", "E", "O", "I", "U", "Y" };
				for (int i = 0; i < 12; i++)
					for (int j = 0; j < s.length(); j++)
						if (s.substring(j, j+1).equals(glas[i]))
							s = s.substring(0, j) + s.substring(j+1);
				for (int i = 0; i < s.length(); i += 2)
					s = s.substring(0, i) + "." + s.substring(i);
				System.out.println(s.toLowerCase());
			}
	}