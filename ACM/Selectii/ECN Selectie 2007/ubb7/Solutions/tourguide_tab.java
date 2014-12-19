/* Sample solution for NCPC 2006: Tour Guide
 * Author: Truls A. Bjoerklund
 *
 * This is a generalization of TSP. We hence try all permutations
 * and choose the best one. A second degree polynomial equation has
 * to be solved to be able to find the time when the guide will meet
 * a particular tourist.
 */

import java.io.*;
import java.lang.*;

public class tourguide_tab {
	
	//Solving a second degree polynomial equation
	public static double timeToMeet(double gx, double gy, double gv, double x, double y, double vx, double vy){
		double a=vx*vx+vy*vy-gv*gv;
		double b = 2*(vx*(x-gx)+vy*(y-gy));
		double c = (x-gx)*(x-gx)+(y-gy)*(y-gy);
		return (-b -  Math.sqrt(b*b - 4*a*c))/(2*a);
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		while(n!=0){
			double v = Double.parseDouble(in.readLine());
			double[][] retards = new double[n][5];
			for(int i=0;i<n;i++){
				String[] inp = in.readLine().split(" ");
				retards[i][0]= Double.parseDouble(inp[0]);
				retards[i][2]= Double.parseDouble(inp[1]);
				retards[i][4] = Double.parseDouble(inp[2]);
				double a = Double.parseDouble(inp[3]);
				retards[i][1]=retards[i][4] * Math.cos(a);
				retards[i][3]=retards[i][4] * Math.sin(a);
			}
			int[] a = new int[n];
			for(int i=0;i<n;i++)a[i]=i;
			double bestTime = Double.MAX_VALUE;
			while(a!=null){
				double maxtime=0.0;
				double t = 0.0;
				double guidex=0.0;
				double guidey=0.0;
				for(int i=0;i<n;i++){
					double retardx = retards[a[i]][0]+retards[a[i]][1]*t;
					double retardy = retards[a[i]][2]+retards[a[i]][3]*t;
					double addt = timeToMeet(guidex,guidey,v,retardx,retardy,retards[a[i]][1],retards[a[i]][3]);
					t+=addt;
					guidex = retardx+addt*retards[a[i]][1];
					guidey = retardy+addt*retards[a[i]][3];
					double newt = (Math.sqrt(guidex*guidex + guidey*guidey)/retards[a[i]][4])+t;
					if(newt>maxtime)maxtime=newt;
				}
				if(maxtime<bestTime)bestTime=maxtime;
				a=next(a);
			}
			System.out.println(""+Math.round(bestTime));
			n=Integer.parseInt(in.readLine());
		}
	}



	public static int[] next(int[] a){
		int temp, j = a.length - 2;
		if(j==-1)return null;
		while (a[j] > a[j+1]) {
			j--;
			if(j==-1) return null;
		}
		int k = a.length - 1;
		while (a[j] > a[k]) k--;
		temp = a[k];
		a[k] = a[j];
		a[j] = temp;
		int r = a.length - 1;
		int s = j + 1;
		while (r > s) {
			temp = a[s];
			a[s] = a[r];
			a[r] = temp;
			r--;
			s++;
		}
		return a;
	}
}
