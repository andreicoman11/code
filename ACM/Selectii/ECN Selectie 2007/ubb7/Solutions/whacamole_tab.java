/* Sample solution for NCPC 2006: Whac-a-Mole
 * Author: Truls A. Bjoerklund
 *
 * This is a straight-forward dp-solution to the problem. It tries all
 * possible startpositions for each end-position in each step.
 */

import java.io.*;

public class whacamole_tab {

	static int n,d,maxt=10,size;
	static boolean[][][] moles;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	public static int gcd(int a, int b){
		if(a>b) return b>0 ? gcd(a%b,b) : a;
		else return a>0 ? gcd(a,b%a): b;
	}
	
	public static boolean readCase() throws Exception{
		String[] inp = in.readLine().split(" ");
		n= Integer.parseInt(inp[0]);
		d= Integer.parseInt(inp[1]);
		size=n+2*d;
		int m=Integer.parseInt(inp[2]);
		if(n==0 && m==0 && d==0) return false;
		moles = new boolean[maxt][size][size];
		for(int i=0;i<m;i++){
			inp=in.readLine().split(" ");
			moles[Integer.parseInt(inp[2])-1][Integer.parseInt(inp[1])][Integer.parseInt(inp[0])]=true;
		}
		return true;
	}

	public static int solve() throws Exception{
		int size = n+2*d;
		int[][][] s = new int[2][size][size];
		for(int t=0;t<maxt;t++){
			for(int i=0;i<size;i++)
				for(int j=0;j<size;j++)
					for(int fx= i-d<0?0:i-d; fx<= (i+d<size? i+d:size-1); fx++)
						for(int fy= j-d<0?0:j-d; fy<= (j+d<size? j+d:size-1); fy++)
							if((i-fx)*(i-fx)+(j-fy)*(j-fy)<=d*d){
								int test = s[(t+1)%2][fx][fy]+(i>d-1 && i<n+d && j>d-1 && j<n+d && moles[t][i-d][j-d]?1:0);
								int dx = (i-fx)==0? 0 :(i-fx)/gcd(i-fx>0?i-fx:fx-i,j-fy>0?j-fy:fy-j);
								int dy = (j-fy)==0? 0 :(j-fy)/gcd(i-fx>0?i-fx:fx-i,j-fy>0?j-fy:fy-j);
								for(int x=fx, y=fy; x!=i || y!=j;  x+=dx, y+=dy)
									test+=(x>d-1 && x<n+d && y>d-1 && y<n+d && moles[t][x-d][y-d]?1:0);
								if(test>s[t%2][i][j]) s[t%2][i][j] = test;
							}
			for(int i=0;i<size;i++) for(int j=0;j<size;j++) s[(t+1)%2][i][j]=0;
		}
		int max=-1;
		for(int i=0;i<size;i++) for(int j=0;j<size;j++) if(s[(maxt+1)%2][i][j]>max) max=s[(maxt+1)%2][i][j];
		return max;
	}
	
	public static void main(String[] args) throws Exception{
		while(readCase()) System.out.println(solve());
	}
}
