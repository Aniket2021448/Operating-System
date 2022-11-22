#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <string.h>

void main(int numOfArgs,char *inputArgs[]) 
{
 struct tm* now; 
  time_t t = time(NULL); 
  
  char *dir = strtok(inputArgs[0]," ");
  printf("%s\n",dir);
  dir = strtok(NULL," ");
  printf("%s",dir);
  // pritnf(typeof(dir));
  // Get the localtime 
  if (dir==NULL){
    now = localtime(&t); 
    printf("%s\n",asctime(now)); 
  }
  
  else if (dir[1]=='u'){   //-u
    now = gmtime(&t);
    printf("%s\n",asctime(now));
  }
  
  else if (dir[3]=='n'){        //Universal
    now = gmtime(&t);
    printf("%s\n",asctime(now));
  }
  else{
    printf("Error: Command not found error.");
  }

    
} 
