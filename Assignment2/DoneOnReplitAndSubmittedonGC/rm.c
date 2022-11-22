#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main(int numOfArgs, char *inputArgs[]){
  char in;
  int check, check1, check2;
  if(inputArgs[0] == NULL){
    perror("Error: ");
  }

  char *dir = strtok(inputArgs[0]," "); //rm 
  dir = strtok(NULL, " ");         //extension or file name
  printf("extension: %s",dir);
  
  if(dir != NULL){
    // printf("in rm for dir: %s",dir);
    if(strcmp(dir,"-i")==0 ){
      // printf("in -i");
      dir = strtok(NULL, " ");       //filename 
      printf("rm: remove regular file '%s' y/n: ",dir);
      scanf("%c",&in);
      check = rmdir(dir);

    }
    else if(strcmp(dir,"-r")==0){
      // char *dir = strtok(command," "); //rm
      // printf("In -r");
      dir = strtok(NULL, " ");         //file name
      check = rmdir(dir);
      
    }
    else{
      // printf("%s",dir);
      const char *fileName;
      fileName = dir;
      // strcpy(fileName, dir);
      // printf("In normal");
      // dir = strtok(NULL, " ");       //filename 
      check = remove(fileName);
        if(check !=0){
          printf("unable to delete\n");
        }
   
    }
        
  }
  else{
      perror("Error");
    }
}