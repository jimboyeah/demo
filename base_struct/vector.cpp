/*
 * https://leetcode.com/problems/self-crossing/
 * 335. Self Crossing
 * Total Accepted: 2337 Total Submissions: 13733 Difficulty: Medium
 * command: g++ -o vector vector.cpp && vector.exe

	You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

	Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
 */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Accepted
bool isSelfCrossing_(vector<int>& x) {
	int i, c = x.size();
	for(i=3;i<c;i++){
		int x0 = x.at(i);
		int x1 = x.at(i-1);
		int x2 = x.at(i-2);
		int x3 = x.at(i-3);
		int x4 = i>3? x.at(i-4):0;
		int x5 = i>4? x.at(i-5):0;
		if( !(x0-x2<0) && !(x1-x3>0) ) return true;
		if( i>3 && (x0+x4==x2 && x1+x5==x3) )  return true;
		if( i>4 && ( x1<=x3 && x0+x4>=x2 && x0>=x4 && x1+x5>=x3) ) return true;
	}
	return false;
}

//raw version 2016/3/8 14:01
bool isSelfCrossing(vector<int>& x) {
	int i, c = x.size();
	for(i=3;i<c;i++){
		int x1st = x.at(i-1);
		int x2nd = x.at(i-2);
		int x3rd = x.at(i-3);
		int x4th = i>3? x.at(i-4):0;
		int x5th = i>4? x.at(i-5):0;
		int o = x.at(i)-x2nd;
		int g = x1st-x3rd;
		bool fi = ( !(g>0) && !(o<0) );
		bool fe = i>3 && ( x.at(i)>=x4th && g+x5th<=0 );
		bool fs = i>3 && !(g>0) && x.at(i)>=x4th && (o+x4th>=0 && g+x5th>=0);
		if( fi || fe || fs ) return true;
	}
	return false;
}

void assert(int a[], int c, bool b, bool assert){
	int i;
	b==assert? system("color 0a"):system("color 6a");
	cout << (b!=assert? "Failure!":"OK!") << " {";
	for(i=0; i<c-1; i++) cout << a[i] << ",";
	cout << a[i] << "} " <<  (b? "Self crossing":"Pass") << endl;
}

void test(int d[], int c, bool key){
	//cout << "sizeof []:" << sizeof(d); // sizeof(int)
	vector<int> x(d, d+c);
	assert(d, c, isSelfCrossing(x), key);
}

int main(){

	int d[] = {1,1,2,1,1};
	int c = sizeof(d)/sizeof(int);
	vector<int> x(d, d+c);
	assert(d, c, isSelfCrossing(x), true);

	int d0[] = {1,1,2,2,1,1};
	test(d0, 6, true);

	int da[] = {1,2,2,2};
	test(da, 4, false);

	int db[] = {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1,};
	test(db, 8, false);
	test(db, 11, false);
	test(db, 12, false);
	test(db, 13, false);
	test(db, 17, false);

	int dc[] = {1,1,2,2,3,1,1};
	test(dc, 7, true);

	int dd[] = {2,2,3,1,1};
	test(dd, 4, false);

	int de[] = {1,1,3,2,1,1};
	test(de, 6, false);

	int d1[] = {1, 1, 1, 1};
	test(d1, 4, true);

	int d2[] = {1, 2, 3, 4};
	test(d2, 4, false);

	int d3[] = {2, 1, 1, 2};
	test(d3, 4, true);

	int d4[] = {9,8,6,4,2};
	test(d4, 5, false);

	int d5[] = {2,1,4,4,3,3,2,1,1};
	test(d5, 5, false);
	test(d5, 9, true);

	return 0;
}