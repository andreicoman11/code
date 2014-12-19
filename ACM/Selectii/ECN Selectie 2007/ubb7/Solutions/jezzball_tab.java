/* Sample solution NCPC 2006: Jezzball
 * Author: Truls A. Bjoerklund
 * 
 * The solution finds all intervals where we are unable to start extending the ray in both
 * the horisontal and vertical direction. These are then shortest and we search for the first
 * open interval for both cases.
 */

import java.io.*;
import java.util.*;
import java.text.NumberFormat;

public class jezzball_tab {

	static double maxtime = 0.0;
	static double rayspeed=200.0;
	static double ymax=768.0;
	static double xmax=1024.0;

	private static class Hit implements Comparable<Hit>{
		public double[] interval;
		public Hit(double from, double to){
			interval=new double[2];
			interval[0]=from;
			interval[1]=to;
		}

		public int compareTo(Hit h){
			if(h.interval[0]==interval[0]) return h.interval[1]<interval[1] ? 1: h.interval[1]==interval[1] ? 0:-1;
			else return h.interval[0]<interval[0] ? 1:-1;
		}
	}
	
	public static boolean addTimesForAtom(ArrayList<Hit> a, double x, double y, double x0, double y0, 
			double vx, double vy,double maxy, double maxx, double wantedx){
		double time = 0.0;
		double[] intervals = new double[2];
		if(y0<y){
			if(vy==0.0) return false;
			time= vy>0 ? (y-y0)/vy: (y+y0)/(-vy);
			intervals[0]=2*(maxy-y)/vy;
			if(intervals[0]<0) intervals[0]=-intervals[0];
			intervals[1]=2*y/vy;
			if(intervals[1]<0) intervals[1]=-intervals[1];
		}
		else if(y0>y){
			if(vy==0.0) return false;
			time= vy>0 ? (2*maxy-y-y0)/vy: (y0-y)/(-vy);
			intervals[0]=2*y/vy;
			if(intervals[0]<0) intervals[0]=-intervals[0];
			intervals[1]=2*(maxy-y)/vy;
			if(intervals[1]<0) intervals[1]=-intervals[1];
		}
		else{
			if(vy==0) return true;
			intervals[0]=vy<0?2*y/(-vy):2*(maxy-y)/vy;
			intervals[1]= vy<0? 2*(maxy-y)/(-vy): 2*y/vy;
		}
		int i=0;
		while(time<maxtime){
			double xpos =x0 + vx*time;
			xpos-=(2*maxx*Math.floor((xpos/(2*maxx))));
			if(xpos>maxx) xpos=2*maxx-xpos;
			double to =time - Math.abs(x-xpos)/rayspeed;
			double from =time-wantedx;
			a.add(new Hit(from,to));
			time+=intervals[i%2];
			i++;
		}
		return false;
	}

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		NumberFormat nf = NumberFormat.getInstance();
		nf.setMinimumFractionDigits(5);
		nf.setMaximumFractionDigits(5);
		nf.setGroupingUsed(false);
		while(n!=0){
			String[] inp = in.readLine().split(" ");
			double x = Double.parseDouble(inp[0]);
			double wantedx = Math.max(x,xmax-x)/rayspeed;
			double y = Double.parseDouble(inp[1]);
			double wantedy = Math.max(y,ymax-y)/rayspeed;
			ArrayList<Hit> h = new ArrayList<Hit>();
			ArrayList<Hit> v = new ArrayList<Hit>();
			boolean fh=false;
			boolean fv=false;
			maxtime = 10000.0+2.0*Math.max(wantedx,wantedy);
			for(int i=0;i<n;i++){
				inp = in.readLine().split(" ");
				double x0 = Double.parseDouble(inp[0]);
				double y0 = Double.parseDouble(inp[1]);
				double vx = Double.parseDouble(inp[2]);
				double vy = Double.parseDouble(inp[3]);
				if(!fh) fh=addTimesForAtom(h,x,y,x0,y0,vx,vy,ymax,xmax,wantedx);
				if(!fv) fv=addTimesForAtom(v,y,x,y0,x0,vy,vx,xmax,ymax,wantedy);
			}
			Collections.sort(h);
			Collections.sort(v);
			double hf=Double.MAX_VALUE;
			if(!fh) hf = findFirst(wantedx,h);
			double lf = Double.MAX_VALUE;
			if(!fv) lf=findFirst(wantedy,v);
			if(hf<lf) System.out.println(nf.format(hf));
			else if(hf>lf) System.out.println(nf.format(lf));
			else if(hf==Double.MAX_VALUE) System.out.println("Never");
			else System.out.println(nf.format(hf));
			n = Integer.parseInt(in.readLine());
		}
	}

	public static double findFirst(double wanted,ArrayList<Hit> l){
		double currentmax=0.0;
		for(int i=0;i<l.size();i++){
			if(l.get(i).interval[0]>=currentmax) return currentmax<=10000.0? currentmax: Double.MAX_VALUE;
			if(l.get(i).interval[1]>currentmax) currentmax=l.get(i).interval[1];
		}
		return Double.MAX_VALUE;
	}
}
