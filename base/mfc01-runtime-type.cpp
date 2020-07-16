#include <iostream>
#include <cstring>
using namespace std;

/*
 * Runtime Type Information 
 */
class CRuntimeClass {
public:
    const char * name;
    const int size;
    CRuntimeClass* pBase;
    void * (* constructor)();
    CRuntimeClass* pNext;
    static CRuntimeClass* pFirst;
    static void * CreateObject(char *);
    bool isKindOf(const CRuntimeClass*) const;
};

CRuntimeClass *CRuntimeClass::pFirst = NULL;

bool CRuntimeClass::isKindOf(const CRuntimeClass *c) const {
    const CRuntimeClass *p = this;
    while(p){
        if(c==p) return true;
        p = p->pBase;
    }
    return false;
}

void *CRuntimeClass::CreateObject(char * classname){
    CRuntimeClass *p = CRuntimeClass::pFirst;
    while(p){
        cout << "---> " << p->name << "\t has contructor? " << p->constructor << endl;
        if( strcmp(classname, p->name) == 0 ) 
        {
            break;
        }
        p = p->pNext;
    }
    if (p==NULL) {
        cout << "Not found!" << endl;
        return NULL;
        // throw "Not a valid dynamic class specified!";
    }
    if (p->constructor == NULL) return NULL;
    return p->constructor();
}


struct AFX_CLASSINIT {
    AFX_CLASSINIT(CRuntimeClass *);
};

AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass* pNew){
    pNew->pNext = CRuntimeClass::pFirst;
    CRuntimeClass::pFirst = pNew;
}


#define DECLARE_DYNAMIC \
    static CRuntimeClass Class; \
    static AFX_CLASSINIT ClassInit;

#define IMPLEMENT_DYNAMIC(ClassName, Base) \
    CRuntimeClass ClassName::Class = { #ClassName, sizeof(ClassName), &Base::Class }; \
    AFX_CLASSINIT ClassName::ClassInit(&ClassName::Class); 


#define DECLARE_DYNCREATE \
    DECLARE_DYNAMIC \
    static void * CreateObject();

#define IMPLEMENT_DYNCREATE_BASE(ClassName) \
    CRuntimeClass ClassName::Class = { #ClassName, sizeof(ClassName), NULL, ClassName::CreateObject }; \
    IMPLEMENT_DYNCREATE_COMMON(ClassName)

#define IMPLEMENT_DYNCREATE(ClassName, Base) \
    CRuntimeClass ClassName::Class = { #ClassName, sizeof(ClassName), &Base::Class, ClassName::CreateObject }; \
    IMPLEMENT_DYNCREATE_COMMON(ClassName)

#define IMPLEMENT_DYNCREATE_COMMON(ClassName) \
    void *ClassName::CreateObject() \
    { \
        return new ClassName(); \
    } \
    AFX_CLASSINIT ClassName::ClassInit(&ClassName::Class);  


/* Classs for test RT */

class Shape
{
public:
    Shape() { cout << "Raw shape" << endl; }
    DECLARE_DYNCREATE
};

IMPLEMENT_DYNCREATE_BASE(Shape)


class Trangle: public Shape
{
public:
    Trangle (){ 
        cout << "Trangle ..." << endl;
    }
    DECLARE_DYNCREATE
};

IMPLEMENT_DYNCREATE(Trangle, Shape)


class Ellipse: public Shape
{
public:
    Ellipse(){ 
        cout << "Ellipse" << endl; 
    }
    DECLARE_DYNAMIC
};

IMPLEMENT_DYNAMIC(Ellipse, Shape)


int main()
{
    char classname[256];
    cout << "Type a dynamic cratable class, ex. Shape:";
    while(1)
    try{
        cin >> classname;
        void * o = CRuntimeClass::CreateObject(classname);
        if( o==NULL ){
            cout << "Not a dynamicaly create class specified!" << endl;
            return 1;
        }
    }catch(char* m){
        cout << m << endl;
    }
    return 0;
}
