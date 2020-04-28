#include <stdio.h>
#include <time.h>
#include <string.h>
#include "md5.c"

void helpme() {
    printf("\n--run or -r      | Intructions on how to run the program\n");
    printf("\n--version or -v  | The version of the program\n");
    printf("\n--author or -A   | The author of the program\n");
    printf("\n--test or -t     | Test suite to test the accuracy of the hashing algorithm\n");
    printf("\n--about or -a    | About the project\n");
    printf("\n--md or -m       | About the algorithm and the differences between the MD4 and MD5 hashing algorithms\n");
}


int main(int argc, char *argv[]) {
  char choice[20];
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
        scanf("%s", &choice);

        if (strcmp(choice, "1") == 0) {
            printf("Please enter the name of your file: ");
            scanf("%s", fileName);

            FILE *infile = fopen(fileName, "r");

            if (!infile) {
                printf("Error: couldn't open file %s.\n", argv[1]);
                return 1;
            } else {
                printf("\nHashing file...\n");
                process(infile);
                fclose(infile);

            }

        } else if (strcmp(choice, "2") == 0) {
            printf("Input a string to hash: ");
            scanf("%s", input);

            FILE *file = fopen("userinput.txt", "w");
            fprintf(file, "%s", input);
            fclose(file);

            FILE *infile = fopen("userinput.txt", "rb");
            
            printf("\nHashing Input...\n");
            process(infile);
            fclose(infile);

      } else if (strcmp(choice, "--help") == 0 || strcmp(choice, "-h") == 0) {
            helpme();

      } else if (strcmp(choice, "--run") == 0 || strcmp(choice, "-r") == 0) {
            printf("\n--run or -r      | Intructions on how to run the program\n");

      } else if (strcmp(choice, "--version") == 0 || strcmp(choice, "-v") == 0) {
            printf("\n--version or -v  | The version of the program\n");

      } else if (strcmp(choice, "--author") == 0 || strcmp(choice, "-A") == 0) {
            printf("\n--author or -A   | The author of the program\n");

      } else if (strcmp(choice, "--test") == 0 || strcmp(choice, "-t") == 0) {
            printf("\n--test or -t     | Test suite to test the accuracy of the hashing algorithm\n");

      } else if (strcmp(choice, "--about") == 0 || strcmp(choice, "-a") == 0) {
            printf("\n--about or -a    | About the project\n");

      } else if (strcmp(choice, "--md") == 0 || strcmp(choice, "-m") == 0) {
            printf("\n--md or -m       | About the algorithm and the differences between the MD4 and MD5 hashing algorithms\n");

      } else {
          printf("\nInvalid Input. Please try --help or -h for a list of executable commands...\n");

      }
  } while (strcmp(choice, "0") != 0);

  return 0;
}
