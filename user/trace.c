#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;
  char *nargv[MAXARG];

  // If not enough parameters are entered (e.g., trace mask command)
  if(argc < 3){
    fprintf(2, "Usage: trace mask command\n");
    exit(1);
  }

  // Convert the mask string (argv[1]) to an integer and call the system call trace
  if (trace(atoi(argv[1])) < 0) {
    fprintf(2, "trace: failed\n");
    exit(1);
  }

  // Prepare arguments to pass to exec (from argv[2] onwards)
  for(i = 2; i < argc && i < MAXARG; i++){
    nargv[i-2] = argv[i];
  }
  nargv[i-2] = 0; // Mark the end of the argument array

  // Execute the target command
  exec(nargv[0], nargv);

  // If exec fails
  fprintf(2, "exec %s failed\n", nargv[0]);
  exit(1);
}