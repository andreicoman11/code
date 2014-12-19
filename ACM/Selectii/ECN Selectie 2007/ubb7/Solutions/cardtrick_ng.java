/* Sample solution for NCPC 2006: Card Trick
 * Author: Nils Grimsmo
 */
import java.io.*;
import java.util.*;

public class cardtrick_ng {

    public static void main(String[] args) throws Exception {
        int cases = rInt();
        for (int c = 0; c < cases; c++) {
            int n = rInt();

            int[] D = new int[n];
            int p = 0;
            // For each of the cards you want to draw
            for (int i = 1; i <= n; i++) {
                // Find first free "slot" in deck
                while (D[p] != 0) {
                    p = (p + 1) % n;
                }
                // Let the next i-1 slots also be free for cards you draw 
                // and put at the bottom
                for (int j = 0; j < i; j++) {
                    p = (p + 1) % n;
                    while (D[p] != 0) {
                        p = (p + 1) % n;
                    }
                }
                // Put the card you want to draw in the i'th free slot
                D[p] = i;
            }
            for (int i = 0; i < D.length; i++) {
                System.out.print("" + D[i] + " ");
            }
            System.out.println();
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
