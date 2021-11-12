#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char **parse_args(char *line);
int main(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  char **listargs = parse_args(argv[1]);

  int i = 0;
  while (listargs[i] != NULL) {
    printf("[%d] %s\n",i,listargs[i]);
    i++;
  }
  execvp(listargs[0],listargs);
  return 0;
}

char **parse_args(char *line) {
  char *strend = strchr(line,'\0');
  char *strtemp = line;

  char **liststr;
  int length = 0;
  while (strtemp < strend) {
    char *strstart = strtemp;
    if (strtemp != line) {
      *(strtemp - 1) = ' ';
    }
    if (strchr(strtemp,' ') != NULL) {
      strsep(&strtemp," ");
    } else {
      strtemp = strend;
    }
    length++;
  }
  liststr = malloc((length + 1) * sizeof(char *));
  
  int i = 0;
  strtemp = line;
  while (strtemp < strend) {
    char *strstart = strtemp;
    if (strtemp != line) {
      *(strtemp - 1) = ' ';
    }
    if (strchr(strtemp,' ') != NULL) {
      strsep(&strtemp," ");
    } else {
      strtemp = strend;
    }
    liststr[i] = malloc(strlen(strstart) + 1);
    strcpy(liststr[i],strstart);
    i++;
  }
  liststr[i] = NULL;
  return liststr;
}
