#pragma once

#include "Mutex.h"
// Singleton

class Shm
{
  public:
    ~Shm();
    static Shm* instance();
    int setString(char* string);
    int getString(char* string, int max_length);

  private:
    Shm();
    static Shm* instance_;
    char* string_;
    Mutex lock_;
};
