#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	    char device[] = "/dev/sdb1";  // 마운트할 장치 경로
					     char mountpoint[] = "/mnt/usb";  // 마운트 지점 경로
					 
					          char command[256];
					              sprintf(command, "mount %s %s", device, mountpoint);
					 
					                  int result = system(command);
					                      if (result == -1) {
					                              printf("Error executing mount command.\n");
					                                      return 1;
					                                          } else if (WIFEXITED(result) && WEXITSTATUS(result) == 0) {
					                                                  printf("Mount successful.\n");
					                                                      } else {
					                                                              printf("Mount failed.\n");
					                                                                  }
					 
					                                                                     return 0;
					                                                                      }
					                                                                      
