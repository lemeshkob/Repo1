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

char shiftLeftByOne(char myChar) {
	int msb = currentBit(myChar, 8);
	myChar <<= 1;
	myChar ^= msb;
	return myChar;
}

int main(void) {
	int i, counter = 3;
	char myChar = -99;
	puts("before");
	printCharBits(myChar);
	printf("\nafter %d times\n", counter);
	for (i = 0; i < counter; i++) {
		myChar = shiftLeftByOne(myChar);
	}
	printCharBits(myChar);

	return 0;
}