// STAGE - B - COS10008 - ASSIGNMENT-2 TP1-2020

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef enum {Chicken=1, HumBurger, Veggie}Type;

typedef struct Burger {
	Type bType;
	int quantity;
	float Price;
}Burger;

typedef struct Order {
	int receiptNo;
	float totalPrice;
	int totalBurgerCount;
	int bCount;
	Burger *bP;
}Order;

int main()
{
	Order *oP=NULL;
	int choice, orderCount=0, delete, i, flag=0;
	char oType, oContinue;
	
	do
	{
		system("cls");
		printf("Welcome to Tasty Burgers \n");
		printf("Place your order here \n");
		printf("1. Order Burger \n");
		printf("2. Cancel Order \n");
		printf("3. Exit \n");
		printf("Select your option \n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:  
					oP = (Order *) realloc(oP, sizeof(Order) * (orderCount + 1));  //Allocate memory for the new Order
					if(oP == NULL)
					{
						printf("Error in allocating memory");
						return 0;
					}
					oP[orderCount].bP=NULL;				//The order being just created, set the Burger Pointer to NULL
					oP[orderCount].bCount=0;			// Assign Burger Count in this order to zero
					oP[orderCount].totalBurgerCount=0;	//Total number of burgers in this order
					oP[orderCount].totalPrice=0;		// Assign the Order TotalPrice to zero
					
					do
					{
						printf("		Select the Burger Type \n");
						printf("		A - Chicken Burger - $15 \n		B - HamBurger - $17\n		C - Veggie - $12\n");
						fflush(stdin);
						scanf("%c",&oType);
					
						oP[orderCount].bP = (Burger *) realloc(oP[orderCount].bP, sizeof(Burger)* (oP[orderCount].bCount + 1));   //Memory is allocated for the burger
					
						switch(oType)
						{
							case 'A' :  
									oP[orderCount].bP[oP[orderCount].bCount].bType=1;
									printf("You have selected Chicken Burger. How many burgers you wish you order? \n");
								    break;
									
							case 'B' :  
									oP[orderCount].bP[oP[orderCount].bCount].bType=2;
									printf("You have selected HamBurger. How many burgers you wish you order? \n");
									break;
									
							case 'C' :  
									oP[orderCount].bP[oP[orderCount].bCount].bType=3;
									printf("You have selected Veggie Burger. How many burgers you wish you order? \n");
									break;
						}			
						do
						{
							scanf("%d", &oP[orderCount].bP[oP[orderCount].bCount].quantity);
							if(oP[orderCount].bP[oP[orderCount].bCount].quantity<=0)
								printf("Quantity cannot be 0 or less \n Please enter a valid quantity \n");
						}while(oP[orderCount].bP[oP[orderCount].bCount].quantity<=0);
					
						switch(oP[orderCount].bP[oP[orderCount].bCount].bType)
						{
							case 1: oP[orderCount].bP[oP[orderCount].bCount].Price = oP[orderCount].bP[oP[orderCount].bCount].quantity * 15; break;
						
							case 2: oP[orderCount].bP[oP[orderCount].bCount].Price = oP[orderCount].bP[oP[orderCount].bCount].quantity * 17; break;
							
							case 3: oP[orderCount].bP[oP[orderCount].bCount].Price = oP[orderCount].bP[oP[orderCount].bCount].quantity * 13; break;
						}
						
						
						
						oP[orderCount].totalBurgerCount = oP[orderCount].totalBurgerCount + oP[orderCount].bP[oP[orderCount].bCount].quantity;
						oP[orderCount].totalPrice = oP[orderCount].totalPrice + oP[orderCount].bP[oP[orderCount].bCount].Price;    					//Add the burger price to the order total price
						
						printf("Your current bill value is $%.2f \n",oP[orderCount].bP[oP[orderCount].bCount].Price);
						
						oP[orderCount].bCount++;																								// Increment the burger count for the order

						
				
						printf("Press Y to add more burgers into your order or Press N to process your order now \n");
						fflush(stdin);
						scanf("%c", &oContinue);
					}while(oContinue=='Y');
					
					
					if(oP[orderCount].totalBurgerCount >= 5)
					{
						printf("Discount 10%%\t 	$%.2f \n", oP[orderCount].totalPrice * 0.1);
						oP[orderCount].totalPrice = oP[orderCount].totalPrice - oP[orderCount].totalPrice * 0.1;
						printf("Final Bill Value is \t $%.2f \n\n",oP[orderCount].totalPrice);
					}
					
					
					oP[orderCount].receiptNo = orderCount+1;  //Receipt No is stored
					
					printf("Your Receipt Number is B00%d \n",oP[orderCount].receiptNo);
					printf("Please go to a register and make the payment by quoting the Receipt Number B00%d\n\n\n",oP[orderCount].receiptNo);
					
					orderCount++;		//orderCount is incremented
					printf("Press any key to continue \n");
					getch();
					break;
			
			case 2:	flag=0;
					printf("Please enter your Receipt No B00");
					scanf("%d", &delete);
					
					for(i=0;i<orderCount;i++)
					{
						if(delete == oP[i].receiptNo){
							oP[i].receiptNo=0;	//By assigning 0 to the receiptNo, logically the order is cancelled
							flag=1;
						}
					}
					if(flag==0)
						printf("Sorry, invalid Receipt No... No orders deleted ...\n\n");
					else
						printf("Order deleted successfully ...\n\n");
					printf("Press any key to continue \n");
					getch();
					break;
			
					
		}
		
	}while(choice !=3);
	
	return 0;
}