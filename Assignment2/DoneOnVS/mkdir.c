#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>


int main(int numOfArg, char *inputArgs[]){
    // printf("yug");
    int fileStatus; //stores the status whether the file has been created or not
    char *dir = strtok(inputArgs[0], " "); //mkdir
    dir = strtok(NULL, " ");               //filename
    fileStatus = mkdir(dir, 0777);
    //mkdir return 0 if file has been created successfully
    //mkdir return -1 if file has not been created peoperly

    if (fileStatus==-1)
    //In case mkdir doesnot return 0
    {
        perror("Error occured: ");
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