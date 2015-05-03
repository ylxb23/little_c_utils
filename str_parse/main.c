#include <stdio.h>

char **parse_line(char *, char *);

int main()
{
  char line[] = "hello world; how many arguments";
  char **origen = parse_line(line, ";");
  char **arglist = origen;
  char **arguments, **tmp;
  while (*arglist != NULL) {
    printf("%s\n", *arglist);

    arguments = parse_line(*arglist, " \t");
    tmp = arguments; 
    while (*tmp != NULL) {
      printf("%s\n", *tmp);
      tmp++;
    }
    printf("\n");

    arglist++;
  }

  return (0);
}
