

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IAdd_h__
#define __IAdd_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAdd_FWD_DEFINED__
#define __IAdd_FWD_DEFINED__
typedef interface IAdd IAdd;

#endif 	/* __IAdd_FWD_DEFINED__ */


#ifndef __IIServiceComTest_FWD_DEFINED__
#define __IIServiceComTest_FWD_DEFINED__
typedef interface IIServiceComTest IIServiceComTest;

#endif 	/* __IIServiceComTest_FWD_DEFINED__ */


#ifndef __IAdd_FWD_DEFINED__
#define __IAdd_FWD_DEFINED__
typedef interface IAdd IAdd;

#endif 	/* __IAdd_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAdd_INTERFACE_DEFINED__
#define __IAdd_INTERFACE_DEFINED__

/* interface IAdd */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAdd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1221db62-f3d8-11d4-825d-00104b3646c0")
    IAdd : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFirstNumber( 
            long nX1) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSecondNumber( 
            long nX2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoTheAddition( 
            /* [retval][out] */ long *pBuffer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAddVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAdd * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAdd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAdd * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFirstNumber )( 
            IAdd * This,
            long nX1);
        
        HRESULT ( STDMETHODCALLTYPE *SetSecondNumber )( 
            IAdd * This,
            long nX2);
        
        HRESULT ( STDMETHODCALLTYPE *DoTheAddition )( 
            IAdd * This,
            /* [retval][out] */ long *pBuffer);
        
        END_INTERFACE
    } IAddVtbl;

    interface IAdd
    {
        CONST_VTBL struct IAddVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdd_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAdd_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAdd_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAdd_SetFirstNumber(This,nX1)	\
    ( (This)->lpVtbl -> SetFirstNumber(This,nX1) ) 

#define IAdd_SetSecondNumber(This,nX2)	\
    ( (This)->lpVtbl -> SetSecondNumber(This,nX2) ) 

#define IAdd_DoTheAddition(This,pBuffer)	\
    ( (This)->lpVtbl -> DoTheAddition(This,pBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAdd_INTERFACE_DEFINED__ */


#ifndef __IIServiceComTest_INTERFACE_DEFINED__
#define __IIServiceComTest_INTERFACE_DEFINED__

/* interface IIServiceComTest */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IIServiceComTest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4DDE5CA3-F5D7-4BC3-9045-E697297C5530")
    IIServiceComTest : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE add( 
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ LONG *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIServiceComTestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIServiceComTest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIServiceComTest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIServiceComTest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIServiceComTest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIServiceComTest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIServiceComTest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIServiceComTest * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *add )( 
            IIServiceComTest * This,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [retval][out] */ LONG *result);
        
        END_INTERFACE
    } IIServiceComTestVtbl;

    interface IIServiceComTest
    {
        CONST_VTBL struct IIServiceComTestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIServiceComTest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIServiceComTest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIServiceComTest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIServiceComTest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIServiceComTest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIServiceComTest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIServiceComTest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIServiceComTest_add(This,x,y,result)	\
    ( (This)->lpVtbl -> add(This,x,y,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIServiceComTest_INTERFACE_DEFINED__ */



#ifndef __CodeGuruMathLib_LIBRARY_DEFINED__
#define __CodeGuruMathLib_LIBRARY_DEFINED__

/* library CodeGuruMathLib */
/* [helpstring][uuid] */ 



EXTERN_C const IID LIBID_CodeGuruMathLib;
#endif /* __CodeGuruMathLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


