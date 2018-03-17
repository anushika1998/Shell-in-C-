#include <stdio.h>
#include <string.h>

char *root[100];

void last_occ(char *);

void last_occ(char *line){
	char *tkn=NULL;
	tkn=strtok(line,"/");
	
	char *exec[100];
	int i=0;
	//root = (char *) malloc(15);
	
	while(tkn !=NULL){
		root[i] = (char *) malloc(strlen(tkn)+1);
		strcpy(root[i],tkn);
		//printf("%d\n",strlen(tkn));
		tkn=strtok(NULL," ");
		i++;
	}
	
	root[i]=NULL;
	
}

int main (){
	char *s;
	gets(s);
	
	last_occ(s);


	printf("%s\n",root[0] );
}