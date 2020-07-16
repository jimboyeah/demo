/******************************************************************************\
  Bitmap Demo by Jimbowhy
        Date: 2016/3/24 19:31:00
       Coder: editplus 3.70.164
       Maker: GNU Make 3.82 Built for i386-pc-mingw32
              Nmake Microsoft (R) Program Maintenance Utility 6.00.9782.0
    makefile: gnumakefile & makefile
    Compilrs: TDM-GCC 4.7.1, VC6, VC5
	   build: g++ -o bitmap bitmap.cpp -lgdi32 && bitmap MARIO16.bmp
              nmake BUILD=RELEASE bitmap && bitmap 7 1 2 3 4 res/mario16.bmp
              mingw32-make BUILD=RELEASE bitmap && bitmap res/mario16.bmp
\********************************************************************************/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <windows.h>

#pragma comment(lib, "user32.lib")

using namespace std;


#pragma pack(push,2)
typedef struct BitmapHeader {	// BITMAPFILEHEADER
	unsigned short	bfType;		// 0x4d42; it occupy 4bytes if memory aligned
	unsigned int	bfSize;		// DWORD  bitmap file size
	unsigned short	bfReserved1;
	unsigned short	bfReserved2;
	unsigned int	bfOffBits; // offset to the bitmap bits data
} BitmapHeader;

typedef struct BitmapInfo{		// BITMAPINFOHEADER
	unsigned int	biSize;		// DWORD the size of this structure.
			long	biWidth;	// LONG the width of the bitmap, in pixels.
			long	biHeight;
	unsigned short	biPlanes;	// WORD always is 1!
	unsigned short	biBitCount; // the number of bits-per-pixel. 1 for monochrome bmiColors
	unsigned int    biCompression; // BI_RGB(uncompressed)，BI_RLE8，BI_RLE4，BI_BITFIELDS, BI_JPEG/BI_PNG (Win9x/2k)
	unsigned int    biSizeImage;   // the size, in bytes, of the image. may be zero for BI_RGB.
			long	biXPelsPerMeter;
			long	biYPelsPerMeter;
	unsigned int    biClrUsed;
	unsigned int    biClrImportant;
} BitmapInfo, *PBitmapInfo;

typedef struct RGBA {			// RGBQUAD
  unsigned char     Blue;		// BYTE
  unsigned char     Green;
  unsigned char     Red;
  unsigned char     Alpha;
  RGBA() {};
  RGBA( int r, int g, int b, int a ) : Blue(b), Green(g), Red(r), Alpha(a) { };
} RGBA;

typedef struct BMP { // WARNING: Shadow copy in BMP!
	BitmapHeader		header;
	BitmapInfo			infos;
	RGBA				*palette;
	unsigned int		count;
	unsigned char		*data;
	BMP( ) : count(0), data(NULL) { }
	BMP( string &bin ) {
		int bhs = sizeof(BitmapHeader);
		int bis = sizeof(BitmapInfo);

		const char *pbh = bin.data();
		const char *pbi = pbh + bhs;
		memcpy( &header, pbh, bhs );
		memcpy( &infos, pbi, bis );

		int fsize = header.bfSize;
		int bsize = infos.biSize;
		int bpp = infos.biBitCount;
		int w = infos.biWidth, h = infos.biHeight;
		int pixels= w * h * bpp / 8;
		int offset = header.bfOffBits;
		int dl = bin.length();
		char msg[] = "Error, size(%d), biSize(%d), pixels@(%d), data(%d)\n";
		if( dl<fsize || (fsize - offset)<pixels)
			printf(msg, fsize, infos.biSize, offset, dl);
		int ic = offset - bsize - bhs;
		count  = ic/sizeof(RGBA);
		palette = (RGBA *)(bin.data() + bhs + bis);
		data = (unsigned char *)bin.data() + bhs + bis + ic;
	}
} BMP;
#pragma pack(pop)

void paletteInfo(RGBA *palette, int count)
{
	if( !count || !palette || count>256 ){
		printf( "Palette data error @%x count %d \n", palette, count);
		return;
	}
	cout << count;
	char hex[32];
	string ics;
	int ic = count * sizeof( RGBA );
	int bhs = sizeof(BitmapHeader);
	int bis = sizeof(BitmapInfo);
	for( int i=0; i<count; i++){
		RGBA c = palette[i];
		sprintf(hex, " #%02x [%2x,%2x,%2x,%2x]  ", i, c.Red, c.Green, c.Blue, c.Alpha);
		ics += hex;
	}
	cout<< " Index Colors Table:\n"
		<< "       palette size: " << ic				<< endl
		<< "   palette start at: " << bhs + bis		<< endl
		<< "     palette end at: " << bhs + bis + ic	<< endl
		<< "      colors number: " << count			<< endl
		<< ics << endl;
}

void bmpInfo(BMP &bmp){
	static string BIC[] ={"BI_RGB","BI_RLE8", "BI_RLE4 2", "BI_BITFIELDS", "BI_JPEG", "BI_PNG" };
	cout<< "Bitmap File Header:\n"
		<< "      bitmap type: " << string((char *)&bmp.header.bfType, 2) << endl
		<< " bitmap file size: " << bmp.header.bfSize			<< endl
		<< " offset to pixels: " << bmp.header.bfOffBits		<< endl
		<< endl;

	cout<< "Bitmap Information:\n"
		<< "      bitmap size: " << bmp.infos.biSize			<< endl
		<< "            width: " << bmp.infos.biWidth			<< endl
		<< "           height: " << bmp.infos.biHeight			<< endl
		<< "           planes: " << bmp.infos.biPlanes			<< endl
		<< "             bits: " << bmp.infos.biBitCount		<< endl
		<< "      compression: " << BIC[bmp.infos.biCompression]<< endl
		<< "       image size: " << bmp.infos.biSizeImage		<< endl
		<< "            X-PPM: " << bmp.infos.biXPelsPerMeter	<< endl
		<< "            Y-PPM: " << bmp.infos.biYPelsPerMeter	<< endl
		<< " index color used: " << bmp.infos.biClrUsed			<< endl
		<< "  important index: " << bmp.infos.biClrImportant	<< endl
		<< endl;
}

void dcInfo( HDC dc)
{
	static char dct[][64] = {
		"DT_PLOTTER","DT_RASDISPLAY","DT_RASPRINTER",
		"DT_RASCAMERA","DT_CHARSTREAM","DT_METAFILE","DT_DISPFILE"
	};
    static char dcr[][64] = {
        "RC_NONE",
        "RC_BITBLT", "RC_BANDING", "RC_SCALING", "RC_BITMAP64",
        "RC_GDI20_OUTPUT", "RC_GDI20_STATE", "RC_SAVEBITMAP", "RC_DI_BITMAP",
        "RC_PALETTE", "RC_DIBTODEV", "RC_BIGFONT", "RC_STRETCHBLT",
        "RC_FLOODFILL", "RC_STRETCHDIB", "RC_OP_DX_OUTPUT", "RC_DEVBITS"
    };
    int k = GetDeviceCaps( dc, RASTERCAPS);
    string rascaps;
    for(int i=0; i<16; i++) if(k>>i & 1) rascaps = rascaps + " " + dcr[i+1];
	cout << "Device Context Information:" << endl;
	cout << "   DRIVERVERSION:" << GetDeviceCaps( dc, DRIVERVERSION) << endl;
	cout << "      TECHNOLOGY:" << dct[GetDeviceCaps( dc, TECHNOLOGY)] << endl;
	cout << "        HORZSIZE:" << GetDeviceCaps( dc, HORZSIZE) << endl;
	cout << "        VERTSIZE:" << GetDeviceCaps( dc, VERTSIZE) << endl;
	cout << "         HORZRES:" << GetDeviceCaps( dc, HORZRES) << endl;
	cout << "         VERTRES:" << GetDeviceCaps( dc, VERTRES) << endl;
	cout << "      LOGPIXELSX:" << GetDeviceCaps( dc, LOGPIXELSX) << endl;
	cout << "      LOGPIXELSY:" << GetDeviceCaps( dc, LOGPIXELSY) << endl;
	cout << "       BITSPIXEL:" << GetDeviceCaps( dc, BITSPIXEL) << endl;
	cout << "      NUMBRUSHES:" << GetDeviceCaps( dc, NUMBRUSHES) << endl;
	cout << "         NUMPENS:" << GetDeviceCaps( dc, NUMPENS ) << endl;
	cout << "       NUMCOLORS:" << GetDeviceCaps( dc, NUMCOLORS ) << endl;
	cout << "     SIZEPALETTE:" << GetDeviceCaps( dc, SIZEPALETTE) << endl;
	cout << "     NUMRESERVED:" << GetDeviceCaps( dc, NUMRESERVED) << endl;
	cout << "        COLORRES:" << GetDeviceCaps( dc, COLORRES) << endl;
	cout << "      RASTERCAPS:" << rascaps << endl;
}

bool setPalette(BMP bmp, int index, RGBA color)
{
	if( bmp.infos.biBitCount>8 ){
		cout << "No palette for colorful bitmap with " << bmp.infos.biBitCount << "bpp" << endl;
		return false;
	}
	RGBA &co = bmp.palette[index];
	unsigned char *cs = (unsigned char*)&co;
	unsigned char *cd = (unsigned char*)&color;
	char text[128];
	char rx[] = "Hexadec #%03x RGBA[%03x,%03x,%03x,%03x] => [%03x,%03x,%03x,%03x]\n";
	char rd[] = "Decimal #%03d RGBA[%03d,%03d,%03d,%03d] => [%03d,%03d,%03d,%03d]\n";
	sprintf(text, rx, index, cs[2], cs[1], cs[0], cs[3], cd[2], cd[1], cd[0], cd[3]);
	cout << text;
	sprintf(text, rd, index, cs[2], cs[1], cs[0], cs[3], cd[2], cd[1], cd[0], cd[3]);
	cout << text;
	co = color;
	return true;
}

// expand bmp pixels what base 1/2/4/8bbp
// @return DIB base on 24bpp, allocate by malloc, if bbp set to below 8
BMP * expandDIB(BMP &b)
{
	int bpp = b.infos.biBitCount;
	if( !(bpp==1 || bpp==2 || bpp==4 || bpp==8) ){
		cout << "expandDIB work not for " << bpp << "bpp bitmap" << endl;
		return &b;
	}
	int k, o, x, y, w = b.infos.biWidth, h = b.infos.biHeight;
	int mask = 0xff>>(8-bpp), hsize = sizeof(BMP), psize = w * h * 3;
	int bsize = sizeof(BitmapHeader) + sizeof(BitmapInfo);

	void *mem = malloc(hsize + psize);
	memcpy( mem, &b, hsize );

    unsigned char* dat = (unsigned char*)mem;
	dat = dat+hsize;

	BMP &bmp = *(BMP*)mem;
	bmp.data = dat;
	bmp.count = 0;
	bmp.palette = NULL;
	bmp.infos.biSize = sizeof(BitmapInfo);
	bmp.infos.biSizeImage= psize;
	bmp.infos.biBitCount = 24;
	bmp.infos.biClrUsed  = 0;
	bmp.infos.biClrImportant = 0;
	bmp.header.bfOffBits = bsize;      // offset of .bmp header no for BMPw
	bmp.header.bfSize = bsize + psize; // pixel size of .bmp not BMP
    RGBA c;

    for( y=0; y<h; y++){
        for( x=0; x<w; x++){
            k = (x + y * w);
            k = b.data[k * bpp/8]>>(8-bpp-k * bpp%8) & mask;
            c = b.palette[k];
            *dat++ = c.Blue; // revert order BGRA
            *dat++ = c.Green;
            *dat++ = c.Red;
        }
    }
    return (BMP *)mem;
}

bool writeDibFile( string fp, BMP &b )
{
	ofstream fo( fp.data(), ios::binary | ios::out );
	if( !fo || fo.fail() ) return false;
	bool f = true;
	char *data = (char *)b.data;
	int hsize = sizeof(BitmapHeader);
	int isize = sizeof(BitmapInfo);
	f = f && fo.write( (char *)&b.header, hsize );
	f = f && fo.write( (char *)&b.infos,  isize );
	f = f && fo.write( data, b.infos.biSizeImage );
	if( !fo ) return false;
	char msg[] = "write DBI header: %d biSize: %d data:%d to %s \n";
	printf( msg, hsize + isize, b.infos.biSize, b.infos.biSizeImage, fp.data());
	fo.close();
	return true;
}


typedef HWND (WINAPI *GCW)();
HWND GetConsoleWin()
{
    HMODULE hKernel32 = GetModuleHandle("kernel32");
    GCW f = (GCW)GetProcAddress(hKernel32,"GetConsoleWindow");
    return f();
}

enum DRAW2SCREEN {
	D2S_TOPLEFT, D2S_TOPCENTER, D2S_TOPRIGHT,
	D2S_MIDDLEL, D2S_MIDDLEC, D2S_MIDDLER,
	D2S_BOTTOML, D2S_BOTTOMC, D2S_BOTTOMR
};

void drawRawData(BMP bmp){
	HDC sc =  GetDC( NULL );
	int sw = GetSystemMetrics(SM_CXSCREEN);
	int i, j, k, x = sw/2 - bmp.infos.biWidth/2;
	int h = bmp.infos.biHeight, w = bmp.infos.biWidth;
	int bpp = bmp.infos.biBitCount;
	int mask = 0xff>>(8-bpp);
	RGBA c;
	if(bpp>8){
		for( i=0; i<h; i++){      // rows
			for( j=0; j<w; j++){  // cols
				k = (i * w + j) * bpp / 8;
				c = RGBA(bmp.data[k+2],bmp.data[k+1],bmp.data[k],0);
				//c = *(int*)(&bmp.data[k*bpp/8]);
				SetPixel( sc, x+j, h-i, *(COLORREF*)&c);
			}
		}
	}else{
		for( i=0; i<h; i++){
			for( j=0; j<w; j++){
				k = (i*w+j);
				k = bmp.data[k*bpp/8]>>(8-bpp-k*bpp%8) & mask;
				c = bmp.palette[k];
				c.Red = c.Red ^ c.Blue;
				c.Blue= c.Red ^ c.Blue;
				c.Red = c.Red ^ c.Blue;
				SetPixel( sc, x+j, h-i, *(COLORREF*)&c);
			}
		}
	}
}

void draw2screen(BMP bmp, int pos=0)
{
	int sw = GetSystemMetrics(SM_CXSCREEN);
	int sh = GetSystemMetrics(SM_CYSCREEN);
	int w  = bmp.infos.biWidth;
	int h  = bmp.infos.biHeight;
	int m  = sh/2-h/2;
	int c  = sw/2-w/2;
	pos = pos % 9;
	int ps[] = { // [x,y, x,y...]
		0, 0,    c,0,    sw-w,0,
		0, m,    c,m,    sw-w,m,
		0, sh-h, c,sh-h, sw-w,sh-h
	};
	int x = ps[pos*2], y = ps[pos*2+1];

	HDC sc =  GetDC( NULL );
	HDC dc = CreateCompatibleDC(NULL);



	int size = bmp.count*sizeof(RGBA);
	void * mem = malloc(size+sizeof(LOGPALETTE));
	LOGPALETTE &pal = *(LOGPALETTE*)mem;
	pal.palVersion = 0x300; // win3x
	pal.palNumEntries = bmp.count;
	UINT pc = GetSystemPaletteEntries( sc,20,25, (PALETTEENTRY*)&pal.palPalEntry );
	printf("GetSystemPaletteEntries(%d) \n", pc);
	printf("(%d) \n", GetLastError());
	for( int i=0; i<pc; i++){
		printf(" #%02x [%2x,%2x,%2x]  ",i,
			(unsigned char)pal.palPalEntry[i].peRed,
			(unsigned char)pal.palPalEntry[i].peGreen,
			(unsigned char)pal.palPalEntry[i].peBlue);
		//pal.palPalEntry[i].peRed   = bmp.palette[i].Red;
		//pal.palPalEntry[i].peGreen = bmp.palette[i].Green;
		//pal.palPalEntry[i].peBlue  = bmp.palette[i].Blue;
	}

    HPALETTE palet = CreatePalette( &pal );
    HPALETTE opal = SelectPalette( dc,palet,true );
	if( !palet ) cout << "CreatePalette F!" << endl;
	if( !opal  ) cout << "SelectPalette F!" << endl;
	RealizePalette( dc );

	free(mem);
	SelectPalette( dc,opal,true );
	DeleteObject( palet );

	BMP &b = bmp; // *expandDIB(bmp);
	BITMAPINFO bmpi = *(BITMAPINFO*)&b.infos;
	BITMAPINFOHEADER bmpih = *(BITMAPINFOHEADER*)(&b.infos);
	HBITMAP bm = CreateDIBitmap( dc,&bmpih,CBM_INIT,b.data,&bmpi, DIB_PAL_COLORS);//
	//for( int i=0; i<256; i++) printf("%02x  ",((unsigned char*)&bm)[i] );
	//HBITMAP bm = CreateBitmap( w,h,1,b.infos.biBitCount,b.data );
	if( !bm ) cout << "CreateBitmap F!" << GetLastError();
	HGDIOBJ obm = SelectObject(dc,bm);
	HPEN hpen = CreatePen( PS_SOLID, 2, RGB(255, 0, 0) );
	HGDIOBJ open = SelectObject( dc, hpen );
	LineTo(  dc, w, h );
	MoveToEx(dc, w, 0, NULL );
	LineTo(  dc, 0, h );
	BitBlt( sc,x,y,w,h,dc,0,0,SRCCOPY );

	SelectObject( dc,obm);
	SelectObject( dc,open);
	DeleteObject( bm );
	DeleteDC(dc);

	/*char szText[128];
	GetConsoleTitle( szText,128 );
	TextOut(dc,20,20,szText,strlen(szText));
    BLENDFUNCTION bf = {0};
	bf.BlendOp = AC_SRC_OVER;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = 9;
	AlphaBlend(sc,0,0,sw,sh,dc,0,0,w,h,bf);*/
}

string readStream(string p){
	int len;
	char *buf;
	ifstream fi( p.data(), ios::binary|ifstream::in );
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

bool writeStream(string p, string d)
{
	ofstream fo( p.data(), ios::binary|ios::out );
	if( !fo || fo.fail() ) return false;
	bool f = fo.write(d.data(), d.length());
	if( !fo ) return false;
	fo.close();
	return true;
}

int main(int argc, char *args[] ){

	unsigned int id, r, g, b, a;
	bool f = false;
	BMP bmp, *dib;

	stringstream s(stringstream::in | stringstream::out);
	string fp, fs;

	switch(argc){
	case 2:
		fp = string(args[1]);
		fs = readStream(fp);
		cout << fp << " check length: " << fs.length();
		if( !(fs.length()) )return 1;
		bmp = BMP(fs);
		bmpInfo(bmp);
		paletteInfo( bmp.palette, bmp.count );
		break;
	case 7:
		s << args[1] <<" "<< args[2] <<" "<< args[3] <<" "<< args[4] <<" "<< args[5];
		s >> id >> r >> g >> b >> a;
		if( id<0 || id>256) return 1;
		fp = string(args[6]);
		fs = readStream(fp);
		cout << fp << " check length: " << fs.length() << endl;
		if( !(fs.length()) ) return 1;
		bmp = BMP(fs); // shadow copy data in BMP!
		drawRawData(bmp);
		//dib = expandDIB(bmp);
		//writeDibFile(fp+".dib",*dib );
		f = setPalette( bmp,id,RGBA(r,g,b,a) );
		draw2screen(bmp,D2S_TOPRIGHT);
		if( f ){
			f = writeStream( fp, fs );
			!f && cout << "Fail to write data to file " << fp << endl;
		}
		break;
	default:
		cout << "Usage of bitmap.exe:" << endl;
		cout << "	Show bmp infos: bitmap path/to/file.bmp" << endl;
		cout << "	Set color in palette: bitmap #ID #R #G #B #alpha file.bmp" << endl;
		cout << "Demo: " << endl;
		cout << "	bitmap res/mario16.bmp" << endl;
		cout << "	bitmap 7 117 224 80 128 res/mario16.bmp" << endl;
		cout << "	bitmap 226 64 128 192 0 res/mario256.bmp" << endl;
	}
	return 0;

}

