#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int main(int numOfArg, char *inputArgs[]){
    //inputArgs = stores the arguments given during Runtime, eg.(cat text.txt) as {'cat','text.txt'}
    //numOfArg = stores the number of arguments given during Runtime, in above example numOfArg = 2 

    // printf("In catFUn");
    char fileName[100];
    char *dir = strtok(inputArgs[0]," "); //cat
    dir = strtok(NULL, " ");              //extension

  if(strcmp(dir, "-n")==0){
    // printf("in -n");
    dir = strtok(NULL, " ");              //extension
    strcpy(fileName,dir);

    //creating a pointer that will point to the file
    FILE * ptr = fopen(fileName, "r");
    //If everything goes fine, then print data from file
    if(ptr == NULL){
      // printf("Cannot open file")
      perror("Error while opening file");
    }
    else {
      int lineNum = 0;
      char ch;
      printf("%d",lineNum);
      while ((ch = fgetc(ptr))!=EOF)
      {  
          if(ch=='\n'){
            lineNum++;
            
            printf("\n %d",lineNum);
          }
          else{
            printf("%c", ch);
          }
      }

      fclose(ptr);
    }
    
  }
   else if(strcmp(dir, "-E")==0){
     // printf("in -E");
    dir = strtok(NULL, " ");              //filename
    strcpy(fileName,dir);

    //creating a pointer that will point to the file
    FILE * ptr = fopen(fileName, "r");
    //If everything goes fine, then print data from file
    if(ptr == NULL){
      // printf("Cannot open file")
      perror("Error while opening file");
    }
    else {
      char lineChar = '$';
      char ch;
      while ((ch = fgetc(ptr))!=EOF)
      {   
        if(ch=='\n'){
          printf("%c\n",lineChar);
        }
        else{
          printf("%c", ch);  
        }
      
      }
      fclose(ptr);
    }
    
  }
  else{
    strcpy(fileName,dir);
    // printf("in normal cat");
    //creating a pointer that will point to the file
    FILE * ptr = fopen(fileName, "r");
    //If everything goes fine, then print data from file
    
    if(ptr == NULL){
      // printf("Cannot open file")
      perror("Error while opening file");
    }
    else {
      char ch;
      while ((ch = fgetc(ptr))!=EOF)
      {
          printf("%c", ch);
      }
      fclose(ptr);
    }  
  } 
}
