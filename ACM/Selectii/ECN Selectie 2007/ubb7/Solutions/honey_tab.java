/* Sample solution for NCPC 2006: Honeycomb Walk
 * Author: Truls A. Bjoerklund
 * 
 * The solution is by simple dynamic programming in a hexagonal grid.
 */

import java.io.*;

public class honey_tab {
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		for(int i=0;i<n;i++){
			int t = Integer.parseInt(in.readLine());
			int size=2*t+4;
			int[][][] m = new int[2][size][size];
			m[1][t+1][t+1]=1;
			int j=0;
			for(j=0;j<t;j++){
				for(int k=0;k<size;k++) for(int l=0;l<size;l++) m[j%2][k][l]=0;
				for(int k=1;k<size-1;k++){
					for(int l=1;l<size-1;l++){
						m[j%2][k][l+1]+=m[(j+1)%2][k][l];
						m[j%2][k][l-1]+=m[(j+1)%2][k][l];
						m[j%2][k+1][l]+=m[(j+1)%2][k][l];
						m[j%2][k-1][l]+=m[(j+1)%2][k][l];
						if(k%2 ==1){
							m[j%2][k+1][l-1]+=m[(j+1)%2][k][l];
							m[j%2][k-1][l-1]+=m[(j+1)%2][k][l];
						}
						else{
							m[j%2][k+1][l+1]+=m[(j+1)%2][k][l];
							m[j%2][k-1][l+1]+=m[(j+1)%2][k][l];
						}
					}
				}
			}
			System.out.println(m[(j+1)%2][t+1][t+1]);
		}
	}
}
