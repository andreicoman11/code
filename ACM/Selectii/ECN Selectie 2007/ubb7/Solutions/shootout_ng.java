/* Sample solution for NCPC 2006: Shoot-out
 * Author: Nils Grimsmo
 *
 * Solution: Recursive search trough the state-space with memoization.
 *
 * The state is whos turn it is, pluss who is alive. For a given state, go
 * through all possible turn of events from there (misses and a hit), all
 * possible choices, assume that the best choices are always taken.
 */
import java.util.*;
import java.io.*;

public class shootout_ng {

    static final double EPS = 1E-9;

    static int n;
    static double[] hitProb;
    static double[][][] winChance; // The winning chance given who's turn it
                                   // is, given who is alive, for each cowboy.

    static boolean equal(double a, double b) {
        return Math.abs(a - b) < EPS;
    }

    static boolean greater(double a, double b) {
        return a > b && !equal(a, b);
    }

    static void calculate(int turn, int alive) {
        winChance[turn][alive] = new double[n];
        if ((alive ^ 1 << turn) == 0) {
            winChance[turn][alive][turn] = 1.0;
            return;
        }
        double eventProb = 1.0; // Probability of getting to shooters turn
        for (int s = 0; s < n; s++) {
            int shooter = (turn + s) % n;
            if ((alive & 1 << shooter) > 0) {
                // The chance each cowboy has if the shooter makes best choice
                double[] chance = new double[n];
                int c = 0;
                double maxChance = 0.0; // For this shooter
                int numMax = 0; // Number of choices with maxChance
                for (int target = 0; target < n; target++) {
                    if (target != shooter && (alive & 1 << target) > 0) {
                        int newTurn = (shooter + 1) % n;
                        int newAlive = alive ^ 1 << target;
                        // Which is the next alive cowboy if we chose this
                        // target and hit?
                        while ((newAlive & 1 << newTurn) == 0) {
                            newTurn = (newTurn + 1) % n;
                        }
                        if (winChance[newTurn][newAlive] == null) {
                            calculate(newTurn, newAlive);
                        }
                        if (greater(winChance[newTurn][newAlive][shooter],
                                    maxChance)) {
                            Arrays.fill(chance, 0);
                            maxChance = winChance[newTurn][newAlive][shooter];
                            numMax = 0;
                        }
                        // For equally good targets, you make a random choice.
                        // Calculate this by averaging the winning chances 
                        // for each cowboy from these choices.
                        if (equal(winChance[newTurn][newAlive][shooter], 
                                  maxChance)) {
                            numMax += 1;
                            for (int i = 0; i < n; i++) {
                                chance[i] += winChance[newTurn][newAlive][i];
                            }
                        }
                    }
                }
                for (int i = 0; i < n; i++) {
                    chance[i] /= numMax;
                    winChance[turn][alive][i] += 
                            hitProb[shooter] * chance[i] * eventProb;
                }
                // What was the probability of getting to the next turn without
                // anyone being shot?
                eventProb = eventProb * (1 - hitProb[shooter]);
            }
        }
        // Instead of iterating over the shooters untill eventProb == 0.0, 
        // you go through just one round. You know that everything will be
        // exactly the same next round, except for the changed factor
        // eventProb. You know the sum of this series: 
        // sum(a*r^i, i=0..inf) = a/(1-r)
        for (int i = 0; i < n; i++) {
            winChance[turn][alive][i] /= 1 - eventProb;
        }
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        int t = rInt();
        for (int c = 0; c < t; c++) {
            n = rInt();
            hitProb = new double[n];
            for (int i = 0; i < n; i++) {
                hitProb[i] = rInt() / 100.0;
            }
            winChance = new double[n][1 << n][];
            //        0's turn, everybody is alive
            calculate(0, (1 << n) - 1);
            double[] P = winChance[0][(1 << n) - 1];
            for (int i = 0; i < n; i++) {
                System.out.printf("%.2f%c", P[i] * 100, i < n - 1 ? ' ' : '\n');
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

    static double rDouble() throws Exception {
        return Double.parseDouble(rStr());
    }
}
