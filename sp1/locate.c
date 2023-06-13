#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	    char command[512];
	        char filename[512];

		    printf("Enter the filename to search: ");
		        fgets(filename, sizeof(filename), stdin);
			    filename[strcspn(filename, "\n")] = '\0';  // 개행 문자 제거
								       
					  snprintf(command, sizeof(command), "locate %s", filename);
					   FILE *fp = popen(command, "r");
					     if (fp == NULL) {
					        perror("Error executing command");
					                   return 1;
					             }
					 char result[256];
					         while (fgets(result, sizeof(result), fp) != NULL) {
					                 printf("%s", result);
					                        }
					            pclose(fp);
					             return 0;
					    }
								       
