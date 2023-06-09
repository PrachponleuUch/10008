#include <stdio.h>
#include <math.h>
#include <time.h>
int main(){
//Declare variables
int TicketLimitA = 30, TicketLimitB = 60, TicketLimitC = 90, 
FullTicketA = 15, FullTicketB = 10, FullTicketC = 5,
ConTicketA = 10, ConTicketB = 5, ConTicketC = 3,
FreeTicket, Option, Full, Con, TotalTicketPrice, Leftover;
struct tm *local;
time_t t;
int hour;
t = time(NULL);
local = localtime(&t);
hour = local->tm_hour;
printf("%d", hour);
while ((hour>=9) && (hour<=17)){
// Loop to run ticket system
while (Option != 5){
// Print Options and Read Input 
printf("\n1 - Class A\n2 - Class B\n3 - Class C\n4 - Current Availability\n5 - Exit\nEnter your option...");
scanf("%d", &Option);
getchar(); 
// Avoid input error
switch (Option){
// Switch Condition foreach Option
    case 1:
//Ask for amount and type of tickets and Read Inputs
        printf("How many full ticket...");
        scanf("%d", &Full);
        printf("How many concession tickets - Senior and Children under 12 and above 3...");
        scanf("%d", &Con);
        printf("How many kids under 3 years...");
        scanf("%d", &FreeTicket);
//If statement to display ticket availability if asking amount is more than ticket availability
        if ((Full+Con+FreeTicket)>TicketLimitA){
            printf("\nLess tickets available than required...\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n", TicketLimitA, TicketLimitB, TicketLimitC);
            break;
        }
//If statement to ensure that the input is positive, , Else calculate and display total price
        if ((Full<0) || (Con<0) || (FreeTicket<0)){
            printf("Please enter a positive number");
            break;
        }else{
        TotalTicketPrice = (Full*FullTicketA) + (Con*ConTicketA) + (FreeTicket*0);
        printf("You total ticket price = %d\n", TotalTicketPrice);
        };
//Declare to verify for its ticket class
        Leftover = TicketLimitA;
        break;
    case 2:
//Repeat Case 1
        printf("How many full ticket...");
        scanf("%d", &Full);
        printf("How many concession tickets - Senior and Children under 12 and above 3...");
        scanf("%d", &Con);
        printf("How many kids under 3 years...");
        scanf("%d", &FreeTicket);
        if ((Full+Con+FreeTicket)>TicketLimitB){
            printf("\nLess tickets available than required...\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n", TicketLimitA, TicketLimitB, TicketLimitC);
            break;
        }
        if ((Full<0) || (Con<0) || (FreeTicket<0)){
            printf("Please enter a positive number");
            break;
        }else{
        TotalTicketPrice = (Full*FullTicketB) + (Con*ConTicketB) + (FreeTicket*0);
        printf("You total ticket price = %d\n", TotalTicketPrice);
        };
        Leftover = TicketLimitB;
        break;
    case 3:
//Repeat Case 1
        printf("How many full ticket...");
        scanf("%d", &Full);
        printf("How many concession tickets - Senior and Children under 12 and above 3...");
        scanf("%d", &Con);
        printf("How many kids under 3 years...");
        scanf("%d", &FreeTicket);
        if ((Full+Con+FreeTicket)>TicketLimitC){
            printf("\nLess tickets available than required...\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n", TicketLimitA, TicketLimitB, TicketLimitC);
            break;
        }
        if ((Full<0) || (Con<0) || (FreeTicket<0)){
            printf("Please enter a positive number");
            break;
        }else{
        TotalTicketPrice = (Full*FullTicketC) + (Con*ConTicketC) + (FreeTicket*0);
        printf("You total ticket price = %d\n", TotalTicketPrice);
        };
        Leftover = TicketLimitC;
        break;
    case 4:
//Display ticket availability
        printf("\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n", TicketLimitA, TicketLimitB, TicketLimitC);
        break;
    case 5:
//Display ticket availability and Exit out of loop
        printf("\nTotal available\nClass A is %d\nClass B is %d\nClass C is %d\n", TicketLimitA, TicketLimitB, TicketLimitC);
        break;
    default:
//Display when enter invalid option
        printf("\nPlease enter a valid option\n");
    }
if (Leftover == TicketLimitA){
    TicketLimitA -= (Full+Con+FreeTicket);
    }
else if (Leftover == TicketLimitB){
    TicketLimitB -= (Full+Con+FreeTicket);
    }
else if(Leftover == TicketLimitC){
    TicketLimitC -= (Full+Con+FreeTicket);
}
}
//Constraint Loop as so exit the loop if case 5 is selected
}
return 0;
}