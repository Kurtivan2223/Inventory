#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <ctype.h>
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
int temporarySize;
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
void Search(char brandString[]); // done
void ReadTxtFile(); // done
void WritesFile(); //pending
void insertAnyLocation();
int compare(char stringName[]);
int stringlocator(char stringName[]);
int strInputCheck(char stringInput[]);
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
        printf("\n\n[1] Add Item\n[2] Delete Item\n[3] Insert at Any location List\n[4] Show Records\n[5] Exit\n: ");
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
            insertAnyLocation();
            break;
        case 4:
            system("cls");
            Sleep(1000);
            Records();
            break;
        case 5:
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
    while(option != 5);
}

//Add Item Screen
void AddItems()
{
	int i, k, n, j, tempID, count;
    char temp[20];
	int tempOld, tempNew;

    char option = 'Y';

	count = temporarySize;

   	do
   	{
   		fflush(stdin);
	    printf("Enter Number of Shoe Brands to be added: ");
	    scanf("%d", &n);
	    fflush(stdin);

		temporarySize += n;

	    for(i = count; i < count + n; i++)
	    {
ids:
	    	system("cls");

	    	fflush(stdin);
	        printf("Brand ID: ");
	        scanf("%d", &tempID);

	        for(k = 0; k < n; k++)
	        {
	        	if(brandID[k] == tempID)
				{
					printf("Brand ID Already Used!");
					Sleep(5000);
					fflush(stdin);
					system("cls");
					goto ids;
				}
			}
			brandID[i] = tempID;
names:
	        fflush(stdin);
	        printf("Brand name: ");
	        scanf("%s", temp);

			if(strInputCheck(temp) == true)
			{
				printf("Input only Accepts letter for string!");
				Sleep(5000);
				fflush(stdin);
				system("cls");
				goto names;
			}

			if(compare(temp) == true)
			{
				printf("Brand Already Exists!");
				Sleep(5000);
				fflush(stdin);
				system("cls");
				goto names;
			}

			strcpy(brandName[i], temp);

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

		WritesFile();
	    
		fflush(stdin);
	    printf("\n\n");
	    printf("Do you want to Retry? [Y]es|[N]o: ");
	    scanf("%c", &option);
		fflush(stdin);

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
	int i, location = 0;
	int size = temporarySize;
	int found;

	do
	{
temps:
		printf("Enter Brand Name You want to Delete: ");
		scanf("%s", temp);
		fflush(stdin);

		found = compare(temp);

		if(found == true)
		{
			location = stringlocator(temp);

			for(i = location - 1; i < size - 1; i++)
			{
				brandID[i] = brandID[i + 1];
			
				wsize_5_qty[i] = wsize_5_qty[i + 1];
			
				wsize_6_qty[i] = wsize_6_qty[i + 1];
			
				wsize_7_qty[i] = wsize_7_qty[i + 1];
			
				wsize_8_qty[i] = wsize_8_qty[i + 1];
			
				wsize_9_qty[i] = wsize_9_qty[i + 1];
			
				wsize_10_qty[i] = wsize_10_qty[i + 1];
			
				wsize_11_qty[i] = wsize_11_qty[i + 1];
			
				wsize_12_qty[i] = wsize_12_qty[i + 1];
			
				msize_4_qty[i] = msize_4_qty[i + 1];
			
				msize_5_qty[i] = msize_5_qty[i + 1];
			
				msize_6_qty[i] = msize_6_qty[i + 1];
			
				msize_7_qty[i] = msize_7_qty[i + 1];
			
				msize_8_qty[i] = msize_8_qty[i + 1];
			
				msize_9_qty[i] = msize_9_qty[i + 1];
			
				msize_10_qty[i] = msize_10_qty[i + 1];
			}

			//Erase one element | 'P.S' idk where this shifted to so goodluck partner on your presentation!!
			memmove(brandName[location - 1], brandName[location], (size - location) * sizeof(brandName[0]));
			//Erase the final slot whose content has been shifted
			memset(brandName[size - 1], 0, sizeof(brandName[0]));

			temporarySize -= 1;
			WritesFile();

			printf("Successfully Deleted %s records in the Inventory!", temp);
			Sleep(5000);
		}
		else
		{
			printf("There is no such Brand in the Inventory!");
			Sleep(5000);
			system("cls");
			goto temps;
		}

		printf("Do you want to Retry? [Y]es|[N]o: ");
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
    int option, i, k, j, size, count = temporarySize;
    int m = 4, w = 5;

    do
    {
        system("cls");
        printf("********** Main Menu **********");
        printf("\n\n[1] Show Current Records\n[2] Show All Records\n[3] Search Record\n[4] Menu\n: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option)
        {
        case 1:
			system("cls");
			Sleep(1000);
			printf("\t\t\t***** INVENTORY *****\n");
			printf("--------------------------------------------------------------------------------\n");
			printf("\tID\t|\tNAME\t|\tSize\t|\tQUANTITY\n");
			printf("--------------------------------------------------------------------------------\n");
	
			for(i = 0; i < count; i++)
			{
				printf("\t%-8d\t%-25s\n", brandID[i], brandName[i]);

				printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 4, msize_4_qty[i]);
				printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 5, msize_5_qty[i]);
				printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 6, msize_6_qty[i]);
				printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 7, msize_7_qty[i]);
				printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 8, msize_8_qty[i]);
				printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 9, msize_9_qty[i]);
				printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 10, msize_10_qty[i]);

				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 5, wsize_5_qty[i]);
				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 6, wsize_6_qty[i]);
				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 7, wsize_7_qty[i]);
				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 8, wsize_8_qty[i]);
				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 9, wsize_9_qty[i]);
				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 10, wsize_10_qty[i]);
				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 11, wsize_11_qty[i]);
				printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 12, wsize_12_qty[i]);
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

		printf("Do you want to Retry? [Y]es|[N]o: ");
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

void Search(char brandString[])
{
	
	int i;
	int found = false;
	int location = 0;

	if(compare(brandString) == true)
		found = true;
	
	if(found == true)
	{
		location = stringlocator(brandString);

		system("cls");
		Sleep(1000);
		printf("\t\t\t***** INVENTORY *****\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("\tID\t|\tNAME\t|\tSize\t|\tQUANTITY\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t%-8d\t%-25s\n", brandID[location - 1], brandName[location - 1]);
		printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 4, msize_4_qty[location - 1]);
		printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 5, msize_5_qty[location - 1]);
		printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 6, msize_6_qty[location - 1]);
		printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 7, msize_7_qty[location - 1]);
		printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 8, msize_8_qty[location - 1]);
		printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 9, msize_9_qty[location - 1]);
		printf("\t\t\t\t\tMen-%-5d\t%-5d\n", 10, msize_10_qty[location - 1]);

		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 5, wsize_5_qty[location - 1]);
		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 6, wsize_6_qty[location - 1]);
		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 7, wsize_7_qty[location - 1]);
		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 8, wsize_8_qty[location - 1]);
		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 9, wsize_9_qty[location - 1]);
		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 10, wsize_10_qty[location - 1]);
		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 11, wsize_11_qty[location - 1]);
		printf("\t\t\t\t\tWomen-%-5d\t%-5d\n", 12, wsize_12_qty[location - 1]);
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

	int i;

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

	printf("\n\n");

	for(i = 5; i >= 0; i--)
	{
		if(i >= 1)
			printf("\rRedirecting to Records Menu in %d second");
		else
			printf("\rRedirecting to Records Menu in %d seconds");
		Sleep(1000);
	}

	fflush(stdout);
	fflush(stdin);
	Records();
}

void WritesFile()
{
	FILE* fileptr;
	fileptr = fopen("Logs\\records.txt", "w");

	int size, count = temporarySize, i;

	if(NULL != fileptr)
	{
		fprintf(fileptr, "\t\t\t***** INVENTORY *****\n");
		fprintf(fileptr, "--------------------------------------------------------------------------------\n");
		fprintf(fileptr, "\tID\t|\tNAME\t|\tSize\t|\tQUANTITY\n");
		fprintf(fileptr, "--------------------------------------------------------------------------------\n");

		for(i = 0; i < count; i++)
		{
			fprintf(fileptr, "\t%-8d\t%-25s\n", brandID[i], brandName[i]);

			fprintf(fileptr, "\t\t\t\t\tMen-%-5d\t%-5d\n", 4, msize_4_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tMen-%-5d\t%-5d\n", 5, msize_5_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tMen-%-5d\t%-5d\n", 6, msize_6_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tMen-%-5d\t%-5d\n", 7, msize_7_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tMen-%-5d\t%-5d\n", 8, msize_8_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tMen-%-5d\t%-5d\n", 9, msize_9_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tMen-%-5d\t%-5d\n", 10, msize_10_qty[i]);

			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 5, wsize_5_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 6, wsize_6_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 7, wsize_7_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 8, wsize_8_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 9, wsize_9_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 10, wsize_10_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 11, wsize_11_qty[i]);
			fprintf(fileptr, "\t\t\t\t\tWomen-%-5d\t%-5d\n", 12, wsize_12_qty[i]);
		}
	}
	fclose(fileptr);
}

void insertAnyLocation()
{
	int location, size = temporarySize, i, k, tempID;
	
	char temp[20], option = 'Y';

	do
	{
		system("cls");
		fflush(stdin);
		printf("Location: ");
		scanf("%d", &location);
		
		location -= 1;

		memmove(brandName[location + 1], brandName[location], (size - location) * sizeof(brandName[0]));

		size++;

		for(i = size - 1; i >= location - 1; i--)
		{
			brandID[i] = brandID[i - 1];
			wsize_5_qty[i] = wsize_5_qty[i - 1];
			wsize_6_qty[i] = wsize_6_qty[i - 1];
			wsize_7_qty[i] = wsize_7_qty[i - 1];
			wsize_8_qty[i] = wsize_8_qty[i - 1];
			wsize_9_qty[i] = wsize_9_qty[i - 1];
			wsize_10_qty[i] = wsize_10_qty[i - 1];
			wsize_11_qty[i] = wsize_11_qty[i - 1];
			wsize_12_qty[i] = wsize_12_qty[i - 1];
			msize_4_qty[i] = msize_4_qty[i - 1];
			msize_5_qty[i] = msize_5_qty[i - 1];
			msize_6_qty[i] = msize_6_qty[i - 1];
			msize_7_qty[i] = msize_7_qty[i - 1];
			msize_8_qty[i] = msize_8_qty[i - 1];
			msize_9_qty[i] = msize_9_qty[i - 1];
			msize_10_qty[i] = msize_10_qty[i - 1];
		}

insertids:

		fflush(stdin);
		printf("Brand ID: ");
		scanf("%d", &tempID);

		for(k = 0; k < size; k++)
		{
			if(brandID[k] == tempID)
			{
				printf("Brand ID Already Used!");
				Sleep(5000);
				fflush(stdin);
				system("cls");
				goto insertids;
			}
		}
		brandID[location] = tempID;
insertnames:
		fflush(stdin);
		printf("Brand name: ");
		scanf("%s", temp);

		if(strInputCheck(temp) == true)
		{
			printf("Input only Accepts letter for string!");
			Sleep(5000);
			fflush(stdin);
			system("cls");
			goto insertnames;
		}

		if(compare(temp) == true)
		{
			printf("Brand Already Exists!");
			Sleep(5000);
			fflush(stdin);
			system("cls");
			goto insertnames;
		}

		strcpy(brandName[location], temp);

		fflush(stdin);
		printf("Enter Quantity for Women Size 5: ");
		scanf("%d", &wsize_5_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Women Size 6: ");
		scanf("%d", &wsize_6_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Women Size 7: ");
		scanf("%d", &wsize_7_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Women Size 8: ");
		scanf("%d", &wsize_8_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Women Size 9: ");
		scanf("%d", &wsize_9_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Women Size 10: ");
		scanf("%d", &wsize_10_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Women Size 11: ");
		scanf("%d", &wsize_11_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Women Size 12: ");
		scanf("%d", &wsize_12_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Men Size 4: ");
		scanf("%d", &msize_4_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Men Size 5: ");
		scanf("%d", &msize_5_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Men Size 6: ");
		scanf("%d", &msize_6_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Men Size 7: ");
		scanf("%d", &msize_7_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Men Size 8: ");
		scanf("%d", &msize_8_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Men Size 9: ");
		scanf("%d", &msize_9_qty[location]);

		fflush(stdin);
		printf("Enter Quantity for Men Size 10: ");
		scanf("%d", &msize_10_qty[location]);

		temporarySize += 1;
		WritesFile();

		fflush(stdin);
		printf("Do you want to Retry? [Y]es|[N]o: ");
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

int compare(char stringName[])
{
	int size = temporarySize;
	int i, same = false;
				
	for(i = 0; i < size; i++)
		if(strcmp(tolower(brandName[i]), tolower(stringName)) == false)
			same = true;

	return same;
}

int stringlocator(char stringName[])
{
	int size = temporarySize;
	int i, location = 0;
				
	for(i = 0; i < size; i++)
		if(strcmp(tolower(brandName[i]), tolower(stringName)) == false)
			location = i + 1;

	return location;
}

int strInputCheck(char stringInput[])
{
	int i, length = strlen(stringInput), check;
	
	for(i = 0; i < length + 1; i++)
		if(stringInput[i] != '\0')
			if(!isdigit(stringInput[i]))
				check = false;
			else
				check = true;
	
	return check;
}

void Exit()
{
    exit(EXIT_SUCCESS);
}
