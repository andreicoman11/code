/* Sample solution for NCPC 2006: Shootout
 * Author: Truls A. Bjoerklund
 *
 * The solution is by dynamic programming where the states are given by which
 * cowboys that are alive and whose turn it is next. 
 *
 * In order to avoid circular dependencies among states, the known sum of a
 * geometric series is used.
 */

import java.io.*;
import java.text.NumberFormat;
import java.util.ArrayList;

public class shootout_tab {
	
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		NumberFormat nf = NumberFormat.getInstance();
		nf.setMaximumFractionDigits(5);
		nf.setMinimumFractionDigits(5);
		int t = Integer.parseInt(in.readLine());
		for(int c=0;c<t;c++){
			String[] inp = in.readLine().split(" ");
			double[] prob = new double[inp.length-1];
			for(int i=0;i<prob.length;i++) prob[i]= Double.parseDouble(inp[i+1])/100.0;
			int s = 1<<prob.length, n=prob.length;
			double[][][] p = new double[s][n][];
			for(int i=1;i<s;i++){
				double[] restp = new double[n];
				double p_all_misses=1.0;
				for(int j=0;j<n;j++) restp[j]=1.0-prob[j];
				ArrayList<Integer> pos = new ArrayList<Integer>();
				for(int j=0;j<n;j++) if((i&(1<<j)) >0){
					p_all_misses*=restp[j];
					pos.add(j);
				}
				if(pos.size()==1){
					p[i][pos.get(0)]=new double[n];
					p[i][pos.get(0)][pos.get(0)]=1.0;
				}
				else{
					for(int j=0;j<pos.size();j++){
						ArrayList<Integer> best = new ArrayList<Integer>();
						double bestval=0.0;
						p[i][pos.get(j)]= new double[n];
						for(int k=0;k<pos.size();k++){
							if(k==j) continue;
							int ind = i ^ (1<<pos.get(k));
							int next = (j+1)%pos.size();
							if(k==next) next = (k+1)%pos.size();
							if(p[ind][pos.get(next)][pos.get(j)]>bestval) bestval=p[ind][pos.get(next)][pos.get(j)];
						}
						 for(int k=0;k<pos.size();k++){
							 if(k==j) continue;
							 int ind = i ^ (1<<pos.get(k));
							 int next = (j+1)%pos.size();
							 if(k==next) next = (k+1)%pos.size();
							 if(bestval-p[ind][pos.get(next)][pos.get(j)]<1e-12) best.add(k);
						}
						for(int k=0;k<best.size();k++){
							int next = (j+1)%pos.size();
							if(best.get(k)==next) next = (best.get(k)+1)%pos.size();
							for(int a=0;a<n;a++) p[i][pos.get(j)][a]+=(p[i^(1<<pos.get(best.get(k)))][pos.get(next)][a]/((double)best.size()));
						}
						for(int k=0;k<n;k++) p[i][pos.get(j)][k]*=prob[pos.get(j)];
					}
					double[][] ins = new double[pos.size()][n];
					for(int j=0;j<pos.size();j++){
						int posi = (j+pos.size()-1)%pos.size();
						while(posi!=j){
							for(int a=0;a<n;a++) ins[j][a]*=restp[pos.get(posi)];
							for(int a=0;a<n;a++) ins[j][a]+=p[i][pos.get(posi)][a];
							posi--;
							if(posi==-1)posi+=pos.size();
						}
						for(int a=0;a<n;a++) ins[j][a]*=restp[pos.get(j)];
						for(int a=0;a<n;a++){
							ins[j][a]+=p[i][pos.get(j)][a];
							ins[j][a]/=(1.0-p_all_misses);
						}
					}
					for(int j=0;j<pos.size();j++) p[i][pos.get(j)]=ins[j];
				}
			}
			for(int i=0;i<n;i++)System.out.print(nf.format(p[s-1][0][i])+" ");
			System.out.println();
		}
	}
}
