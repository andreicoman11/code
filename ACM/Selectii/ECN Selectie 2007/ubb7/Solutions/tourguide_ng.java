/* Sample solution for NCPC 2006: Tour Guide
 * Author: Nils Grimsmo
 *
 * Solution: 
 * Go through all permutations of the order in which you collect the seniors.
 * Use Pythagoras to find the intersection point between you and a senior. 
 * Split x and y speed for the senior, but not for yourself, and solve to find 
 * the time t (see below).
 */
import java.util.*;
import java.io.*;

public class tourguide_ng {

    static boolean nextPerm(int[] S) {
        int n = S.length;
        int i = n - 2;
        while (true) {
            if (i < 0) {
                return false;
            }
            if (S[i] < S[i+1]) {
                break;
            }
            i--;
        }
        int j = n - 1;
        while (S[i] >= S[j]) {
            j--;
        }
        int tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
        int a = i + 1;
        int b = n - 1;
        while (a < b) {
            tmp = S[a];
            S[a] = S[b];
            S[b] = tmp;
            a++; b--;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        while (true) {
            int n = rInt();
            if (n == 0) {
                break;
            }
            double v = rDouble();
            double[] Xi = new double[n];
            double[] Yi = new double[n];
            double[] Vi = new double[n];
            double[] Ai = new double[n];
            for (int i = 0; i < n; i++) {
                Xi[i] = rDouble();
                Yi[i] = rDouble();
                Vi[i] = rDouble();
                Ai[i] = rDouble();
            }
            int[] order = new int[n];
            for (int i = 0; i < n; i++) {
                order[i] = i;
            }
            double bestTime = Double.POSITIVE_INFINITY;
            do {
                double time = 0.0;
                double finishTime = 0.0;
                double x = 0.0;
                double y = 0.0;
    
                for (int k = 0; k < order.length; ++ k) {
		    // java 1.4 compatible Børge 22.9
		    int i = order[k];
                    double ai = Ai[i];
                    double vi = Vi[i];
                    double vix = vi * Math.cos(ai);
                    double viy = vi * Math.sin(ai);
                    double xi = Xi[i] + vix * time;
                    double yi = Yi[i] + viy * time;

                    /* ((xi-x)+vix*t)^2+((yi-y)+viy*t)^2=(v*t)^2
                     * ==>
                     * (xi-x)^2+2(xi-x)*vix*t+vix^2*t^2 +
                     * (yi-y)^2+2(yi-y)*viy*t+viy^2*t^2 = v^2*t^2
                     * ==>
                     * (vix^2+viy^2-v^2)*t^2+2((xi-x)*vix+(yi-y)*viy)*t +
                     * ((xi-x)^2+(yi-y)^2 = 0
                     */
                    double a = vix*vix+viy*viy-v*v;
                    double b = 2*((xi-x)*vix+(yi-y)*viy);
                    double c = (xi-x)*(xi-x)+(yi-y)*(yi-y);
                    double t = (-b-Math.sqrt(b*b-4*a*c))/(2*a);
                    time += t;
                    x = xi+vix*t;
                    y = yi+viy*t;
                    finishTime = Math.max(finishTime,
                                          time + Math.sqrt(x*x+y*y)/vi);
                }
                if (finishTime < bestTime) {
                    bestTime = finishTime;
                }
            } while (nextPerm(order));
            if (    (int)Math.round(bestTime) != (int)Math.round(bestTime + 1E-10) ||
                    (int)Math.round(bestTime) != (int)Math.round(bestTime - 1E-10)) {
                System.err.println("potential rounding error");
                System.exit(13);
            }
            System.out.println((int)Math.round(bestTime));
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
