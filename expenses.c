#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 10
#define LMAX 70

typedef struct Date{
    int day;
    int month;
    int year;
}Date;

typedef struct Expense{
    char description[LMAX];
    char name[LMAX];
    Date date;
    unsigned int amount;
    int type;
}Expense;

Expense expenses[NMAX];