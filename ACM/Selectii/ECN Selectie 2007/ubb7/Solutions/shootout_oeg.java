/* Sample solution for NCPC 2006: Shoot-out
 * Author: Øyvind Grotmol
 */

import java.io.DataInputStream;
import java.util.StringTokenizer;
import java.util.Locale;

public class shootout_oeg {
	
	int n;
	double[] prob;
	double[][][] memo;
	
	/** initialize variables etc */
	void solve() {
		n = INT();
		prob = new double[n];
		for (int i=0; i<n; ++i) {
			prob[i] = (double)INT()/100;
		}
		int M = 1<<n;
		memo = new double[M][n][];
		double[] ans = chances(M-1,0);
		for (int i=0; i<n; ++i) {
			if (i!=0) System.out.print(' ');
			System.out.printf("%.2f",ans[i]*100);
		}
		System.out.println();
	}

	/** Memoize the results */
	double[] chances(int state, int turn) {
		if (memo[state][turn]==null) {
			memo[state][turn] = calc(state,turn);
		}
		return memo[state][turn];
	}

	/** Do the actual calculation */
	double[] calc(int state, int turn) {
		double[] ans = new double[n];
		if ((state^(1<<turn))==0) {
			ans[turn] = 1;
			return ans;
		}
		double p = 1;
		for (int i=0; i<n; ++i) {
			int pos = turn+i;
			if (pos>=n) pos-=n;
			if ((state&(1<<pos))==0) continue;
			double[][] options = new double[n-1][];
			int cnt = 0;
			for (int j=0; j<n; ++j) {
				if ((state&(1<<j))==0) continue;
				if (j==pos) continue;
				int newstate = state^(1<<j);
				int newturn = pos;
				while (true) {
					++newturn;
					if (newturn>=n) newturn-=n;
					if ((newstate&(1<<newturn))!=0) break;
				}
				options[cnt++] = chances(newstate,newturn);
			}
			double best = 0;
			for (int j=0; j<cnt; ++j) {
				if (options[j][pos]>best)
					best = options[j][pos];
			}
			int numBest = 0;
			double[] result = new double[n];
			for (int j=0; j<cnt; ++j) {
				if (best-options[j][pos]<1e-12) {
					++numBest;
					for (int k=0; k<n; ++k) {
						result[k] += options[j][k];
					}
				}
			}
			for (int j=0; j<n; ++j) {
				result[j] /= numBest;
			}
			for (int j=0; j<n; ++j) {
				ans[j] += result[j]*prob[pos]*p;
			}
			p *= 1-prob[pos];
		}
		for (int i=0; i<n; ++i) {
			ans[i] /= 1-p;
		}
		return ans;
	}
	
	
	/*** the rest is uninteresting IO etc ***/
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		int T = INT();
		shootout_oeg obj = new shootout_oeg();
		for (int i=0; i<T; ++i) {
			obj.solve();
		}
	}
	
	static DataInputStream ds = new DataInputStream(System.in);
	static StringTokenizer st;
	static int INT() {
		while (st==null || !st.hasMoreTokens()) {
			String line;
			try { line = ds.readLine(); }
			catch(Exception e) { throw new Error(e); }
			st=new StringTokenizer(line);
		}
		return Integer.parseInt(st.nextToken());
	}

}
