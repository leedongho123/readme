#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	    if (argc < 2) {
		            printf("Usage: %s <command>\n", argv[0]);
			            return 1;
				        }

	        const char *command = argv[1];

		   // Check if the command is an absolute path
		         if (access(command, X_OK) == 0) {
		                printf("%s\n", command);
		                         return 0;
		                            }
			 // Get the PATH environment variable
                    const char *path_env = getenv("PATH");
                                       if (path_env == NULL) {
                                               printf("Error retrieving PATH environment variable\n");
                                                    return 1;
                                               }
                                char *path_env_copy = strdup(path_env);
                                       if (path_env_copy == NULL) {
                                     printf("Error allocating memory\n");
                                                    return 1;
                                                  }
                              // Tokenize the PATH variable by ":"
                                            char *path = strtok(path_env_copy, ":");
                                                 while (path != NULL) {
                                // Construct the full command path
		                                                                                                                     size_t command_path_len = strlen(path) + strlen(command) + 2;
		                                                                                                                             char *command_path = malloc(command_path_len);
		                                                                                                                                     if (command_path == NULL) {
		                                                                                                                                                printf("Error allocating memory\n");
		                                                                                                                                                            free(path_env_copy);
		                                                                                                                                                                        return 1;
		                                                                                                                                                                                }
                                                                                                                                                                snprintf(command_path, command_path_len, "%s/%s", path, command);
                                                                                                                                                                   // Check if the command exists
                                                                                                                                                                                     if (access(command_path, X_OK) == 0) {
                                                                                                                                                                                             printf("%s\n", command_path);
                                                                                                                                                                                               free(command_path);
                                                                                                                                                                                             free(path_env_copy);
                                                                                                                                                                                                       return 0;
                                                                                                                                                                                                               }
	    
                                                                                                                                                                                      free(command_path);
                                                                                                                                                                                               path = strtok(NULL, ":");
                                                                                                                                                                                                                  }
		    
		                                                                                                                                                                                                                                                                                         free(path_env_copy);
		    
		                                                                                                                                                                                                                                                                                             printf("%s: command not found\n", command);
		                                                                                                                                                                                                                                                                                                 return 1;
		                                                                                                                                                                                                                                                                                                 }
		                                                                                                                                                                                                                                                                                                 
