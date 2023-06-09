#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int MainMenu(int);
int Option_Process(int, int, int);
int OrderPrice(char, int, int);
float TotalPrice(int);
int TotalAmount(int);
int Continues(float, int, int);
float Discount(int, float);
struct Order Cancel(int, int);
int ReceiptCheck(int, int);

typedef enum BurgerTypes{Chicken = 1, Ham , Veggie } BurgerTypes;

typedef struct Burger
{
    int Amount;
    float Total;
    enum BurgerTypes BurgerType;
}Burger;

typedef struct Order
{
    int ReceiptNo;
    int TotalOrderValue;
    Burger *Burger;
}Order;

Order* o;


int main()
{   
    int x;
    o = (Order*)calloc(25,sizeof(Order));
    for (x=0; x<25; x++)
        o[x].Burger = (Burger*)calloc(25,sizeof(Burger));
    int i = 0;
    MainMenu(i);
}

int MainMenu(int i)
{   
    int option, j = 0;
    float sum = 0;
    while (!(option == 3 || i >= 25))
    {
        j = 0;
        printf("\n\n\n\nWelcome to Tasty Burgers\nPlace your order here...\n1.    Order Burger\n2.    Cancel\n3.    Exit\n\nSelect your option:\n");
        scanf("%d", &option);
        getchar();
        Option_Process(option, i, j);
    }
    return 0;
}

int Option_Process(int option, int i, int j)
{
    int receiptNum = 0, totalamount = 0;
    float totalFull = 0;
    char burgertype;
    switch (option)
    {
        case 1:
            printf("\nSelect the Burger Type\nA - Chicken Burger - 15$\nB - Ham Burger - 17$\nC - Veggie Burger - 13$\nX - To return to Main Menu\n\nSelect your burger type \n");
            scanf(" %s", &burgertype);
            fflush(stdin);
            OrderPrice(burgertype, i, j);
            totalFull = TotalPrice(i);
            totalamount = TotalAmount(i);
            (o+i)->TotalOrderValue = Discount(totalamount,totalFull);
            (o+i)->ReceiptNo = i;
            ReceiptCheck(1, i);
            break;
        case 2:
            printf("Please enter your receipt number:\nB00");
            scanf("%d", &receiptNum);
            fflush(stdin);
            *(o+receiptNum-1) = Cancel(receiptNum, i);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nPlease enter a valid option.");
            break;
    }
    return 0;
}


int OrderPrice(char burgertype, int i, int j)
{
    float totalFull = 0;
    int Aprice = 15, Bprice = 17, Cprice = 13;
    while (j != 100)
        {
            j++;
            switch (toupper(burgertype))
                {
                    case'X':
                        MainMenu(i);
                        break;
                    case 'A':
                        printf("You have selected Chicken Burger. How many burgers you wish you order?\n");
                        scanf("%d", &(o[i].Burger+j)->Amount);
                        fflush(stdin);
                        (o[i].Burger+j)->Total = (o[i].Burger+j)->Amount * Aprice;
                        (o[i].Burger+j)->BurgerType = Chicken;
                        break;
                    case 'B':
                        printf("You have selected Ham Burger. How many burgers you wish you order?\n");
                        scanf("%d", &(o[i].Burger+j)->Amount);
                        fflush(stdin);
                        (o[i].Burger+j)->Total = (o[i].Burger+j)->Amount * Bprice;
                        (o[i].Burger+j)->BurgerType = Ham;
                        break;
                    case 'C':
                        printf("You have selected Veggie Burger. How many burgers you wish you order?\n");
                        scanf("%d", &(o[i].Burger+j)->Amount);
                        fflush(stdin);
                        (o[i].Burger+j)->Total = (o[i].Burger+j)->Amount * Cprice;
                        (o[i].Burger+j)->BurgerType = Veggie;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
            j = Continues((o[i].Burger+j)->Total, i, j);
        }
}

int Continues(float total, int i, int j)
{
    char continueOption;
    printf("\nYour current bill value is %.2f", total);
    printf("\nPress Y to add more burgers into your order or Press N to process your order now. \n");
    scanf(" %s", &continueOption);
    fflush(stdin);
    switch(toupper(continueOption))
    {
        case 'Y':
            Option_Process(1, i, j);
            break;
        case 'N':
            j = 100;
            return j;
            break;
        default:
            printf("Please enter a valid option.");
            break;
    }
}

float TotalPrice(int i)
{
    int j, Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += (o[i].Burger+j)->Total;
    }
    return Total_Price;
}

int TotalAmount(int i)
{
    int j, TotalBurger = 0;
    for (j=0;j<25;j++)
    {
        TotalBurger += (o[i].Burger+j)->Amount;
    }
    return TotalBurger;
}

float Discount(int amount, float totalFull)
{   
    float discountAMT = 0.1, total = 0;
    if (amount>=5)
    {
        total = totalFull*(1-discountAMT);
        printf("\nYour total bill value is $%.2f", totalFull);
        printf("\nDiscount 10%% - $%.2f", totalFull*discountAMT);
        printf("\nFinal bill values is $%.2f", total);
        return total;
    }
    else
    {
        printf("\nYour total bill value is $%.2f", totalFull);
        return totalFull;
    }
}

struct Order Cancel(int receiptNum, int receiptTotal)
{
    if (receiptNum<=receiptTotal)
    {
        int j;
        (o+receiptNum-1)->TotalOrderValue = 0;
        for (j=0;j<25;j++)
        {
            (o[receiptNum-1].Burger+j)->Amount = 0;
            (o[receiptNum-1].Burger+j)->Total = 0;
        }
        printf("\nYour order has been cancelled. Thank you.");
    }
    else
    {
        printf("Incorrect Receipt Number");
    }
    return *(o+receiptNum-1);
}

int ReceiptCheck(int option, int i)
{
    if (!(option == 2 || option == 3))
    {
    printf("\nYour receipt number is B00%d", i+1);
    printf("\nPlease go to a register and make the payment by quoting the Receipt Number - B00%d", i+1);
    printf("\n\n<< Press Any Key to show the main menu>>\n");
    getchar();
    i++;
    }
    MainMenu(i);
}
