#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	    const char *path = "file.txt";  // 소유자와 그룹을 변경할 파일 경로
					         uid_t uid = 1000;               // 새로운 소유자 ID
					            gid_t gid = 1000;               // 새로운 그룹 ID
					    
					                 if (chown(path, uid, gid) == -1) {
					                         perror("Error changing file ownership");
					                                 return 1;
					                                     }
					    					                                         return 0;
					                                         }
					                                         
