

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for IAdd.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "IAdd.h"

#define TYPE_FORMAT_STRING_SIZE   7                                 
#define PROC_FORMAT_STRING_SIZE   165                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _IAdd_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } IAdd_MIDL_TYPE_FORMAT_STRING;

typedef struct _IAdd_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } IAdd_MIDL_PROC_FORMAT_STRING;

typedef struct _IAdd_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } IAdd_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const IAdd_MIDL_TYPE_FORMAT_STRING IAdd__MIDL_TypeFormatString;
extern const IAdd_MIDL_PROC_FORMAT_STRING IAdd__MIDL_ProcFormatString;
extern const IAdd_MIDL_EXPR_FORMAT_STRING IAdd__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAdd_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAdd_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IIServiceComTest_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IIServiceComTest_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const IAdd_MIDL_PROC_FORMAT_STRING IAdd__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure SetFirstNumber */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nX1 */

/* 26 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 28 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 30 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSecondNumber */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x4 ),	/* 4 */
/* 46 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nX2 */

/* 64 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 66 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 68 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoTheAddition */

/* 76 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x5 ),	/* 5 */
/* 84 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x24 ),	/* 36 */
/* 90 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 92 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBuffer */

/* 102 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure add */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x7 ),	/* 7 */
/* 122 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 124 */	NdrFcShort( 0x10 ),	/* 16 */
/* 126 */	NdrFcShort( 0x24 ),	/* 36 */
/* 128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 130 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x */

/* 140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 146 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 148 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter result */

/* 152 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 154 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 160 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const IAdd_MIDL_TYPE_FORMAT_STRING IAdd__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAdd, ver. 0.0,
   GUID={0x1221db62,0xf3d8,0x11d4,{0x82,0x5d,0x00,0x10,0x4b,0x36,0x46,0xc0}} */

#pragma code_seg(".orpc")
static const unsigned short IAdd_FormatStringOffsetTable[] =
    {
    0,
    38,
    76
    };

static const MIDL_STUBLESS_PROXY_INFO IAdd_ProxyInfo =
    {
    &Object_StubDesc,
    IAdd__MIDL_ProcFormatString.Format,
    &IAdd_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAdd_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    IAdd__MIDL_ProcFormatString.Format,
    &IAdd_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IAddProxyVtbl = 
{
    &IAdd_ProxyInfo,
    &IID_IAdd,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IAdd::SetFirstNumber */ ,
    (void *) (INT_PTR) -1 /* IAdd::SetSecondNumber */ ,
    (void *) (INT_PTR) -1 /* IAdd::DoTheAddition */
};

const CInterfaceStubVtbl _IAddStubVtbl =
{
    &IID_IAdd,
    &IAdd_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IIServiceComTest, ver. 0.0,
   GUID={0x4DDE5CA3,0xF5D7,0x4BC3,{0x90,0x45,0xE6,0x97,0x29,0x7C,0x55,0x30}} */

#pragma code_seg(".orpc")
static const unsigned short IIServiceComTest_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    114
    };

static const MIDL_STUBLESS_PROXY_INFO IIServiceComTest_ProxyInfo =
    {
    &Object_StubDesc,
    IAdd__MIDL_ProcFormatString.Format,
    &IIServiceComTest_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IIServiceComTest_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    IAdd__MIDL_ProcFormatString.Format,
    &IIServiceComTest_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IIServiceComTestProxyVtbl = 
{
    &IIServiceComTest_ProxyInfo,
    &IID_IIServiceComTest,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IIServiceComTest::add */
};


static const PRPC_STUB_FUNCTION IIServiceComTest_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IIServiceComTestStubVtbl =
{
    &IID_IIServiceComTest,
    &IIServiceComTest_ServerInfo,
    8,
    &IIServiceComTest_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    IAdd__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _IAdd_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IAddProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIServiceComTestProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _IAdd_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IAddStubVtbl,
    ( CInterfaceStubVtbl *) &_IIServiceComTestStubVtbl,
    0
};

PCInterfaceName const _IAdd_InterfaceNamesList[] = 
{
    "IAdd",
    "IIServiceComTest",
    0
};

const IID *  const _IAdd_BaseIIDList[] = 
{
    0,
    &IID_IDispatch,
    0
};


#define _IAdd_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _IAdd, pIID, n)

int __stdcall _IAdd_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _IAdd, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _IAdd, 2, *pIndex )
    
}

const ExtendedProxyFileInfo IAdd_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _IAdd_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _IAdd_StubVtblList,
    (const PCInterfaceName * ) & _IAdd_InterfaceNamesList,
    (const IID ** ) & _IAdd_BaseIIDList,
    & _IAdd_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

