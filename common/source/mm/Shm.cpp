#include "Shm.h"
#include "debug.h"
#include "kstring.h"
#include "MutexLock.h"

Shm* Shm::instance_ = 0;

Shm::Shm() :
  string_(0),
  lock_("Shm::lock_")
{
  debug(SHM, "ctor\n");
}

Shm::~Shm()
{
  if (string_ != 0)
  {
    delete string_;
  }
  debug(SHM, "dtor\n");
}

Shm* Shm::instance()
{
  if (instance_ == 0)
  {
    instance_ = new Shm();
  }
  return instance_;
}

int Shm::setString(char* string)
{
  debug(SHM, "setString: string <%p>\n", string);
  int length = strlen(string);
  MutexLock ml(lock_);
  if (string_ != 0)
  {
    return -1;
  }
  string_ = new char[length+1];
  memset(string_, 0, length+1);
  strncpy(string_, string, length);
  debug(SHM, "setString: string <%s>\n", string_);
  return 0;
}

int Shm::getString(char* string, int max_length)
{
  debug(SHM, "getString: string <%p> max_length <%d>\n", string, max_length);
  char temp[max_length];
  memset(temp, 0, max_length);
  lock_.acquire();
  if (string_ == 0)
  {
    lock_.release();
    return -1;
  }
  strncpy(temp, string_, max_length);
  lock_.release();
  strncpy(string, temp, max_length);
  return 0;
}
