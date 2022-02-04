/***Copyright [2022] <Yidong Li> [copyright]***/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]) {
  int ch;  // this is for getopt()
  char *dict;  // this is for the file we will be looking at
  char *dst;  // this is the string we are trying to find
  while ((ch = getopt(argc, argv, "Vhf:"))!= -1) {
    switch (ch) {
      case 'V':
        printf("my-look from CS537 Spring 2022\n");
        exit(0);
      case 'h':
        printf("\n  use -v for the version of this app.\n\n  ");
        printf("use -h to show this information.\n\n  ");
        printf("use -f to specify the file you want to looking up.\n\n  ");
        printf("if you don't use -f, you could type it by press enter.\n\n  ");
        printf("2 ways of using it:\n\n  ");
        printf("  1. my-look -f filename string\n\n  ");
        printf("  2. my-look string ; press enter, input your filename.\n\n  ");
        printf("  string is what you wanna look for.\n");
        exit(0);
      case 'f':
        dict = optarg;
        break;
      case '?':
        printf("my-look: invalid command line\n");
        exit(1);
    }
  }
  dst = argv[argc-1];
  if (dict == NULL) {
    char input[100];
    while (fgets(input, 100, stdin) != NULL) {
      if (strncasecmp(input, dst, strlen(dst)) == 0) {
        printf("%s", input);
      }
    }
  } else {
    FILE *fp = fopen(dict, "r");
    if (fp == NULL) {
      printf("my-look: cannot open file\n");
      exit(1);
    }
    char buffer[100];
    while (fgets(buffer, 100, fp)) {
      printf("%s's length is %zu\n", buffer, strlen(buffer));
      if (strncasecmp(buffer, dst, strlen(dst)) == 0) {
        printf("%s", buffer);
      }
    }
    fclose(fp);
  }
  return 0;
}
