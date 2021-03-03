#include "shm.h"
#include "stdio.h"

#define SIZE 64

int main()
{
  __attribute__((unused))char* test = "test";
  char dst[SIZE];
  getString(dst, SIZE);
  printf("%s\n", dst);
}