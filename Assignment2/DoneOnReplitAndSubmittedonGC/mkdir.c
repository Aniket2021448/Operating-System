#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>


int main(int numOfArg, char *inputArgs[]){
    // printf("yug");
    //-p 
    int fileStatus; //stores the status whether the file has been created or not
    
    char *dir = strtok(inputArgs[0], " "); //mkdir
    dir = strtok(NULL, " ");               //filename
    if(strcmp(dir,"-v")==0){
      dir = strtok(NULL," ");
      while(dir!=NULL){
        fileStatus = mkdir(dir,0777);
        dir = strtok(NULL," ");
      }
    }
      
    else if(strcmp(dir,"--verbose")==0){
      dir = strtok(NULL," ");
      while(dir!=NULL){
        fileStatus = mkdir(dir,0777);
        dir = strtok(NULL," ");
      }
    }

    else{
      if(dir[0]=='-'){
        printf("Command does not exist");
      }
      else{
        fileStatus = mkdir(dir, 0777);  
      }
    }
    //mkdir return 0 if file has been created successfully
    //mkdir return -1 if file has not been created peoperly

    if (fileStatus==-1)
    //In case mkdir doesnot return 0
    {
        perror("Error: Address not given ");
        //errorno gives the preRegistered error number and strerror gives the corresponding error message
        // perror(strerror(errno));   
        exit(1);
    }
    else{
        //In case file created and mkdir returns 0
        
        printf("File has been created successfully.%s",dir);
        // exit(0);
    }

}