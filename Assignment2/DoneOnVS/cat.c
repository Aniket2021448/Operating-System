#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int main(int numOfArg, char *inputArgs[]){
    //inputArgs = stores the arguments given during Runtime, eg.(cat text.txt) as {'cat','text.txt'}
    //numOfArg = stores the number of arguments given during Runtime, in above example numOfArg = 2 

    printf("In catFUn");
    char fileName[100];
    char *dir = strtok(inputArgs[0]," ");
    dir = strtok(NULL, " ");
    strcpy(fileName,dir);
    printf("%s",dir);
    puts(fileName);
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
          // ch = fgetc(ptr);
          printf("%c", ch);
          // exit(0); 
      }
      // exit(0);
      //Closing file
      fclose(ptr);
    }
}