

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for mfcstaticHandlers.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IPreview,0xf8df47d7,0x3b7f,0x4c67,0x8d,0xdd,0x06,0x7a,0x9a,0xd1,0xbc,0x14);


MIDL_DEFINE_GUID(IID, IID_IThumbnail,0x97872261,0xb367,0x4c20,0xa9,0xf7,0x3a,0x4d,0xd2,0x8b,0x51,0x1b);


MIDL_DEFINE_GUID(IID, IID_ISearch,0xd62758c9,0x7f96,0x4230,0xbd,0x1f,0x57,0xd4,0x45,0xc8,0x18,0xd4);


MIDL_DEFINE_GUID(IID, LIBID_mfcstaticHandlersLib,0x4965b931,0xfa37,0x4dfe,0x87,0x2c,0xbd,0xc4,0x6b,0x9d,0x68,0xb7);


MIDL_DEFINE_GUID(CLSID, CLSID_Preview,0xa2cb44ef,0xefd5,0x4981,0xb8,0x05,0xcb,0x59,0xd7,0x21,0xb9,0x41);


MIDL_DEFINE_GUID(CLSID, CLSID_Thumbnail,0x6f3ac922,0x350d,0x4043,0xa0,0x8f,0x11,0x7c,0xb3,0x31,0xff,0xa9);


MIDL_DEFINE_GUID(CLSID, CLSID_Search,0x1ac85458,0x1247,0x4dda,0x8a,0x58,0xa7,0xa9,0x73,0x2b,0x69,0x2b);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



