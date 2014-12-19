/* Sample solution for NCPC 2006: Jezzball
 * Author: Nils Grimsmo
 *
 * Solution: 
 * Go through all occasions where a ball hits the vertical and horizontal 
 * line. All such hits give an interval where the respective ray _cannot_
 * be fired. For both the vertical and horisontal case: 
 *      Sort these time intervals on their start time, and traverse them,
 *      looking for an open interval.
 * Choose the minimum of these.
 */
import java.util.*;
import java.text.*;
import java.io.*;

public class jezzball_ng {

    // A hit gives an inteval when the ray _cannot_ be fired.
    static class Hit implements Comparable<Hit> {
        double from, to;
        public Hit(double from, double to) {
            this.from = from;
            this.to = to;
        }
        // Let hits be sortable
        public int compareTo(Hit other) {
            if (this.from < other.from) {
                return -1;
            } else if (this.from > other.from) {
                return 1;
            } else {
                return 0;
            }
        }
        public String toString() {
            return "(" + from + "," + to + ")";
        }
    }

    static final double XEND = 1024;
    static final double YEND = 768;
    static final double RAYSPEED = 200;
    static final double MAXTIME = 10000;

    static DecimalFormat DF = 
            new DecimalFormat("0.00000", 
                    new DecimalFormatSymbols(Locale.ENGLISH));

    public static void main(String[] args) throws Exception {
    	while(true) {
            int n = rInt();
            if (n==0) break;
            double x = rDouble();
            double y = rDouble();
            ArrayList<Hit> vHits = new ArrayList<Hit>();
            ArrayList<Hit> hHits = new ArrayList<Hit>();
            for (int i = 0; i < n; i++) {
                double xi = rDouble();
                double yi = rDouble();
                double vxi = rDouble();
                double vyi = rDouble();
                if (vxi == 0 || vyi == 0) {
                    System.err.println("jaggu");
                    System.exit(13);
                }
                double time = 0;
                int count = 0;
                boolean vLeft = vxi != 0; // Whether or not there may be
                boolean hLeft = vyi != 0; // vertical or horisontal hits left
                while (vLeft || hLeft) {
                    double tSid, tTop; 
                    double tVer = Double.POSITIVE_INFINITY;
                    double tHor = Double.POSITIVE_INFINITY;
                    // Crash with left or right wall
                    if (vxi < 0) {
                        tSid = xi / -vxi;
                    } else {
                        tSid = (XEND - xi) / vxi;
                    }
                    // Crash with floor or roof
                    if (vyi < 0) {
                        tTop = yi / -vyi;
                    } else {
                        tTop = (YEND - yi) / vyi;
                    }
                    // Crash with vertical line
                    if ((xi > x && vxi < 0) || (xi < x && vxi > 0)) {
                        tVer = (x - xi) / vxi;
                    }
                    // Crash with horizontal line
                    if ((yi > y && vyi < 0) || (yi < y && vyi > 0)) {
                        tHor = (y - yi) / vyi;
                    }
                    double           tMin = tSid;
                    if (tTop < tMin) tMin = tTop;
                    if (tVer < tMin) tMin = tVer;
                    if (tHor < tMin) tMin = tHor;
                    if (tMin < 0) {
                        System.err.println("Mor di!");
                        System.exit(13);
                    }
                    time += tMin;
                    xi += vxi * tMin;
                    yi += vyi * tMin;
                    if (tSid == tMin) {
                        vxi *= -1;
                    }
                    if (tTop == tMin) {
                        vyi *= -1;
                    }
                    if (tVer == tMin) {
                        Hit hit = new Hit(time - Math.max(y, YEND - y) / RAYSPEED,
                                          time - Math.abs(y - yi) / RAYSPEED);
                        vHits.add(hit);
                        vLeft = time <= MAXTIME
                                + Math.max(y, YEND - y) / RAYSPEED;
                    }
                    if (tHor == tMin) {
                        Hit hit = new Hit(time - Math.max(x, XEND - x) / RAYSPEED,
                                          time - Math.abs(x - xi) / RAYSPEED);
                        hHits.add(hit);
                        hLeft = time <= MAXTIME
                                + Math.max(x, XEND - x) / RAYSPEED;
                    }
                }
            }
            Collections.sort(vHits);
            Collections.sort(hHits);
            double min = Double.POSITIVE_INFINITY;
            for (int t = 0; t <= 1; t++) {
                ArrayList<Hit> hits;
                if (t == 0) {
                    hits = vHits;
                } else {
                    hits = hHits;
                }
                boolean found = false;
                double next = 0.0;
                for (Hit hit: hits) {
                    if (next < hit.from) {
                        if (hit.from - next < 1E-5) {
                            System.err.println("Interval of size " + (hit.from - next));
                            System.exit(13);
                        }
                        if (next < min) {
                            min = next;
                        }
                        found = true;
                        break;
                    }
                    if (hit.to > next) {
                        next = hit.to;
                    }
                }
            }
            if (min < MAXTIME) {
                System.out.println(DF.format(min));
                // Check for potential rounding errors
                String t1 = DF.format(min - 1E-7);
                String t2 = DF.format(min);
                String t3 = DF.format(min + 1E-7);
                if (!(min == 0.0 || t1.equals(t2)) || !t2.equals(t3)) {
                    System.err.println("Potential rounding error "+t1+" "+t2+" "+t3);
                    System.exit(13);
                }
            } else {
                System.out.println("Never");
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
