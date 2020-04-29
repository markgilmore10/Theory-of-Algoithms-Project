#include <stdio.h>

void help() {
      printf("\n|------------------------------------------------------------------------------------------------------|\n");
      printf("\n| Command          | Process                                                                           |\n");
      printf("\n|------------------------------------------------------------------------------------------------------|\n");
      printf("\n| --run or -r      | Intructions on how to run the program                                             |\n");
      printf("\n| --version or -v  | The version of the program                                                        |\n");
      printf("\n| --author or -A   | The author of the program                                                         |\n");
      printf("\n| --test or -t     | Test suite to test the accuracy of the hashing algorithm                          |\n");
      printf("\n| --about or -a    | About the project                                                                 |\n");
      printf("\n| --md or -m       | About the algorithm and the differences between the MD4 and MD5 hashing algorithms|\n");
      printf("\n|------------------------------------------------------------------------------------------------------|\n");
}

void run() {
      printf("\nNote: You must have a C compiler installed in you machine to run this program\n");
      printf("\n1. Open the cmd line and navigate to whatever folder you wish to clone the project into\n");
      printf("\n2. Type `git clone https://github.com/markgilmore10/Theory-of-Algoithms-Project.git'\n");
      printf("\n3. Navigate to the project folder\n");
      printf("\n4. To compile the program type gcc -o md5 mddriver.c in the command line\n");
      printf("\n5. To run the program type md5.exe in the command line and press enter\n");
}

void version() {
      printf("\nVersion 1.0\n");
}

void author() {
      printf("\nAuthor: Mark Gilmore\n");
      printf("\nStudent Number: G00214777\n");
}

void about() {
      printf("\nModule:         Theory of Algorithms\n");
      printf("\nAdvisor:        Dr. Ian McLoughlin\n"  );
      printf("\nGalway Mayo Institute of Technology\n" );
      printf("\nThis repository contains the working code for an MD5 Hashing Algorithm \n");
      printf("\nwritten in C along with 2 hello world programs written in Python and C and a working \n");
      printf("\nSHA256 hashing algorithm also written in C.\n" );
      printf("\nA look at previous commits will show how these projects were pieced together \n");
      printf("\nfor the duration of the semester using online tutorials provided by my lecturer, Dr Ian McLoughlin, \n");
      printf("\nas well as self study and investigation via online documentation and tutorials.\n" );
      printf("\nThroughout the semester a series of video lectures helped us understand key hashing concepts \n");
      printf("\nlike C bit operations, unions and padding in C.\n" );
      printf("\nThe hello world programs were used to refresh students memory regarding the Python and C \n");
      printf("\nlanguages and how they are run.\n" );
      printf("\nThe SHA256 program is the project which our lecturer used as an example to help us on our \n");
      printf("\nway to building the MD5.\n" );
      printf("\nThroughout this module we used the VIM text editor on a Debian Virtual Machine hosted on \n");
      printf("\nGoogle Cloud to develop our code. \n" );
      printf("\nThis gave us a great understanding of using such a text editor to create, develop and run \n");
      printf("\nprograms on a VM.\n" );
}

void md() {
      printf("\n***** Insert taken from https://en.wikipedia.org/wiki/MD5 *****\n");
      printf("\nThe MD5 message-digest algorithm is a widely used hash function producing a 128-bit hash value.\n");
      printf("\nMD5 was designed by Ronald Rivest in 1991 to replace an earlier hash function MD4.\n");
      printf("\nOne basic requirement of any cryptographic hash function is that it should be computationally infeasible \n");
      printf("\nto find two distinct messages that hash to the same value. MD5 fails this requirement catastrophically; such \n");
      printf("\ncollisions can be found in seconds on an ordinary home computer.\n");
      printf("\nThe weaknesses of MD5 have been exploited in the field, most infamously by the Flame malware in 2012. The \n");
      printf("\nCMU Software Engineering Institute considers MD5 essentially cryptographically broken and unsuitable for further use.\n");
      printf("\nAs of 2019, MD5 continues to be widely used, in spite of its well-documented weaknesses and deprecation by \n");
      printf("\nsecurity experts.\n");
}
