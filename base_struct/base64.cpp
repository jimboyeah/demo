/*
	Base64 by Jimbowhy NOT A STANDARD VERSION
	map:0:0			map:1:1			map:2:2			map:3:3			map:4:4 
	map:5:5			map:6:6			map:7:7			map:8:8			map:9:9
	map:A:10        map:B:11        map:C:12        map:D:13        map:E:14
	map:F:15        map:G:16        map:H:17        map:I:18        map:J:19
	map:K:20        map:L:21        map:M:22        map:N:23        map:O:24
	map:P:25        map:Q:26        map:R:27        map:S:28        map:T:29
	map:U:30        map:V:31        map:W:32        map:X:33        map:Y:34
	map:Z:35        map:[:36        map:b:37        map:c:38        map:d:39
	map:e:40        map:f:41        map:g:42        map:h:43        map:i:44
	map:j:45        map:k:46        map:l:47        map:m:48        map:n:49
	map:o:50        map:p:51        map:q:52        map:r:53        map:s:54
	map:t:55        map:u:56        map:v:57        map:w:58        map:x:59
	map:y:60        map:z:61        map:+:62        map:-:63
	encode
	0x77 0x76 0x75 => 0b01110111 0b01110110 0b01110101
				   => 0b  110111   011001  010111   011101

	RFC2045～RFC2049 different
	map:A:0			map:B:1			map:C:2			map:D:3			map:E:4 
	map:F:5			map:G:6			map:H:7			map:I:8			map:J:9
	map:K:10        map:L:11        map:M:12        map:N:13        map:O:14
	map:P:15        map:Q:16        map:R:17        map:S:18        map:T:19
	map:U:20        map:V:21        map:W:22        map:X:23        map:Y:24
	map:Z:25        map:a:26        map:b:27        map:c:28        map:d:29
	map:e:30        map:f:31        map:g:32        map:h:33        map:i:34
	map:j:35        map:k:36        map:l:37        map:m:38        map:n:39
	map:o:40        map:p:41        map:q:42        map:r:43        map:s:44
	map:t:45        map:u:46        map:v:47        map:w:48        map:x:49
	map:y:50        map:z:51        map:0:52        map:1:53        map:2:54
	map:3:55        map:4:56        map:5:57        map:6:58        map:7:59
	map:8:60        map:9:61        map:+:62        map:/:63
	the difference:
	0x77 0x76 0x75 => 0b01110111 0b01110110 0b01110101
				   => 0b011101 110111  011001   110101

	C code by Jimbowhy 2016/3/14 04:47:30
	Compile: g++ -o base64 base64.cpp && base64
*/

#include <cstdlib>
#include <cstring>
#include <cstdio>

char * Base64map(){
	char * m = (char *)malloc(64);
	for(int i=0; i<26; i++ ){
		if( i<=9 ) m[i] = '0' + i;
		m[i+10] = 'A' + i;
		m[i+36] = 'a' + i;
	}
	m[62] = '+';
	m[63] = '-';
	return m;
}

char * Base64map_std(){
	char * m = (char *)malloc(64);
	for(int i=0; i<26; i++ ){
		if( i>15 ) m[i+36] = '0' + (i - 16);
		m[i] = 'A' + i;
		m[i+26] = 'a' + i;
	}
	m[62] = '+';
	m[63] = '/';
	return m;
}

char * Base64rev(){
	char *m = Base64map();
	char *d = new char[128];
	for(int i=0; i<64; i++){
		d[m[i]] = i;
	}
	return d;
}

char * Base64enc(char *p){
	int size = strlen(p);
	int i = 0, k = 0, t = size % 3;
	int s = 4 * (size/3) + (t>0? 4:1), max_loop = size / 3;
	char *map = Base64map(), *code = (char *)malloc( s );
	unsigned char * pu = (unsigned char *)p;

	while(max_loop--){
		code[k  ] = map[ pu[i  ]&0x3f ];
		code[k+1] = map[ pu[i  ]>>6 | (pu[i+1]&0x0f)<<2 ];
		code[k+2] = map[ pu[i+1]>>4 | (pu[i+2]&0x03)<<4 ];
		code[k+3] = map[ pu[i+2]>>2 ];
		//printf(" %d %d %d %d %d \n", i,pu[i],pu[i+1], pu[i+2], pu[i+3]);
		k += 4;
		i += 3;
	}
	if( t == 1 ){
		code[k  ] = map[ pu[i  ]&0x3f ];
		code[k+1] = map[ pu[i  ]>>6   ];
		code[k+2] = 0;
		code[k+3] = 0;
	}else if( t == 2 ){
		code[k  ] = map[ pu[i  ]&0x3f ];
		code[k+1] = map[ pu[i  ]>>6 | (pu[i+1]&0x0f)<<2 ];
		code[k+2] = map[ pu[i+1]>>4 ];
		code[k+3] = 0;
	}else code[k] = 0;

	return code;
}

char * Base64dec(char *p){
	int size = strlen(p);
	int i = 0, k = 0, t = size % 4;
	int s = 3 * (size/4) + t, max_loop = size / 4;
	char *map = Base64rev(), *code = (char *)malloc( s );
	unsigned char * pu = (unsigned char *)p;

	while(max_loop--){
		pu[i  ] = map[pu[i  ]];
		pu[i+1] = map[pu[i+1]];
		pu[i+2] = map[pu[i+2]];
		pu[i+3] = map[pu[i+3]];
		code[k  ] = (pu[i+1]&0x03)<<6 | pu[i];
		code[k+1] = (pu[i+1]&0xfc)>>2 |(pu[i+2]&0x0f)<<4;
		code[k+2] = (pu[i+2]&0x30)>>4 |(pu[i+3]&0x3f)<<2;
		k += 3;
		i += 4;
	}
	if( t == 3 ){
		pu[i  ] = map[pu[i  ]];
		pu[i+1] = map[pu[i+1]];
		pu[i+2] = map[pu[i+2]];
		code[k  ] = (pu[i+1]&0x03)<<6 | pu[i];
		code[k+1] = (pu[i+1]&0x3f)>>2 |(pu[i+2]&0x0f)<<4;
		code[k+2] = 0;
	}else if( t == 2 ){
		pu[i  ] = map[pu[i  ]];
		pu[i+1] = map[pu[i+1]];
		code[k  ] = (pu[i+1]&0x03)<<6 | pu[i];
		code[k+1] = 0;
	}else code[k] = 0;

	return code;
}


int main(){
	char k[] = "any thing even binary!"; //YW55JTIwdGhpbmclMjBldmVuJTIwYmluYXJ5JTIx
	char o[] = "Base64dec(Base64enc(o))";

	printf( "==================TEST==================\n" );
	printf( "plaintext: %s \n", k );
	printf( "Base64: %s \n",  Base64enc(k) );
	printf( "Decoded: %s \n", Base64dec(Base64enc(k)) );
	printf( "==================TEST==================\n" );
	printf( "plaintext: %s \n", o );
	printf( "Base64: %s \n",  Base64enc(o) );
	printf( "Decoded: %s \n", Base64dec(Base64enc(o)) );

	char m[128];
	for(int i=0; i<128; i++)  m[i] = i+1;
	printf( "Base64 Test 0x01~0x7f: %s \n", Base64enc(m) );

	return 0;
}
