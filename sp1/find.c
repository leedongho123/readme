#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void find(const char *path, const char *pattern) {
	    DIR *dir = opendir(path);
	        if (dir == NULL) {
			        perror("디렉토리 열기 오류");
				        return;
					    }

		    struct dirent *entry;
		        struct stat fileStat;

			    while ((entry = readdir(dir)) != NULL) {
				            char childPath[256];
					            snprintf(childPath, sizeof(childPath), "%s/%s", path, entry->d_name);

						            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
								                continue;
										        }

							            if (stat(childPath, &fileStat) == -1) {
									                perror("파일 정보 가져오기 오류");
											            continue;
												            }

								            if (S_ISDIR(fileStat.st_mode)) {
										                find(childPath, pattern);
												        } else if (S_ISREG(fileStat.st_mode)) {
														            if (strstr(entry->d_name, pattern) != NULL) {
																                    printf("%s/%s\n", path, entry->d_name);
																		                }
															            }
									        }

			        closedir(dir);
}

int main(int argc, char *argv[]) {
	    if (argc != 2) {
		            printf("사용법: %s <패턴>\n", argv[0]);
			            return 1;
				        }

	        const char *pattern = argv[1];
		    find(".", pattern);

		        return 0;
}

