/*
	Record test data:
	11,2006/1/27,M.,90001,Bobert
	4,2012/3/4,S.,90301,White M.
	2,2011/3/7,C.,3401,John Fanck
	6,2003/4/17,W.,21401,Lyn W.
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define DATE_LEN	12
#define LOCA_LEN	256
#define WORKER_LEN	512
#define MAX_LOOP	1024
#define MAX_LINE	MAX_LOOP

typedef struct day_record
{
    int  worker_nu;
    char date[DATE_LEN];
    char loca[LOCA_LEN];
    int  work_nu;
    char worker[WORKER_LEN];
} day_record;

void putdr(day_record *rcd[], int c){
	int i;
	printf("No.\t Work No.\t Date\t Loca\t Worker\n");
	for(i=0; i<c; i++){
		day_record &r = *rcd[i];
		printf("%d\t %d\t %s\t %s\t %s\n", r.worker_nu, r.work_nu, r.date, r.loca, r.worker);
	}
}

void replace(char s, char d, char c[]){
	int i=0;
	while(1){
		if( c[i]==0 ) break;
		c[i++]==s? c[i-1]=d:0;
		if( i>MAX_LOOP ) break;
	}
}

void inputrc(day_record *rcd, char c[], char delima){
	int i=0,j=0,k[5],ld,ll,lw;
	while(1){
		if( c[i]=='\0' ||  c[i]=='\n' || i>MAX_LOOP ){ 
			// NULL terminate with gets()/fscanf, \n with fgets()
			c[i] = 0;
			k[j] = i;
			break;
		}else{
			c[i++]==delima? k[j++]=i,c[i-1]=0:0;
		}
	}
	day_record &r = *rcd;
	i = sscanf(c,"%d", &r.worker_nu);
	i+= sscanf(    (char*)&c[k[2]], "%d", &r.work_nu);
	ld = k[1]-k[0];
	ll = k[2]-k[1];
	lw = k[4]-k[3];

	if( !(i==2 && ld<DATE_LEN && ll<LOCA_LEN && lw<WORKER_LEN) ){
		printf("Data error! line #%d. %s\n", __LINE__, c);
		exit(__LINE__);
	}
	strncpy( r.date,   (char*)&c[k[0]], ld+1);
	strncpy( r.loca,   (char*)&c[k[1]], ll+1);
	strncpy( r.worker, (char*)&c[k[3]], lw+1); //plus NULL terminator
	//printf("%d\t %d\t %s\t %s\t %s\n", r.worker_nu, r.work_nu, r.date, r.loca, r.worker);
	//sscanf(c, "%d %s %s %d %s", &r.worker_nu, r.date, r.loca, &r.work_nu, r.worker);
}

int init_rec(day_record *rcd[],FILE *file)
{
    char temp[MAX_LINE];
    int index=0;
    while( fgets(temp,MAX_LINE,file)!=NULL) // don't fscanf(file,"%s",temp)!=EOF
    {
        rcd[index]=NULL;
        rcd[index]=(day_record * )malloc(sizeof(day_record));
        if(rcd[index]==NULL)
        {
            printf("failure of memory allocation. line #%d\n", __LINE__);
            exit(1);
        }
        //replace(',',' ',temp);
        inputrc(rcd[index],temp, ',');
        index++;
    }
	return index;
}


int main()
{
    FILE * fp;
    day_record * record[31];
    fp = fopen("pay.txt","r");
    if(fp==NULL)
    {
        printf("file pay.txt open failed\n");
        exit(1);
    }

    int c = init_rec(record,fp);
    putdr(record, c);
    fclose(fp);
    return 0;
} 