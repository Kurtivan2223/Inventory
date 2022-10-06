#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define and &&
#define or ||
#define true 1
#define false 0
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

//Global Variables
int ID;
int brandID[20];
char brandName[20][20];

//US size Womens
int wsize_5_qty[20];
int wsize_6_qty[20];
int wsize_7_qty[20];
int wsize_8_qty[20];
int wsize_9_qty[20];
int wsize_10_qty[20];
int wsize_11_qty[20];
int wsize_12_qty[20];

//US size Mens
int msize_4_qty[20];
int msize_5_qty[20];
int msize_6_qty[20];
int msize_7_qty[20];
int msize_8_qty[20];
int msize_9_qty[20];
int msize_10_qty[20];

//Declared user defined functions
void Loading(); //done
void Menu(); // done
void AddItems(); // done
void DeleteItem(); // done
void Records(); // done
void searchMenu(); //pending
void Search(char* brandString); // done
void ReadTxtFile(); // done
// void WriteFile(); //pending
void Exit(); // done

//main function
int main(int argc, char** argv[])
{
	Loading();

	return 0;
}

//loading screen
void Loading()
{
    int i;
    
    for(i = 0; i < 39; i++)
        printf(" ");
        
    printf("]");
    printf("\r");
	printf("Loading [");
	
    for(i = 0; i < 30; i++)
    {
        printf("%c", 219);
        Sleep(100);
    }

    Menu();
}

//Menu screen
void Menu()
{
    int option, i;

    do
    {
        system("cls");
        printf("********** Main Menu **********");
        printf("\n\n[1] Add Item\n[2] Delete Item\n[3] Show Records\n[4] Exit\n: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option)
        {
        case 1:
            system("cls");
            Sleep(1000);
            AddItems();
            break;
        case 2:
            system("cls");
            Sleep(1000);
            DeleteItem();
            break;
        case 3:
            system("cls");
            Sleep(1000);
            Records();
            break;
        case 4:
            system("cls");
            Sleep(1000);
            Exit();
        default:
            system("cls");
            printf("There is no such Option!\n");
            for(i = 0; i < 5; i++)
            {
                printf("Please try again in \r%d", i + 1);
                Sleep(5000);
            }
        }
    }
    while(option != 3);
}

//Add Item Screen
void AddItems()
{
	int i, k, n, tempID;
    char temp[20];

    char option = 'Y';

   	do
   	{
   		fflush(stdin);
	    printf("Enter Number of Shoe Brands to be added: ");
	    scanf("%d", &n);
	    fflush(stdin);

	    ID = n;

	    for(i = 0; i < ID; i++)
	    {
	    	system("cls");

	    	fflush(stdin);
	        printf("Brand ID: ");
	        scanf("%d", &tempID);

	        for(k = 0; k < ID; k++)
	        {
	        	if(brandID[k] == tempID)
				{
					printf("Brand ID Already Used!");
					Sleep(5000);
					fflush(stdin);
					system("cls");
					AddItems();
				}
			}

	        fflush(stdin);
	        printf("Brand name: ");
	        scanf("%s", temp);

	        for(k = 0; k < n; k++)
	        {
	        	if(strcmp(brandName[i], temp) == 0)
				{
					printf("Brand Already Exists!");
					Sleep(5000);
					fflush(stdin);
					system("cls");
					AddItems();
				}
			}

			brandID[i] = tempID;
			strcpy(brandName[i], temp);

			//Women Size
			fflush(stdin);
			printf("Enter Quantity for Women Size 5: ");
			scanf("%d", &wsize_5_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Women Size 6: ");
			scanf("%d", &wsize_6_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Women Size 7: ");
			scanf("%d", &wsize_7_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Women Size 8: ");
			scanf("%d", &wsize_8_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Women Size 9: ");
			scanf("%d", &wsize_9_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Women Size 10: ");
			scanf("%d", &wsize_10_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Women Size 11: ");
			scanf("%d", &wsize_11_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Women Size 12: ");
			scanf("%d", &wsize_12_qty[i]);

			//Mens Size
			fflush(stdin);
			printf("Enter Quantity for Men Size 4: ");
			scanf("%d", &msize_4_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Men Size 5: ");
			scanf("%d", &msize_5_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Men Size 6: ");
			scanf("%d", &msize_6_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Men Size 7: ");
			scanf("%d", &msize_7_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Men Size 8: ");
			scanf("%d", &msize_8_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Men Size 9: ");
			scanf("%d", &msize_9_qty[i]);

			fflush(stdin);
			printf("Enter Quantity for Men Size 10: ");
			scanf("%d", &msize_10_qty[i]);
	    }

	    printf("\n\n");
	    printf("Do you want to Retry? [Y]es|[N]o: ");
	    scanf("%c", &option);


	    if(option == 'N' or option == 'n')
	    {
	    	fflush(stdin);
	    	Menu();
	    }
	}
	while(option == 'Y' or option == 'y');
}

void DeleteItem()
{
	char option = 'Y';
	char temp[20];
	int i, location, j;
	int tempBrand = sizeof(brandID) / sizeof(brandID[0]);
	int found = false;

	do
	{
		printf("Enter Brand Name You want to Delete: ");
		scanf("%s", temp);
		fflush(stdin);
		
		for(i = 0; i < tempBrand; i++)
		{
			if(strcmp(brandName[i], temp) == 0)
			{
				found = true;
				location = i + 1;
			}
			else
			{
				found = false;
				location = 0;
			}
		}

		if(found == true)
		{
			for(j = location - 1; j < tempBrand; j++)
			{
				brandID[j] = brandID[j + 1];
				strcpy(brandName[j], brandName[j + 1]);
				wsize_5_qty[j] = wsize_5_qty[j + 1];
				wsize_6_qty[j] = wsize_6_qty[j + 1];
				wsize_7_qty[j] = wsize_7_qty[j + 1];
				wsize_8_qty[j] = wsize_8_qty[j + 1];
				wsize_9_qty[j] = wsize_9_qty[j + 1];
				wsize_10_qty[j] = wsize_10_qty[j + 1];
				wsize_11_qty[j] = wsize_11_qty[j + 1];
				wsize_12_qty[j] = wsize_12_qty[j + 1];
				msize_4_qty[j] = msize_4_qty[j + 1];
				msize_5_qty[j] = msize_5_qty[j + 1];
				msize_6_qty[j] = msize_6_qty[j + 1];
				msize_7_qty[j] = msize_7_qty[j + 1];
				msize_8_qty[j] = msize_8_qty[j + 1];
				msize_9_qty[j] = msize_9_qty[j + 1];
				msize_10_qty[j] = msize_10_qty[j + 1];
			}

			printf("Successfully Deleted %s records in the Inventory!", temp);
		}
		else
		{
			printf("There is no such Brand in the Inventory!");
		}

		temp[0] = '\0';

		scanf("%c", &option);
		fflush(stdin);
		
		if(option == 'N' or option == 'n')
		{
			Sleep(5000);
			Menu();
		}
	}while(option == 'Y' or option == 'y');
}

void Records()
{
    int option, i, k, j, tempBrand;
    int m = 4, w = 5;
	tempBrand = sizeof(brandID) / sizeof(brandID[0]);

    do
    {
        system("cls");
        printf("********** Main Menu **********");
        printf("\n\n[1] Show Current Records\n[2] Show All Records\n[3]Search Record\n[4] Menu\n: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option)
        {
        case 1:
			system("cls");
			Sleep(1000);
			printf("\t\t\t***** INVENTORY *****\n");
			printf("-------------------------------------------------------------------------------------\n");
			printf("ID\t|\tNAME\t|\t\t\tSize\t|\tQUANTITY \n");
			printf("-------------------------------------------------------------------------------------\n");
	
			for(i = 0; i < tempBrand; i++)
			{
				if(brandID[i] != '\0')
				{
					printf("%-4d %-15s\n", brandID[i], brandName[i]);
	
					printf("\t\tMen: %-5d %-5d\n", 4, msize_4_qty[i]);
					printf("\t\tMen: %-5d %-5d\n", 5, msize_5_qty[i]);
					printf("\t\tMen: %-5d %-5d\n", 6, msize_6_qty[i]);
					printf("\t\tMen: %-5d %-5d\n", 7, msize_7_qty[i]);
					printf("\t\tMen: %-5d %-5d\n", 8, msize_8_qty[i]);
					printf("\t\tMen: %-5d %-5d\n", 9, msize_9_qty[i]);
					printf("\t\tMen: %-5d %-5d\n", 10, msize_10_qty[i]);
		
					printf("\t\tWomen: %-5d %-5d\n", 5, wsize_5_qty[i]);
					printf("\t\tWomen: %-5d %-5d\n", 6, wsize_6_qty[i]);
					printf("\t\tWomen: %-5d %-5d\n", 7, wsize_7_qty[i]);
					printf("\t\tWomen: %-5d %-5d\n", 8, wsize_8_qty[i]);
					printf("\t\tWomen: %-5d %-5d\n", 9, wsize_9_qty[i]);
					printf("\t\tWomen: %-5d %-5d\n", 10, wsize_10_qty[i]);
					printf("\t\tWomen: %-5d %-5d\n", 11, wsize_11_qty[i]);
					printf("\t\tWomen: %-5d %-5d\n", 12, wsize_12_qty[i]);
				}
			}
			system("pause");
			Records();
			break;
        case 2:
			system("cls");
			Sleep(1000);
			ReadTxtFile();
			Exit();
			break;
		case 3:
			system("cls");
			Sleep(1000);
			searchMenu();
			break;
        case 4:
			system("cls");
			Sleep(1000);
			Menu();
			break;
	        default:
	            system("cls");
	            printf("There is no such Option!\n");
	            for(k = 0; k < 5; k++)
	            {
	                printf("Please try again in \r%d", k + 1);
	                Sleep(5000);
	            }
        }
    }
    while(option != 3);
}

void searchMenu()
{
	char option = 'Y';
	char temp[20];

	do
	{
		printf("Enter Brand Name You want to search: ");
		scanf("%s", temp);
		Search(temp);
		temp[0] = '\0'; //empty the string
		scanf("%c", &option);
		fflush(stdin);
		if(option == 'N' or option == 'n')
		{
			Sleep(5000);
			Menu();
		}
	}
	while(option == 'Y' or option == 'y');
}

void Search(char* brandString)
{
	
	int i;
	int size = sizeof(brandID) / sizeof(brandID[0]);
	//bool
	int found = false;
	
	int location;
	
	for(i = 0; i < size; i++)
	{
		if(strcmp(brandName[i], brandString) == 0)
		{
			found = true;
			location = i + 1;
		}
		else
		{
			found = false;
			location = 0;
		}
	}
	
	
	if(found == true)
	{
		system("cls");
		Sleep(1000);
		printf("\t\t\t***** INVENTORY *****\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("ID\t|\tNAME\t|\t\t\tSize\t|\tQUANTITY \n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("%-4d %-15s\n", brandID[location], brandName[location]);
		printf("\t\tMen: %-5d %-5d\n", 4, msize_4_qty[location - 1]);
		printf("\t\tMen: %-5d %-5d\n", 5, msize_5_qty[location - 1]);
		printf("\t\tMen: %-5d %-5d\n", 6, msize_6_qty[location - 1]);
		printf("\t\tMen: %-5d %-5d\n", 7, msize_7_qty[location - 1]);
		printf("\t\tMen: %-5d %-5d\n", 8, msize_8_qty[location - 1]);
		printf("\t\tMen: %-5d %-5d\n", 9, msize_9_qty[location - 1]);
		printf("\t\tMen: %-5d %-5d\n", 10, msize_10_qty[location - 1]);

		printf("\t\tWomen: %-5d %-5d\n", 5, wsize_5_qty[location - 1]);
		printf("\t\tWomen: %-5d %-5d\n", 6, wsize_6_qty[location - 1]);
		printf("\t\tWomen: %-5d %-5d\n", 7, wsize_7_qty[location - 1]);
		printf("\t\tWomen: %-5d %-5d\n", 8, wsize_8_qty[location - 1]);
		printf("\t\tWomen: %-5d %-5d\n", 9, wsize_9_qty[location - 1]);
		printf("\t\tWomen: %-5d %-5d\n", 10, wsize_10_qty[location - 1]);
		printf("\t\tWomen: %-5d %-5d\n", 11, wsize_11_qty[location - 1]);
		printf("\t\tWomen: %-5d %-5d\n", 12, wsize_12_qty[location - 1]);
		system("pause");
	}
	else
	{
		printf("There is no such Brand!");
		Sleep(5000);
	}
}


void ReadTxtFile()
{
	char buffer;

	FILE* fileptr;
	fileptr = fopen("Logs\\records.txt", "r");

	if(fileptr == NULL)
		printf("There is no Records!");

	do
	{
		buffer = fgetc(fileptr);
		printf("%c", buffer);
	}
	while(buffer != EOF);

	fclose(fileptr);

	system("pause");
	
	Records();
}

// void WriteFile()
// {
// 	//something ..
// }

void Exit()
{
    exit(EXIT_SUCCESS);
}
