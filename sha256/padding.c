// Mark Gilmore
// Padding for SHA256
// https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.180-4.pdf

#include <stdio.h>
#include <inttypes.h>

uint64_t nozerobytes(uint64_t nobits) {

	uint64_t result = 512ULL - (nobits % 512ULL);

	if (result < 65)
		result += 512;

	result -= 72;
	return (result / 8ULL);
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("Error: Single filename as argument expected.\n");
		return 1;
	}

	FILE *infile = fopen(argv[1], "rb");

	if (!infile) {
		printf("Error: Could not open file %s.\n", argv[1]);
		return 1;
	}

	uint8_t b;
	uint64_t nobits;

	for (nobits = 0; fread(&b, 1, 1, infile) == 1; nobits += 8) {

		printf("%02x" PRIx8 "\n", nobits);
	}

	printf("%02" PRIx8 " ", 0x80); // Bits: 1000 0000

	for (uint64_t i = nozerobytes(nobits); i > 0; i--) {

		printf("%02" PRIx8 " ", 0x00);

	}

	printf("%016" PRIx64 " ", b);

	printf("\n");

	fclose(infile);

	return 0;

}


