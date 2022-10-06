#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int ID;
int brandID[20];
char brandName[20];

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

void Loading();
void Menu();
void AddItems();
void DeleteItem();
void Records();
void Search();
void ReadFile();
void WriteFile();
void Exit();

int main(int argc, char** argv[])
{
	Loading();

	return 0;
}

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

void AddItems()
{
	int i, n, tempID, cs = 0;
    char temp[20];

    char option = 'Y';

   	do
   	{
   		ID = cs++;

   		fflush(stdin);
	    printf("Enter Number of Shoe Brands to be added: ");
	    scanf("%d", &n);
	    fflush(stdin);

	    for(i = 0; i < n; i++)
	    {
	    	system("cls");

	    	fflush(stdin);
	        printf("Brand ID: ");
	        scanf("%d", &tempID);

	        for(k = 0; k < n; k++)
	        {
	        	if(!strcmp(toupper(brandName[i]), toupper(temp)))
				{
					printf("Brand Already Exists!");
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
	        	if(!strcmp(toupper(brandName[i]), toupper(temp)))
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


	    if(option == 'N' || option == 'n')
	    {
	    	fflush(stdin);
	    	Menu();
	    }
	}
	while(option == 'Y' || option == 'y');
}

void DeleteItem()
{
	//
}

void Records()
{
	int i, j;
	struct Inventory item[20];
	
	printf(" ***** INVENTORY *****\n");
    printf("------------------------------------------------------------------\n");
    printf("ID\t|\tNAME\t|\tSize\t|\tQUANTITY \n");
    printf("------------------------------------------------------------------\n");
    
    //
}

void Search()
{
	//
}

void ReadFile()
{
	//
}

void WriteFile()
{
	//
}

void Exit()
{
    exit(EXIT_SUCCESS);
}
