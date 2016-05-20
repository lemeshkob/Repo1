#include <stdio.h>

//char myByte - one-byte variable.
//int index - position of the desired byte in range [1;8]
int printBit(char myByte, int index) {
	char mask = 1;
	mask <<= index - 1;
	mask &= myByte;
	mask >>= index - 1;
	if (mask == -1) {1
		mask = 1;
	}
	return mask;
}

int main(void) {
	int result = printBit('H', 7);
	printf("%d\n", result);
}

