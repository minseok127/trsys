#include <mimalloc.h>
#include <stdio.h>

int main() {
	mi_option_enable(mi_option_verbose);

	void* ptr = malloc(1024);
	if (ptr == NULL) {
		fprintf(stderr, "Memory allocation failed!\n");
		return 1;
	}

	printf("Memory allocated at %p\n", ptr);

	free(ptr);

	return 0;
}

