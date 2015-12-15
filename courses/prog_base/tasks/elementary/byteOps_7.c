#include <stdio.h>

int currentBit(short myByte, int index) {
	short mask = 1;
	mask <<= index - 1;
	mask &= myByte;
	mask >>= index - 1;
	if (mask == (short)0xffff) {
		mask = 1;
	}
	return mask;
}

void printShortBits(short myShort) {
	int i, curBit;
	for (i = 16; i > 0; i--) {
		curBit = currentBit(myShort, i);
		printf("%d ", curBit);
	}
}

short shiftShortRightByOne(short myShort) {
	int msb = currentBit(myShort, 16);
	myShort >>= 1;
	//@todo: take from byteOps_2 functions to change N bit to 0 or 1. Fix them for short. Add if()else{}

	return myShort;
}

int main(void) {
	printShortBits(-25000);

	return 0;
}