#include <stdio.h>

void message_usage(char *programName)
{
  printf("Usage: %s [options]\n", programName);
  printf("\n");
  printf("Options:\n");
  printf("  -l              Show license\n");
  printf("  -d              Run daemon, passing incoming messages from the WAN address\n");
  printf("                  to clients connected to the LAN socket.\n");
  printf("  -c              Run client, passing remote message to a local server\n");
  printf("  -P proto[:arg]  Select which transfer protocol to listen for.\n");
  printf("  -L addr[:port]  Set the LOCAL address\n");
  printf("                      daemon\n");
  printf("                          Determines the local listening address.\n");
  printf("                          The default port will be 666.\n");
  printf("                      client\n");
  printf("                          Determines the address of the 'local' server.\n");
  printf("                          Messages will be sent towards this address.\n");
  printf("  -R addr[:port]  Set the REMOTE address\n");
  printf("                      daemon\n");
  printf("                          Sets the remote address (where external messages\n");
  printf("                          enter the system). The port will be ignored as\n");
  printf("                          the client specified which port to listen on.\n");
  printf("                      client\n");
  printf("                          Defines where the remote server is located\n");
  printf("                          (a running daemon of this program). The default\n");
  printf("                          port is 666.");
  printf("\n");
}

void message_license()
{
  printf("\n");
  printf("MIT LICENSE\n");
  printf("\n");
  printf("Copyright (c) 2016 finwo\n");
  printf("\n");
  printf("Permission is hereby granted, free of charge, to any person obtaining a copy\n");
  printf("of this software and associated documentation files (the \"Software\"), to deal\n");
  printf("in the Software without restriction, including without limitation the rights\n");
  printf("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n");
  printf("copies of the Software, and to permit persons to whom the Software is\n");
  printf("furnished to do so, subject to the following conditions:\n");
  printf("\n");
  printf("The above copyright notice and this permission notice shall be included in all\n");
  printf("copies or substantial portions of the Software.\n");
  printf("\n");
  printf("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n");
  printf("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n");
  printf("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n");
  printf("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n");
  printf("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n");
  printf("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n");
  printf("SOFTWARE.\n");
  printf("\n");
}
