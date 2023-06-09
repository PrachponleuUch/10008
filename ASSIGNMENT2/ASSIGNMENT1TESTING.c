#include <stdio.h>
#include <math.h>
int main(){
//Declare variables
int TicketLimitA = 30, TicketLimitB = 60, TicketLimitC = 90, 
FullTicketA = 15, FullTicketB = 10, FullTicketC = 5,
ConTicketA = 10, ConTicketB = 5, ConTicketC = 3,
FreeTicket, Option, Full, Con, TotalTicketPrice;
//Loop to run ticket system
do{
// Print Options and Read Input 
printf("\n1 - Class A\n2 - Class B\n3 - Class C\n4 - Current Availability\n5 - Exit\nEnter your option...\n");
scanf("%d", &Option);
getchar(); 
// Avoid character input error
switch (Option){
// Switch Condition for each Option
    case 1:
//Ask for amount and type of tickets and Read Inputs
        printf("How many full ticket...\n");
        scanf("%d", &Full);
        printf("How many concession tickets - Senior and Children under 12 and above 3...\n");
        scanf("%d", &Con);
        printf("How many kids under 3 years...\n");
        scanf("%d", &FreeTicket);
//If statement to display ticket availability if asking amount is more than ticket currently available
        if ((Full+Con+FreeTicket)>TicketLimitA){
            printf("\n\n\nLess tickets available than required...\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n\n\n", TicketLimitA, TicketLimitB, TicketLimitC);
            break;
        }
//If statement to ensure that the input is positive, Else calculate, display total price and calculate remaining tickets
        if ((Full<0) || (Con<0) || (FreeTicket<0)){
            printf("\nPlease enter a positive number\n");
            break;
        }else{
        TotalTicketPrice = (Full*FullTicketA) + (Con*ConTicketA) + (FreeTicket*0);
        TicketLimitA -= (Full+Con+FreeTicket);
        printf("You total ticket price = %d\n\n\n\n", TotalTicketPrice);
        };
        break;
    case 2:
//Repeat Case 1
        printf("How many full ticket...\n");
        scanf("%d", &Full);
        printf("How many concession tickets - Senior and Children under 12 and above 3...\n");
        scanf("%d", &Con);
        printf("How many kids under 3 years...\n");
        scanf("%d", &FreeTicket);
        if ((Full+Con+FreeTicket)>TicketLimitB){
            printf("\n\n\nLess tickets available than required...\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n\n\n", TicketLimitA, TicketLimitB, TicketLimitC);
            break;
        }
        if ((Full<0) || (Con<0) || (FreeTicket<0)){
            printf("\nPlease enter a positive number\n");
            break;
        }else{
        TotalTicketPrice = (Full*FullTicketB) + (Con*ConTicketB) + (FreeTicket*0);
        TicketLimitB -= (Full+Con+FreeTicket);
        printf("You total ticket price = %d\n\n\n\n", TotalTicketPrice);
        };
        break;
    case 3:
//Repeat Case 1
        printf("How many full ticket...\n");
        scanf("%d", &Full);
        printf("How many concession tickets - Senior and Children under 12 and above 3...\n");
        scanf("%d", &Con);
        printf("How many kids under 3 years...\n");
        scanf("%d", &FreeTicket);
        if ((Full+Con+FreeTicket)>TicketLimitC){
            printf("\n\n\nLess tickets available than required...\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n\n\n", TicketLimitA, TicketLimitB, TicketLimitC);
            break;
        }
        if ((Full<0) || (Con<0) || (FreeTicket<0)){
            printf("\nPlease enter a positive number\n");
            break;
        }else{
        TotalTicketPrice = (Full*FullTicketC) + (Con*ConTicketC) + (FreeTicket*0);
        TicketLimitC -= (Full+Con+FreeTicket);
        printf("You total ticket price = %d\n\n\n\n", TotalTicketPrice);
        };
        break;
    case 4:
//Display ticket availability
        printf("\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n\n\n", TicketLimitA, TicketLimitB, TicketLimitC);
        break;
    case 5:
//Display ticket availability and Exit out of loop
        printf("\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n\n\n", TicketLimitA, TicketLimitB, TicketLimitC);
        break;
    default:
//Display when enter invalid option
        printf("\nPlease enter a valid option\n");
    }
} while (Option != 5);
//Infinite Loop until case 5 is selected
return 0;
}