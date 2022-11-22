#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<dirent.h> 
int main(int numOfArgs,char *inputArgs[]) 
{ 
  for(int i=0; i<numOfArgs; i++){
    printf("%s\n",inputArgs[i]);
  }
    
	struct dirent **fileNames;            //Stores file names
	int numOfFiles;                                 //Number of files
  // printf("%d",numOfArgs);
  char *directory=inputArgs[0];       //ls'0'
                //'0,1'Extension or file -1 or -a or filename

    // printf("%c",directory[1]);
  if(numOfArgs < 1) 
	{ //Wrong COmmand entered
		perror("Error: ");
	} 
	else if((strcmp(directory,"ls")==0 || strcmp(directory,"ls\n")==0)){
    printf("with arg0 in ls");
    numOfFiles=scandir(".",&fileNames,NULL,alphasort);
    while (numOfFiles--) 
		{   
			  printf("%s\n",fileNames[numOfFiles]->d_name); 
  			free(fileNames[numOfFiles]); 
      }
		// n--;
		free(fileNames);
  }     
  
  else if (strcmp(directory,"ls -a\n")==0) 
	{ //scans for all files
    // directory = strtok(NULL," ");
   
      printf("with arg1 in a");
        numOfFiles=scandir(".",&fileNames,NULL,alphasort);
        while (numOfFiles--) 
  		  {   
  			  printf("%s\n",fileNames[numOfFiles]->d_name); 
    			free(fileNames[numOfFiles]); 
        }
  		// n--;
  		free(fileNames); 
    }
    
    
    else if(strcmp(directory,"ls -1\n" )==0){
      printf("ehy");
      numOfFiles = scandir(".", &fileNames, NULL, alphasort);
      while (numOfFiles--) 
		  { 
        if(fileNames[numOfFiles]->d_name[0]== '.' || fileNames[numOfFiles]->d_name[1]== '.'){
            continue;
        }
        else{
          printf("%s\n",fileNames[numOfFiles]->d_name); 
          free(fileNames[numOfFiles]);   
        }
      }
		  // n--;
		  free(fileNames);
    }

    else{
      printf("Command not found\n");
    }
      
	return 0; 
}
