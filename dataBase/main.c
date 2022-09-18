//
//  main.c
//  dataBase
//
//  Created by Win Lwin on 18/09/2022.
//

#include <stdio.h>

struct dataInfo {
	char name[30];
	char email[30];
	char phoneNumber[30];
};

int main(int argc, const char * argv[]) {
	struct dataInfo personList[10];
	int sizeOfArray = sizeof(personList)/sizeof(personList[0]);
	
	static int index = 0;
	
	static int choose = 0; //false
	
	FILE *fptr = NULL;
	
	while (choose != 4) {
		printf("1. Add Person.\n");
		printf("2. Show Person.\n");
		printf("3. Save.\n");
		printf("4. Exit.\n");

		choose = getchar();
		getchar();
		switch (choose) {
			case '1':
				if (index != sizeOfArray) {
					printf("Enter Name : ");
					scanf("%[^\n]%*c", personList[index].name);

					printf("Enter Email : ");
					scanf("%[^\n]%*c",personList[index].email);

					printf("Enter Phone Number : ");
					scanf("%[^\n]%*c",personList[index].phoneNumber);

					index++;
					break;
				} else {
					printf("Out Of Storage!\n\n");
					break;
				}
			
			case '2':
				//do something
				printf("Didn't implement yet\n");
				break;
				
			case '3':
				fptr = fopen("dataBase.txt", "w");
				if (fptr == NULL) {
					printf("File not found!\n");
				} else {
					printf("Saved Successfully.\n");
				}

				fprintf(fptr, "Name                           Email                               Phone Number              \n");
				fprintf(fptr, "----------------------------------------------------------------------------------------\n");
				for (int i = 0; i < index; i++) {
					fprintf(fptr, "%-30s %-35s %-30s\n",personList[i].name,personList[i].email,personList[i].phoneNumber);
				}
				fclose(fptr);
				break;

			case '4':
				choose = 4;
				break;

			default:
				printf("Invalid input!\n");
				break;
		}
	}
	
}

