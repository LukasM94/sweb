#include "shm.h"
#include "sys/syscall.h"
#include "../../../common/include/kernel/syscall-definitions.h"
#include "types.h"

int setString(char* string)
{
  return __syscall(sc_set_string, (size_t)string, 0, 0, 0, 0);
}

int getString(char* string, int max_lentgh)
{
  return __syscall(sc_get_string, (size_t)string, (size_t)max_lentgh, 0, 0, 0);
}
