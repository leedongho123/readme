#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
	    struct sysinfo info;

	        if (sysinfo(&info) == -1) {
			        perror("Error retrieving system information");
				        return 1;
					    }

		    unsigned long total_memory = info.totalram * info.mem_unit;
		        unsigned long free_memory = info.freeram * info.mem_unit;
			    unsigned long used_memory = total_memory - free_memory;

			        printf("Total memory: %lu bytes\n", total_memory);
				    printf("Used memory: %lu bytes\n", used_memory);
				        printf("Free memory: %lu bytes\n", free_memory);

					    return 0;
}

