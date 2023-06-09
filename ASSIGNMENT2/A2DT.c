#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Functions Prototypes
int MainMenu(int, int, int);
int Option_Process(int, int, int);
int OrderPriceMeal(char, int, int);
int OrderPriceBurger(char, int, int);
int OrderPriceChips(char, int, int);
int OrderPriceDrinks(char, int, int);
int Continues(float, int, int, int);
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
int PrintReceipt(int, int, int);
float CalculateRevenue(int);

//Implementing Enumeration
typedef enum MealTypes {Chicken_Meal = 1, Ham_Meal, Veggie_Meal} MealTypes;
typedef enum BurgerTypes {Chicken = 1, Ham , Veggie } BurgerTypes;
typedef enum ChipsSize {Medium = 1, Large } ChipsSize;
typedef enum DrinkSize {Med = 1, Lg } DrinkSize;

//Declaring structures and elements inside them
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
    enum MealTypes MealType;
    Burger *Burger; //Pointer to Burger Structure
    Chips *Chips; //Pointer to Chips Structure
    Drinks *Drinks; //Pointer to Drinks Structure
}Meal;

typedef struct Order
{
    int ReceiptNo;
    float TotalOrderValue;
    Burger *Burger; //Pointer to Burger Structure
    Meal *Meal; //Pointer to Meal Structure
    Chips *Chips; //Pointer to Chips Structure
    Drinks *Drinks; //Pointer to Drinks Structure
}Order;
//Pointer for structure "Order"  variable
Order* o;


int main()
{   
//Dynamic Memory Allocation with Calloc
    system("cls");
    int x =0;
    o = (Order*)calloc(25,sizeof(Order));
    for (x=0; x<25; x++)
        o[x].Meal = (Meal*)calloc(26,sizeof(Meal));
    for (x=0; x<25; x++)
        o[x].Burger = (Burger*)calloc(26,sizeof(Burger));
    for (x=0; x<25; x++)
        o[x].Chips = (Chips*)calloc(26,sizeof(Chips));
    for (x=0; x<25; x++)
        o[x].Drinks = (Drinks*)calloc(26,sizeof(Drinks));
    int i = 0;
    int option, j = 0;
    MainMenu(i, option, j);
}
//MainMenu Function
int MainMenu(int i, int option, int j)
{   
    float sum = 0;
    while (!(option == 7 || i >= 25))
    { 
        //Getting MainMenu User Input
        printf("\n\n\n\nWelcome to Tasty Burgers\nPlace your order here...\n1.    Order Meals\n2.    Order Burgers\n3.    Order Chips\n4.    Order Cold Drinks\n5.    Process Order\n6.    Cancel\n7.    Exit\n\nSelect your option:\n");
        scanf("%d", &option);
        getchar();
        //Send Option, i and j parameters to Option_Process function
        Option_Process(option, i, j);
    }
    return 0;
}
//Function to process the options
int Option_Process(int option, int i, int j)
{
    //Declare variables
    int receiptNum = 0;
    float totalFull = 0;
    char burgertype, mealtype,chipstype, drinkstype;
    char passwordInput[12];
    //Switch function to process all the options
    switch (option)
    {
        //Meal Case
        case 1:
            printf("\nSelect the Meal Type\nA - Big Chicken Meal - 20$\nB - Big Ham Meal - 22$\nC - Big Veggie Meal - 18$\nX - To return to Main Menu\n\nSelect your meal type \n");
            scanf(" %s", &mealtype);
            fflush(stdin);
            //j get incremented by one everytime this case runs
            j++;
            //Send mealtype, i and j parameters to calculate meal price
            OrderPriceMeal(mealtype, i, j); 
            //Send i parameter to function that calculate total meal price and return it to structure member "Total"
            (o[i].Meal+25)->Total= TotalPriceMeal(i);
            //Send i parameter to function that calculate total meal amount and return it to structure member "Amount"
            (o[i].Meal+25)->Amount = TotalAmountMeal(i);
            //Send total meal price from structure, i, j and option as parameters to function that ask user whether to continue or not
            Continues((o[i].Meal+25)->Total, i, j, option);
            break;
        //Burger Case: Follow the same logic as Meal Case
        case 2:
            printf("\nSelect the Burger Type\nA - Chicken Burger - 15$\nB - Ham Burger - 17$\nC - Veggie Burger - 13$\nX - To return to Main Menu\n\nSelect your burger type \n");
            scanf(" %s", &burgertype);
            fflush(stdin);
            j++;
            OrderPriceBurger(burgertype, i, j);
            (o[i].Burger+25)->Total = TotalPriceBurger(i);
            (o[i].Burger+25)->Amount = TotalAmountBurger(i);
            Continues((o[i].Burger+25)->Total, i, j, option);
            break;
        //Chips Case: Follow the same logic as Meal Case
        case 3:
            printf("\nSelect the Chips Type\nM - Medium Chips - 5$\nB - Large Chips - 7$\nX - To return to Main Menu\n\nSelect your chips type \n");
            scanf(" %s", &chipstype);
            fflush(stdin);
            j++;
            OrderPriceChips(chipstype, i, j);
            (o[i].Chips+25)->Total = TotalPriceChips(i);
            (o[i].Chips+25)->Amount = TotalAmountChips(i);
            Continues((o[i].Chips+25)->Total, i, j, option);
            break;
        //Drinks Case: Follow the same logic as Meal Case
        case 4:
            printf("\nSelect the Drinks Type\nM - Medium Drinks - 3.5$\nB - Large Drinks - 5$\nX - To return to Main Menu\n\nSelect your Drinks type \n");
            scanf(" %s", &drinkstype);
            fflush(stdin);
            j++;
            OrderPriceDrinks(drinkstype, i, j);
            (o[i].Drinks+25)->Total = TotalPriceDrinks(i);
            (o[i].Drinks+25)->Amount = TotalAmountDrinks(i);
            Continues((o[i].Drinks+25)->Total, i, j, option);
            break;
        //Process Order Case
        case 5:
            //Calculate full total price of the order
            totalFull = (o[i].Meal+25)->Total + (o[i].Burger+25)->Total + (o[i].Chips+25)->Total + (o[i].Drinks+25)->Total;
            //Send total burger amount and full total price of the order as parameters to function to check for discount
            o[i].TotalOrderValue = Discount((o[i].Burger+25)->Amount,totalFull);
            //Assign Receipt Number value 
            o[i].ReceiptNo = i;
            //Passing 1, i and j as parameters to function that print the receipt
            PrintReceipt(1, i, j);
            break;
        //Cancel Order Case
        case 6:
            //Getting Cancel Order Input from User
            printf("Please enter your receipt number:\nB00");
            scanf("%d", &receiptNum);
            fflush(stdin);
            //Send Cancel Order Input number and i as parameters to function to cancel order and return value to structure
            *(o+receiptNum-1) = Cancel(receiptNum, i);
            break;
        //Close program
        case 7:
            exit(0);
            break;
        //Secret case to calculate total revenue
        case 9:
            printf("Enter the password: \n");
            scanf(" %s", &passwordInput);
            fflush(stdin);
            if (strcmp(passwordInput,"TastyBurger") == 0)
            {
                printf("Total Revenue: %.2f", CalculateRevenue(0));
                printf("\n\n<< Press Any Key to show the main menu>>\n");
                getchar();
            }
            else
            {
                printf("Incorrect password.");
                printf("\n\n<< Press Any Key to show the main menu>>\n");
                getchar();
            }
            break;
        //Use for any invalid inputs
        default:
            printf("\nPlease enter a valid option.");
            break;
    }
    return 0;
}

//Function for calculating price, amount and inputing types for each meal option
int OrderPriceMeal(char mealtype, int i, int j)
{
    //Declare variable for each option price
    int Aprice = 20, Bprice = 22, Cprice = 18;
            //Switch statement for calculating price, amount and inputing types for each meal option
            switch (toupper(mealtype))
                {
                    //Going back to mainmenu case
                    case'X':
                        MainMenu(i, 1, j);
                        break;
                    //Chicken Meal Case
                    case 'A':
                        //User input for amount of meal they order
                        printf("You have selected Chicken Meal. How many meals you wish you order?\n");
                        scanf("%d", &(o[i].Meal+j)->Amount);
                        fflush(stdin);
                        //Calculating Price for the meal amount
                        (o[i].Meal+j)->Total = (o[i].Meal+j)->Amount * Aprice;
                        //Assigning meal type with enumeration
                        (o[i].Meal+j)->MealType = Chicken_Meal;
                        break;
                    //Ham Meal Case
                    case 'B':
                        //User input for amount of meal they order
                        printf("You have selected Ham Meal. How many meals you wish you order?\n");
                        scanf("%d", &(o[i].Meal+j)->Amount);
                        fflush(stdin);
                        //Calculating Price for the meal amount
                        (o[i].Meal+j)->Total = (o[i].Meal+j)->Amount * Bprice;
                        //Assigning meal type with enumeration
                        (o[i].Meal+j)->MealType = Ham_Meal;
                        break;
                    case 'C':
                        //User input for amount of meal they order
                        printf("You have selected Veggie Meal. How many meals you wish you order?\n");
                        scanf("%d", &(o[i].Meal+j)->Amount);
                        fflush(stdin);
                        //Calculating Price for the meal amount
                        (o[i].Meal+j)->Total = (o[i].Meal+j)->Amount * Cprice;
                        //Assigning meal type with enumeration
                        (o[i].Meal+j)->MealType = Veggie_Meal;
                        break;
                    //Use for any invalid inputs
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}
//Function create with same logic as "OrderPriceMeal" function
int OrderPriceBurger(char burgertype, int i, int j)
{
    int Aprice = 15, Bprice = 17, Cprice = 13;
            switch (toupper(burgertype))
                {
                    case'X':
                        MainMenu(i, 1, j);
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
                        (o[i].Burger+j)->Total = (o[i].Burger+j)->Amount * Bprice;
                        (o[i].Burger+j)->BurgerType = Veggie;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}
//Function create with same logic as "OrderPriceMeal" function
int OrderPriceChips(char chipstype, int i, int j)
{
    int Mprice = 5, Lprice = 7;
            switch (toupper(chipstype))
                {
                    case'X':
                        MainMenu(i, 1, j);
                        break;
                    case 'M':
                        printf("You have selected Medium Chips. How many portions do you wish you order?\n");
                        scanf("%d", &(o[i].Chips+j)->Amount);
                        fflush(stdin);
                        (o[i].Chips+j)->Total = (o[i].Chips+j)->Amount * Mprice;
                        (o[i].Chips+j)->ChipsSize = Medium;
                        break;
                    case 'L':
                        printf("You have selected Large Chips. How many portions do you wish you order?\n");
                        scanf("%d", &(o[i].Chips+j)->Amount);
                        fflush(stdin);
                        (o[i].Chips+j)->Total = (o[i].Chips+j)->Amount * Lprice;
                        (o[i].Chips+j)->ChipsSize = Large;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}
//Function create with same logic as "OrderPriceMeal" function
int OrderPriceDrinks(char drinkstype, int i, int j)
{
    float Mprice = 3.5;
    int Lprice = 5;
            switch (toupper(drinkstype))
                {
                    case'X':
                        MainMenu(i, 1, j);
                        break;
                    case 'M':
                        printf("You have selected Medium Drinks. How many portions do you wish you order?\n");
                        scanf("%d", &(o[i].Drinks+j)->Amount);
                        fflush(stdin);
                        (o[i].Drinks+j)->Total = (o[i].Drinks+j)->Amount * Mprice;
                        (o[i].Drinks+j)->DrinkSize = Med;
                        break;
                    case 'L':
                        printf("You have selected Large Drinks. How many portions do you wish you order?\n");
                        scanf("%d", &(o[i].Drinks+j)->Amount);
                        fflush(stdin);
                        (o[i].Drinks+j)->Total = (o[i].Drinks+j)->Amount * Lprice;
                        (o[i].Drinks+j)->DrinkSize = Lg;
                        break;
                    default:
                        printf("Please enter a valid option.");
                        break;
                }
}
//Function to ask for User Input if they want to continue or go back to MainMenu
int Continues(float total, int i, int j, int option)
{
    char continueOption;
    printf("\nYour current bill value is %.2f", total);
    printf("\nPress Y to add more into your order or Press X to back to previous menu. \n");
    scanf(" %s", &continueOption);
    //Getting User Input whether to continue or not
    fflush(stdin);
    //Switch statement to process User Input
    switch(toupper(continueOption))
    {
        //Continue Case
        case 'Y':
            Option_Process(option, i, j);
            break;
        //Mainmenu Case
        case'X':
            MainMenu(i, 1, j);
            break;
        //Use for any invalid inputs
        default:
            printf("Please enter a valid option.");
            break;
    }
}
//Function to calculate Total Meal Price
float TotalPriceMeal(int i)
{
    //Declare variables
    int j; 
    float Total_Price = 0;
    //Loops to calculate Total Meal Price
    for (j=0;j<25;j++)
    {
        Total_Price += (o[i].Meal+j)->Total;
    }
    //Return Total Price value 
    return Total_Price;
}
//Function to calculate Total Burger Price with the same logic as "Total Meal Price" function
float TotalPriceBurger(int i)
{
    int j; 
    float Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += (o[i].Burger+j)->Total;
    }
    return Total_Price;
}
//Function to calculate Total Chips Price with the same logic as "Total Meal Price" function
float TotalPriceChips(int i)
{
    int j;
    float Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += (o[i].Chips+j)->Total;
    }
    return Total_Price;
}
//Function to calculate Total Drinks Price with the same logic as "Total Meal Price" function
float TotalPriceDrinks(int i)
{
    int j; 
    float Total_Price = 0;
    for (j=0;j<25;j++)
    {
        Total_Price += (o[i].Drinks+j)->Total;
    }
    return Total_Price;
}
//Function to calculate Total Meal Amount
int TotalAmountMeal(int i)
{
    //Declare variables
    int j, Total_Amount = 0;
    //Loops to calculate Total Meal Amount
    for (j=0;j<25;j++)
    {
        Total_Amount += (o[i].Meal+j)->Amount;
    }
    //Return Total Meal Amount value
    return Total_Amount;
}
//Function to calculate Total Burger Amount with the same logic as "Total Meal Amount" function
int TotalAmountBurger(int i)
{
    int j, Total_Amount = 0;
    for (j=0;j<25;j++)
    {
        Total_Amount += (o[i].Burger+j)->Amount;
    }
    return Total_Amount;
}
//Function to calculate Total Chips Amount with the same logic as "Total Meal Amount" function
int TotalAmountChips(int i)
{
    int j, Total_Amount = 0;
    for (j=0;j<25;j++)
    {
        Total_Amount += (o[i].Chips+j)->Amount;
    }
    return Total_Amount;
}
//Function to calculate Total Drinks Amount with the same logic as "Total Meal Amount" function
int TotalAmountDrinks(int i)
{
    int j, Total_Amount = 0;
    for (j=0;j<25;j++)
    {
        Total_Amount += (o[i].Drinks+j)->Amount;
    }
    return Total_Amount;
}
//Function to find eligibility for discount
float Discount(int amount, float totalFull)
{   
    //Declare variables
    float discountBurger = 0.1, total = 0, discountOver100 = 0.15;
    //Infinite loop
    while(1)
    {
    //If statement for discount for order over 100$
        if (totalFull>100)
    {
        total = totalFull*(1-discountOver100);
        printf("\nYour total bill value is $%.2f", totalFull);
        printf("\nDiscount 15%% - $%.2f", totalFull*discountOver100);
        printf("\nFinal bill values is $%.2f", total);
        return total;
        break;
    }
    //Else if statement for discount for 5 burger ordered or more
    else if (amount>=5)
    {
        total = totalFull*(1-discountBurger);
        printf("\nYour total bill value is $%.2f", totalFull);
        printf("\nDiscount 10%% - $%.2f", totalFull*discountBurger);
        printf("\nFinal bill values is $%.2f", total);
        return total;
        break;
    }
    //Else print bill
    else 
    {
        printf("\nYour total bill value is $%.2f", totalFull);
        return totalFull;
        break;
    }
    }
}
//Function for canceling order
struct Order Cancel(int receiptNum, int receiptTotal)
{
    //If statement use to see if the receipt number is less than current total receipt number and if so cancel the order
    if (receiptNum<=receiptTotal)
    {
        int j;
        o[receiptNum-1].TotalOrderValue = 0;
        for (j=0;j<25;j++)
        {
            (o[receiptNum-1].Burger+j)->Amount = 0;
            (o[receiptNum-1].Burger+j)->Total = 0;
            (o[receiptNum-1].Burger+j)->BurgerType = 0;
            (o[receiptNum-1].Meal+j)->Amount = 0;
            (o[receiptNum-1].Meal+j)->Total = 0;
            (o[receiptNum-1].Meal+j)->MealType = 0;
            (o[receiptNum-1].Chips+j)->Amount = 0;
            (o[receiptNum-1].Chips+j)->Total = 0;
            (o[receiptNum-1].Chips+j)->ChipsSize = 0;
            (o[receiptNum-1].Drinks+j)->Amount = 0;
            (o[receiptNum-1].Drinks+j)->Total = 0;
            (o[receiptNum-1].Drinks+j)->DrinkSize = 0;
        }
        printf("\nYour order has been cancelled. Thank you.");
    }
    //Else output incorrect receipt number
    else
    {
        printf("Incorrect Receipt Number");
    }
    return *(o+receiptNum-1);
}
//Function for printing receipt number
int PrintReceipt(int option, int i, int j)
{
    printf("\nYour receipt number is B00%d", i+1);
    printf("\nPlease go to a register and make the payment by quoting the Receipt Number - B00%d", i+1);
    printf("\n\n<< Press Any Key to show the main menu>>");
    getchar();
    //Increment i by 1
    i++;
    //Resetting j to 0
    j = 0;
    //Call to MainMenu function
    MainMenu(i, option, j);
}

float y = 0;
float CalculateRevenue(int n)
{
    if (n > 25)
    {
        y = 0;
        return y;
    }
    else
    {
        y = (o+n)->TotalOrderValue + CalculateRevenue(n+1);
        return y;
    }
}

//Function to calculate revenue
/*CalculateRevenue()
{
    //Declare variables
    int i;
    float sum = 0;
    char passwordInput[12];
    //Getting User Input for password
    printf("Enter the password: \n");
    scanf(" %s", &passwordInput);
    fflush(stdin);
    //If statement to check if the password is correct
    if (strcmp(passwordInput,"TastyBurger") == 0)
    {
        //loops to calculate total revenue
        for (i=0;i<25;i++)
        {
            sum += (o+i)->TotalOrderValue;
        }
        printf("Total Revenue: $%.2f", sum);
        printf("\n\n<< Press Any Key to show the main menu>>\n");
        getchar();
    }
    else
    {
        printf("Invalid Password");
        printf("\n\n<< Press Any Key to show the main menu>>\n");
        getchar();
    }
}
*/








