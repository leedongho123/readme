#include <stdio.h>
#include <dirent.h>

int main() {
	    DIR *dir;
	        struct dirent *ent;
		    if ((dir = opendir(".")) != NULL) {
			            while ((ent = readdir(dir)) != NULL) {
					                printf("%s\n", ent->d_name);
							        }
				            closedir(dir);
					        } else {
							        perror("디렉토리를 열 수 없습니다.");
								        return 1;
									    }
		        return 0;
}
