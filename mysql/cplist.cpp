/*
 *******************************************************************************
 *
 *   Copyright (C) 2000, International Business Machines
 *   Corporation and others.  All Rights Reserved.
 *
 *******************************************************************************
 *
 *  Modification History:
 *
 *   Date        Name        Description
 *   03/08/2000  helena      Created.
 *   01/08/2001  grhoten     Try to differentiate between MBCS and DBCS
 */


const char *getCPName(UINT cpID) {
    switch (cpID) {
    case 37:   return "EBCDIC US/Canada";
    case 437:  return "OEM MS-DOS United States";
    case 500:  return "EBCDIC \"500V1\" (International)";
    case 708:  return "OEM Arabic (ASMO 708)";
    case 709:  return "OEM Arabic (ASMO 449+, BCON V4)";
    case 710:  return "OEM Arabic (Transparent Arabic)";
    case 720:  return "OEM Arabic (Transparent ASMO)";
    case 737:  return "OEM Greek (formerly 437G)";
    case 775:  return "OEM Baltic";
    case 850:  return "OEM MS-DOS Multilingual (Latin I)";
    case 852:  return "OEM MS-DOS Slavic (Latin II)";
    case 855:  return "OEM IBM Cyrillic (primarily Russian)";
    case 857:  return "OEM IBM Turkish";
    case 858:  return "OEM Multilingual Latin 1 + Euro";
    case 860:  return "OEM MS-DOS Portuguese";
    case 861:  return "OEM MS-DOS Icelandic";
    case 862:  return "OEM Hebrew";
    case 863:  return "OEM MS-DOS Canadian-French";
    case 864:  return "OEM Arabic";
    case 865:  return "OEM MS-DOS Nordic";
    case 866:  return "OEM MS-DOS Russian (former USSR)";
    case 869:  return "OEM IBM Modern Greek";
    case 870:  return "IBM EBCDIC - Multilingual/ROECE (Latin-2)";
    case 874:  return "ANSI/OEM Thai";
    case 875:  return "EBCDIC";
    case 932:  return "Shift-JIS, (ANSI/OEM Japan)";
    case 936:  return "GBK (ANSI/OEM Chinese (PRC, Singapore))";
    case 949:  return "ks_c_5601-1987 (ANSI/OEM Korean)";
    case 950:  return "Big5 (ANSI/OEM Chinese (Taiwan Region; Hong Kong SAR, PRC))";
    case 1026: return "EBCDIC Turkish/Latin-5";
    case 1047: return "EBCDIC Latin-1/Open System";
    case 1140: return "EBCDIC US/Canada (cp37 + Euro)";
    case 1141: return "EBCDIC Germany (cp20273 + Euro)";
    case 1142: return "EBCDIC Denmark/Norway (cp20277 + Euro)";
    case 1143: return "EBCDIC Finland/Sweden (cp20278 + Euro)";
    case 1144: return "EBCDIC Italy (cp20280 + Euro)";
    case 1145: return "EBCDIC Latin America/Spain (cp20284 + Euro)";
    case 1146: return "EBCDIC United Kingdom (cp20285 + Euro)";
    case 1147: return "EBCDIC France (cp20297 + Euro)";
    case 1148: return "EBCDIC International (cp500 + Euro)";
    case 1149: return "EBCDIC Icelandic (cp20871 + Euro)";
    case 1200: return "ANSI Unicode (BMP of ISO 10646)";
    case 1250: return "ANSI Windows 3.1 Eastern European"; 
    case 1251: return "ANSI Windows 3.1 Cyrillic";
    case 1252: return "ANSI Windows 3.1 Latin 1 (US, Western Europe)";
    case 1253: return "ANSI Windows 3.1 Greek";
    case 1254: return "ANSI Windows 3.1 Turkish";
    case 1255: return "ANSI Hebrew";
    case 1256: return "ANSI Arabic";
    case 1257: return "ANSI Baltic";
    case 1258: return "ANSI/OEM Vietnamese";
    case 1361: return "Johab (OEM Korean)";
    case 10000: return "Macintosh Roman";
    case 10001: return "Macintosh Japanese";
    case 10002: return "Big5 (Macintosh Traditional Chinese)";
    case 10003: return "Macintosh Korean";
    case 10004: return "Macintosh Arabic";
    case 10005: return "Macintosh Hebrew";
    case 10006: return "Macintosh Greek I";
    case 10007: return "Macintosh Cyrillic";
    case 10008: return "GB 2312 (Macintosh Simplified Chinese)";
    case 10010: return "Macintosh Romania";
    case 10017: return "Macintosh Ukraine";
    case 10021: return "Macintosh Thai";
    case 10029: return "Macintosh Latin 2";
    case 10079: return "Macintosh Icelandic";
    case 10081: return "Macintosh Turkish";
    case 10082: return "Macintosh Croatia";
    case 20000: return "CNS - Taiwan";
    case 20001: return "TCA - Taiwan";
    case 20002: return "Eten - Taiwan";
    case 20003: return "IBM5550 - Taiwan";
    case 20004: return "TeleText - Taiwan";
    case 20005: return "Wang - Taiwan";
    case 20105: return "IA5 IRV International Alphabet #5";
    case 20106: return "IA5 German";
    case 20107: return "IA5 Swedish";
    case 20108: return "IA5 Norwegian";
    case 20127: return "US-ASCII";
    case 20261: return "T.61";
    case 20269: return "ISO 6937 Non-Spacing Accent";
    case 20273: return "IBM EBCDIC - Germany";
    case 20277: return "IBM EBCDIC - Denmark/Norway";
    case 20278: return "IBM EBCDIC - Finland/Sweden";
    case 20280: return "IBM EBCDIC - Italy";
    case 20284: return "IBM EBCDIC - Latin America/Spain";
    case 20285: return "IBM EBCDIC - United Kingdom";
    case 20290: return "IBM EBCDIC - Japanese Katakana Extended";
    case 20297: return "IBM EBCDIC - France";
    case 20420: return "IBM EBCDIC - Arabic";
    case 20423: return "IBM EBCDIC - Greek";
    case 20424: return "IBM EBCDIC - Hebrew";
    case 20833: return "IBM EBCDIC - Korean Extended";
    case 20838: return "IBM EBCDIC - Thai";
    case 20866: return "KOI8 (Russian)";
    case 20871: return "IBM EBCDIC - Icelandic";
    case 20880: return "IBM EBCDIC - Cyrillic (Russian)";
    case 20905: return "IBM EBCDIC - Turkish";
    case 20924: return "IBM EBCDIC - Latin-1/Open System (cp1047 + Euro)";
    case 20932: return "JIS X 0208-1990 & 0212-1990";
    case 20936: return "GB3212 (Simplified Chinese)";
    case 21025: return "IBM EBCDIC - Cyrillic (Serbian, Bulgarian)";
    case 21027: return "Ext Alpha Lowercase";
    case 21866: return "KOI8-U (Ukranian)";
    case 28591: return "ISO 8859-1 Latin-1";
    case 28592: return "ISO 8859-2 Central Europe";
    case 28593: return "ISO 8859-3 Latin 3";
    case 28594: return "ISO 8859-4 Baltic";
    case 28595: return "ISO 8859-5 Cyrillic";
    case 28596: return "ISO 8859-6 Arabic";
    case 28597: return "ISO 8859-7 Greek";
    case 28598: return "ISO 8859-8 Hebrew: Visual Ordering";
    case 28599: return "ISO 8859-9 Latin 5";
    case 28605: return "ISO 8859-15 Latin 9";
    case 38598: return "ISO 8859-8 Hebrew: Logical Ordering";
    case 50220: return "iso-2022-jp";
    case 50221: return "iso-2022-jp$ESC";
    case 50222: return "iso-2022-jp$SIO";
    case 50225: return "iso-2022-kr";
    case 51949: return "euc-kr (Korean (EUC))";
    case 52936: return "hz-gb-2312 (Chinese Simplified (HZ))";

    case 57002: return "x-iscii-de (ISCII Devanagari)";
    case 57003: return "x-iscii-be (ISCII Bengali)";
    case 57004: return "x-iscii-ta (ISCII Tamil)";
    case 57005: return "x-iscii-te (ISCII Telugu)";
    case 57006: return "x-iscii-as (ISCII Assamese)";
    case 57007: return "x-iscii-or (ISCII Oriya)";
    case 57008: return "x-iscii-ka (ISCII Kannada)";
    case 57009: return "x-iscii-ma (ISCII Malayalam)";
    case 57010: return "x-iscii-gu (ISCII Gujarathi)";
    case 57011: return "x-iscii-pa (ISCII Panjabi)";
    }
    return NULL;
}
