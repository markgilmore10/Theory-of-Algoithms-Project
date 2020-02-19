#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    bool menu = true;
	char text[250];
	int choice;
    char file_name[25];
    FILE *fp;

	while (menu == true) {
		printf("Enter 1 for Manual Input\n");
        printf("Enter 2 to Input a File\n");
        printf("Enter 0 to Exit: \n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Please enter a string: ");
			scanf("%s", text);

			printf(text);
			break;
		case 2:
			printf("Please choose a file");
            gets(file_name);
			fp = fopen(file_name, "r");

			fclose(fp);
			break;
		case 0:
			printf("Program Terminated");
			getch();
			exit(0);
		default:
			printf("Invalid input. Please try again");
			break;
		}
	}

	getch();

	return 0;
}