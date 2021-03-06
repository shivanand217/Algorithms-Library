import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class TheArithmeticProgression
{
	
		public double minimumChange(int a, int b, int c)
	{
		double num = ((c-a)/2.0)+a, ans1 = b>num?b-num:num-b;
			//	if (num<0||(c-a)<0)
			//ans1 = 100000000;
		double n2 = b-(c-b), ans2 = a>n2?a-n2:n2-a;
		//if (n2<0||(c-b)<0)
		//	ans2 = 100000000;
		double n3 = b+(b-a), ans3 = c>n3?c-n3:n3-c;
		//		if (n3<0||(b-a)<0)
		//	ans3 = 100000000;
		System.out.println(ans1+" "+ans2+" "+ans3);
		return Math.min(ans1, Math.min(ans2, ans3));
	}
	
	
	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	private static boolean KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, boolean hasAnswer, double p3) {
		System.out.print("Test " + testNum + ": [" + p0 + "," + p1 + "," + p2);
		System.out.println("]");
		TheArithmeticProgression obj;
		double answer;
		obj = new TheArithmeticProgression();
		long startTime = System.currentTimeMillis();
		answer = obj.minimumChange(p0, p1, p2);
		long endTime = System.currentTimeMillis();
		boolean res;
		res = true;
		System.out.println("Time: " + (endTime - startTime) / 1000.0 + " seconds");
		if (hasAnswer) {
			System.out.println("Desired answer:");
			System.out.println("\t" + p3);
		}
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		if (hasAnswer) {
			res = Math.abs(p3 - answer) <= 1e-9 * Math.max(1.0, Math.abs(p3));
		}
		if (!res) {
			System.out.println("DOESN'T MATCH!!!!");
		} else if ((endTime - startTime) / 1000.0 >= 2) {
			System.out.println("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			System.out.println("Match :-)");
		} else {
			System.out.println("OK, but is it right?");
		}
		System.out.println("");
		return res;
	}
	public static void main(String[] args) {
		boolean all_right;
		all_right = true;
		
		int p0;
		int p1;
		int p2;
		double p3;
		
		// ----- test 0 -----
		p0 = 0;
		p1 = 1;
		p2 = 2;
		p3 = 0.0D;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = 0;
		p1 = 2;
		p2 = 1;
		p3 = 1.5D;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = 3;
		p1 = 2;
		p2 = 1;
		p3 = 0.0D;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		// ----- test 3 -----
		p0 = 4;
		p1 = 4;
		p2 = 8;
		p3 = 2.0D;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
		// ------------------
		
		if (all_right) {
			System.out.println("You're a stud (at least on the example cases)!");
		} else {
			System.out.println("Some of the test cases had errors.");
		}
	}
	// END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
