#include <stdio.h>
#include <string.h>
#include <conio.h>

float Discount(float);
struct Burger Cancel(int, int);
int ReceiptCheck(int, int);



struct Burger
{
    int ReceiptNo;
    int Amount;
    float Total; 
    
};


int main()
{   
    int option, i = 0, receiptNum = 0, j; 
    float sum=0;
    struct Burger burger[25];
    while (!(option == 3 || i >= 25))
    {
        burger[i].Amount = 0;
        burger[i].Total = 0;
        burger[i].ReceiptNo = 0;
        printf("\n\n\n\nWelcome to Tasty Burgers\nPlace your order here...\n1.    Order Burger\n2.    Cancel\n3.    Exit\n\nSelect your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            printf("How many burgers you wish you order?\n");
            scanf("%d", &burger[i].Amount);
            burger[i].Total = Discount(burger[i].Amount);
            break;
        case 2:
            printf("Please enter your receipt number:\nB00");
            scanf("%d", &receiptNum);
            burger[receiptNum-1] = Cancel(receiptNum, i);
            break;
        case 3:
            break;
        default:
        printf("\nPlease enter a valid option.");
            break;
        }
    burger[i].ReceiptNo = i;
    i = ReceiptCheck(option, i);
    printf("\n\n<< Press Any Key to show the main menu>>");
    for (j=0; j<i; j++)
    {
        printf("\nTotal Burger: %d", burger[j].Amount);
        printf("\nTotal price: %.2f", burger[j].Total);
    }
    }
    for(j=0;j<i;j++)
        sum += burger[j].Total;
    printf("\nTotal Revenue: %.2f", sum);
    return 0;
}

float Discount(float amount)
{   
    float price = 12, total = 0, discountAMT = 0.1;
    if (amount>=5)
    {
        total = amount*price*(1-discountAMT);
        printf("\nYour total bill value is $%.2f", amount*price);
        printf("\nDiscount 10%% - $%.2f", amount*price*discountAMT);
        printf("\nFinal bill values is $%.2f", total);
    }
    else
    {
        total = amount*price;
        printf("Your total bill value is $%.2f", total);
    }
    return total;
}

struct Burger Cancel(int receiptNum, int receiptTotal)
{
    struct Burger burger[25];
    if (receiptNum<=receiptTotal)
    {
        //struct Burger burger[receiptNum-1] = {0, 0, 0};
        burger[receiptNum-1].Amount = 0;
        burger[receiptNum-1].Total = 0;
        //burger[receiptNum-1].ReceiptNo = 0;
        printf("\nYour order has been cancelled. Thank you.");
    }
    else
    {
        printf("Incorrect Receipt Number");
    }
    return burger[receiptNum-1];
}

int ReceiptCheck(int option, int i)
{
    if (!(option == 2 || option == 3))
    {
    printf("\nYour receipt number is B00%d", i+1);
    printf("\nPlease go to a register and make the payment by quoting the Receipt Number - B00%d", i+1);
    i++;
    }
    return i;
}
