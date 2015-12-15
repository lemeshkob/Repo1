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

void invertBits(char myByte1) {
	char mask = ~myByte1;
	printCharBits(mask);
}

int main(void) {
	char myChar = 'Z';
	puts("before");
	printCharBits(myChar);
	puts("\nafter");
	invertBits(myChar);

	return 0;
}