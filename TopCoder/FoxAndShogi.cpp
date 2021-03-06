#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MOD = 1000000007;

class FoxAndShogi {
public:
	int differentOutcomes(vector <string> board) {
		int N = board.size();
		long long ret = 0LL;
		for (int j=0;j<N;j++){
            string s = "";
            for (int i=0;i<N;i++)
                s+=board[i][j];
            //printf("%d: %s\n",j,s.c_str());
            int confs = 0;
            queue<string> q;
            set<string> st;
            q.push(s);
            while(!q.empty()){
                string s1 = q.front();q.pop();
                if (st.count(s1)>0)
                    continue;
                //printf("%d: %s\n",confs,s1.c_str());
                st.insert(s1);
                confs++;
                for (int i=0;i<N;i++){
                    if (s1[i]=='D'){
                        if (i+1<N&&s1[i+1]=='.'){
                            s1[i]='.';
                            s1[i+1]='D';
                            q.push(s1);
                            s1[i]='D';
                            s1[i+1]='.';
                        }
                    }
                    else if (s1[i]=='U'){
                        if (i-1>=0&&s1[i-1]=='.'){
                            s1[i]='.';
                            s1[i-1]='U';
                            q.push(s1);
                            s1[i]='U';
                            s1[i-1]='.';
                        }
                    }
                }
            }
            //printf("%d\n",confs);
            if (ret==0)
                ret = confs;
            else ret = ((ret%MOD)*(confs%MOD))%MOD;
		}
		return ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	FoxAndShogi *obj;
	int answer;
	obj = new FoxAndShogi();
	clock_t startTime = clock();
	answer = obj->differentOutcomes(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <string> p0;
	int p1;

	{
	// ----- test 0 -----
	string t0[] = {".D.","...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {".D.","...",".U."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"DDDDD",".....",".....",".....","....."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3125;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"DDDDD","U....",".U...","..U..","...U."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 900;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"....D..","U....D.","D.D.U.D","U.U...D","....U..","D.U...D","U.U...."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2268;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	string t0[] = {"DDDDDDDDDD","..........","..........","..........","..........","..........","..........","..........","..........",".........."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 999999937;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	string t0[] = {"..",".."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
