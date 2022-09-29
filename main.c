#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char** argv[])
{
    struct Inventory item[20];
    int i, j, n, m;

    printf("Enter Number of Shoe Brands to be added: ");
    scanf("%d", &n);
    
    fflush(stdin);
    printf("Enter Number of Sizes Available: ");
    scanf("%d", &m);

    for(i = 0; i < n; i++)
    {
        fflush(stdin);
        item[i].brandID = i + 1;
        printf("Brand name: ");
        scanf("%s", item[i].brandName);
        
        for(j = 0; j < m; j++)
        {
        	fflush(stdin);
            printf("Enter Shoe Size %d: ", j + 1);
            scanf("%d", &item[i].quantity[j].brandSize);
            
            fflush(stdin);
            printf("Enter Shoe Size Quantity %d: ", j + 1);
            scanf("%d", &item[i].quantity[j].brandQuantity);
            fflush(stdin);
        }
    }

    printf(" ***** INVENTORY *****\n");
    printf("------------------------------------------------------------------\n");
    printf("ID | NAME | Size | QUANTITY \n");
    printf("------------------------------------------------------------------\n");
    
    for(i = 0; i < n; i++)
    {
    	printf("%-4d %-15s\n", item[i].brandID, item[i].brandName);
        for(j = 0; j < m; j++)
        {
            printf("\t\t%-5d %-5d\n", item[i].quantity[j].brandSize, item[i].quantity[j].brandQuantity);
        }
    }    
}
