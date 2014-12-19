import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;

public class B_Requirements {
	static final int MOD = 1000000007;
	static Vector<Integer> v, sums, bucket;
	static int n, t, npow;
	static long res;
	static BigInteger tpow;
	static final BigInteger mod = new BigInteger("1000000007");
	static final BigInteger mod2 = new BigInteger("1000000006");

	static void computeBucket(int i, int j, int pos) {
		if(j>=n) {
			//System.out.println(Integer.toBinaryString(new Integer(i)) + " " + Integer.toBinaryString(new Integer(pos)));
			bucket.set(i, (bucket.elementAt(i) + v.elementAt(pos)) % MOD);
		} else {
			if( (i & (1<<j)) == 0 )
				computeBucket(i, j+1, pos);
			else {
				computeBucket(i, j+1, pos);
				computeBucket(i, j+1, pos + (1<<j));
			}				
		}
	}

	static long solve(Scanner fin) {
		n = fin.nextInt();
		t = fin.nextInt();
		npow = 1<<n;
		v = new Vector<Integer>(n);
		sums = new Vector<Integer>(npow);
		bucket = new Vector<Integer>(npow);
		Integer sum = new Integer("0");
		for(int i=0; i<npow; i++) {
			int vi = fin.nextInt();
			v.add(vi);
			bucket.add(0);
			sum += vi;
		}
		System.out.println("v");

		tpow = new BigInteger("2");
		BigInteger tbig = new BigInteger(Integer.toString(t));
		tpow = tpow.modPow(tbig, mod2);

		//		// generate sums
		//		for(int b=0; b<npow; b++) {
		//			Integer sumb = 0;
		//			for(int i=0; i<npow; i++)
		//				if( (i|b)==b ) {
		//					sumb = (sumb + v.elementAt(i)) % (int)MOD;
		//				}
		//			sums.add(sumb);
		//		}

		// generate sum buckets
		System.out.println("npow " + npow);
		for(int i=0; i<npow; i++) {
			if( i%100000==0 ) System.out.println(i);
			computeBucket(i, 0, 0);
		}
		System.out.println("bucket");

		//System.out.println(sum + " " + tpow + " " + res);

		// inclusion-exclusion principle
		res = 0;
		for(int i=0; i<npow; i++) {
			int zero_count = 0;
			for(int j=1; j<npow; j*=2)
				if( (i & j)==0 ) zero_count++;

			BigInteger cur_bucket = new BigInteger(bucket.elementAt(i).toString());
			cur_bucket = cur_bucket.modPow(tpow, mod);
			if( (zero_count%2)==1 ) 	res = (res - cur_bucket.intValue() + MOD) % MOD;
			else 						res = (res + cur_bucket.intValue()) % MOD;
		}

		System.out.println(res);
		return res;
	}

	public static void main(String args[]) {
		try {
			for(int i=0; i<=10; i++) {
				String ins, outs;
				ins  = i + ".in";
				outs = i + ".out";		

				Scanner scanner = new Scanner(new File(ins));
				Scanner compare = new Scanner(new File(outs));

				long res = solve(scanner);
				long actual_res = compare.nextLong();
				if( res==actual_res)
					System.out.println("Test case: " + i + " Succes");
				else 
					System.out.println("Test case: " + i + " Failure");

				scanner.close();
				compare.close();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}
