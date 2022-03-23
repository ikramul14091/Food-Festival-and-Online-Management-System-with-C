#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

struct Node{

char foodname[30];
int data,stock;
float price;
struct Node *next;

};

typedef struct Node node;

node*head,*menu;


int credit_card[20];
float total_poisa[20];
char problem_box[20];

void print(char list[])
{
    printf("%s",list);
}

void line(int cnt)
{
    int i;
    for(i=1;i<=cnt;i++);
    printf("\n");
}

void tab (int cnt)
{
    int i;
    for (i=1;i<=cnt;i++);
    printf("\t");
}

void scr()
{
    system ("cls");
}

fooodlist()
{
    line(10); tab(20); print("1.  \"*Food Menu\"");line(2);Sleep(350);system("color 0F");
    line(10); tab(20); print("2.  \"*Admin Log In\"");line(2);Sleep(350);
    line(10); tab(20); print("3.  \"*Rules & Regulation\"");line(2);Sleep(350);
    line(10); tab(20); print("4.  \"*Problem & Suggestion\"");line(2);Sleep(350);
    line(10); tab(20); print("5.  \"*Exit\"");line(2);Sleep(350);
}

void insertfood (char foodname[30],int data,int stock,float price)
{
    node*temp;

    temp=(node*)malloc(sizeof(node));

    temp->data=data;

    temp->stock=stock;

    temp->price=price;

    strcpy(temp->foodname,foodname);

    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        menu=head;
    }
    else
    {
        while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=temp;
    }
}

void foodlist()
{
    node *start;

    start=menu;

    printf("------------------------------------------------------\n");system("color 0F");
    printf("   Item No. | Food Name & Code No  |  stock  |  price  \n ");

    while(start !=NULL)
    {

        printf("----------------------------------------------\n");

        line(30);tab (30);

        printf("%d   |   %s     |  %d     |  %.2f    \n",start->data, start->foodname,start->stock,start->price);Sleep(200);

        printf("--------------------------------------------\n");

        start=start->next;
    }
}

int count ()
{
    int cnt=0;

    node *temp;
    temp=menu;

    while(temp  !=NULL)
    {
        temp=temp->next;
        cnt++;
    }

    return cnt;
}

int total_money(int foodchoice , int much)
{
    scr();

    node *temp;

    temp=(node*)malloc (sizeof(node));

    temp=menu;

    while(temp->data !=foodchoice)
    {
        temp=temp->next;
    }

    if(temp->data==foodchoice)
    {
        int o;
        float total=temp->price*much;

        line(3);tab(2);print("Total Money for your order : ");line(2);system("color 0F");
        line(3);tab(2);printf(" %.2f",total);line(2);
        line(10);tab(20);print("Enter your Area Code : ");line(2);
        line(10);tab(70);scanf("%d",&o);line(2);

        return total;

    }

}

void payment (float money)
{
    scr();


    back_option:

        line(10);tab(20);printf("How you pay this money : "); line (2);system("color 0F");
        line(10);tab(70);printf("1.Cash"); line (2);
        line(10);tab(70);printf("2. Credit Card"); line (2);

       int choose;
       float taka;

       line(5);tab(3);scanf("%d",&choose); line (2);

        if(choose==1)
        {
          scr();

          give:
          line(5);tab(5);print("HOW much you give :");line(2);system ("color 0F");
          line(5);tab(5);scanf("%f",taka);line(2);

         if(money>taka)
        {
            scr();
            line(10);tab(10);printf("please give %.2f some also,money-taka");line(2);
            goto give;
        }
        else
        {
        scr();
        line(5);tab(5);printf("you take%.2f ,money-taka ");line(2);
        }

    }

    else if(choose==2){

             scr();

             int card_num[20],i=0;
             line(5);tab(5);print(" Please give your card_num :");line(2);
             line(5);tab(10);("%d",&card_num[i]);line(2);
             credit_card[i]=card_num[i];
             i++;

             scr();

             line(2);tab(2);printf("Thank you sir");line(2);

         }
         else
        {
           line(10);tab(5);printf("Please enter correct password sir ");line(2);
           goto back_option;
        }

}

int orderlist()
{
    int foodchoice,much,i,j,k;

    food_choice:
        line(2);("Which product !");line(3);

        tab(5);scanf("%d",&foodchoice);
        i=count();

        if(foodchoice>=1 && foodchoice<=i)
        {
            line(2);tab(2);print("How much do you need & Start Taking Orders ==>:");
            tab(3);scanf("%d",&much);

            k=total_money(foodchoice,much);
            payment(k);
            return k;
        }
        else
        {
            scr();
            line(5);tab(3);print("Enter correct item number please :");line(2);
            foodlist();
            goto food_choice;
        }
}

    void windows()
    {
        system("title**..Food Festival..**");
        system ("mode con:lines=35 cols=120");
    }

    int main()
    {

        windows();

         line(30);tab(20);print("* Welcome To Our Food Festival *");line(2);
         line(30);tab(20);print("********************************");line(2);Sleep(3000);

          main_menu:

              line(5);tab(5);print("Enter Your Choice Sir/Madam :");line(2);

               fooodlist();

               head=NULL;

               insertfood("Beef_code:101",1,500,150.50);
               insertfood("Chicken_code:222",2,450,50.75);
               insertfood("Biryani_code:271",3,300,60.50);
               insertfood("Kacchi_code:824",4,450,70.25);
               insertfood("pizza_code:613",5,420,90.45);
               insertfood("Pasta_code:543",6,430,80.30);
               insertfood("Chinese Food",7,500,110.85);
               insertfood("Italian Food",8,480,117.75);
               insertfood("Indian Food",10,405,78.25);
               insertfood("Russain Food",11,290,80.10);
               insertfood("Japanese Food",12,360,120);
               insertfood("Arabian Food",13,380,66.26);
               insertfood("Pakistani Food",14,220,98.20);
               insertfood("Korean Food",15,350,135.00);


               int choose,foodstock,fooddata,backmenu;
               float foodprice;
               char choice,addfood[30];
               char problem[2000],problem_box[2000];

               line(5);tab(3);print("-->");scanf("%c",&choice);

               if(choice>='1'  && choice<='5')
               {
                   if(choice=='1')
                   {
                       food_list:
                       scr();
                       line(30);tab(20);print("Enter Your Choice");line(3);

                       foodlist();
                     orderlist();

                       line(10);tab(5);printf("Thank you For Choosing");line(2);

                       another_food :

                           line(10);tab(5);printf("Are you want to buy another food:");line(2);
                           line(3);tab(2);printf("press 1 for main menu 2 for food list 0 for exit =>");
                           tab(5);fflush(stdin);scanf("%d",&backmenu);

                           switch (backmenu)
                         {
                             case 1:

                                    scr();
                                    goto main_menu;
                                    break;

                            case 2 :

                                     scr();
                                     goto food_list;
                                     break;

                            case 0:

                                   scr();
                                   line(10);tab(5); printf("**..Thank you sir ..**");line(5);
                                   break;

                            default :

                                    printf("Enter correct press sir");
                                    goto another_food;
              }

          }

          else if(choice=='2')
         {
    scr();
    int pass;

    admin_log:

    line(5);tab(5);print("Enter 0 for got to  main menu");line(2);system("color 0F");

    line(10);print("Enter the password :");line(4);

    line(3);tab(2);fflush(stdin);scanf("%d",&pass);

    if(pass==15215)
    {
        choose_option:
        scr();

        line(5);tab(5);print("1.Total Money");line(2);system("color 0F");
        line(5);tab(5);print("2.Problem  and suggestion");line(2);
        line(5);tab(5);print("3.Add food");line(2);
        line(5);tab(5);print("4.Delete food");line(2);
        line(5);tab(5);print("5. All Card number");line(2);
        line(5);tab(5);print("6.Total item"); line(2);
        line(5);tab(5);print("Enter 0 for go to main menu");line (2);


        line(5);tab(5);scanf("%d",&choose);

        if(choose>=0 && choose<=7)
        {

            if(choose==1)
            {
                scr();
                int k;
                line(5);tab(5);
                 orderlist (k);
                printf("%d",k);

                line (2);
            }

            else if (choose ==2)
                     {
                         scr();
                            int q=0;
                            line(5);tab(5); printf("%s",problem_box[q]);line(2);
                            q++;
                     }

            else if(choose==3)
            {
                scr();

                print("Enter list Number : ");

                scanf("%d",&fooddata);

                print("Enter the food name : ");

                scanf("%s",&addfood);

                print("Enter food price : ");

                scanf("%f",&foodprice);

                print("Enter food stock: ");

                scanf("%f",&foodstock);


                line (5);tab(5);print("sorry...we work for improving software:) thank u");line(2);
}

            else if(choose==4)
            {
                scr();
                line(5);tab(5);print("sorry...we work for improving software:) thank u");line(2);
            }

            else if(choose==5)
            {
                int k=0;
                scr();
                     line(5);tab(5);printf("%d",credit_card[k]);line(2);
                     k++;


            }

            else if(choose==0)
            {
                scr();
                goto main_menu;
            }

            else if(choose==6)
            {
                scr();

                int total,k;


                total=count();
                line(20);tab(20); printf("Our total food  %d item",total);line(20);

                admin_panel:

                line(5);tab(5);print("Enter 0 for back\n");
                line(5);tab(5);fflush(stdin);scanf("%d",&k);

                if(k==0)
                {
                    scr();
                    goto choose_option;
                }

                else {

                    scr();
                    line(5);tab(5);print("Please enter the correct pass");line(2);
                    goto admin_panel;

                }
            }

        }

        else
        {
            line(5);tab(5);print("Enter between 1 and 7");
            goto choose_option;
        }

        }

     else

    {
        scr();

        line(10); print("wrong password....enter correct pass");line(5);

        if(pass==0)
        {
            scr();

             goto main_menu;
        }

        else
            goto admin_log;
    }

}

else if (choice=='3')
{
    scr();
    int rules;

    rules_option:

    line(5);tab(30);print("**Rules and Regulation**");line(5);system("color 0F");
    line(10);tab(10);print("1. If you order any product, you have to know an order method and rules.");line(5);Sleep(700);
    line(10);tab(10);print("2. If you do order any product. You can't cancel that parcel.");line(5);Sleep(700);
    line(10);tab(10);print("3. But If you want to cancel your parcel. Then You must have to cancel your product before parceled to the delivery.");line(5);Sleep(700);
    line(10);tab(10);print("4. If you order any product, you must have to pay 30% bill before ordering.");line(5);Sleep(700);
    line(10);tab(10);print("5. If you order any product, you will get many vouchers. And the next time you can use other products for buying.");line(5);Sleep(700);
    line(10);tab(10);print("6. If you want to see your product delivery location, you can. ");line(5);Sleep(700);
    line(10);tab(10);print("7. If you want, You can see live cooking.**");line(5);Sleep(700);
    line(10);tab(20);print("keep me enjoy your food..");line(5);
    line(10);tab(10);print("press 0 for back:");scanf("%d",&rules);

    if(rules==0)
    {
        scr();
        fflush(stdin);
        goto main_menu;
    }

    else
    {

        scr();
        line(5);tab(5);print("Enter correct press sir");
        goto rules_option;

    }

    }

else if(choice =='4')
{
    scr();

    int back,m=0;

    line(10);tab(10);print("please write your suggestion");line(5);system("color 0F");
    line(10);tab(5);fflush(stdin);
    gets(problem);line(5);
    problem_box[m]=problem;
    m++;

    scr();
    line(5);tab(5);print("Thank you");line(5);

    back_option:

    line(5);tab(5);print("--> 0 for back");
    tab(3);scanf("%d",&back);

    if(back==0)
    {
        scr();
        fflush(stdin);
        goto main_menu;
}
    else
    {
        scr();
        line(5);tab(5);print("Enter correct pass");line(5);
        goto back_option;
    }
}

else if(choice=='5')
{
    scr();
    line(20);tab(3);print("**..Thank you..**");line(20);
}

}
else if(choice>='a'&& choice<='z')
{
    scr();
    line(20);tab(3);printf("Please,Enter A number between 1 and 5");line(3);
    goto main_menu;
}

else
{
    scr();
    line(20);tab(5);printf("please,Enter your choice between 1 and 5");line(3);
    goto main_menu;
}

return 0;
}
