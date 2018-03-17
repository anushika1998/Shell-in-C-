#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

void my_mkdir(int argc, char *c[]){

	if(argc==1){
		printf("Enter a name\n");
	}


	if(strcmp(c[1],"-v")==0){
		DIR* dir =opendir(c[2]);
		if(dir){
			printf("Directory already exists\n");
			closedir(dir);
		}
		else{
			mkdir((const char *)c[2], S_IRWXU);
			printf("Directory has been created \n" );
		}
	}
	else if(strcmp(c[1],"-m")==0){
		int mode =atoi(c[2]);

		DIR* dir =opendir(c[3]);
		if(dir){
			printf("Directory already exists\n");
			closedir(dir);
		}
		else{
			mkdir((const char *)c[3], mode);
			printf("Directory has been created \n" );
		}
	}
	else{
		DIR* dir =opendir(c[1]);
		if(dir){
			printf("Directory already exists\n");
			closedir(dir);
		}
		else{
			mkdir((const char *)c[1], S_IRWXU);
		}
	}
}

int main(int argc, char const *argv[])
{
	my_mkdir(argc, argv);
	return 0;
}