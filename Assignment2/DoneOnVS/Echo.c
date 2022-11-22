#include<stdio.h>
#include<stdlib.h>

int main(int numOfArgs, char *inputArgs[]){
    
    if (numOfArgs<=1)
    {
        printf("Invalid Format");
        printf("Correct format: CommandName inputVariable");
        exit(1);
    }

    for (int i = 1; i < numOfArgs; i++)
    {
        printf("%s ",inputArgs[i]);
    }
    printf("\n");
    exit(0);

    
}