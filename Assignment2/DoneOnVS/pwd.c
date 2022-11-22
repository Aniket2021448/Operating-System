#include <unistd.h>  //Stores the getcwd function to get the current dir. path
#include <stdio.h>   // for basic IO

int main() {
    //this time we haven't passed any arguments to main() because pwd command doesnot require 
    //any user input it just returns the address of the current working directory

    char path[1024];            //To store the path of the working directory 
    printf("Path of current Directory: %s\n", getcwd(path, sizeof(path)));
}