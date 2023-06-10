#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
	    char filesystem[256];
	        unsigned long long totalSize;
		    unsigned long long usedSize;
		        unsigned long long availableSize;
} FileSystemInfo;

int main() {
	    FILE *fp;
	        char buffer[BUFFER_SIZE];

		    fp = popen("df --output=filesystem,size,used,avail --block-size=1", "r");
		        if (fp == NULL) {
				        printf("Error executing df command.\n");
					        return 1;
						    }

			    FileSystemInfo fileSystems[100];
			        int fileSystemCount = 0;

				    // 첫 번째 라인은 헤더이므로 무시
		         fgets(buffer, BUFFER_SIZE, fp);
		    
	            while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
		                     char filesystem[256], size[32], used[32], avail[32];
		                             sscanf(buffer, "%s %s %s %s", filesystem, size, used, avail);
	    
	                                     strcpy(fileSystems[fileSystemCount].filesystem, filesystem);
			                                             fileSystems[fileSystemCount].totalSize = strtoull(size, NULL, 10);
                                                     fileSystems[fileSystemCount].usedSize = strtoull(used, NULL, 10);
                                                           fileSystems[fileSystemCount].availableSize = strtoull(avail, NULL, 10);

                                                                  fileSystemCount++;
                                                                      }

	                                                                      pclose(fp);
	 
	                                                                             // 결과 출력
	                                                                            printf("%-20s %-15s %-15s %-15s\n", "Filesystem", "Total Size", "Used Size", "Available Size");
	                                                                                     for (int i = 0; i < fileSystemCount; i++) {
	                                                                                     printf("%-20s %-15llu %-15llu %-15llu\n", fileSystems[i].filesystem, fileSystems[i].totalSize,
	                                                                                                         fileSystems[i].usedSize, fileSystems[i].availableSize);
                                                                                                       }
				    
                                                                                                                   return 0;
                                                                                                                   }
				    
