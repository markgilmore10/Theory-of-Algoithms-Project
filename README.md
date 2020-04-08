# Theory-of-Algoithms-Project
## MD5 Secure Hash Algorithm

|     |     |
| --- | --- |
| **Author** | [Mark Gilmore](https://github.com/markgilmore10) |
| **Student Number** | G00214777 |
| **Lecturer** | Dr Ian McLoughlin |
| **Course** | BSc (Hons) in Software Development
| **Module** |  Theory of Algorithms |

This Repository contains the submission for my 4th year Theory of Algorithms project as part of my BSc (Hons) in Software Development course.

<hr>

## Introduction

This repository contains the working code for an MD5 Hashing Algorithm written in C along with 2 hello world programs written in Python and C and a working SHA256 hashing algorithm also written in C.  
A look at previous commits will show how these projects were pieced together for the duration of the semester using online tutorials provided by my lecturer, Dr Ian McLoughlin, as well as self study and investigation via online documentation and tutorials. Throughout the semester a series of video lectures helped us understand key hashing concepts like C bit operations, unions and padding in C.  
The hello world programs were used to refresh students memory regarding the Python and C languages and how they are run.    
The SHA256 program is the project which our lecturer used as an example to help us on our way to building the MD5.  
Throughout this module we used the VIM text editor on a Debian Virtual Machine hosted on Google Cloud to develop our code. This gave us a great understanding of using such a text editor to create, develop and run programs on a VM.

<hr>

## Problem Statement
You must write a program in the C programming language that calculates the MD5 hash digest of an input.  
The algorithm is specified in the Request For Comments 1321 document supplied by the Internet Engineering Task Force.  
The only pre-requisite is that your program performs the algorithm — you are free to decide what input the algorithm should be performed on.

<hr>

## The MD5 Algorithm

[The MD5 message-digest algorithm is a widely used hash function producing a 128-bit hash value.  
Although MD5 was initially designed to be used as a cryptographic hash function, it has been found to suffer from extensive vulnerabilities.  It can still be used as a checksum to verify data integrity, but only against unintentional corruption.  
It remains suitable for other non-cryptographic purposes, for example for determining the partition for a particular key in a partitioned database.  
MD5 was designed by Ronald Rivest in 1991 to replace an earlier hash function MD4 and was specified in 1992 as RFC 1321.](https://en.wikipedia.org/wiki/MD5)

<hr>

## Steps
The following are the steps involved in the hashing process:

### 1. Append Padding Bits
The first step towards building the MD5 is padding. Padding is the process in which a message, of arbitrary length, is padded so that the length of the message in bits is equal to 448 modulo 512.  
Padding is done only when the message is less than 64 bytes in size otherwise it is left as is. 

### 2. Append Length
A 64-bit representation of the length of the given message before the padding was added is appended to the result of the padding resulting in a message which has a length multiple of 512 bits.

### 3. Initialize Message Digest buffer
Four 32 bit words are required to generate the message digest.  
The initial value of the words will be changed throughout the hashing process.  
The initial word values are as follows:

```C
WORD H[] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
```

```C
 WORD a = H[0];
 WORD b = H[1];
 WORD c = H[2];
 WORD d = H[3];
```

### 4. Process Message in 16-Word Blocks
F, G, H and I are auxilery functions which receive three 32bit words (x, y, z), and output a single 32bit word. 

```C
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))    
```

The next step sees each 512 bit block go through the following four rounds of calculations:
```C
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
```


Each 16-word block is processed and passed through to make the following calculations:
```C
  H[0] += a;
  H[1] += b;
  H[2] += c;
  H[3] += d;
```

### 5. Output Results
The Message Digest then yields an output A, B, C, D.   
Beginning with the lower byte of A and ending with the higher byte of D.

## Code

## Run the Program Locally

### 1. Cloning the Repository
1. Open the cmd line and navigate to whatever folder you wish to clone the project into.
2. type `git clone https://github.com/markgilmore10/Theory-of-Algoithms-Project.git'
3. Navigate to the project folder.
### 2. Compiling the Program
4. To compile the program type `gcc -o md5 md5.c` in the command line.
### 3. Running the Program
5. To run the program type `md5 sample.txt` in the command line.
## Testing

## Research

## References
