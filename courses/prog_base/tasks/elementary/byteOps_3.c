#include <stdio.h>

char changeNBitToZero(char myByte, int N) {
	char mask = 1;
	mask <<= N - 1;
	mask ^= -1; //or 255 or 0xff
	myByte &= mask;
	return myByte;
}

char changeNBitToOne(char myByte, int N) {
	char mask = 1;
	mask <<= N - 1;
	myByte |= mask;
	return myByte;
}

int main(void) {
	char myVar;
	myVar = changeNBitToZero('q', 6); //myVar = 'Q'
	myVar = changeNBitToOne('Q', 6); //myVar = 'q'
	return 0;
}