#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  struct sysinfo info;

  // Call the sysinfo system call and pass the address of the info struct
  if (sysinfo(&info) < 0) {
    printf("sysinfo fail\n");
    exit(1);
  }

  // Print the collected parameters to the screen
  printf("--- Sysinfo Test ---\n");
  printf("Free memory (bytes): %d\n", (int)info.freemem);
  printf("Number of active processes: %d\n", (int)info.nproc);
  printf("Number of open files: %d\n", (int)info.nopenfiles);
  printf("--------------------\n");

  exit(0);
}
