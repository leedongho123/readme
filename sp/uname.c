#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main() {
	    struct utsname sysInfo;

	        if (uname(&sysInfo) == -1) {
			        printf("Error executing uname command.\n");
				        return 1;
					    }

		    printf("System Name: %s\n", sysInfo.sysname);
		        printf("Node Name  : %s\n", sysInfo.nodename);
			    printf("Release    : %s\n", sysInfo.release);
			        printf("Version    : %s\n", sysInfo.version);
				    printf("Machine    : %s\n", sysInfo.machine);

				        return 0;
}

