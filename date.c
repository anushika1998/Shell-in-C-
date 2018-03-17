#include <time.h>

void date(int argc, char *c[]){
	time_t Time;
	struct tm *tm;
	time(&Time);
	tm=localtime(&Time);
	char buffer[100];

	if(argc==1){
		time_t Time;
		struct tm *tm;
		time(&Time);
		tm=localtime(&Time);
		char buffer[100];
		strftime(buffer,100,"%a %b %d %X %Z %Y ", tm);
		//printf("%d %d %d %d:%d%d IST %d \n",tm.tm_wday, tm.tm_mon +1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year+1900 );
		printf("%s\n", buffer);
	}

	if(strcmp(c[1],"-I")==0){
		strftime(buffer,100,"%Y-%m-%d ", tm);
		//printf("%d %d %d %d:%d%d IST %d \n",tm.tm_wday, tm.tm_mon +1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year+1900 );
		printf("%s\n", buffer);
	}
	else if (strcmp(c[1],"-R")==0){
		strftime(buffer,100,"%a, %d %b %Y %X %Z ", tm);
		//printf("%d %d %d %d:%d%d IST %d \n",tm.tm_wday, tm.tm_mon +1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year+1900 );
		printf("%s +0530\n", buffer);
	}

}

int main(int argc, char const *argv[])
{
	date(argc, argv);
	return 0;
}