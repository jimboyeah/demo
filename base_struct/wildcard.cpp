/*

44. Wildcard Matching

https://leetcode.com/problems/wildcard-matching/

Total Accepted: 52145 Total Submissions: 305251 Difficulty: Hard

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "*") → true
	isMatch("aa", "a*") → true
	isMatch("ab", "?*") → true
	isMatch("aab", "c*a*b") → false

compile: g++ -o wildcard wildcard.cpp && wildcard.exe
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

// Accepted
class Solution {
public:

	//dynamic programming
	bool isMatch_d0(string s, string p) {
		int i, j, k, m = s.length(), n = p.length(), msize = (m+1)*(n+1)*sizeof(bool);
		//bool (*matrix)[n+1] = (bool (*)[n+1])malloc( msize ); // NOT for VC++
		//if( matrix != memset( matrix, false, msize ) ) cout << "memset failed!\n";
		vector<vector<bool> >matrix(m+1, vector<bool>(n+1, false));

		//s="" p="" is true
		matrix[0][0] = true;

		//Handle cases like s="" p="****"
		for( i=1;i<=n;i++)
		{
			if(p[(i-1)] == '*')
				matrix[0][i] = true;
			else
				break;
		}

		for( i=1;i<=m;i++)
		{
			for( j=1;j<=n;j++)
			{
				char c = p[(j-1)];
				if(c != '*')
					matrix[i][j] = matrix[i-1][j-1] && (s[(i-1)] == c || c == '?');
				else
				{
					matrix[i][j] = matrix[i][j-1] || matrix[i-1][j];
				}
			}
		}
		return matrix[m][n];
	}

    bool isMatch_d1(string s, string p) {
        int i, j, sl = s.length(), pl = p.length();
        vector<bool> dp;

        dp.push_back(true);
        for(i=0; i<sl; i++) dp.push_back(false);

        for(i=0; i<pl; i++)
        {
			// char pc = p.at(i); not a good idea to redefine variable looping
            if(p.at(i) != '*')
            {
                for(j=0; j<sl; j++)
                    dp[sl-j] = dp[sl-j-1] && ( p.at(i)=='?' || s.at(sl-j-1)==p.at(i));
                dp[0] = 0;
            }
            else
            {
                for(j=0; j<sl; j++) dp[j+1] = dp[j+1] || dp[j] ;
            }
        }
        return dp[sl];
    }

	bool isMatch_d2(string s, string p) {
		int sL = s.length(), pL = p.length();

		//bool (*dp)[pL+1] = (bool (*)[pL+1]) malloc( (sL+1)*(pL+1)*sizeof(bool) );
		//for( int k=0; k<=sL; k++) dp[k][0] = false;
		vector< vector<bool> > dp(sL+1, vector<bool>(sL+1, false));

		dp[0][0] = true;
		for(int i=0; i<=sL; i++) {

			for(int j=1; j<=pL; j++) {
				char c = p[j-1];

				if(c != '*') {
					dp[i][j] = i>0 && dp[i-1][j-1] && (c=='?' || c==s[i-1]);
				} //else dp[i][j] = j==1 ||true;
				else for(int k=i; k>=0; k--) { if( dp[i][j] = dp[k][j-1] ) break;};
			}
		}

		return dp[sL][pL];
	}

    bool isMatch(string s, string p) {
		int k = 0, is = 0, ip = 0, ls = s.length(), lp = p.length();
		int *m = (int *)malloc(2 * lp * sizeof(int));
		unsigned short max_loop = -1, max_m = lp*2;
		bool sm = false; // Super Magic not Sadism & Masochism
		while(--max_loop){
			if( p[ip] == '*' ){
				if( k>= max_m ) cout << "max_m " << __FILE__ << __LINE__ << endl;
				m[k] = is;
				m[k+1] = ip;
				ip ++;
				k += 2;
				sm = true;
			}else if( ip<lp && ( p[ip]=='?' || is<ls && s[is]==p[ip] ) ){
				ip++;
				is++;
				sm = false;
			}else if( is<ls && sm ){
				is++;
			}else if( is==ls && ip==lp ){
				return true;
			}else if( is>ls || ip>lp ){
				return false;
			}else if( k>0 ){
				k -= 2;
				is = m[k] + 1;
				ip = m[k+1];
				sm = true;
			}else return false;
		}
		if(!max_loop) cout << "max_loop " << __FILE__ << __LINE__ << endl;
		return false;
	}

	// : Accepted 2016/3/11 17:37:05
    bool isMatch_N2(string s, string p) {
		int i=0,j=0,k=0,l=0, magic = -1, gl = 0, sl = s.length(), pl = p.length();
		int cl = 4, ml = pl*cl*sizeof(int);
		bool seq = false;
		char pc;

		int * g = (int *)malloc(ml);
		if( g!=memset(g, magic, ml) ) cout << "memset failed!\n";
		
		for(i=0; i<pl; i++){
			if( p[i]=='*' ) {
				if( gl>3 && g[gl-cl]==magic ) continue;
				//g[gl] = magic; set by memset
				gl += cl;
			}else{
				if(gl==0||g[gl-cl]==magic){
					g[gl]=i; g[gl+1] = 1; gl += cl;
				}else g[gl-3] ++;
			}
		}
		for(i=0; i<gl; i+=cl){
			if( g[i]==magic ) continue;
			for(j=k; j<sl; j++){
				if( !seq ) k = j;
				pc = p[g[i]+j-k];
				seq = s[j]==pc || pc=='?';
				if( seq && j-k+1<g[i+1]){
					continue;
				}else if( seq && j-k+1==g[i+1] ){
					seq = false;
					if( i>0 && g[i-cl]==magic && i+cl>=gl && k+g[i+1]<sl){
						j = k; continue;
					}
					g[i+2] = j; k = j+1; break;
				}else if( !seq ){
					if( j>=sl-1 || i<=0 || g[i-cl]!=magic ) return false;
					j = k;
				}else return false;
			}
			if( g[i+2]<0 ) return false;
			// the mase old one condition: i+cl<gl && k>=sl && ( i+8<gl || g[gl-cl]!=magic
		}

		if( sl==0 && gl>=8 ) return false; // for test: a, a*
		if( sl==0 && sl==pl ) return true;
		if( (g[0]==magic || g[0]==0) && (g[gl-cl]==magic || g[gl-2]+1==sl && g[gl-2]>=0) ) return true;
		return false;
	}
};

bool assert(Solution solve, string i, string p, bool a){
	unsigned long st = time(NULL) * CLOCKS_PER_SEC + clock();
	bool b = solve.isMatch(i, p);
	st = (time(NULL) * CLOCKS_PER_SEC + clock())-st;

	b==a? system("color 0a"):system("color 6a");
	cout << (b!=a? "Failed!":"    OK!") << "\t";
	cout << "elapse " << st << "ms\t";
	if(st>1000) cout << "time's up\t";
	cout << (i.length()>22? i.substr(0,18)+"...":i) << "\t";
	cout << (p.length()>22? p.substr(0,18)+"...":p) << "\t";
	cout <<  (b? "matched":"not matched") << endl;
	return b == a;
}

int main(){
	/* pointer to class member. Nothing much useful!
	typedef bool (Solution::*ToMatch)(string, string);
	Solution sol;
	ToMatch fun = &Solution::isMatch;
	bool b = (sol.*fun)("a","b");

	int a = 10, b = 10;
	int (*p)[10] = (int (*)[10])malloc(sizeof(int) * a * b);
    free(a);  
	*/
	
	Solution solve;
	assert(solve, "",     "",     true);
	assert(solve, "a",    "b",    false);
	assert(solve, "a",    "b*",   false);
	assert(solve, "a",    "*b",   false);
	assert(solve, "",     "*",    true);
	assert(solve, "",     "a*",   false);
	assert(solve, "",     "?",    false);
	assert(solve, "",     "**",   true); //what for this case
	assert(solve, "a",    "a*",   true); //leetcode say it is true!
	assert(solve, "aa",   "*",    true);
	assert(solve, "aa",   "*aa",  true);
	assert(solve, "ab",   "*a",   false);
	assert(solve, "aa",   "*a",   true);
	assert(solve, "a",    "*?*",  true);
	assert(solve, "a",    "?*?",  false);
	assert(solve, "a",    "*?*?",  false);
	assert(solve, "aa",   "?*?",  true);
	assert(solve, "a",    "**?**",true);
	assert(solve, "a",    "?",    true);
	assert(solve, "a",   "*a",    true);
	assert(solve, "aa",   "?",    false);
	assert(solve, "aa",   "a",    false);
	assert(solve, "aa",  "aa",    true);
	assert(solve, "aaa", "aa",    false);
	assert(solve, "aa",  "a*",    true);
	assert(solve, "a",   "ab*",   false);
	assert(solve, "aa",  "a**",   true);
	assert(solve, "abcd","abc*d", true);
	assert(solve, "aab", "a**b",  true);
	assert(solve, "aabb","a**b",  true);
	assert(solve, "ab",  "?*",    true);
	assert(solve, "aab", "c*a*b", false);
	assert(solve, "b",   "*?*?*", false);
	assert(solve, "aaab","b**",   false);
	assert(solve, "aabb","**??",  true);
	assert(solve, "abb", "**??",  true);

	assert(solve, "abcdefdefg",	       "abc*def",    false);  // Submission Result: Runtime Error
	assert(solve, "abcdefdef",	       "abc*def",    true);
	assert(solve, "ab*efcdgiescdfimde","ab*cd?i*de", true);
	assert(solve, "abefcdgiescdfimde", "ab*cd?i*de", true);
	assert(solve, "abecdgiscdfidecde", "ab*cd?i*de", true);
	assert(solve, "abcdgisdecdfideide","ab*cd?i*de", true);
	assert(solve, "abbbaaaaaaaabbbabaaabbabbbaabaabbbbaabaabbabaabbabbaabbbaabaabbabaabaabbbbaabbbaabaaababbbbabaaababbaaa", "ab**b*bb*ab**ab***b*abaa**b*a*aaa**bba*aa*a*abb*a*a", true);
	assert(solve, string(3072,'a'), string(1024,'a')+'*', true);
	return 0;
}