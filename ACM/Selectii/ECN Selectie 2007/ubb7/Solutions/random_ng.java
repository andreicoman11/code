/* Sample solution for NCPC 2006: Jezzball
 * Author: Nils Grimsmo
 *
 * Solution: 
 * Maintain the probability for beeing in each node in each time step. The 
 * probility of being in node v in time round r is the sum of the probabilities
 * for going from u to v for all u. The probability of going from u to v is 
 * the probability of being in u in round r-1, times the probability of going 
 * to u given that you are in v. The latter can be found by divining the
 * number of edges from u to v by the total number of edges from v.
 *
 * Then, for each bit, sum the probabilities of being in all states that 
 * have this bit set in its number. Do this separately for all k rounds.
 */
import java.util.*;
import java.io.*;
import java.text.*;

public class random_ng {

    public static void main(String[] args) throws Exception {
        while (true) {
            int k = rInt();
            if (k == 0) {
                break;
            }
            int n = rInt();
            int e = rInt();
            int N = 1 << n; // The number of nodes
            ArrayList<ArrayList<Integer>> E // Neighbour lists
                    = new ArrayList<ArrayList<Integer>>();
            for (int u = 0; u < N; u++) {
                E.add(new ArrayList<Integer>());
            }
            for (int i = 0; i < e; i++) {
                int u = rInt();
                int v = rInt();
                E.get(u).add(v);
                E.get(v).add(u);
            }
            // The probability of being in each state
            double[] lastP = null;
            boolean good = true;
            for (int r = 0; r < k; r++) {
                double[] P = new double[N]; 
                if (r == 0) {
                    for (int u = 0; u < N; u++) {
                        // Start probability is equal for all nodes
                        P[u] = 1.0 / N; 
                    }
                } else {
                    for (int u = 0; u < N; u++) {
                        for (int v: E.get(u)) {
                            P[v] += lastP[u] / E.get(u).size();
                        }
                    }
                }
                // The probability for each bit.
                double[] F = new double[n];
                for (int i = 0; i < n; i++) {
                    for (int u = 0; u < N; u++) {
                        if ((u & (1 << i)) > 0) {
                            F[i] += P[u];
                        }
                    }
                    if (F[i] <= 0.25 || 0.75 <= F[i]) {
                        good = false;
                    }
                }
                lastP = P;
            }
            if (good) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }

    static DecimalFormat DF = 
        new DecimalFormat("0.00", new DecimalFormatSymbols(Locale.ENGLISH));

    static void pArr(double[] A) {
        System.err.print("[");
        for (double a: A) {
            System.err.print("" + DF.format(a) + " ");
        }
        System.err.println();
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

    static double rDouble() throws Exception {
        return Double.parseDouble(rStr());
    }
}
