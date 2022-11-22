#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
// #include<sys/stats.h>

void run_cd(char *command){
    // ~ sends home 
    // .. goes 1 step back
    
    char *dir = strtok(command," ");//cd
    dir = strtok(NULL," ");             //extension
    printf("extension: %s",dir);
  
    if(dir == '~' || dir == NULL){
      chdir("/home");
      
    }
    // else if(strcmp(dir,"..")==0)
    // {
    //   printf("in chdir for ..");
    //   chdir("..");
    // }
      
    else
    {
      int change = chdir(dir);
      if (change!=-1)
      {
          printf("Directory changed Successfully");
          return;
          // exit(0);
      }
      else{
          perror("ERROR");
          return;
        // exit(1);
      }
  }
}
void run_pwd(char *command){

    //any user input it just returns the address of the current working directory
    //-l and -p do same work in both commands
    
    char *dir = strtok(command," ");
    dir = strtok(NULL," ");  
    if(dir == NULL || strcmp(dir,"-L")==0 || strcmp(dir,"-P")==0 ){
      
      char path[1024];            //To store the path of the working directory 
      printf("Path of current Directory: %s\n", getcwd(path, sizeof(path)));
        
    }
  else{
    printf("You have entered wrong command");
  }
    // char path[1024];            //To store the path of the working directory 
    // printf("Path of current Directory: %s\n", getcwd(path, sizeof(path)));
}
void run_echo(char *command)
{
    // echo -n removes new line character in the last
    // echo -e gives checks for escape character. \t, \a,\n
    int i=0;
    char *dir = strtok(command," ");//echo
    dir = strtok(NULL," ");           //extension or String
    // char *store[]= 
    if (command == NULL)
    {
        printf("Wrong Command");
        return ;
    }

    if (strcmp(dir,"-n")==0)
    {  
      dir = strtok(NULL,"\0");
      int parse=0;
      while(dir[parse]!=NULL){
        if(dir[parse]=='\\')
        { 
          // printf("here found\t");
        }

        else{
          printf("%c",dir[parse]);
        }
        parse++;
      }
    }
    
    if(strcmp(dir,"-E")==0){
      dir = strtok(NULL,"\0");
      int parse=0;
      while(dir[parse]!=NULL){
        if(dir[parse]=='\\')
        { 
          // printf("here found\t");
        }

        else{
          printf("%c",dir[parse]);
        }
        parse++;
      }
      printf("\n");

    }  
  
    else
      //Normal echo  
    {        
      dir = strtok(NULL,"\0");
      int parse=0;
      while(dir[parse]!=NULL){
        if(dir[parse]=='\\')
        { 
          // printf("here found\t");
        }

        else{
          printf("%c",dir[parse]);
        }
        parse++;
      }
      printf("\n");
      }

  }    


int main(){
  char command[100];
  do{
    printf("XDD: ");
    fgets(command,100,stdin);
    if(command[0]=='e' && command[1]=='x' && command[2]=='i' &&command[3]=='t'){
      break;
    }
    else if(command[0]=='c' && command[1]=='d'){
      //call cd command
      run_cd(command);
    }
    else if(command[0]=='r' && command[1]=='m'){
      //call rm command
      int pid = fork();
      if(pid == 0){
        execl("./rm",command, NULL);
      }
      else{
        wait(NULL);
      }
    }

    else if(command[0]=='m' && command[1]=='k' && command[2]=='d' && command[3]=='i' && command[4]=='r'){
      // printf("hi");
      //call mkdir command
      int pid = fork();
      if(pid<0){
        printf("Couldn't fork");
      }
      if(pid == 0){
        // printf("adada");
        execl("./mkdir",command, NULL);
      }
      else{
        wait(NULL);
      }
    }  
    
    else if(command[0]=='p' && command[1]=='w' && command[2]=='d'){
      //call pwd command
      run_pwd(command);
    }
    else if(command[0]=='c' && command[1]=='a' && command[2]=='t'){
      //call cat command
      printf("going for cat\n");
      pid_t pid = fork();
      if(pid<0){
        printf("Couldn't fork");
      }
      else if(pid == 0){
        printf("going for cat2");
        execl("./cat",command, NULL);
      }
      else{
        wait(NULL);
      }
    }
    else if(command[0]=='l' && command[1]=='s'){
    //call ls command
    }
    else if(command[0]=='e' && command[1]=='c'&& command[2]=='h'&& command[3]=='o'){
      //call echo command
      run_echo(command);
    }
    else if(command[0]=='d' && command[1]=='a' && command[2]=='t' && command[3]=='e'){
      //call date command
      pid_t pid = fork();
      if(pid<0){
        printf("Couldn't fork");
      }
      else if(pid == 0){
        // printf("going for cat2");
        execl("./date",command, NULL);
      }
      else{
        wait(NULL);
      }
    }
    
      
  }while(1);
    
  return 0;  
}