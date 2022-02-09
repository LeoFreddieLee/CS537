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
  if (argc == 1 || argv[argc-1] == NULL) {
    printf("my-look: invalid command line\n");
    exit(1);
  }
  dst = argv[argc-1];
  if (dict == NULL) {
    char input[10000];
    while (fgets(input, 10000, stdin)) {
      char *tmp = malloc(10000);
      int j = 0;
      for (int i = 0; i < strlen(input); i++) {
        if ((input[i] >= 48 && input[i] <= 57) ||
          (input[i] >= 65 && input[i] <= 90) ||
          (input[i] >= 97 && input[i] <= 122)) {
          tmp[j] = input[i];
          j++;
          }
      }
      if (strncasecmp(tmp, dst, strlen(dst)) == 0) {
        printf("%s", input);
      }
      free(tmp);
    }
  } else {
    FILE *fp = fopen(dict, "r");
    if (fp == NULL) {
      printf("my-look: cannot open file\n");
      exit(1);
    }
    char buffer[10000];
    while (fgets(buffer, 10000, fp)) {
      char *tmp = malloc(10000);
      int j = 0;
      for (int i = 0; i < strlen(buffer); i++) {
        if ((buffer[i] >= 48 && buffer[i] <= 57)
          || (buffer[i] >= 65 && buffer[i] <= 90) ||
          (buffer[i] >= 97 && buffer[i] <= 122)) {
          tmp[j] = buffer[i];
          j++;
          }
        }
      if (strncasecmp(tmp, dst, strlen(dst)) == 0) {
        printf("%s", buffer);
      }
      free(tmp);
    }
    fclose(fp);
  }
  return 0;
}
