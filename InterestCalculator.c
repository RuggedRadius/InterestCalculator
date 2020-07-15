#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool running = true;

void main()
{
    while (running)
    {
        getMenuChoice();
    }
}

int getMenuChoice()
{
    // Clear screen
    clrscr();

    // Print header
    printf("*******************************\n");
    printf("***** INTEREST CALCULATOR *****\n");
    printf("*******************************\n");

    // Print menu
    printf("Enter selection:\n\n\t1. Simple Interest\n\t2. Compound Interest\n\t3. Exit\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        simpleInterest();
        break;

    case 2:
        compoundInterest();
        break;

    case 3:
        clrscr();
        printf("Exiting...\n\nThanks for using this calculator!\n");
        running = false;
        exit(0);
        break;

    default:
        getMenuChoice();
        break;
    }
}

void simpleInterest()
{
    // Init
    double principal;
    double interest;
    double total;
    double rate;
    double loanTerm;

    // Clear screen
    clrscr();

    // Print header
    printf("**************************************\n");
    printf("***** SIMPLE INTEREST CALCULATOR *****\n");
    printf("**************************************\n\n");

    printf("Principal amount: \n\t$");
    scanf("%lf", &principal);
    printf("Interest rate %%: \n\t");
    scanf("%lf", &rate);
    printf("Loan term in years: \n\t");
    scanf("%lf", &loanTerm);

    rate /= 100;
    interest = principal * rate * loanTerm;

    printf("\nPrincipal: \n\t$%lf\n", principal);
    printf("Interest: \n\t$%lf\n", interest);
    printf("Total: \n\t$%lf\n\n\n", principal + interest);

    system("pause");
}

void compoundInterest()
{
    // Init
    double principal;
    double interest;
    double total;
    double rate;
    double loanTerm;
    double interval;

    // Clear screen
    clrscr();

    // Print header
    printf("****************************************\n");
    printf("***** COMPOUND INTEREST CALCULATOR *****\n");
    printf("****************************************\n");

    printf("Principal amount: \n\t$");
    scanf("%lf", &principal);
    printf("Interest rate %%: \n\t");
    scanf("%lf", &rate);
    printf("Loan term in years: \n\t");
    scanf("%lf", &loanTerm);
    printf("Compound interval: \n\t");
    scanf("%lf", &interval);

    rate /= 100;
    double base = (1 + (rate/interval));
    double exp = (loanTerm * interval);
    interest = (principal * pow(base, exp)) - principal;

    printf("\nPrincipal: \n\t$%lf\n", principal);
    printf("Interest: \n\t$%lf\n", interest);
    printf("Total: \n\t$%lf\n\n\n", principal + interest);

    system("pause");
}

void clrscr()
{
    system("@cls||clear");
}

