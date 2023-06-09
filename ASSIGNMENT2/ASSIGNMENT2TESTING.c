#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct chips
{
    char desc[100]; // chips description
    int min_weight; 
}chips;
typedef struct drinks
{
    char desc[100];
    int min_quantity; 
}drinks;
typedef struct burgers
{
    char desc[100]; //burger description
}burgers;
typedef struct meals
{
    chips *ch; 
    drinks *dr;
    burgers *bg;
    int n; // number of meals purchased for this partiular type
}meals;
typedef struct order 
{   
    char receipt_number[1024];
    meals *m;
    chips *ch;
    drinks *dr;
    burgers *bg;
    int total_meals,total_chips,total_dr,total_bg;
}order;
void add_order(char v, order *od, int x) // add meals to the order
{
    meals *nm = (meals*)malloc(sizeof(meals));

    if(v== 'A') // Big Chiken meal
    {
        char temp[1024] = "Chicken Burger";
        int flag=1;
        for(int i=0;i<od->total_meals;i++)
        {
            if(strcmp(od->m[i].bg->desc,temp)==0)// if meal is alredy present in the order , update the quantity
            {
                od->m[i].n+=x;
                flag=0;break;
            }
        }
        if(flag==1) // add meal to the meals array in the order structure , for this the arrya size is to be increased
        {
            if(od->m==NULL)// if no meals have been added yet
            {
                od->m = (meals*)malloc(sizeof(meals)*(x));
                
                
                od->m[od->total_meals].bg = (burgers*)malloc(sizeof(burgers));
                od->m[od->total_meals].ch = (chips*)malloc(sizeof(chips)); 
                od->m[od->total_meals].dr = (drinks*)malloc(sizeof(drinks));
                od->m[od->total_meals].n = x;

                
                strcpy(od->m[od->total_meals].bg->desc,temp);
                od->total_meals++;
                return;
            }
            meals *tp = (meals*)malloc(sizeof(meals)*od->total_meals);
            memcpy(tp,od->m,sizeof(tp));
            od->m = (meals*)realloc(od->m,sizeof(meals)*(od->total_meals+1)); // dynamically reallocate memory to meals array

            memcpy(od->m,tp,sizeof(tp));

             
            od->m[od->total_meals].bg = (burgers*)malloc(sizeof(burgers));
            od->m[od->total_meals].ch = (chips*)malloc(sizeof(chips)); 
            od->m[od->total_meals].dr = (drinks*)malloc(sizeof(drinks));
            od->m[od->total_meals].n = x;

            char xc[1024] = "Chicken Burger";
            strcpy(od->m[od->total_meals].bg->desc,xc);
            od->total_meals++;
        }
    }
    else if(v=='B')// Big Ham meal
    {
        char temp[1024] = "Ham Burger";
        int flag=1;
        for(int i=0;i<od->total_meals;i++)
        {
            if(strcmp(od->m[i].bg->desc,temp)==0)// if meal is alredy present in the order , update the quantity
            {
                od->m[i].n+=x;
                flag=0;break;
            }
        }
        if(flag==1) // add meal to the meals array in the order structure , for this the arrya size is to be increased
        {
            if(od->m==NULL)// if no meals have been added yet
            {
                od->m = (meals*)malloc(sizeof(meals)*(x));

                
                od->m[od->total_meals].bg = (burgers*)malloc(sizeof(burgers));
                od->m[od->total_meals].ch = (chips*)malloc(sizeof(chips)); 
                od->m[od->total_meals].dr = (drinks*)malloc(sizeof(drinks));
                od->m[od->total_meals].n = x;

                strcpy(od->m[od->total_meals].bg->desc,temp);
                od->total_meals++;
                return;
            }
            meals *tp = (meals*)malloc(sizeof(meals)*od->total_meals);
            memcpy(tp,od->m,sizeof(tp));
            od->m = (meals*)realloc(od->m,sizeof(meals)*(od->total_meals+1));

            memcpy(od->m,tp,sizeof(tp));

            
            od->m[od->total_meals].bg = (burgers*)malloc(sizeof(burgers));
            od->m[od->total_meals].ch = (chips*)malloc(sizeof(chips)); 
            od->m[od->total_meals].dr = (drinks*)malloc(sizeof(drinks));
            od->m[od->total_meals].n = x;

            char xc[1024] = "Ham Burger";
            strcpy(od->m[od->total_meals].bg->desc,xc); // add the burger description to the new meal
            od->total_meals++;
        }
    }
    else // Big vegie meal
    {
        char temp[1024] = "Vegie Burger";
        int flag=1;
        for(int i=0;i<od->total_meals;i++)
        {
            if(strcmp(od->m[i].bg->desc,temp)==0)// if meal is alredy present in the order , update the quantity
            {
                od->m[i].n+=x;
                flag=0;break;
            }
        }
        if(flag==1) // add meal to the meals array in the order structure , for this the arrya size is to be increased
        {
            if(od->m==NULL)// if no meals have been added yet
            {
                od->m = (meals*)malloc(sizeof(meals)*(x));

                
                od->m[od->total_meals].bg = (burgers*)malloc(sizeof(burgers));
                od->m[od->total_meals].ch = (chips*)malloc(sizeof(chips)); 
                od->m[od->total_meals].dr = (drinks*)malloc(sizeof(drinks));
                od->m[od->total_meals].n = x;

                strcpy(od->m[od->total_meals].bg->desc,temp);
                od->total_meals++;
                return;
            }
            meals *tp = (meals*)malloc(sizeof(meals)*od->total_meals);
            memcpy(tp,od->m,sizeof(tp));
            od->m = (meals*)realloc(od->m,sizeof(meals)*(od->total_meals+1));

            memcpy(od->m,tp,sizeof(tp));

            
            od->m[od->total_meals].bg = (burgers*)malloc(sizeof(burgers));
            od->m[od->total_meals].ch = (chips*)malloc(sizeof(chips)); 
            od->m[od->total_meals].dr = (drinks*)malloc(sizeof(drinks));
            od->m[od->total_meals].n = x;

            char xc[1024] = "Vegie Burger";
            strcpy(od->m[od->total_meals].bg->desc,xc);
            od->total_meals++;
        }
    }
}
void add_drinks(order *od,double *total)// function to add drinks to the order
{
    int n=0;
    printf("You have selected drinks.How many drinks do you want to order\n");
    scanf("%d",&n);
    if(od->dr == NULL) // if no drinks have been added yet
    {
        od->dr == (drinks*)malloc(sizeof(drinks));
    }
    od->total_dr+=n;
    (*total)+=(3.5)*n;
    printf("your current bill value : %lf\n",*total);
}
void add_chips(order *od,double *total)// function to add chips to the order
{
    int n=0;
    printf("You have selected chips.How many chips do you want to order\n");
    scanf("%d",&n);
    if(od->ch == NULL)// if no chips have been added yet
    {
        od->ch = (chips*)malloc(sizeof(chips));
    }
    od->total_chips+=n;
    (*total)+=(5)*n;
    printf("your current bill value : %lf\n",*total);
}
void add_burgers(order *od,double *total)
{
    int n;
    printf("You have selected burger.How many burgers do you want to order\n");
    scanf("%d",&n);
    if(od->bg == NULL)// if function to add burgers to the order
    {
        od->bg = (burgers*)malloc(sizeof(burgers));
    }
    od->total_bg+=n;
    (*total)+=(n*11);
    printf("your current bill value : %lf\n",*total);
}
int order_meals(order *od,double *total)
{
    char c,f;

    do
    {
    printf("Select the meal type : \n");
    printf("A - Big Chicken Meal - 20$\n");
    printf("B - Big Ham Meal - 22$\n");
    printf("C - Big Vegie Meal - 18$\n");
    getchar();
    c = getchar();

    if(c=='A')
    {
        int x;
        printf("You have selected Big Chicken meal. How many meals do you want to order?\n");
        scanf("%d",&x);

        add_order('A',od,x); // add meal to the order
        (*total)+=(x*20);
    }
    else if(c=='B')
    {
        int x;
        printf("You have selected Big Ham meal. How many meals do you want to order?\n");
        scanf("%d",&x);

        add_order('B',od,x); // add meal to the order
        (*total)+=(x*22);
    }
    else if(c=='C')
    {
        int x;
        printf("You have selected Big Vegie meal. How many meals do you want to order?\n");
        scanf("%d",&x);
        
        add_order('C',od,x); // add meal to the order
        (*total)+=(x*18);
    }   
    printf("Press Y to add more meals to your order or press X go to the previous menu\n");
    getchar();
    f = getchar();
    printf("your current bill value : %lf\n",*total);
    }while(f!='X');
    
}
int calc_revenue(double *arr,int n,int i) // calculate total revenue recursively
{
    if(i==n)
    return 0;

    int x = arr[i] + calc_revenue(arr,n,i+1);

    return x;
}
double calculate_discount(order *od,double total)
{
    if(total>100) // first it is checked whether the order total is bigger than 100 or not
    {
        total = (double)0.85*total;
    }
    else if(od->total_bg>=5) // else if more than 5 burgers have been purchased or not.
    {
        total = (double)(0.9*total);
    }
    return total;
}   
int main()
{
    int ch,n;
    double total_revenue=0;
    char op[1024] = "TastyBurgers";
    printf("How many orders do you want to place\n");
    scanf("%d",&n);
    // printf("%d num\n",n);
    order arr[n];
    double val_arr[n];
    memset(val_arr,0,sizeof(val_arr));
    
    for(int i=0;i<n;i++)
    {
        double total=0;
        order *od = (order*)malloc(sizeof(order));
        od->bg=NULL;
        od->dr=NULL;
        od->ch=NULL;
        od->m=NULL;
        od->total_bg = 0;
        od->total_chips = 0;
        od->total_meals = 0;
        od->total_dr = 0;
        char xt[100] = "B00";
        char kk = '0'+i+1;
        strncat(xt,&kk,1);
        strcpy(od->receipt_number,xt);
        do
        {
            
            printf("Welcome to Tasty Burgers\n");
            printf("Place your order here.....\n");
            printf("Order Meals\n");
            printf("Order Burgers\n");
            printf("Order Chips\n");
            printf("Order Cold Drinks\n");
            printf("Process order\n");
            printf("Cancel\n");
            printf("Exit\n");
            printf("Select your option\n");
            scanf("%d",&ch);
            // printf("%d cht\n",ch);
            // getchar();
            if(ch == 1)
            {
                order_meals(od,&total);
            }
            else if(ch==2)
            {
                add_burgers(od,&total);
            }
            else if(ch==3)
            {
                add_chips(od,&total);
            }
            else if(ch==4)
            {
                add_drinks(od,&total);
            }
            else if(ch==5) // process order
            {
                printf("Your total bill value is : %lf\n",total);
                printf("Your receipt number is : %s\n",od->receipt_number);
            }
            else if(ch==6)
            {
                printf("Order Cancelled!\n");
                total = 0; // if the order is cancelled , the reinitialize total to 0
            }
            else if(ch==7)// exit
            {   break;}
            else if(ch==9)
            {
                printf("enter password\n");
                char pas[1024];
                getchar();
                fgets(pas,sizeof(pas),stdin);
                pas[strlen(pas)-1]=0;
                
                if(strcmp(pas,op)==0)
                {
                    val_arr[i] = calculate_discount(od,total);
                    total_revenue = calc_revenue(val_arr,n,0);
                    printf("Your total revenue : %lf\n",total_revenue);
                }
                else
                {
                    printf("Invalid password!\n");
                }
            }
            else
            {
                printf("invalid options selected , try again\n");

            }

        } while (1);
        arr[i]=*od;
        val_arr[i]=calculate_discount(od,total);
    }
    
}