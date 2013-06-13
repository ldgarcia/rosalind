#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if(argc != 3) {
		fprintf(stderr, "Usage: %s n k\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	const long n = atoi(argv[1]);
	const long k = atoi(argv[2]);
	long pairs[n];
	pairs[0] = 1;
	pairs[1] = 1;
	long i;
	for(i = 2; i < n; ++i) {
		// Rabbits reach reproductive age after one month.
		pairs[i] = pairs[i-1] + pairs[i-2] * k;
	}
	printf("%li\n", pairs[n-1]);
	return 0;
}
