
#include "Hello.h"

jint JNICALL Java_Hello_add(JNIEnv* env, jclass clazz, jint a, jint b)
{
  return (a + b);
}

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}