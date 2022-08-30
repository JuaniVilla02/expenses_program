#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 10
#define LMAX 100

//struct that stores all the aspects of a date.
typedef struct Date{
    int day;
    int month;
    int year;
}TDate;

//sruct that stores all the aspects of an expense.
typedef struct Expense{
    char description[LMAX];
    char name[LMAX];
    TDate date;
    unsigned int amount;
    int type;
}TExpense;

//struct that stores the array of expenses and the actual elements of the array.
typedef struct Data{
    TExpense expenses[NMAX];
    int elements;
}TData;

//void functions that will handle the menu.
void Option1();
void Option2();
void Option3();
void Option4();
void Option5();
void Option6();
void Option7();
void Option8();

TData data;
TDate date;

int main() {
    int option;

    printf("Input today's day: ");
    scanf("%d\n", &date.day);
    printf("Input today's month: ");
    scanf("%d\n", &date.month);
    printf("Input today's year: ");
    scanf("%d\n", &date.year);

    do{
        printf("\n-----------------------------------\n");
        printf("New expense (1)\n");
        printf("Modify an expense (2)\n");
        printf("Delete an expense (3)\n");
        printf("Show expenses (4)\n");
        printf("Monthly expenses (5)\n");
        printf("Show expenses's names (6)\n");
        printf("Show fixed expense's names and amount spended in a given month (7)\n");
        printf("Show variable expense's names and amount spended in a given month (8)\n");
        printf("Save and exit (9)");
        printf("-----------------------------------\n");
        printf("Input an option: ");
        fflush(stdout); fflush(stdin);
        scanf("%d", &option);
        fflush(stdin);

        switch (option){
            case 1:
                Option1();    
                break;

            case 2:
                Option2();
                break;

            case 3:
                Option3();
                break;

            case 4: 
                Option4();
                break;

            case 5:
                Option5();
                break;

            case 6:
                Option6();
                break;

            case 7:
                Option7();
                break;

            case 8:
                Option8();
                break;

            case 9:
                return 0;
                break;
            
            default: // 'option' option is not between 1 and 6.
                printf("\nInvalid option.\n");
                break;
        }
    } while (1);
}