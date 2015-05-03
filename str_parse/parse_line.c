#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DFL_LINESIZE 20

/*
 * purpose: parse a line into seperate arguments
 * return: vectors of arguments
 */
char **parse_line(char *line, char *delstr)
{
  int linesize = DFL_LINESIZE;
  int position = 0; /* which line are we */
  char **arglist = malloc(sizeof(char *) * linesize); /* default argument length */
  char *token;

  if (!arglist) {
    fprintf(stderr, "parse_line: allocate memory failed");
    exit(-1);
  }

  token = strtok(line, delstr);
  while (token != NULL) {
    arglist[position] = token;
    position++;

    if (position >= linesize) {
      linesize += DFL_LINESIZE;
      arglist = realloc(arglist, linesize * sizeof(char *));
      
      /* remember to check if the realloc failed !*/
      if (arglist == NULL) {
        fprintf(stderr, "parse_line: reallocate memory failed");
        exit(-1);
      }
    }
    token = strtok(NULL, delstr);
  }

  /* end the string vector with NULL */
  arglist[position] = NULL;

  return arglist;
}
