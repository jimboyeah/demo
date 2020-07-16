/*****************************************************************************\

	Runtime Type Information demo by Jimbowhy 2016/4/1 23:50
	Compiler: Visual C++ 6, TDM-GCC 3.7.1
	1st edition: ‎2015‎年‎1‎月‎31‎日，‏‎17:50:20
	This programme is a demonstration of how MFC implementates RuntimeClass

\*****************************************************************************/


#include <cstdio>
#include <cstring>


/*
 * --------------=========== Step I: Runtime Classs ===========---------------
 */
class CRuntimeClass {
	public:
		char * name; // keep order for the first 4 members
		int    size;
		void * (* constructor)();
		CRuntimeClass* pBase;
		CRuntimeClass* pNext;
		static CRuntimeClass* theFirst;
		static void * CreateObject(char *);
		bool isKindOf(const CRuntimeClass*) const;
};

CRuntimeClass *CRuntimeClass::theFirst = NULL;

bool CRuntimeClass::isKindOf(const CRuntimeClass *c) const {
    const CRuntimeClass *p = this;
    while(p){
        if( c==p ) return true;
        p = p->pBase;
    }
    return false;
}

void *CRuntimeClass::CreateObject(char * classname){
    CRuntimeClass *c = CRuntimeClass::theFirst;
    while(c){
		CRuntimeClass &cr = *c;
        if( strcmp(classname, cr.name) == 0 ) break;
        c = cr.pNext;
    }
	CRuntimeClass &cr = *c;
    if( c==NULL) throw "Not a valid dynamic class specified!";
    if( cr.constructor==NULL ) return NULL;
    return cr.constructor();
}

/*
 * --------------=========== Step II: Runtime Auxiliary ===========---------------
 */
struct AFX_CLASSINIT {
    AFX_CLASSINIT(CRuntimeClass *);
};

AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass* pNew){
    pNew->pNext = CRuntimeClass::theFirst;
    CRuntimeClass::theFirst = pNew;
}

/*
 * --------------============ Step IV: Macro Auxiliary ===========---------------
 */
#define DECLARE_DYNAMIC \
		static CRuntimeClass Class; \
		static AFX_CLASSINIT ClassInit;

#define IMPLEMENT_DYNAMIC(ClassName, Base) \
		CRuntimeClass ClassName::Class = { #ClassName, sizeof(ClassName), NULL, &Base::Class };\
		AFX_CLASSINIT ClassName::ClassInit(&ClassName::Class); 

#define DECLARE_DYNCREATE \
		DECLARE_DYNAMIC \
		static void * CreateObject();

#define IMPLEMENT_DYNCREATE(ClassName, Base) \
		void *ClassName::CreateObject(){ return new ClassName(); } \
		CRuntimeClass ClassName::Class = { #ClassName, sizeof(ClassName), ClassName::CreateObject, &Base::Class };\
		AFX_CLASSINIT ClassName::ClassInit(&ClassName::Class);  

/*
 * --------------=========== Step V: Use Runtime Class ===========---------------
 */
class Shape {
	public:
		Shape() {
			printf("Raw shape \n");
		}
		DECLARE_DYNCREATE
};
IMPLEMENT_DYNCREATE(Shape, Shape);

class Trangle: public Shape {
	public:
		Trangle (){
			printf("Trangle \n");
		}
		DECLARE_DYNCREATE
};
IMPLEMENT_DYNCREATE(Trangle, Shape)

class Ellipse: public Shape {
	public:
		Ellipse(){
			printf("Ellipse \n");
		}
		DECLARE_DYNAMIC
};
IMPLEMENT_DYNAMIC(Ellipse, Shape)

/*
 * ---------------============== Programme Entry ==============----------------
 */
int main(){
    char classname[256];
	printf("Try RuntimeClass, dynamicaly create Shape, Trangle, Ellipse, and more...\n");
	printf("Type what class you want now:");
    while(1)
    try{
        scanf("%s", classname);
        void * o = CRuntimeClass::CreateObject(classname);
        if( o==NULL ){
            printf("Not a dynamicaly create class specified! \n");
            return 1;
        }
    }catch(char* m){
        printf(m);
    }
	return 0;
}
