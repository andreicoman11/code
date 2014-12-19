import java.math.*;
import java.util.Scanner;

public class prime {

	public static int verif(String s) {
		int c = 0;

		if( s.length()==1 ) {
			return 1;
			
		} else {
			for(int i=0; i<s.length(); i++) {
				String t = s.substring(0, i);
				t += s.substring(i+1, s.length());
				BigInteger bi = new BigInteger(t);
				if( bi.isProbablePrime(10) ) {
					c += verif(t);
				}
			}
		}
		return c;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.nextLine();

		System.out.println("Final result: " + verif(s));
	}

}
