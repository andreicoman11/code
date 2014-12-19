/* Sample solution for NCPC 2006: Traveling Salesman
 * Author: Nils Grimsmo
 *
 * Solution: 
 * Hash edges on their endpoints to find neighbouring countries.
 * (Order the two points of all edges in the same way.)
 * Do a breadth first searh to find the distance between two countries.
 *
 * Bloated object-oriented implementation.
 */
import java.io.*;
import java.util.*;

public class traveling_ng {

    static final int INF = 1 << 20;

    static class Point implements Comparable<Point> {
        int[] p = new int[3];
        int x, y, z;
        Point(int x, int y, int z) {
            this.x = p[0] = x;
            this.y = p[1] = y;
            this.z = p[2] = z;
        }
        public int compareTo(Point o) {
            for (int i = 0; i < 3; i++) {
                if (this.p[i] < o.p[i]) {
                    return -1;
                } else if (this.p[i] > o.p[i]) {
                    return 1;
                }
            }
            return 0;
        }
        public boolean equals(Object o) {
            return compareTo((Point)o) == 0;
        }
        public int hashCode() {
            return x*y*z + x*y + x*z + y*z + x + y + z;
        }
    }

    static class Edge {
        Point p1, p2;
        Edge(Point p1, Point p2) {
            if (p1.compareTo(p2) < 0) {
                this.p1 = p1;
                this.p2 = p2;
            } else {
                this.p1 = p2;
                this.p2 = p1;
            }
        }
        public boolean equals(Object o) {
            Edge oe = (Edge)o;
            return p1.equals(oe.p1) && p2.equals(oe.p2);
        }
        public int hashCode() {
            int h1 = p1.hashCode();
            int h2 = p2.hashCode();
            return h1 * h2 + h1 + h2;
        }
    }

    public static void main(String[] args) throws Exception {
        while (true) {
            int c = rInt();
            if (c == 0) {
                break;
            }
            // Make a mapping from edges to a list of countries sharing the     
            // edge. List will contain two elements.
            HashMap<Edge,ArrayList<Integer>> borders = 
                    new HashMap<Edge,ArrayList<Integer>>();
            for (int i = 0; i < c; i++) {
                int n = rInt();
                // Collect points defining country
                ArrayList<Point> ps = new ArrayList<Point>();
                for (int j = 0; j < n; j++) {
                    int x = rInt(); int y = rInt(); int z = rInt();
                    ps.add(new Point(x, y, z));
                }
                // Edges are given by consecutive points.
                for (int j = 0; j < n; j++) {
                    Edge e = new Edge(ps.get(j), ps.get((j+1) % n));
                    if (!borders.containsKey(e)) {
                        borders.put(e, new ArrayList<Integer>());
                    }
                    borders.get(e).add(i);
                }
            }
            // Make neighbour lists from the borders.
            ArrayList<ArrayList<Integer>> neigh = 
                    new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < c; i++) {
                neigh.add(new ArrayList<Integer>());
            }
            for (ArrayList<Integer> list: borders.values()) {
                int ca = list.get(0);
                int cb = list.get(1);
                if (!neigh.get(ca).contains(cb)) {
                    neigh.get(ca).add(cb);
                    neigh.get(cb).add(ca);
                }
            }
            int m = rInt();
            for (int i = 0; i < m; i++) {
                int ca = rInt() - 1;
                int cb = rInt() - 1;
                // Do a breadth first search using a queue
                Queue<Integer> Qc = new LinkedList<Integer>(); // Country
                Qc.offer(ca);
                Queue<Integer> Qd = new LinkedList<Integer>(); // Distance
                Qd.offer(0);
                HashSet<Integer> seen = new HashSet<Integer>();
                while (true) {
                    int c1 = Qc.remove();
                    int d = Qd.remove();
                    if (c1 == cb) {
                        System.out.println(d);
                        break;
                    }
                    for (int c2: neigh.get(c1)) {
                        if (!seen.contains(c2)) {
                            Qc.offer(c2);
                            Qd.offer(d + 1);
                            seen.add(c2);
                        }
                    }
                }
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
