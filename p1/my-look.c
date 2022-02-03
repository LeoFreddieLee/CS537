#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]){

	int ch; //this is for getopt()
	char *dict;//this is for the file we will be looking at
	char *dst;//this is the string we are trying to find
	while((ch = getopt(argc, argv, "Vhf:"))!= -1){
		switch (ch){
			case 'V':
				printf("my-look from CS537 Spring 2022\n");
				exit(0);
			case 'h':
				printf("\n  use -v for the version of this app.\n\n  use -h to show this information.\n\n  use -f to specify the file you want to looking up.\n\n  if you don't use -f, you could type it by press enter.\n\n  two ways of using my-look:\n\n	1. my-look -f filename string\n\n	2. my-look string ,and then press enter, input your filename through keyboard.\n\n  string is what you wanna look for.\n");
				exit(0);
			case 'f':
				dict = optarg;
				break;
			case '?':
				printf("my-look:invalid command line\n");
				exit(1);
		}
	}
	if(dict == NULL){
		dict = (char*)malloc(100);
		if(fgets(dict,100,stdin)==NULL){
			printf("failed to read input");
			exit(0);
		}
		dict[strlen(dict)-1]=0;//omit the \n caused by fgets in the end of dict
	}

	dst = argv[argc-1];
	FILE *fp = fopen(dict, "r");
	if(fp == NULL){
		printf("my-look: cannot open file\n");
		exit(1);
	}
	char buffer[100];
	while(fgets(buffer,100,fp)){
		if(strncasecmp(buffer,dst,strlen(dst))==0){
			printf("%s",buffer);
		}
	}
	fclose(fp);

	return 0;
}
