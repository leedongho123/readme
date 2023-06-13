#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
	    char name[32];
	        char type[32];
		    char mountpoint[256];
} BlockDevice;

int main() {
	    FILE *fp;
	        char buffer[BUFFER_SIZE];

		    fp = popen("lsblk --output NAME,TYPE,MOUNTPOINT --noheadings", "r");
		        if (fp == NULL) {
				        printf("Error executing lsblk command.\n");
					        return 1;
						    }

			    BlockDevice devices[100];
			        int deviceCount = 0;

				    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
					            char name[32], type[32], mountpoint[256];
						            sscanf(buffer, "%s %s %s", name, type, mountpoint);

							            strcpy(devices[deviceCount].name, name);
								            strcpy(devices[deviceCount].type, type);
									            strcpy(devices[deviceCount].mountpoint, mountpoint);

										            deviceCount++;
											        }

				        pclose(fp);

					    // 결과 출력
					         printf("NAME\t\tTYPE\t\tMOUNTPOINT\n");
					             for (int i = 0; i < deviceCount; i++) {
					                     printf("%s\t\t%s\t\t%s\n", devices[i].name, devices[i].type, devices[i].mountpoint);
					                         }
					    
					                             return 0;
					                             }
					                             
