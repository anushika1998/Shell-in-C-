#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>
//#include "ls.c"
// #include "date.c"
// #include "cat.c"
// #include "mkdir.c"
// #include "rm.c"



int main(){
	int max_size = 100;
	
	char line[max_size];
	int ctr=0;

	char root_folder[100];
	getcwd(root_folder,sizeof(root_folder));

	while (1){
		printf("myShell>>>");
		fgets(line,max_size,stdin);
		//printf("%s\n",line );

		if(line==NULL){
			break;
		}

		char *history[100];
		history[ctr]=strdup(line);
		//printf("his : %s\n", history[ctr]);
		ctr++;
		//printf("%d\n", ctr);

		char root[100];
		strcpy(root,root_folder);
		char *final=line;
		char *inCmd[5];
		inCmd[0]="exit";
		inCmd[1]="cd";
		inCmd[2]="pwd";
		inCmd[3]="history";
		inCmd[4]="echo";

		int command_check=0;

		char *present_dir;
		char curr_path[100];
		char buff[1000];
		//printf("%s\n",exit );
		//char *cmd=strtok(final," ");

		

		char *tkn=NULL;
		tkn=strtok(line," ");
		
		char *exec[100];
		int i=0;
		//exec = (char *) malloc(15);
		
		while(tkn !=NULL){
			exec[i] = (char *) malloc(strlen(tkn)+1);
			strcpy(exec[i],tkn);
			//printf("%d\n",strlen(tkn));
			tkn=strtok(NULL," ");
			i++;
		}
		
		exec[i]=NULL;
		// printf("%s\n", line);
		// int k=0;
		// while(exec[k] != NULL){
		// 	printf("%s bakns\n", exec[k] );
		// 	k++;
		// }

		
		if(strcmp(exec[0],inCmd[0])==0){
			//printf("jsdk\n");
			break;
		}
		else if(strcmp(exec[0],inCmd[1])==0){
			
			command_check=1;
			if(exec[1]==NULL){
				chdir("/home/verma");
			}
			else{
				int check=chdir(exec[1]);
				present_dir=getcwd(buff,sizeof(buff));
				//printf("cd %s cmd\n",exec[1] );
				if(check==-1){
					printf("Invalid path\n");
				}
			}
			

		}
		else if(strcmp(exec[0],inCmd[2])==0){
			command_check=1;
			getcwd(curr_path,sizeof(curr_path));
			printf("current working directory : %s\n", curr_path);
			printf("pwd cmd\n" );
		}
		else if(strcmp(exec[0],inCmd[3])==0){
			command_check=1;
			//printf("history cmd\n");

			for (int x = ctr-1;x>=0;--x){
				printf("print %s\n", history[x]);
			}
			int j=ctr-1;
			int ct=0;
			while(history[j]!= NULL && ct<10){
				printf("%s \n",history[j] );
				j--;
				ct++;
			}
		}
		else if(strcmp(exec[0],inCmd[4])==0){
			command_check=1;
			if(exec[1]==NULL){
				printf("\n");
			}
			else if(strcmp(exec[1],"-n")==0){

			}
			else{
				i=1;
				
				while(exec[i]!= NULL){
					printf("%s",exec[i] );
					i++;
				}
				printf("\n");
				
			}
			//printf("echo cmd\n");
		}

		
		
		// printf("%s\n", initial[0]);
		if(fork()==0){
			//printf("jkewf\n");
			//for(int j=0;j<i;++j) printf("%s\n",exec[j]);
			if(strcmp(exec[0],"ls")==0){
				// printf("inside ls\n");
				// if(exec[1]==NULL){
				// 	DIR *folders;
				// 	struct dirent *file_names;

				// 	printf("never mind\n");
				// 	folders = opendir(".");
				// 	if(folders!= NULL){
				// 		printf("inside folders\n");
				// 		while((file_names= readdir(folders)) != NULL){
				// 			if(!(strcmp(file_names->d_name,".")==0 || strcmp(file_names->d_name,"..")==0))
				// 				printf("%s \t",file_names->d_name );
				// 		}
				// 		printf("\n");
				// 		closedir(folders);
				// 	}
				// }
				// else{
					strcat(root,"/ls");
					execv(root,exec);
					//ls(exec);
				//}
				//printf("ls opt ^^^ \n");
			}


			else if(strcmp(exec[0],"cat")==0){
				// if(exec[1]==NULL){
				// 	printf("ERROR: :Enter file name\n");
				// }
				// else{
					strcat(root,"/catto");
					execv(root,exec);
					
					//cat(exec);
				//}
			}


			else if(strcmp(exec[0],"rm")==0){
				if(exec[1]==NULL){
					printf("Enter a name\n");
				}
				else{
					strcat(root,"/rem");
					execv(root,exec);
					//execve("/home/verma/Desktop/Operating_Systems/Assign0/2016015/rem",exec,NULL);
					//rem(exec);
				}
			}


			else if(strcmp(exec[0],"date")==0){
				// if(exec[1]==NULL){
				// 	time_t Time;
				// 	struct tm *tm;
				// 	time(&Time);
				// 	tm=localtime(&Time);
				// 	char buffer[100];
				// 	strftime(buffer,100,"%a %b %d %X %Z %Y ", tm);
				// 	//printf("%d %d %d %d:%d%d IST %d \n",tm.tm_wday, tm.tm_mon +1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year+1900 );
				// 	printf("%s\n", buffer);
				// }
				// else{
				strcat(root,"/dato");
				execv(root,exec);
				// 	execve("/home/verma/Desktop/Operating_Systems/Assign0/2016015/dato",exec,NULL);
				// 	//date(exec);
				// }
			}


			else if(strcmp(exec[0],"mkdir")==0){
				// if(exec[1]==NULL){
				// 	printf("Enter a name\n");
				// }
				// else{
				// 	execve("/home/verma/Desktop/Operating_Systems/Assign0/2016015/mak",exec,NULL);
					//my_mkdir(exec);
				strcat(root,"/mak");
				execv(root,exec);
				//}
			}
			else {
				if(command_check==0)
					printf("Command not found\n");
			}
			exit(0);

		}
		else{
			wait(NULL);
		}

	}
	return 0;
}
