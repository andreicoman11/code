/* Sample solution for NCPC 2006: Nasty Hacks
 * Author: Nils Grimsmo
 */
import java.io.*;
import java.util.*;

public class nasty_ng {

    public static void main(String args[]) throws Exception {
        int n = rInt();
        for (int i = 0; i < n; i++) {
            int r = rInt();
            int e = rInt();
            int c = rInt();
            if (r > e - c) {
                System.out.println("do not advertise");
            } else if (r < e - c) {
                System.out.println("advertise");
            } else {
                System.out.println("does not matter");
            }
        }
    }

    static BufferedReader br = 
            new BufferedReader(new InputStreamReader(System.in));

    static StringTokenizer st = new StringTokenizer("");

    static String rStr() throws Exception {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    static int rInt() throws Exception {
        return Integer.parseInt(rStr());
    }
}
