#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <string.h>

void main(int numOfArgs,char *inputArgs[]) 
{ 

    char *dir = strtok(inputArgs[0]," ");      //date
    dir = strtok(NULL," ");                    //extension
    struct tm* local; 
    time_t t = time(NULL); 
    printf("%s",dir);
    // Get the localtime 
    if (dir==NULL){
      local = localtime(&t); 
      printf("%s\n",asctime(local)); 
    }
    
    // Get the universaltime
    
    else if (strcmp(dir,"-u")==0){
      printf("In gmt");
    	local = gmtime(&t);
    	printf("%s\n",asctime(local));
    }
    else{
      printf("Command not found\n");
    }
    
} 
