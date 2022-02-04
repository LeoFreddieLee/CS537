/***Copyright [2022] <Yidong Li> [copyright]***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("wordle: invalid number of args\n");
    exit(1);
  }
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("wordle: cannot open file\n");
    exit(1);
  }
  char buffer[255];
  while (fgets(buffer, 255, fp)) {
    for (int i = 0; i < strlen(buffer); i ++) {
      if (buffer[i] == '\r') {
        buffer[i] = '\n';
        buffer[i+1] = '\0';
        break;
      }
    }
    if (!strpbrk(buffer, argv[2]) && strlen(buffer) == 6) {
      printf("%s", buffer);
    }
  }
  fclose(fp);
  return 0;
}
