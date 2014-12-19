/* Sample solution for NCPC 2006: Random Walking
 * Author: Truls A. Bjoerklund
 *
 * The solution is with dynamic programming, always keeping track of the
 * probability of beeing in a given node at a given time.
 */

import java.io.*;
import java.util.ArrayList;

public class random_tab {
	static int k,n,e;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	public static void readCase() throws Exception{
		String[] inp = in.readLine().split(" ");
		k = Integer.parseInt(inp[0]);
		n = Integer.parseInt(inp[1]);
		e = Integer.parseInt(inp[2]);
	}
	
	public static void main(String[] args) throws Exception{
		readCase();
		outer: while(!(k==0 && n==0 && e==0)){
			int nodes = 1<<n;
			double nd = (double)nodes;
			ArrayList[] nl = new ArrayList[nodes];
			for(int i=0;i<nodes;i++) nl[i]=new ArrayList();
			for(int i=0;i<e;i++){
				String[] inp = in.readLine().split(" ");
				int f = Integer.parseInt(inp[0]);
				int t = Integer.parseInt(inp[1]);
				nl[f].add(new Integer(t));
				if(f!=t) nl[t].add(new Integer(f));
			}
			double[][] s = new double[2][nodes];
		 	for(int i=0;i<nodes;i++) s[0][i]=1.0/nd;
			double[] g = new double[n];
			for(int i=0;i<nodes;i++) for(int j=0;j<n;j++) if(((1<<j)&i)>0)g[j]+=s[0][i];
			for(int j=0;j<n;j++){
				if(g[j]<=0.25||g[j]>=0.75){
					System.out.println("No");
					readCase();
					continue outer;
				}	
				g[j]=0.0;
			}
			
			for(int i=1;i<k;i++){
				for(int j=0;j<nodes;j++){
					double size = (double)nl[j].size();
					for(int t=0;t<nl[j].size();t++) 
						s[i%2][((Integer)nl[j].get(t)).intValue()]+=(s[(i+1)%2][j]/size);
				}
				for(int j=0;j<nodes;j++){
					s[(i+1)%2][j]=0.0;
					for(int t=0;t<n;t++) if(((1<<t)&j)>0)g[t]+=s[i%2][j];
				}
				for(int j=0;j<n;j++){
					if(g[j]<=0.25||g[j]>=0.75){
						System.out.println("No");
						readCase();
						continue outer;
					}
					g[j]=0.0;
				}
			}
			System.out.println("Yes");
			readCase();
		}
	}
}
