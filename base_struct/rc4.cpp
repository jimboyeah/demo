/*
	RC4 by Ron Rivest 

	In 1987, Ron Rivest developed the RC4 cipher-system for RSA Data Security, Inc. The code is extremely simple and can be written by most programmers from the description:

	We have an array of 256 bytes, all different. Every time the array is used it changes by swapping two bytes. The swaps are controlled by counters i and j, each initially 0. To get a new i, add 1. To get a new j, add the array byte at the new i. Exchange the array bytes at i and j. The code is the array byte at the sum of the array bytes at i and j. This is XORed with a byte of the plaintext to encrypt, or the ciphertext to decrypt. The array is initialized by first setting it to 0 through 255. Then step through it using i and j, getting the new j by adding to it the array byte at i and a key byte, and swapping the array bytes at i and j. Finally, i and j are set to 0. All additions are modulo 256.

	C code by Jimbowhy 2016/3/14 04:47:30
	Compile: g++ -o rc4 rc4.cpp && rc4
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <tchar.h>

using namespace std;

char * toHexMap(bool lowercase = false){
	char * m = (char *)malloc(16);
	int i = 0; // 0 0x30 A 0x41 a 0x61
	for(; i<10; i++ ) m[i] = ('0' + i);
	for(; i<16; i++ ) m[i] = ((lowercase? 'a':'A') + i-10);
	return m;
}

string toHex(string p, bool lowercase = true){
	int i = 0, k = 0, l = p.length();

	unsigned char *pu = (unsigned char *)p.data();
	string h(l*5+1,' '); //(char *)malloc(l*5+1);

	static char *hexMap_lower = toHexMap(true);
	static char *hexMap_upper = toHexMap(false);
	char *m = lowercase? hexMap_lower:hexMap_upper;

	for(i=0; i<l; i++){
		h[k++] = '0';
		h[k++] = 'x';
		h[k++] = m[pu[i]/16];
		h[k++] = m[pu[i]%16];
		h[k++] = ' ';
	}
	return h;
}

/*
 * RC4 encryption
 * @key : password whin 256 bytes
 * @p   : plaintext/chipher to encrypt/decrypt, MODIFIED
 */
string RC4(string key, string &p){
	unsigned int k = 0, lp = p.length(), mod = 256, lk = key.length();
	unsigned char *sbox = (unsigned char *)malloc(mod);
	unsigned char i = 0, j = 0;

	if(lk==0) return NULL;
	lk = lk>256? 256:lk;

	for(i=0; i<mod; i++){
		sbox[i] = i;
		if(i==255) break;
	}

	for(i=0; i<mod; i++){
		j += key[i%lk] + sbox[i];
		sbox[i] = sbox[i] ^ sbox[j]; // a = a + b
		sbox[j] = sbox[i] ^ sbox[j]; // b = a - b
		sbox[i] = sbox[i] ^ sbox[j]; // a = a - b

		if(i==255) break;
	}

	i = j = k = 0;
	while(k<lp){
		j += sbox[++i]; /*
		sbox[i] = sbox[i] ^ sbox[j];
		sbox[j] = sbox[i] ^ sbox[j];
		sbox[i] = sbox[i] ^ sbox[j];
		*/
		p[k] = p[k] ^ sbox[(sbox[i] + sbox[j]) % mod];
		k++;
	}
	delete sbox;
	return p;
}

void putStream(string p, string d){
	ofstream fo( p.data(), ios::binary|ios::out );
	fo.write( d.data(), d.length() );
	fo.close();
}
string getStream(string p){
	int len;
	char *buf; 
	ifstream fi( p.data(), ios::binary|ifstream::in );
	//fi.open( p.data(), ios::binary|ios::in );
	if( !fi.is_open() || fi.fail() ) return string();
	fi.seekg( 0,ios::end );
	len = fi.tellg();
	fi.seekg( 0,ios::beg );

	buf = new char[len];
	fi.read ( buf,len );

	fi.close();
	string *r = new string(buf, len);
	delete buf;
	return *r;
}

int main(int argc, char *args[]){
	if(argc==3){
		string fp(args[2]);
		string fk = getStream(args[1]);
		string fs = getStream(fp);
		if( !(fs.length() && fk.length()) ){
			cout << "check key length: " << fk.length() << " data length: " << fs.length();
			return 1;
		}
		putStream( fp+".log",fs );
		RC4(fk, fs);
		putStream( fp,fs );
		cout << "\"file encrypted, length:" << fs.length() << "\"";
		return 0;
	}

	char k[] = {0x61, 0x8A, 0x63, 0xD2, 0xFB};
	char p[] = {0x2C, 0xF9, 0x4C, 0xEE, 0xDC};
	string ps(p, sizeof(p));
	string ks(k, sizeof(k));
	cout << "plaintext to encrypt: " << toHex(ps) << endl;
	cout << "          key to hex: " << toHex(ks) << endl;
	cout << "   ciphertext to hex: " << toHex( RC4(ks, ps) ) << endl;
	cout << "    decrypted to hex: " << toHex( RC4(ks, ps) ) << endl << endl;

	string T1key("1234");
	string T1txt("We have an array of 256 bytes, all different!");
	cout << "plaintext to encrypt: " << toHex(T1txt) << endl;
	cout << "          key to hex: " << toHex(T1key) << endl;
	cout << "   ciphertext to hex: " << toHex( RC4(T1key, T1txt) ) << endl;
	cout << "    decrypted to hex: " << toHex( RC4(T1key, T1txt) ) << endl << endl;
	T1key = "1234567890";
	cout << "          key to hex: " << toHex(T1key) << endl;
	cout << "   ciphertext to hex: " << toHex( RC4(T1key, T1txt) ) << endl;
	cout << "    decrypted to hex: " << toHex( RC4(T1key, T1txt) ) << endl << endl;

	string T2key("abcdefg");
	string T2txt = _TEXT("RC4于1987年提出，和DES算法一样，是一种对称加密算法。"); /* 0xE2 0x80 0xA2 NOT for VC6 */

	cout << "plaintext to encrypt: " << toHex(T2txt) << endl;
	cout << "          key to hex: " << toHex(T2key) << endl;
	cout << "   ciphertext to hex: " << toHex( RC4(T2key, T2txt) ) << endl;
	cout << "    decrypted to hex: " << toHex( RC4(T2key, T2txt) ) << endl << endl;
	T2key = "对称加密算法";
	cout << "          key to hex: " << toHex(T2key) << endl << endl;
	cout << "   ciphertext to hex: " << toHex( RC4(T2key, T2txt) ) << endl;
	cout << "    decrypted to hex: " << toHex( RC4(T2key, T2txt) ) << endl << endl;
	return 0;
}
