/* Sample solution for NCPC 2006: Honeycomb Walk
 * Author: Nils Grimsmo
 *
 * Solution: 
 * Dynamic programming. The number of ways to get to a cell at time t+1 is the
 * sum of the ways to get to all neighbouring cells at time t. The answer is
 * the value for starting cell at time n.
 *
 * (Note: There is a simpler and prettier way to represent the grid than what
 * is described below. See the other solutions.)
 *
 * The tricky part is how to represent neighbouring cells. One way is two look
 * up and to the sides for odd numbered columns...
 *
 *   <-\  ^  /->
 *      \ | /
 *   <--     -->
 *        |
 *        v
 *
 * and down and to the sides for even numbered columns
 *
 *        ^     
 *        |  
 *   <--     -->
 *      / | \
 *   <-/  v  \->
 *
 * This gives six neighbours to which you are also a neighbour.
 */
import java.io.*;
import java.util.*;

public class honey_ng {

    public static void main(String[] args) throws Exception {
        int cases = rInt();
        for (int ca = 0; ca < cases; ca++) {
            int n = rInt();
            int s = 33;
            int[][] W = new int[s][s];
            int[][] W2 = new int[s][s];
            // The starting cell in the center:
            W[s/2][s/2] = 1;
            for (int i = 0; i < n; i++) {
                for (int x = 1; x < s - 1; x++) {
                    for (int y = 1; y < s - 1; y++) {
                        // threat odd and even numbered columns differently
                        W2[y][x] = W[y+1][x+0] 
                                 + W[y-1][x+0] 
                                 + W[y+((x+0)%2)][x-1] 
                                 + W[y-((x+1)%2)][x-1] 
                                 + W[y+((x+0)%2)][x+1] 
                                 + W[y-((x+1)%2)][x+1];
                    }
                }
                int[][] tmp = W; W = W2; W2 = tmp;
            }
            System.out.println(W[s/2][s/2]);
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
