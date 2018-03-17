#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void rem(int argc, char *c[]){
	if(argc==1){
		printf("Enter a name\n");
	}

	if(strcmp(c[1],"-v")==0){
		DIR *dir =opendir(c[2]);
		if(dir){
			printf("It is a Directory\n");
			closedir(dir);
		}
		else{
			int result=remove(c[2]);
			if(result == 0){
				printf("File deleted successfully \n" );
			}
			else{
				printf("Error: unable to delete the file");

			}
		}
	}
	else if(strcmp(c[1],"-i")==0){
		printf("Do you want to delete this file\n");
		char ans[10];
		gets(ans);
		char *temp;
		temp=strtok(ans," ");
		printf("%stemp\n",temp );
		if (strcmp(temp,"no")==0 ||strcmp(temp,"No")==0 )
		{
			printf("++++\n");
		}
		else{
			printf("yoyo\n");
			DIR *dir =opendir(c[2]);
			if(dir){
				printf("It is a Directory\n");
				closedir(dir);
			}
			else{
				int result=remove(c[2]);
				if(result == 0){
					printf("File deleted successfully \n" );
				}
				else{
					printf("Error: unable to delete the file");

				}
			}
		}
	}
	else{
		DIR *dir =opendir(c[1]);
		if(dir){
			printf("It is a Directory\n");
			closedir(dir);
		}
		else{
			int result = remove(c[1]);
			if(result == 0){
				printf("File deleted successfully \n" );
			}
			else{
				printf("Error: unable to delete the file");

			}
		}
	}
}

int main(int argc, char const *argv[])
{
	rem(argc, argv);
	return 0;
}