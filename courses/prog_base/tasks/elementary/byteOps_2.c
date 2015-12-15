#include <stdio.h>

int currentBit(char myByte, int index) {
	char mask = 1;
	mask <<= index - 1;
	mask &= myByte;
	mask >>= index - 1;
	if (mask == -1) {
		mask = 1;
	}
	return mask;
}

void printCharBits(char myChar) {
	int i, curBit;
	for (i = 8; i > 0; i--) {
		curBit = currentBit(myChar, i);
		printf("%d ", curBit);
	}
}

int main() {
	printCharBits('-');
	return 0;
}