#include <stdio.h>
#include <stdlib.h>

void cat(int argc, char *c[]){
	FILE *file_p;
	//printf("hello method\n");

	if(argc == 1){
		printf("ERROR: :Enter file name\n");
	}

	if(strcmp(c[1],"-n")==0){
		//printf("1st if\n");
		file_p =fopen(c[2],"r");
		if( file_p == NULL){
			perror("Error: ");
		}
		else{
			char * buffer=NULL;
			size_t l=0;
			ssize_t read;
			int count=1;
			while ((read= getline(&buffer,&l,file_p)) != -1){
				printf("%d %s",count++,buffer );
			}
			fclose(file_p);
		}

	}

	else if(strcmp(c[1],"-E")==0){
		//printf("2nd if\n");
		file_p =fopen(c[2],"r");
		if( file_p == NULL){
			perror("Error: ");
		}
		else{
			char * buffer=NULL;
			size_t l=0;
			ssize_t read;
			
			while ((read= getline(&buffer,&l,file_p)) != -1){
				strtok(buffer, "\n");
				printf("%s$ \n",buffer );
			}
			fclose(file_p);
		}

	}
	else{
		//printf("3rd if\n");
		file_p =fopen(c[1],"r");
		if( file_p == NULL){
			perror("Error: ");
		}
		else{
			char * buffer=NULL;
			size_t l=0;
			ssize_t read;
			
			while ((read= getline(&buffer,&l,file_p)) != -1){
				printf("%s ",buffer );
			}
			fclose(file_p);
		}
	}
	
	
}

int main(int argc, char const *argv[])
{
	//printf("hello to cat\n");
	cat(argc, argv);
	return 0;
}