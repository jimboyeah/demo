#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#if defined(WIN32) || defined(WIN64)
    #include <windows.h>
    #define sleep(n) Sleep(1000 * (n))
#else
    #include <unistd.h>
#endif

typedef struct
{
    int index;
    int repeat;
    char * message;
} Message;

void * sendMsg(void *);

int main( int c, char * args [])
{
    srand(time(0));
    int num = 5;
    pthread_t ids[num];
    Message m[num];
    for( int i=0; i<num; i++)
    {
        Message msg = { i, rand()%9+1, args[0] };
        m[i] = msg;
        pthread_create( &ids[i], NULL, sendMsg, (void *)&m[i] );
        // pthread_join( ids[i], NULL ); // synchronous threads，this make multi-thread work as single thread
    }
    pthread_join( ids[0], NULL );
    pthread_join( ids[1], NULL );
    pthread_join( ids[2], NULL );
    pthread_join( ids[3], NULL );
    pthread_join( ids[4], NULL );
    printf("main thread done sid:%u \n", pthread_self());
}

void * sendMsg( void *msg)
{
    pthread_t tid = pthread_self();
    Message m = *(Message *)msg;

    for( int i=0; i<m.repeat; i++)
    {
        printf( "%u thread sid:%u %s \n", m.index, tid, m.message);
        fflush(stdout);
        // usleep(200);
        // _sleep(200);
        sleep(200);
    }
    printf("%u thread sid:%u done repeat %u \n", m.index, tid, m.repeat);
    return NULL;
}
