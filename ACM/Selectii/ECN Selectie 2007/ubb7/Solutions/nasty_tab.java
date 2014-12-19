/* Sample solution for NCPC 2006: Nasty hacks
 * Author: Truls A. Bjoerklund
 */

import java.io.*;

public class nasty_tab {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		for(int i = 0; i < n; i++){
			String[] inp = in.readLine().split(" ");
			int r = Integer.parseInt(inp[0]);
			int e = Integer.parseInt(inp[1]);
			int c = Integer.parseInt(inp[2]);
			if (e - r > c)      System.out.println("advertise");
			else if (e - r < c) System.out.println("do not advertise");
			else                System.out.println("does not matter");
		}
	}
}
