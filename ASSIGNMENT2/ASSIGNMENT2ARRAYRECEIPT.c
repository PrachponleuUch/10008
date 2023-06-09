#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int MainMenu(int, int, int);
int Option_Process(int, int, int);
int OrderPriceMeal(char, int, int);
int OrderPriceBurger(char, int, int);
int OrderPriceChips(char, int, int);
int OrderPriceDrinks(char, int, int);
int Continues(float, int, int);
float TotalPriceMeal(int);
float TotalPriceBurger(int);
float TotalPriceChips(int);
float TotalPriceDrinks(int);
int TotalAmountMeal(int);
int TotalAmountBurger(int);
int TotalAmountChips(int);
int TotalAmountDrinks(int);
float Discount(int, float);
struct Order Cancel(int, int);
int ReceiptCheck(int, int, int);
float CalculateRevenue(int);

typedef enum BurgerTypes {Chicken = 1, Ham , Veggie } BurgerTypes;
typedef enum ChipsSize {Medium = 1, Large } ChipsSize;
typedef enum DrinkSize {Med = 1, Lg } DrinkSize;

typedef struct Drinks
{
    int Amount;
    float Total;
    enum DrinkSize DrinkSize;
}Drinks;

typedef struct Chips
{
    int Amount;
    float Total;
    enum ChipsSize ChipsSize;
}Chips;

typedef struct Burger
{
    int Amount;
    float Total;
    enum BurgerTypes BurgerType;
}Burger;

typedef struct Meal
{
    int Amount;
    float Total;
    Burger Burger[26];
    Chips Chips[26];
    Drinks Drinks[26];
}Meal;

typedef struct Order
{
    int ReceiptNo;
    float TotalOrderValue;
    Burger Burger[26];
    Meal Meal[26];
    Chips Chips[26];
    Drinks Drinks[26];
}Order;

system("clear");

Order o[25];
//Order *o;

int main()
{   
    //o = (Order*)calloc(25,sizeof(Order));
    int i = 0;
    int option, j = 0;
    MainMenu(i, option, j);
}

int MainMenu(int i, int option, int j)
{   
    float sum = 0;
    while (!(option == 7 || i >= 25))
    { 
        printf("\n\n\n\nWelcome to Tasty Burgers\nPlace your order here...\n1.    Order Meals\n2.    Order Burgers\n3.    Order Chips\n4.   Order Cold Drinks\n5.   Process Order\n6.   Cancel\n7.  Exit\n\nSelect your option:\n");
        scanf("%d", &option);
        getchar();
        Option_Process(option, i, j);
    }
    /*for(j=0;j<i;j++)
        sum += o[j].TotalOrderValue;
    printf("\nTotal Revenue: %.2f", sum);*/
    return 0;
}

int Option_Process(int option, int i, int j)
{
    int receiptNum = 0; // totalAmountMeal = 0, totalAmountBurger = 0, totalAmountChips = 0, totalAmountDrinks = 0;
    float totalFull = 0;//float totalFullMeal = 0, totalFullBurger = 0, totalFullChips = 0, totalFullDrinks = 0, totalFull = 0;
    char passwordInput[12];
    char burgertype, mealtype, chipstype, drinkstype;
    switch (option)
    {
        case 1:
            printf("\nSelect the Meal Type\nA - Big Chicken Meal - 20$\nB - Big Ham Meal - 22$\nC - Big Veggie Meal - 18$\nX - To return to Main Menu\n\nSelect your meal type \n");
            scanf(" %s", &mealtype);
            fflush(stdin);
            j++;
            OrderPriceMeal(mealtype, i, j);
            o[i].Meal[25].Total = TotalPriceMeal(i);
            o[i].Meal[25].Amount = TotalAmountMeal(i);
            Continues(o[i].Meal[25].Total, i, j);
            break;
        case 2:
            printf("\nSelect the Burger Type\nA - Chicken Burger - 15$\nB - Ham Burger - 17$\nC - Veggie Burger - 13$\nX - To return to Main Menu\n\nSelect your burger type \n");
            scanf(" %s", &burgertype);
            fflush(stdin);
            j++;
            OrderPriceBurger(burgertype, i, j);
            o[i].Burger[25].Total = TotalPriceBurger(i);
            o[i].Burger[25].Amount = TotalAmountBurger(i);
            Continues(o[i].Burger[25].Total, i, j);
            break;
        case 3:
            printf("\nSelect the Chips Type\nM - Medium Chips - 5$\nB - Large Chips - 7$\nX - To return to Main Menu\n\nSelect your chips type \n");
            scanf(" %s", &chipstype);
            fflush(stdin);
            j++;
            OrderPriceChips(chipstype, i, j);
            o[i].Chips[25].Total = TotalPriceChips(i);
            o[i].Chips[25].Amount = TotalAmountChips(i);
            Continues(o[i].Chips[25].Total, i, j);
            break;
        case 4:
            printf("\nSelect the Chips Type\nM - Medium Drinks - 3.5$\nB - Large Drinks - 5$\nX - To return to Main Menu\n\nSelect your chips type \n");
            scanf(" %s", &drinkstype);
            fflush(stdin);
            j++;
            OrderPriceDrinks(drinkstype, i, j);
            o[i].Drinks[25].Total = TotalPriceDrinks(i);
            o[i].Drinks[25].Amount = TotalAmountDrinks(i);
            Continues(o[i].Drinks[25].Total, i, j);
            break;
        case 5:
            totalFull = o[i].Meal[25].Total + o[i].Burger[25].Total + o[i].Chips[25].Total + o[i].Drinks[25].Total;
            o[i].TotalOrderValue = Discount(o[i].Burger[25].Amount,totalFull);
            o[i].ReceiptNo = i;
            ReceiptCheck(1, i, j);
            break;
        case 6:
            printf("Please enter your receipt number:\nB00");
            scanf("%d", &receiptNum);
            fflush(stdin);
            o[receiptNum-1] = Cancel(receiptNum, i);
            break;
        case 7:
            //MainMenu(i, 7, j);
            exit(0);
            break;
        case 9:
            //char passwordInput[12];
            printf("Enter the password: \n");
            scanf(" %s", &passwordInput);
            fflush(stdin);
            if (strcmp(passwordInput,"TastyBurger") == 0)
            {
                printf("Total Revenue: %.2f", CalculateRevenue(25));
            }
            else
            {
                printf("Incorrect password.");
            }
            break;
        default:
            printf("\nPlease enter a valid option.");
            break;
    }
    return 0;
}


int OrderPriceMeal(char mealtype, int i, int j)
{
    float totalFull = 0;
    int Aprice = 20, Bprice = 22, Cprice = 18;
            switch (toupper(mealtype))
                {
                    case'X':
                        MainMenu(i, 1, j);
                        break;
                    case 'A':
                        printf("You have selected Chicken Meal. How many meals you wish you order?\n");
                        scanf("%d", &o[i].Meal[j].Amount);
                        fflush(stdin);
                        o[i].Meal[j].Total = o[i].Meal[j].Amount * Aprice;
                        break;
                    case 'B':
                        printf("You have selected Ham Meal. How many meals you wish you order?\n");
                        scanf("%d", &o[i].Meal[j].Amount);
                        fflush(stdin);
                        o[i].Meal[j].Total = o[i].Meal[j].Amount * Bprice;
                        break;
                    case 'C':
                        printf("You have selected Veggie Meal. How many meals you wish you order?\n");
                        scanf("%d", &o[i].Meal[j].Amount);
                        fflush(stdin);
                        o[i].Meal[j].Total = o[i].Meal[j].Amount * Cprice;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}

int OrderPriceBurger(char burgertype, int i, int j)
{
    float totalFull = 0;
    int Aprice = 15, Bprice = 17, Cprice = 13;
            switch (toupper(burgertype))
                {
                    case'X':
                        MainMenu(i, 1, j);
                        break;
                    case 'A':
                        printf("You have selected Chicken Burger. How many burgers you wish you order?\n");
                        scanf("%d", &o[i].Burger[j].Amount);
                        fflush(stdin);
                        o[i].Burger[j].Total = o[i].Burger[j].Amount * Aprice;
                        o[i].Burger[j].BurgerType = Chicken;
                        break;
                    case 'B':
                        printf("You have selected Ham Burger. How many burgers you wish you order?\n");
                        scanf("%d", &o[i].Burger[j].Amount);
                        fflush(stdin);
                        o[i].Burger[j].Total = o[i].Burger[j].Amount * Bprice;
                        o[i].Burger[j].BurgerType = Ham;
                        break;
                    case 'C':
                        printf("You have selected Veggie Burger. How many burgers you wish you order?\n");
                        scanf("%d", &o[i].Burger[j].Amount);
                        fflush(stdin);
                        o[i].Burger[j].Total = o[i].Burger[j].Amount * Cprice;
                        o[i].Burger[j].BurgerType = Veggie;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}

int OrderPriceChips(char chipstype, int i, int j)
{
    float totalFull = 0;
    int Mprice = 5, Lprice = 7;
            switch (toupper(chipstype))
                {
                    case'X':
                        MainMenu(i, 1, j);
                        break;
                    case 'M':
                        printf("You have selected Medium Chips. How many portions do you wish you order?\n");
                        scanf("%d", &o[i].Chips[j].Amount);
                        fflush(stdin);
                        o[i].Chips[j].Total = o[i].Chips[j].Amount * Mprice;
                        o[i].Chips[j].ChipsSize = Medium;
                        break;
                    case 'L':
                        printf("You have selected Large Chips. How many portions do you wish you order?\n");
                        scanf("%d", &o[i].Chips[j].Amount);
                        fflush(stdin);
                        o[i].Chips[j].Total = o[i].Chips[j].Amount * Lprice;
                        o[i].Chips[j].ChipsSize = Large;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}

int OrderPriceDrinks(char drinkstype, int i, int j)
{
    float totalFull = 0, Mprice = 3.5;
    int Lprice = 5;
            switch (toupper(drinkstype))
                {
                    case'X':
                        MainMenu(i, 1, j);
                        break;
                    case 'M':
                        printf("You have selected Medium Chips. How many portions do you wish you order?\n");
                        scanf("%d", &o[i].Drinks[j].Amount);
                        fflush(stdin);
                        o[i].Drinks[j].Total = o[i].Drinks[j].Amount * Mprice;
                        o[i].Drinks[j].DrinkSize = Med;
                        break;
                    case 'L':
                        printf("You have selected Large Chips. How many portions do you wish you order?\n");
                        scanf("%d", &o[i].Drinks[j].Amount);
                        fflush(stdin);
                        o[i].Drinks[j].Total = o[i].Drinks[j].Amount * Lprice;
                        o[i].Drinks[j].DrinkSize = Lg;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}

int Continues(float total, int i, int j)
{
    char continueOption;
    printf("\nYour current bill value is %.2f", total);
    printf("\nPress Y to add more into your order or Press X to back to previous menu. \n");
    scanf(" %s", &continueOption);
    fflush(stdin);
    switch(toupper(continueOption))
    {
        case 'Y':
            Option_Process(1, i, j);
            break;
        case'X':
            MainMenu(i, 1, j);
            break;
        default:
            printf("Please enter a valid option.");
            break;
    }
}

float TotalPriceMeal(int i)
{
    int j; 
    float Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += o[i].Meal[j].Total;
    }
    return Total_Price;
}

float TotalPriceBurger(int i)
{
    int j; 
    float Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += o[i].Burger[j].Total;
    }
    return Total_Price;
}

float TotalPriceChips(int i)
{
    int j;
    float Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += o[i].Chips[j].Total;
    }
    return Total_Price;
}

float TotalPriceDrinks(int i)
{
    int j; 
    float Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += o[i].Drinks[j].Total;
    }
    return Total_Price;
}

int TotalAmountMeal(int i)
{
    int j, Total_Amount = 0;
    for (j=0;j<25;j++)
    {
        Total_Amount += o[i].Meal[j].Amount;
    }
    return Total_Amount;
}

int TotalAmountBurger(int i)
{
    int j, Total_Amount = 0;
    for (j=0;j<25;j++)
    {
        Total_Amount += o[i].Burger[j].Amount;
    }
    return Total_Amount;
}

int TotalAmountChips(int i)
{
    int j, Total_Amount = 0;
    for (j=0;j<25;j++)
    {
        Total_Amount += o[i].Chips[j].Amount;
    }
    return Total_Amount;
}

int TotalAmountDrinks(int i)
{
    int j, Total_Amount = 0;
    for (j=0;j<25;j++)
    {
        Total_Amount += o[i].Drinks[j].Amount;
    }
    return Total_Amount;
}

float Discount(int amount, float totalFull)
{   
    float discountBurger = 0.1, total = 0, discountOver100 = 0.15;
    while(1)
    {
        if (totalFull>100)
    {
        total = totalFull*(1-discountOver100);
        printf("\nYour total bill value is $%.2f", totalFull);
        printf("\nDiscount 15%% - $%.2f", totalFull*discountOver100);
        printf("\nFinal bill values is $%.2f", total);
        return total;
        break;
    }
    else if (amount>=5)
    {
        total = totalFull*(1-discountBurger);
        printf("\nYour total bill value is $%.2f", totalFull);
        printf("\nDiscount 10%% - $%.2f", totalFull*discountBurger);
        printf("\nFinal bill values is $%.2f", total);
        return total;
        break;
    }
    else 
    {
        printf("\nYour total bill value is $%.2f", totalFull);
        return totalFull;
        break;
    }
    }
}

struct Order Cancel(int receiptNum, int receiptTotal)
{
    if (receiptNum<=receiptTotal)
    {
        int j;
        o[receiptNum-1].TotalOrderValue = 0;
        for (j=0;j<25;j++)
        {
            o[receiptNum-1].Burger[j].Amount = 0;
            o[receiptNum-1].Burger[j].Total = 0;
            o[receiptNum-1].Meal[j].Amount = 0;
            o[receiptNum-1].Meal[j].Total = 0;
            o[receiptNum-1].Chips[j].Amount = 0;
            o[receiptNum-1].Chips[j].Total = 0;
            o[receiptNum-1].Drinks[j].Amount = 0;
            o[receiptNum-1].Drinks[j].Total = 0;
        }
        printf("\nYour order has been cancelled. Thank you.");
    }
    else
    {
        printf("Incorrect Receipt Number");
    }
    return o[receiptNum-1];
}

int ReceiptCheck(int option, int i, int j)
{
    if (!(option == 6 || option == 7))
    {
    printf("\nYour receipt number is B00%d", i+1);
    printf("\nPlease go to a register and make the payment by quoting the Receipt Number - B00%d", i+1);
    printf("\n\n<< Press Any Key to show the main menu>>");
    i++;
    }
    j = 0;
    MainMenu(i, option, j);
}
/*
CalculateRevenue()
{
    int i;
    float sum = 0;
    char passwordInput[12];
    printf("Enter the password: \n");
    scanf(" %s", &passwordInput);
    fflush(stdin);
    if (strcmp(passwordInput,"TastyBurger") == 0)
    {
        for (i=0;i<25;i++)
        {
            sum += o[i].TotalOrderValue;
        }
        printf("Total Revenue: $%.2f", sum);
    }
    else
    {
        printf("Invalid Password");
        printf("\n<< Press Any Key to show the main menu>>\n");
    }
}
*/

float y = 0;
float CalculateRevenue(int n)
{
    if (n <= 0)
    {
        return y;
    }
    else
    {
        y = o[n-1].TotalOrderValue + CalculateRevenue(n-1);
        return y;
    }
}








