#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if(argc != 3) {
		fprintf(stderr, "Usage: %s n m\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	const long n = atoi(argv[1]);
	const long m = atoi(argv[2]);
	long pairs[n+1];
	pairs[0] = 1;
	pairs[1] = 1;
	pairs[2] = 1;
	long i;
	for(i = 3; i <= n; ++i) {
		pairs[i] = pairs[i-1] + pairs[i-2];
		if(i > m) {
			// These rabbits are guaranteed to be dead.
			pairs[i] -= pairs[i-m-1];
		}
	}
	printf("%li\n", pairs[n]);
	return 0;
}
