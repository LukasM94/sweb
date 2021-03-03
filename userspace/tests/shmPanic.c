#include "shm.h"

int main()
{
  // setString((char*)0xdeadbeaf);
  getString((char*)0xdeadbeaf, 1);
}