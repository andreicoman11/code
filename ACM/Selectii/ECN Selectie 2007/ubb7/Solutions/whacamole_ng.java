/* Sample solution for NCPC 2006: Whac-a-Mole
 * Author: Nils Grimsmo
 *
 * Solution: 
 * Dynamic programming. For each time step, maintain the number of moles that
 * can be whacked if you to end up at each position (x,y). For each position,
 * try if you can give neighbouring positions at most d away a good score in
 * the current timestep, based on the score in last time step here, and the
 * number of moles you can whack on the way there in the current timestep. 
 */
import java.util.*;
import java.io.*;

public class whacamole_ng {

    static final double EPS = 1E-10;
    static final int t_MAX = 10;

    public static void main(String[] args) throws Exception {
        while (true) {
            int n = rInt(), d = rInt(), m = rInt();
            if (n == 0 && d == 0 && m == 0) {
                break;
            }
            int N = d + n + d;
            boolean[][][] moles = new boolean[t_MAX+1][N][N];
            for (int i = 0; i < m; i++) {
                int x = rInt(), y = rInt(), t = rInt();
                moles[t][x+d][y+d] = true;
            }
                              // Score when ending up here
            int[][][] score = new int[t_MAX+1][N][N]; 
            for (int t = 1; t <= t_MAX; t++) {
                for (int x = 0; x < N; x++) {
                    for (int y = 0; y < N; y++) {
                        // Jump lengths
                        for (int dx = -d; dx <= d; dx++) {
                            for (int dy = -d; dy <= d; dy++) {
                                // Target positions
                                int ox = x, oy = y;
                                int val = score[t-1][x][y];
                                while (0 <= ox && ox < N &&
                                       0 <= oy && oy < N &&
                                       (y-oy)*(y-oy) + (x-ox)*(x-ox) <= d*d) {
                                    if (moles[t][ox][oy]) {
                                        val += 1;
                                    }
                                    score[t][ox][oy] = max(score[t][ox][oy],
                                                           val);
                                    if (abs(dx) + abs(dy) > 0) {
                                        ox += dx;
                                        oy += dy;
                                    } else {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            int topScore = 0;
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    if (score[t_MAX][x][y] > topScore) {
                        topScore = score[t_MAX][x][y];
                    }
                }
            }
            System.out.println(topScore);
        }
    }

    static int min(int a, int b) {
        if (a <= b) return a;
        else        return b;
    }

    static int max(int a, int b) {
        if (a >= b) return a;
        else        return b;
    }
    
    static int abs(int a) {
        if (a >= 0) return a;
        else        return -a;
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
