#include <stdio.h>
#include <string.h>

//float BurgerTotalFull(char, int, int);
float Discount(int, float);
struct Burger Cancel(int, int);
int ReceiptCheck(int, int);

typedef enum BurgerTypes{Chicken = 1, Ham , Veggie } BurgerTypes;

typedef struct Burger
{
    int ReceiptNo;
    int Amount;
    float Total;
    enum BurgerTypes BurgerType;
}Burger;
//menu(), FUNCTION("",""), FUNCTION(XX,XX)
int main()
{   

    int option, i = 0, receiptNum = 0, j;
    int Aprice = 15, Bprice = 17, Cprice = 13; 
    float sum = 0, totalFull = 0;
    char burgertype;
    Burger b[25];
    while (!(option == 3 || i >= 25))
    {
        mainmenu:
        b[i].Amount = 0;
        b[i].Total = 0;
        b[i].ReceiptNo = 0;
        b[i].BurgerType = 0;
        printf("\n\n\n\nWelcome to Tasty Burgers\nPlace your order here...\n1.    Order Burger\n2.    Cancel\n3.    Exit\n\nSelect your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            printf("Select the Burger Type\nA - Chicken Burger - 15$\nB - Ham Burger - 17$\nC - Veggie Burger - 13$\nX - To return to Main Menu\n\nSelect your burger type\n");
            scanf("%c", &burgertype);
            switch (toupper(burgertype))
            {
                case'X':
                goto mainmenu;
                break;
                case 'A':
                printf("You have selected Chicken Burger. How many burgers you wish you order?\n");
                scanf("%d", &b[i].Amount);
                totalFull = b[i].Amount * Aprice;
                b[i].BurgerType = Chicken;
                break;
                case 'B':
                printf("You have selected Ham Burger. How many burgers you wish you order?\n");
                scanf("%d", &b[i].Amount);
                totalFull = b[i].Amount * Bprice;
                b[i].BurgerType = Ham;
                break;
                case 'C':
                printf("You have selected Veggie Burger. How many burgers you wish you order?\n");
                scanf("%d", &b[i].Amount);
                totalFull = b[i].Amount * Cprice;
                b[i].BurgerType = Veggie;
                break;
                default:
                printf("Please enter a valid option.");
                break;
            }
            //totalFull = BurgerTotalFull(burgertype, i, b[i].Amount);
            b[i].Total = Discount(b[i].Amount,totalFull);
            break;
        case 2:
            printf("Please enter your receipt number:\nB00");
            scanf("%d", &receiptNum);
            b[receiptNum-1] = Cancel(receiptNum, i);
            break;
        case 3:
            break;
        default:
            printf("\nPlease enter a valid option.");
            break;
        }
    b[i].ReceiptNo = i;
    i = ReceiptCheck(option, i);
    printf("\n\n<< Press Any Key to show the main menu>>");
    for (j=0; j<i; j++)
    {
        printf("\n%d", b[j].Amount);
        printf("\n%.2f", b[j].Total);
        printf("\n%d", b[j].BurgerType);
    }
    }
    for(j=0;j<i;j++)
        sum += b[j].Total;
    printf("\nTotal Revenue: %.2f", sum);
    return 0;
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
        printf("Your total bill value is $%.2f", totalFull);
        return totalFull;
    }
}

struct Burger Cancel(int receiptNum, int receiptTotal)
{
    Burger b[25];
    if (receiptNum<=receiptTotal)
    {
        b[receiptNum-1].Amount = 0;
        b[receiptNum-1].Total = 0;
        b[receiptNum-1].BurgerType = 0;
        printf("\nYour order has been cancelled. Thank you.");
    }
    else
    {
        printf("Incorrect Receipt Number");
    }
    return b[receiptNum-1];
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











