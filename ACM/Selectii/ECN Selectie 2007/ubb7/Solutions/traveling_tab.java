/* Sample solution for NCPC 2006: Traveling Salesman
 * Author: Truls A. Bjoerklund
 *
 * The solution hashes borders of all countries. It is possible
 * to go from one country to another if they have a border in common.
 * Then, the solution just uses a bfs-search.
 */

import java.io.*;
import java.text.*;
import java.util.*;

public class traveling_tab {
	
	private static class Edge implements Comparable<Edge>{
		public int[] p1,p2;
		public Edge(int[] p1, int[] p2){
			boolean so = true;
			for(int i=0;i<3;i++){
				if(p1[i]<p2[i]) break;
				if(p2[i]<p1[i]){
					so=false;
					break;
				}
			}
			if(so){
				this.p1=p1;
				this.p2=p2;
			}
			else{
				this.p1=p2;
				this.p2=p1;
			}
		}

		public int compareTo(Edge e){
			for(int i=0;i<3;i++) if(e.p1[i]!=p1[i]) return p1[i]-e.p1[i];
			for(int i=0;i<3;i++) if(e.p2[i]!=p2[i]) return p2[i]-e.p2[i];
			return 0;
		}

		public boolean equals(Object o){
			Edge e = (Edge)o;
			if(compareTo(e)==0) return true;
			else return false;
		}

		public int hashCode(){
			return p1[0]*p1[1]*p1[2]+p1[0]*p1[1]+p1[1]*p1[2]+p1[0]*p1[2]+p1[0]+p1[1]+p1[2]+p2[0]*p2[1]*p2[2]+p2[0]*p2[1]+p2[1]*p2[2]+p2[0]*p2[2]+p2[0]+p2[1]+p2[2];
		}
	}

	public static int bfs(ArrayList<ArrayList<Integer>> a, int f, int t){
		if(f==t) return 0;
		ArrayList<Integer> q = new ArrayList<Integer>();
		int[] v = new int[a.size()];
		for(int i=0;i<v.length;i++)v[i]=-1;
		int i = -1;
		q.add(f);
		v[f]=0;
		while(++i<q.size()){
			int d = v[q.get(i)]+1;
			for(int j=0;j<a.get(q.get(i)).size();j++){
				if(v[a.get(q.get(i)).get(j)]==-1){
					if(a.get(q.get(i)).get(j) ==t) return d;
					q.add(a.get(q.get(i)).get(j));
					v[a.get(q.get(i)).get(j)]=d;
				}
			}
		}
		return -1;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int c = Integer.parseInt(in.readLine());
		while(c!=0){
			HashMap<Edge,Integer> h = new HashMap<Edge,Integer>();
			ArrayList<ArrayList<Integer>> n = new ArrayList<ArrayList<Integer>>();
			for(int i=0;i<c;i++){
				n.add(new ArrayList<Integer>());
				StringTokenizer st = new StringTokenizer(in.readLine());
				int e = Integer.parseInt(st.nextToken());
				if(e>0){
					int[] last = new int[3];
					int[] first = last;
					for(int j=0;j<3;j++) last[j]=Integer.parseInt(st.nextToken());
					for(int j=1;j<e;j++){
						int[] next = new int[3];
						for(int t=0;t<3;t++) next[t]=Integer.parseInt(st.nextToken());
						Edge ed = new Edge(last,next);
						if(h.containsKey(ed)){
							n.get(i).add(h.get(ed));
							n.get(h.get(ed)).add(i);
						}
						else h.put(ed,i);
						last=next;
					}
					Edge ed = new Edge(last,first);
					if(h.containsKey(ed)){
						 n.get(i).add(h.get(ed));
						 n.get(h.get(ed)).add(i);
					}
					else h.put(ed,i);
				}
			}
			int m = Integer.parseInt(in.readLine());
			for(int i=0;i<m;i++){
				String[] inp = in.readLine().split(" ");
				int fr = Integer.parseInt(inp[0])-1;
				int to = Integer.parseInt(inp[1])-1;
				System.out.println(bfs(n,fr,to));
			}
			c = Integer.parseInt(in.readLine());
		}
	}
}
