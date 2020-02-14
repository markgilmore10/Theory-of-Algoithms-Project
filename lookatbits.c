#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void printbits(uint8_t s) {

	for (int i = (8 - 1); i >= 0; i--)
		printf("%d", ((1ULL << i) & s) ? 1 : 0);
}

int main(int argc, char *argv[]) {

	uint8_t a = 73;
	uint8_t b = 99;
	uint8_t c = (a & b);
	uint8_t d = (a | b);
	uint8_t e = (a ^ b);

	printf(" a = "); printbits(a); printf("\n");
	printf(" b = "); printbits(b); printf("\n\n");

	printf(" c = "); printbits(c); printf("\n");
	printf(" d = "); printbits(a); printf("\n");
	printf(" e = "); printbits(a); printf("\n\n");
	
	printf(" a = "); printbits( a); printf("\n");
	printf("~a = "); printbits(~a); printf("\n\n"); // Swaps 1's and 0's
	
	printf(" 1       = "); printbits( 1      ); printf("\n");
	printf("(1 << 3) = "); printbits((1 << 3)); printf("\n\n"); // Pushes everything up 3 positions, right to left

	printf(" 73       = "); printbits( 73      ); printf("\n");
	printf("(73 << 3) = "); printbits((a << 3)); printf("\n\n"); // Pushes everything up 3 positions, right to left

	printf(" 99       = "); printbits( 99      ); printf("\n");
	printf("(99 << 3) = "); printbits((b << 3)); printf("\n\n"); // Pushes everything up 3 positions, right to left

	printf("              99 = "); printbits(        99      ); printf("\n");
	printf("(1ULL << 3)      = "); printbits((1ULL << 3)     ); printf("\n"); // Pushes everything up 3 positions, right to left
	printf("(1ULL << 3) & 99 = "); printbits((1ULL << 3) & b ); printf("\n\n"); // Pushes everything up 3 positions, right to left

	printf("              99 = "); printbits(        99      ); printf("\n");
	printf("(1ULL << 5)      = "); printbits((1ULL << 5)     ); printf("\n"); // Pushes everything up 5 positions, right to left
	printf("(1ULL << 5) & 99 = "); printbits((1ULL << 5) & b ); printf("\n\n"); // Prints out a 1 if 1 in position 5 vice versa	

	return 0;

}
