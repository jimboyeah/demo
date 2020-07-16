#include <iostream>
#include <dlfcn.h>

using namespace std;

int main(void)
{
	int  (*sum  )(int,int,int);
	void (*print)(char *);
	char  *err;

	void *handle = dlopen("./libsp.so",RTLD_LAXY);
	if(!handle){
		fputs( dlerror(), stderr );
		exit(1);
	}

	sum   = dlsym(handle, "sum"  );
	print = dlsym(handle, "print");
	if( (err = dlerror()) != NULL ){
		fputs(err, stderr);
		exit(1);
	}

	print("1+2+3=");
	cout << sum(1,2,3) << endl;

	dlclose(handle);
}