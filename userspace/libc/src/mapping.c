#include "mapping.h"
#include "sys/syscall.h"
#include "../../../common/include/kernel/syscall-definitions.h"
#include "types.h"

void mapping(void* address)
{
  __syscall(sc_mapping, (size_t)address, 0, 0, 0, 0);
}