#include <unistd.h>

#include "messages.h"

int main(int argc, char **argv)
{
  unsigned int flags = 0;
  int opt = 0;
  
  while ((opt=getopt(argc,argv,"dl")) != -1) {
    switch(opt) {
      case 'd':
        flags |= 2;
        break;
      case 'l':
        flags |= 1;
        break;
      default:
        break;
    }
  }
  
  if (flags==0) {
    message_usage(*argv);
    return 1;
  }
  
  if (flags&1) {
    message_license();
    return 0;
  }
  
  return 0;
}