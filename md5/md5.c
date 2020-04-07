#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
//#include <byteswap.h>

#define WORD uint32_t
#define BYTE uint8_t

const WORD K[] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define FF(a,b,c,d,x,s,ac) { \
  a += F(b,c,d) + x + ac; \
  a = b + ROTATE_LEFT(a,s); \
}

#define GG(a,b,c,d,x,s,ac) { \
  a += G(b,c,d) + x + ac; \
  a = b + ROTATE_LEFT(a,s); \
}

#define HH(a,b,c,d,x,s,ac) { \
  a += H(b,c,d) + x + ac; \
  a = b + ROTATE_LEFT(a,s); \
}

#define II(a,b,c,d,x,s,ac) { \
  a += I(b,c,d) + x + ac; \
  a = b + ROTATE_LEFT(a,s); \
}

#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

typedef union {
  uint64_t sixfour[8];
  WORD threetwo[16];
  uint8_t eight[64];
} BLOCK;

typedef enum {
  READ, 
  PAD0, 
  FINISH
} PADFLAG;

void md5Transform(BLOCK *M, WORD *H) {

  WORD a = H[0];
  WORD b = H[1];
  WORD c = H[2];
  WORD d = H[3];

  /* Round 1 */
  FF( a, b, c, d, M->threetwo[ 0], S11, K[ 0]); /* 1  */
  FF (d, a, b, c, M->threetwo[ 1], S12, K[ 1]); /* 2  */
  FF (c, d, a, b, M->threetwo[ 2], S13, K[ 2]); /* 3  */
  FF (b, c, d, a, M->threetwo[ 3], S14, K[ 3]); /* 4  */
  FF (a, b, c, d, M->threetwo[ 4], S11, K[ 4]); /* 5  */
  FF (d, a, b, c, M->threetwo[ 5], S12, K[ 5]); /* 6  */
  FF (c, d, a, b, M->threetwo[ 6], S13, K[ 6]); /* 7  */
  FF (b, c, d, a, M->threetwo[ 7], S14, K[ 7]); /* 8  */
  FF (a, b, c, d, M->threetwo[ 8], S11, K[ 8]); /* 9  */
  FF (d, a, b, c, M->threetwo[ 9], S12, K[ 9]); /* 10 */
  FF (c, d, a, b, M->threetwo[10], S13, K[10]); /* 11 */
  FF (b, c, d, a, M->threetwo[11], S14, K[11]); /* 12 */
  FF (a, b, c, d, M->threetwo[12], S11, K[12]); /* 13 */
  FF (d, a, b, c, M->threetwo[13], S12, K[13]); /* 14 */
  FF (c, d, a, b, M->threetwo[14], S13, K[14]); /* 15 */
  FF (b, c, d, a, M->threetwo[15], S14, K[15]); /* 16 */
  
  /* Round 2 */
  GG (a, b, c, d, M->threetwo[ 1], S21, K[16]); /* 17 */
  GG (d, a, b, c, M->threetwo[ 6], S22, K[17]); /* 18 */
  GG (c, d, a, b, M->threetwo[11], S23, K[18]); /* 19 */
  GG (b, c, d, a, M->threetwo[ 0], S24, K[19]); /* 20 */
  GG (a, b, c, d, M->threetwo[ 5], S21, K[20]); /* 21 */
  GG (d, a, b, c, M->threetwo[10], S22, K[21]); /* 22 */
  GG (c, d, a, b, M->threetwo[15], S23, K[22]); /* 23 */
  GG (b, c, d, a, M->threetwo[ 4], S24, K[23]); /* 24 */
  GG (a, b, c, d, M->threetwo[ 9], S21, K[24]); /* 25 */
  GG (d, a, b, c, M->threetwo[14], S22, K[25]); /* 26 */
  GG (c, d, a, b, M->threetwo[ 3], S23, K[26]); /* 27 */
  GG (b, c, d, a, M->threetwo[ 8], S24, K[27]); /* 28 */
  GG (a, b, c, d, M->threetwo[13], S21, K[28]); /* 29 */
  GG (d, a, b, c, M->threetwo[ 2], S22, K[29]); /* 30 */
  GG (c, d, a, b, M->threetwo[ 7], S23, K[30]); /* 31 */
  GG (b, c, d, a, M->threetwo[12], S24, K[31]); /* 32 */

  /* Round 3 */
  HH (a, b, c, d, M->threetwo[ 5], S31, K[32]); /* 33 */
  HH (d, a, b, c, M->threetwo[ 8], S32, K[33]); /* 34 */
  HH (c, d, a, b, M->threetwo[11], S33, K[34]); /* 35 */
  HH (b, c, d, a, M->threetwo[14], S34, K[35]); /* 36 */
  HH (a, b, c, d, M->threetwo[ 1], S31, K[36]); /* 37 */
  HH (d, a, b, c, M->threetwo[ 4], S32, K[37]); /* 38 */
  HH (c, d, a, b, M->threetwo[ 7], S33, K[38]); /* 39 */
  HH (b, c, d, a, M->threetwo[10], S34, K[39]); /* 40 */
  HH (a, b, c, d, M->threetwo[13], S31, K[40]); /* 41 */
  HH (d, a, b, c, M->threetwo[ 0], S32, K[41]); /* 42 */
  HH (c, d, a, b, M->threetwo[ 3], S33, K[42]); /* 43 */
  HH (b, c, d, a, M->threetwo[ 6], S34, K[43]); /* 44 */
  HH (a, b, c, d, M->threetwo[ 9], S31, K[44]); /* 45 */
  HH (d, a, b, c, M->threetwo[12], S32, K[45]); /* 46 */
  HH (c, d, a, b, M->threetwo[15], S33, K[46]); /* 47 */
  HH (b, c, d, a, M->threetwo[ 2], S34, K[47]); /* 48 */
  /* Round 4 */
  II (a, b, c, d, M->threetwo[ 0], S41, K[48]); /* 49 */
  II (d, a, b, c, M->threetwo[ 7], S42, K[49]); /* 50 */
  II (c, d, a, b, M->threetwo[14], S43, K[50]); /* 51 */
  II (b, c, d, a, M->threetwo[ 5], S44, K[51]); /* 52 */
  II (a, b, c, d, M->threetwo[12], S41, K[52]); /* 53 */
  II (d, a, b, c, M->threetwo[ 3], S42, K[53]); /* 54 */
  II (c, d, a, b, M->threetwo[10], S43, K[54]); /* 55 */
  II (b, c, d, a, M->threetwo[ 1], S44, K[55]); /* 56 */
  II (a, b, c, d, M->threetwo[ 8], S41, K[56]); /* 57 */
  II (d, a, b, c, M->threetwo[15], S42, K[57]); /* 58 */
  II (c, d, a, b, M->threetwo[ 6], S43, K[58]); /* 59 */
  II (b, c, d, a, M->threetwo[13], S44, K[59]); /* 60 */
  II (a, b, c, d, M->threetwo[ 4], S41, K[60]); /* 61 */
  II (d, a, b, c, M->threetwo[11], S42, K[61]); /* 62 */
  II (c, d, a, b, M->threetwo[ 2], S43, K[62]); /* 63 */
  II (b, c, d, a, M->threetwo[ 9], S44, K[63]); /* 64 */

  H[0] += a;
  H[1] += b;
  H[2] += c;
  H[3] += d;

}

int nextblock(BLOCK *M, FILE *infile, uint64_t *nobits, PADFLAG *status) {

  int i;
  size_t nobytesread;

    switch(*status) {

      case FINISH:
        return 0;
      case PAD0:

        for (i = 0; i < 56; i++) {
            M->eight[i] = 0x00;
        }

        M->sixfour[7] = *nobits;
        *status = FINISH;

        break;

      default:

          nobytesread = fread(M->eight, 1, 64, infile);
          *nobits += (8ULL * ((uint64_t) nobytesread));

          if (nobytesread < 56) {
    
            M->eight[nobytesread] = 0x80;

            for (i = nobytesread + 1; i < 56; i++){
                M->eight[i] = 0x00;
            }
            M->sixfour[7] = *nobits;

            *status = FINISH;
	    return 1;
          } else if (nobytesread < 64) {
  
            M->eight[nobytesread] = 0x80;

            for (i = nobytesread + 1; i < 64; i++) {
                M->eight[i] = 0x00;
            }
            *status = PAD0;
        }
    }

      return 1;

}

void process(FILE *infile) {

  BLOCK M;

  uint64_t nobits = 0;

  PADFLAG  status = READ;

  WORD H[] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};

  while (nextblock(&M, infile, &nobits, &status)) {
   md5Transform(&M, H);
  }

  printf("\n Hash: ");

  for (int i = 0; i < 4; i++)
  {
    // https://stackoverflow.com/questions/2182002/convert-big-endian-to-little-endian-in-c-without-using-provided-func
    printf("%08" PRIx32 "", SWAP_UINT32(H[i]));
  }

  printf("\n");

}

int main(int argc, char *argv[]) {
    int choice;
    char input[100];
    char fileName[100];

    printf("\n=================================================================\n");
    printf("\n---------------------- Theory of Algorithms ---------------------\n");
    printf("\n--------------------- MD5 Hashing Algorithm ---------------------\n");
    printf("\n-------------------------- Mark Gilmore -------------------------\n");
    printf("\n--------------------------- G00214777 ---------------------------\n");
    printf("\n=================================================================\n");
  
    do {
        printf("\nChoose 1 to hash a file");
        printf("\nChoose 2 to input a string to hash");
        printf("\nChoose 0 to exit\n");
	scanf("%d", &choice);

        if (choice == 1) {
            printf("Please enter the name of your file: ");
	          scanf("%s", fileName);

            FILE *infile = fopen(fileName, "rb");

            if (!infile) {
                printf("Error: couldn't open file %s.\n", argv[1]);
                return 1;
            } else {
                printf("\nHashing file...\n");
                process(infile);
                fclose(infile);

            }

        } else if (choice == 2) {
            printf("Input a string to hash: ");
            scanf("%s", input);

            FILE *file = fopen("userinput.txt", "w");
            fprintf(file, "%s", input);
            fclose(file);

            FILE *infile = fopen("userinput.txt", "rb");
            
            printf("\nHashing file...\n");
            process(infile);
            fclose(infile);

        } else if (choice == 0) {

	    printf("\nExiting...\n");

	}else {
            printf("\nInvalid Input. Please try again...\n");
        }
    } while (choice != 0);

    return 0;
}
