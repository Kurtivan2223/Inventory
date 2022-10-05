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

struct Sizes
{
    int brandSize;
    int brandQuantity;
};

struct Inventory
{
    int brandID;
    char brandName[20];
    struct Sizes quantity[20];
};

void Loading();
void Menu();
void AddItems();
void DeleteItem();
void Exit();

int main(int argc, char** argv[])
{
    Loading();
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
        printf("\n\n[1] Add Item\n[2] Delete Item\n[3] Exit\n: ");
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
    struct Inventory item[20];
    int i, j, n;

    printf("Enter Number of Shoe Brands to be added: ");
    scanf("%d", &n);
    fflush(stdin);

    int m[n];

    for(i = 0; i < n; i++)
    {
        fflush(stdin);
        item[i].brandID = i + 1;
        printf("Brand name: ");
        scanf("%s", item[i].brandName);

        fflush(stdin);
        printf("Enter Number of Sizes Available for %s: ", item[i].brandName);
        scanf("%d", &m[i]);
        
        for(j = 0; j < m[i]; j++)
        {
            fflush(stdin);
            printf("Enter Shoe Size %d: ", j + 1);
            scanf("%d", &item[i].quantity[j].brandSize);
            
            fflush(stdin);
            printf("Enter Shoe Size Quantity %d: ", j + 1);
            scanf("%d", &item[i].quantity[j].brandQuantity);
        }
    }

    printf(" ***** INVENTORY *****\n");
    printf("------------------------------------------------------------------\n");
    printf("ID | NAME | Size | QUANTITY \n");
    printf("------------------------------------------------------------------\n");
    
    for(i = 0; i < n; i++)
    {
        printf("%-4d %-15s\n", item[i].brandID, item[i].brandName);
        for(j = 0; j < m[i]; j++)
        {
            if(item[i].quantity[j].brandSize != '\0')
                printf("\t\t%-5d %-5d\n", item[i].quantity[j].brandSize, item[i].quantity[j].brandQuantity);
        }
    }
    
    system("pause");
}

void DeleteItem()
{
	Exit();
}

void Exit()
{
    exit(EXIT_SUCCESS);
}
