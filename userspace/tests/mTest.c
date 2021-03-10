#include "mapping.h"
#include "stdio.h"

char global;

int main()
{
  char local = 0xa;
  mapping(&local);
  mapping(&global);
  mapping(&printf);
  global = 0xab;
  printf("test\n");
  mapping(&global);
  mapping(&printf);
}