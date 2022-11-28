#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>
#include <sys/resource.h>

void *countA()
{
  for(long long int i = 0; i<=4294967296; i++){   
  }
}
void *countB()
{  
  for(long long int i = 0; i<=4294967296; i++){
      //Just to count
  }
}

void *countC()
{
  for(long long int i = 0; i<=4294967296; i++){
     //Just to count   
  }
}
int main()
{
  //METHOD-1
	pthread_t p1, p2, p3;
	struct timespec start, end;
  struct sched_param param;
  
  FILE * fptr;
  fptr = fopen("ques1_1.txt","a");


// ----------------------------------------------------------------------------------------------------------------------------------------------
//METHOD-2
//Default A
  clock_gettime( CLOCK_REALTIME, &start );
  
  pthread_create(&p1, NULL, countA, NULL);
  pthread_create(&p1, NULL, countB, NULL);
  pthread_create(&p1, NULL, countC, NULL);
  pthread_setschedparam(p1, SCHED_OTHER, &param);
  nice(0);
  pthread_join(p1, NULL);
  
  clock_gettime( CLOCK_REALTIME, &end );

  fprintf(fptr,"%f\n",((double)(end.tv_nsec - start.tv_nsec))/CLOCKS_PER_SEC);

//Default B
  clock_gettime( CLOCK_REALTIME, &start );
  
  pthread_create(&p2, NULL, countA, NULL);
  pthread_create(&p2, NULL, countB, NULL);
  pthread_create(&p2, NULL, countC, NULL);
  pthread_setschedparam(p2, SCHED_RR, &param);

  pthread_join(p2, NULL);
  
  clock_gettime(CLOCK_REALTIME, &end );

  fprintf(fptr,"%f\n",((double)(end.tv_nsec - start.tv_nsec))/CLOCKS_PER_SEC);

  //Default C
  clock_gettime(CLOCK_REALTIME, &start );
  
  pthread_create(&p3, NULL, countA, NULL);
  pthread_create(&p3, NULL, countB, NULL);
  pthread_create(&p3, NULL, countC, NULL);
  pthread_setschedparam(p3, SCHED_FIFO, &param);
  pthread_join(p3, NULL);
  
  clock_gettime(CLOCK_REALTIME, &end );

  fprintf(fptr,"%f\n",((double)(end.tv_nsec - start.tv_nsec))/CLOCKS_PER_SEC);


// CREATING CUSTOM PRIORITIES
  
  for(int repeat = 1; repeat<=6; repeat++){
    // UPDATING PRIORITY FOR A
  
  clock_gettime( CLOCK_REALTIME, &start );
  
  pthread_create(&p1, NULL, countA, NULL);
  pthread_create(&p1, NULL, countB, NULL);
  pthread_create(&p1, NULL, countC, NULL);
  pthread_setschedparam(p1, SCHED_OTHER, &param);
  pthread_join(p1, NULL);
  
  clock_gettime( CLOCK_REALTIME, &end );

  fprintf(fptr,"%f\n",((double)(end.tv_nsec - start.tv_nsec))/CLOCKS_PER_SEC);

    // UPDATING PRIORITY FOR B

    clock_gettime(CLOCK_REALTIME, &start );
    pthread_setschedprio(p2,repeat);
    pthread_join(p2, NULL);
    clock_gettime( CLOCK_REALTIME, &end );
    
    fprintf(fptr,"%f\n",((double)(end.tv_nsec - start.tv_nsec))/CLOCKS_PER_SEC);

    // Updating Prio FOR C
    
    clock_gettime( CLOCK_REALTIME, &start );
    pthread_setschedprio(p3,repeat);
    pthread_join(p3, NULL);
    clock_gettime( CLOCK_REALTIME, &end );
    
    fprintf(fptr,"%f\n",((double)(end.tv_nsec - start.tv_nsec))/CLOCKS_PER_SEC);
    
  }

  fclose(fptr);
	exit(0);
}