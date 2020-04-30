#include <stdio.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "md5.c"
#include "commands.c"
// Runs a test suite through the hash and prints out the results along with the time taken to hash each input
void MDTestSuite ()
{

    int bufferLength = 100;
    char* buffer = malloc(bufferLength);
    char c;
    clock_t t;
    double time_taken;

    printf ("\nMD5 test suite:\n");
    printf("\nExpected Results\n");

    FILE *file = fopen("testexpect.txt", "r");
    c = fgetc(file);
    while (c != EOF) {
          printf("%c", c);
          c = fgetc(file);
    }
    fclose(file);
    printf("\nActual Results\n");
    FILE *file4 = fopen("testsuite.txt", "r");
    while(fgets(buffer, bufferLength, file)) {
      buffer[strcspn(buffer, "\n")] = 0;
      FILE *file2 = fopen("test.txt", "w");
      fprintf(file2, "%s", buffer);
      fclose(file2);
      FILE *file3 = fopen("test.txt", "r");

      t = clock();
      process(file3);
      t = clock() -t;

      time_taken = ((double)t)/CLOCKS_PER_SEC;
      printf ("\nTime Taken: %.2fms\n", (time_taken * 1000));
      printf("\n====================================\n");
      fclose(file3);  
    }
  
    fclose(file);

}

// Main method. Displays the main menu
int main(int argc, char *argv[]) {
  char choice[20];
  char input[1000];
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
            fgets(input, sizeof(input), stdin);

            FILE *file = fopen("userinput.txt", "w");
  
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;

            fprintf(file, "%s", input);
            fclose(file);

            FILE *infile = fopen("userinput.txt", "r");
            
            printf("\nHashing Input...\n");
            process(infile);
            fclose(infile);

      } else if (strcmp(choice, "--help") == 0 || strcmp(choice, "-h") == 0) {
            help();

      } else if (strcmp(choice, "--run") == 0 || strcmp(choice, "-r") == 0) {
            run();

      } else if (strcmp(choice, "--version") == 0 || strcmp(choice, "-v") == 0) {
            version();

      } else if (strcmp(choice, "--author") == 0 || strcmp(choice, "-A") == 0) {
            author();

      } else if (strcmp(choice, "--test") == 0 || strcmp(choice, "-t") == 0) {
            MDTestSuite();

      } else if (strcmp(choice, "--about") == 0 || strcmp(choice, "-a") == 0) {
            about();

      } else if (strcmp(choice, "--md") == 0 || strcmp(choice, "-m") == 0) {
            md();

      } else if (strcmp(choice, "0") == 0) {
          printf("\nExiting...\n");

      } else {
          printf("\nInvalid Input. Please try --help or -h for a list of executable commands...\n");

      }
  } while (strcmp(choice, "0") != 0);

  return 0;
}
