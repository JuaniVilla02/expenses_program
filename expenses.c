#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    char name[LMAX];
    char description[LMAX];
    TDate date;
    int amount;
    int type;
}TExpense;

//struct that stores the array of expenses and the actual elements of the array.
typedef struct Data{
    TExpense expenses[NMAX];
    int elements;
}TData;

//profile of every function used in the program.
bool isEmpty(TData* data);
bool isFull(TData* data);
void newExpense(TData* data, TDate* date);
void modifyExpense(TData* data, int index);
void deleteExpense(TData* data, int index);
void showExpenses(TData* data);
int mothlyExpenses(TData* data);

//void functions that will handle the menu.
// void Option1();
// void Option2();
// void Option3();
// void Option4();
// void Option5();
// void Option6();
// void Option8();
// void Option9();

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
        //menu that will be displayed everytime the user runs the program
        printf("\n-----------------------------------\n");
        printf("New expense (1)\n");
        printf("Modify an expense (2)\n");
        printf("Delete an expense (3)\n");
        printf("Show expenses (4)\n");
        printf("Monthly expenses (5)\n");
        printf("Show fixed expense's names and amount spended in a given month (6)\n");
        printf("Show variable expense's names and amount spended in a given month (7)\n");
        printf("Save and exit (8)");
        printf("\n-----------------------------------\n");
        printf("Input an option: ");
        fflush(stdout); fflush(stdin);
        scanf("%d", &option);
        fflush(stdin);

        switch (option){
            case 1:
                // Option1();    
                break;

            case 2:
                // Option2();
                break;

            case 3:
                // Option3();
                break;

            case 4: 
                // Option4();
                break;

            case 5:
                // Option5();
                break;

            case 6:
                // Option6();
                break;

            case 7:
                // Option7();
                break;

            case 8:
                // Option8();
                return 0;
                break;
            
            default: // 'option' option is not between 1 and 9.
                printf("\nInvalid option.\n");
                break;
        }
    } while (1);
}

bool isEmpty(TData* data){
    // if the amount of elements in the array is equal to 0, it returns True.
    if ((*data).elements== 0){
        return true;
    }else{
        return false;
    }
}

bool isFull(TData* data){
    // if the amount of elements in the array is equal to NMAX, it returns True.
    if ((*data).elements == NMAX){
        return true;
    }else{
        return false;
    }
}

void newExpense(TData* data, TDate* date){
    char name[LMAX];
    char description[LMAX];
    int amount;
    int type;

    if (isFull(data)){
        printf("The list is full.");
    }else{
        //the data is asked to the user and stored in local variables.
        printf("New expenses's name: ");
        scanf("%s\n", name);
        printf("New expense's description: ");
        scanf("%s\n", description);
        printf("Amount spended: ");
        scanf("%d\n", &amount);
        printf("Expense type. (1) is fixed, (0) is variable: ");
        scanf("%d\n", &type);
        
        //if the type is 1 (that is, the expense is fixed...).
        if (type == 1){
            //every expense in the array is moved one place forward to make room for the newly added expense.
            for (int i = 0; i <= NMAX; i++){
                (*data).expenses[i + 1] = (*data).expenses[i];
            }
            strcpy((*data).expenses[0].name, name);
            strcpy((*data).expenses[0].description, description);
            (*data).expenses[0].date.day = (*date).day;
            (*data).expenses[0].date.month = (*date).month;
            (*data).expenses[0].date.year = (*date).year;
            (*data).expenses[0].amount = amount;
            (*data).expenses[0].type = type;
            (*data).elements++;
            printf("New expense was added successfully!\n");
        }else{
            int i;
            //this loop will traverse the array until it founds the first variable expense.
            for (i = 0; i < NMAX; i++){
                if ((*data).expenses[i].type == 1){
                    continue;
                }else{
                    break;
                }
            }
            //every expense in the array is moved one place forward to make room for the newly added expense.
            for (; i <= NMAX; i++){
                (*data).expenses[i + 1] = (*data).expenses[i];
            }
            strcpy((*data).expenses[0].name, name);
            strcpy((*data).expenses[0].description, description);
            (*data).expenses[0].date.day = (*date).day;
            (*data).expenses[0].date.month = (*date).month;
            (*data).expenses[0].date.year = (*date).year;
            (*data).expenses[0].amount = amount;
            (*data).expenses[0].type = type;
            (*data).elements++;
            printf("New expense was added successfully!\n");
        }
    }
}

void modifyExpense(TData* data, int index){
    char name[LMAX];
    char description[LMAX];
    int amount;
    
    index--;
    printf("\nNew expense's name: ");
    scanf("%s\n", name);
    printf("New expense's description: ");
    scanf("%s\n", description);
    printf("New expense's amount: ");
    scanf("%d\n", &amount);
    
    strcpy((*data).expenses[index].name, name);
    strcpy((*data).expenses[index].description, description);
    (*data).expenses[index].amount = amount;
    printf("The expense at index %d was modified successfully!\n", index++);
}

void deleteExpense(TData* data, int index){
    index--;
    int i = index;
    
    for (; i < (*data).elements; i++){
        (*data).expenses[i] = (*data).expenses[i + 1];
    }
    printf("The expense at index %d was modified successfully!\n", index++);
}

void showExpenses(TData* data){
    printf("\nExpenses:\n");
    for (int i = 0; i < (*data).elements; i++){
        printf("\n-----------------------------------\n");
        printf("%s\n", (*data).expenses[i].name);
        printf("%s\n", (*data).expenses[i].description);
        printf("%ls\n", &(*data).expenses[i].date.day);
        printf("%ls\n", &(*data).expenses[i].date.month);
        printf("%ls\n", &(*data).expenses[i].date.year);
        printf("%ls\n", &(*data).expenses[i].amount);
        printf("%ls\n", &(*data).expenses[i].type);
        printf("-----------------------------------\n");
    }
}

int mothlyExpenses(TData* data){
    int month;
    int counter = 0;

    printf("Input a month (between 1 and 12): ");
    scanf("%d", &month);
    
    for (int i = 0; i < (*data).elements; i++){
        if ((*data).expenses[i].date.month == month){
            counter += (*data).expenses[i].amount; 
        }else{
            continue;
        }
    }
    return counter;
}

void fixedExpenses(TData* data, int month){
    int counter = 0;
    
    for (int i = 0; i < (*data).elements; i++){
        if ((*data).expenses[i].type == 1 && (*data).expenses[i].date.month == month){
            counter += (*data).expenses[i].amount;
            printf("\n-----------------------------------\n");
            printf("%s\n", (*data).expenses[i].name);
            printf("%s\n", (*data).expenses[i].description);
            printf("%ls\n", &(*data).expenses[i].date.day);
            printf("%ls\n", &(*data).expenses[i].date.month);
            printf("%ls\n", &(*data).expenses[i].date.year);
            printf("%ls\n", &(*data).expenses[i].amount);
            printf("%ls\n", &(*data).expenses[i].type);
            printf("-----------------------------------\n");
        }else{
            continue;
        }
    }
    printf("The amount spended in these fixed expenses at month %d is %d\n", month, counter);
}

void variableExpenses(TData* data, int month){
    int counter = 0;

    for (int i = 0; i < (*data).elements; i++){
        if ((*data).expenses[i].type == 0 && (*data).expenses[i].date.month == month){
            counter += (*data).expenses[i].amount;
            printf("\n-----------------------------------\n");
            printf("%s\n", (*data).expenses[i].name);
            printf("%s\n", (*data).expenses[i].description);
            printf("%ls\n", &(*data).expenses[i].date.day);
            printf("%ls\n", &(*data).expenses[i].date.month);
            printf("%ls\n", &(*data).expenses[i].date.year);
            printf("%ls\n", &(*data).expenses[i].amount);
            printf("%ls\n", &(*data).expenses[i].type);
            printf("-----------------------------------\n");
        }else{
            continue;
        }
    }
    printf("The amount spended in these variable expenses at month %d is %d\n", month, counter);
}
