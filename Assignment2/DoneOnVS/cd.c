#include<stdio.h>
#include<conio.h>
#include<dir.h>
#include<errno.h>
#include<stdlib.h>


int main(int numOfArgs, char *inputArgs[]){
    if (numOfArgs != 2)
    {
        perror("INVALID SYNTAX");        
        printf("Correct syntax: CommandName directoryName");
        exit(1);
    }
    else{
        if (chdir(inputArgs[1] == 0))
        {
            printf("Directory changed Successfully");
            exit(0);
        }
        else{
            perror("ERROR");
            exit(1);
        }    
    }
}