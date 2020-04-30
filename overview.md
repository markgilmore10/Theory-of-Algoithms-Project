## Introduction
This repository contains the working code for an MD5 Hashing Algorithm written in C along with 2 hello world programs written in Python and C and a working SHA256 hashing algorithm also written in C.  
A look at previous commits will show how these projects were pieced together, for the duration of the semester, using online tutorials provided by my lecturer, Dr Ian McLoughlin, as well as self-study and investigation via online documentation and tutorials. Throughout the semester a series of video lectures helped us understand key hashing concepts like C bit operations, unions and padding in C.  
The hello world programs were used to refresh our memory regarding the Python and C languages and how they are run.    
The SHA256 program is the project which our lecturer built as an example to help us on our way to building the MD5.  
Throughout this module I used the VIM text editor on a Debian Virtual Machine hosted on Google Cloud to develop our code. This gave us a great understanding of using such a text editor to create, develop and run programs on a VM. I also used Visual Studio Code to edit my project on my local 

## Prerequisites
A C compiler.
A C text editor.

## Software
Google Cloud  
VIM  
CMDER  
Visual Studio Code  
GitHub
  
## Run the Program Locally

### 1. Cloning the Repository
1. Open the cmd line and navigate to whatever folder you wish to clone the project into.  
2. type `git clone https://github.com/markgilmore10/Theory-of-Algoithms-Project.git'.  
3. Navigate to the project folder.  
### 2. Compiling the Program
4. To compile the program type `gcc -o md5 md5.c` in the command line.  
### 3. Running the Program
5. A new executable file ‘md5’ should have been built in your current folder.  
6. To run the program type `md5.exe` in the command line and press enter.  
### 3. Using the Program
7. This command will give you the main program menu.  
Choosing 1 will allow you to enter a file name to hash.  
Choosing 2 will allow you to enter a string to hash.  
Choosing 0 will exit the program.  
If the user chooses an option that is not recognised by the program it will prompt the user to enter –help or -h for a list of options.  
The following is the list of available command line prompts and what they do:  
**--help or -h**  
This will print out instructions on how to run the program.  
**--run or -r**  
Displays intructions on how to run the program.  
**--version or -v**  
Displays the version of the program.  
**--author or -A**  
Displays the author of the program.  
**--test or -t**  
This option will automatically start the testing of the program and print out the results of the test to the screen.  
**--about or -a**  
Displays details about the project.  
**--md or -m**  
Displays details about the algorithm and the differences between the MD4 and MD5 hashing algorithms.  

## Testing
The MD5 algorithm is tested using the suite of tests specified in the MD5 documentation[1].  As the program is designed to read in a file and output the result I have made a file (testsuite.txt) and read it in to the program, reading until the buffer finds a “\n”, processing the line and then moving to the next line to process that and so on.   
The following is the list of inputs and their expected outputs:  
  
"" = d41d8cd98f00b204e9800998ecf8427e  
  
"**a**" = 0cc175b9c0f1b6a831c399e269772661  
  
"**abc**" = 900150983cd24fb0d6963f7d28e17f72  
  
"**message digest**" = f96b697d7cb7938d525a2f31aaf161d0  
  
"**abcdefghijklmnopqrstuvwxyz**" = c3fcd3d76192e4007dfb496cca67e13b  
  
"**ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789**" =
d174ab98d277d9f5a5611c2c9f419d9f  

"**123456789012345678901234567890123456789012345678901234567890123456
78901234567890**" = 57edf4a22be3c955ac49da2e2107b67a  
  
  ![Results](https://github.com/markgilmore10/Theory-of-Algoithms-Project/blob/master/images/Results.JPG)
  
As you can see from the image above each output matches up with the expected output therefore every test passes.  

The test function is also timed using the time.h library. The timer starts as the argument enters process() and stops when it comes out of it. The end time is then subtracted from the start time and divided by CLOCKS_PER_SEC (1,000,000) to get the time in seconds. The result is then multiplied by 1000 and displayed in milliseconds.  


## Algorithm
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
  
### Visual
  
  ![MD5](https://github.com/markgilmore10/Theory-of-Algoithms-Project/blob/master/images/MD5.JPG)
  
The image above shows the processing of the F block. The same process is used for all four of the auxiliary functions (F, G, H, I).  
The four buffers (A, B, C, D) are mixed with the input using the four auxiliary functions.  
In the image the M is the 16, 32 bit, words that the message has been divided into after the padding (M0-M15).  
The K is the K constant used in my code and the <<< denotes the left shift is defined in my code by the ROTATE_LEFT constant.  
All four rounds have to be performed to get the final hash output.  

  
## Complexity
The MD5 Message-Digest-Algorithm is a cryptographic hash function containing a string of digits created by a one-way hashing formula[1] described in detail in the RFC 1321[2] documentation.  
. The Message Digest algorithm (MD5) is the fifth version of the type hence the abbreviation. While MD2, MD4, and MD6 are the only published MD algorithms available, MD1 and MD3 still exist but were never published.  
The algorithm was developed as an improvement of the MD4 algorithm. The MD4 algorithm was designed for speed which severely compromised its security and, in 1995, the first collision attack against the MD4 was published.  
Both technologies were developed by a renowned scientist at MIT, Professor Ronald Rivest. While still widely used as a way to check the integrity of a file after the transfer, design flaws were discovered on the algorithm with regards to security. As a result, the recommended usability of the algorithm was reduced. As with its predecessor, MD4, collisions were easy to find using even a basic home computer. In cases where a similar input is passed through the algorithm, MD5 should not produce similar output. As a result, the algorithm is best used to check whether there has been an intentional corruption of a piece of data.  
To be considered cryptographically secure the algorithm had to meet two requirements: one, It is impossible to generate two inputs that cannot produce the same hash function and two, It is impossible to generate a message having the same hash value. Simply put this means that two different message inputs must have two different outputs but with MD5 this was not the case.
MD5 and other cryptography algorithms are built around the idea of the message digest. MD5, in particular, has been built to digest an input of arbitrary length and produce a 128-bit long output. 
The algorithm is a one-way cryptographic function. This means that a hash value cannot be used to discover or reveal the original input. The algorithm achieves this by accepting an input of arbitrary length and returns an output of a fixed-length digest value. In this case, padding is used to produce a standard length output. This, therefore, complicates the idea of reversing an output. The algorithm upon receiving a message, it is padded to ensure that it meets the standard length requirement in bits. This equals to 448 modulo 512. In this case, the message consists of individual bits which are then padded with several zeros to meet the length requirement. A four-word buffer is then used to compute the input digest. The buffers are in the form of 32- bit registers that are computed in hexadecimal.  
The above functionality, therefore, allows the algorithm to be used to encode passwords and other sensitive data into databases such as Postgress or MySQL. This means that MD5 is a typical fingerprint generator but not an encryption methodology (Danstools00, 2020). This functionality from presented information, therefore, means that it is challenging to reverse engineer MD5 hash algorithm when used as a fingerprint generator. As a cryptographic hash, however, it is easy to reverse engineer an MD5 hash. This process, however, is not straight forward and relays on several loops. Ideally, a hash function is not reversible.  
Such a case has been highlighted by John Cook in his online editorial. The paper illustrates how simple short and weak passwords are often the victims of reverse engineering (Cook, 2019). It is possible to determine the text that was hashed in this case. In specific instances, the author illustrates how 'googling' of several plausible outputs can provide the correct input of an MD5 hash. This means that in very specific instances it is possible to reverse engineer MD5 hash values. This disadvantage has been compared to the characteristics of pigeon-hole principles where the MD5 is found to have quite the basic security breach. The pigeon-hole principle means, in simple terms, that if you have more objects than you have holes to put them into then there has to be more than one object in one or more holes. 
This security breach can be identified in a different scenario. Since the algorithm is based on unlimited inputs and limited outputs, this can technically lead to similar hash values from different inputs. However, due to the complexity of data and the various forms in which it can be stored, the likelihood of this occurring in a practice case is quite low. In a theoretical case, however, we take into effect the 'birthday paradox' hacking code, for example. You can deduce that in a particular birthday, where there are 367 people, there is a 100% chance one person shares the same birthday with another. This means, with access to a considerable amount of data, a hacker can reverse engineer an MD5 algorithm.  
As a result, it is statistically correct to imply that SHA-256, which is also found in my repository, is more secure than MD5 although it too does have several security weak links. This notion can further be developed to indicate that hashing algorithms are as practical as encryption algorithms. This is based on the characteristic expectation that a hash algorithm should improve on encryption procedures. When a hashing algorithm is futile, an encryption process cannot be adequately substantiated. This was one of the determining factors when MD5 was considered insecure.  
In its preceding test, the use of collisions was found to be a viable way of corrupting the effectiveness of the algorithm. This meant the algorithm was insecure and could be reversed engineered (Margaret Rouse, 2020). MD5, however, didn't lose all its functionality by retaining its checksum function. Since the algorithm is characterized by a theoretical case where two different inputs can produce a similar output, it is inevitably challenging to point out that reverse engineering is accurate. The algorithm to reverse MD5 has, therefore, to be complex and developed over time addressing the impeding theoretical cases while providing practice case studies.  

## References
The following references allowed me to gain a greater understanding and build my knowledge of the MD5. These papers allowed me to understand what exactly I was building and how I could implement it:  
  
[1] R. Rivest. (April 1992). The MD5 Message-Digest Algorithm: https://www.ietf.org/rfc/rfc1321.txt  
[2] Shweta Mishra Shikha Mishra, Nilesh Kumar. (September 2013). Hashing Algorithm: MD5  
[3] Danstools00. (2020, April 30). MD5 Generator. https://www.md5hashgenerator.com/  
[4] Cook, J. D. (2019, January 24). Reversing an MD5 hash. https://www.johndcook.com/blog/2019/01/24/reversing-an-md5-hash/  
[5] Margaret Rouse . (2020, April 30). MD5. https://www.searchsecurity.techtarget.com/definition/MD5/  

While not directly referenced the following papers on algorithms offered great insight to the algorithm and hashing functions in general. These papers allowed me to understand what exactly was building and how it worked:  
  
Md. Alam Hossain, Md.Kamrul Islam, Subrata Kumar Dasand Md. Asif Nashiry.(March, 2012). CRYPTANALYZING OF MESSAGE DIGEST ALGORITHMS MD4 AND MD5 https://www.academia.edu/10358185/CRYPTANALYZING_OF_MESSAGE_DIGEST_ALGORITHMS_MD4_AND_MD5  
  
Rashmi P. Sarode, Piyush Gupta and Neeraj Manglani. (2014). A comparative analysis of RSA and MD5 algorithms. https://www.academia.edu/7231024/A_Comparative_Analysis_of_RSA_and_MD5_Algorithms


