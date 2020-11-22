#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Developed By Ankan Das

enum state{menu,loggedin};
enum state currentstate=menu;

typedef struct user
{
    char username[100];
    char password[100];
    char place[100];
    float price;
    int numtick;
    struct user *next;
}user;

void ShowBrochure();
user* InitializeList(user*);
user* AddUser(user*);
void LoginUser(user*);
void BookTicket(user*);
void PrintTicket(user*);
void CancelTicket(user*);
void ChangePassword(user*);
void LogoutUser();
void CheckTicket(user*);
void DisplayAll(user*);
void WriteToFile(user*);
void ExitProgram();

char currentuser[100];

int main()
{
    printf("\t\t\t==== || TOURISM MANAGEMENT SYSTEM || ====\n");
    user *h=NULL;
    int ch1,ch2;
    h=InitializeList(h);
    while (1)
    {
    	
        if(currentstate==menu)
        {
        	
            printf("\n\t\t\t\tAdd User - 1\n\t\t\t\tLogin User - 2\n\t\t\t\tBrochure - 3\n\t\t\t\tExit - 4\n\n\t\t\t\tEnter:");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                    h=AddUser(h);
                    break;
                case 2:
                    LoginUser(h);
                    break;
                case 3:
                    ShowBrochure();
                    break;
                case 4:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
        else if(currentstate==loggedin)
        {
        system("CLS");
        printf("\n\t\t\t\t=========================");
		printf("\n\t\t\t\tTOURISM MANAGEMENT SYSTEM");
		printf("\n\t\t\t\t=========================\n");	
            printf("\n\t\t\t\tBook Package - 1\n\t\t\t\tCheck Ticket - 2\n\t\t\t\tPrint Ticket - 3\n\t\t\t\tCancel Ticket - 4\n\t\t\t\tChange Password - 5"
                   "\n\t\t\t\tLogout User - 6\n\t\t\t\tBrochure - 7\n\t\t\t\tExit - 8\n");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1:
                    BookTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                    CheckTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 3:
                    PrintTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                    CancelTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                    ChangePassword(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 6:
                    LogoutUser(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 7:
                    ShowBrochure();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 8:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
    }
    return 0;
}

user* InitializeList(user *h)
{
    user* t,*ptr,temp;
    FILE *fp;
    int cc=0,x;
    float ff;
    fp=fopen("users.txt","r");

    if(fp==NULL)
        return NULL;

    if(fgetc(fp)==EOF)
        return NULL;

    rewind(fp);
	while(fscanf(fp,"%s %s %s %f %d",temp.username,temp.password,temp.place,&temp.price,&temp.numtick)!=EOF)
	{
		ptr=(user*)malloc(sizeof(user));
		strcpy(ptr->username,temp.username);
		strcpy(ptr->password,temp.password);
		strcpy(ptr->place,temp.place);
		ptr->price=temp.price;
		ptr->numtick=temp.numtick;
		ptr->next=NULL;

		if(h==NULL)
            h=t=ptr;
		else
		{
			h->next=ptr;
			h=ptr;
		}
	}
	fclose(fp);
    return t;
}

void WriteToFile(user *h)
{
    FILE *fp;
    fp=fopen("users.txt","w");
    while(h!=NULL)
    {
        fprintf(fp,"%s %s %s %f %d\n",h->username,h->password,h->place,h->price,h->numtick);
        h=h->next;
    }
    fclose(fp);
}

void ShowBrochure()
{
	system("CLS");
    printf("\tPRICE LIST\n=============================\n1. LL - Antelope Canyon Tours - Rs 40000\n2. JK - Grand Canyon Local Tours - Rs 60000\n3. SK - San Francisco Local Tours - Rs 25000\n4. SHM - Miami Vacation - Rs 38000\n"
           "5. AND - Hawaii - Rs 120000\n6. BHB - Atlanta Vacation - Rs 10000\n7. AG - San Francisco - Rs 30000\n8. ND - Alaska Vacation - Rs 32000\n9. RJ - Orlando Vacation - Rs 45000\n10. SI - South US Tour - Rs 250000\n");
}

void CheckTicket(user *h)
{
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(!strcmp(h->place,"\0") || h->price==0.0 || h->numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    float total=0.0;
    total=(h->price)*(h->numtick);
    printf("You have booked %d tickets for a sum total of Rs %f for tour code %s\n",h->numtick,total,h->place);
}

user* AddUser(user* h)
{
    user *t;
    t=h;
    user *nw;
    nw=(user*)malloc(sizeof(user));
    fflush(stdin);
    printf("Enter username or email\n");
    scanf("%s",nw->username);
    while(h!=NULL)
    {
        if(!strcmp(h->username,nw->username))
        {
            printf("That email already exists\n");
            return t;
        }
        h=h->next;
    }
    h=t;
    fflush(stdin);
    printf("Enter password\n");
    scanf(" %[^\n]s",&nw->password);
    nw->next=NULL;
    strcpy(nw->place,"N/A");
    nw->price=0.0;
    nw->numtick=0;

    if(h==NULL)
    {
        h=t=nw;
    }
    else
    {
        while(h->next!=NULL)
        {
            h=h->next;
        }
        h->next=nw;
    }
    WriteToFile(t);
    return t;
}

void LoginUser(user* h)
{
    char username[100];
    char password[100];
    fflush(stdin);
    printf("\n\n");
    printf("\t\tEnter Email/Username:\n\t\t");
    scanf("%s",username);
    fflush(stdin);
    printf("\n\t\tEnter Password:\n\t\t");
    scanf(" %[^\n]s",password);
    while(h!=NULL)
    {
        if((!strcmp(h->username,username)) && (!strcmp(h->password,password)))
        {
            currentstate=loggedin;
            strcpy(currentuser,username);
            
            printf("\n\t\tLogin successful!\n");
            system("PAUSE");
            return;
        }
        else if((!strcmp(h->username,username)) && (strcmp(h->password,password)))
        {
            printf("Password mismatch\n");
            return;
        }
        h=h->next;
    }
    printf("Sorry, no such user record was found\n");
}

void BookTicket(user *h)
{
    user *t=h;
    char place[100];
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(h==NULL)
        return;
    if(h->price!=0.0)
    {
        printf("You must cancel your previous ticket before buying a new one\n");
        return;
    }
    ShowBrochure();
    float pricelist[]={40000.0,60000.0,25000.0,38000.0,120000.0,10000.0,30000.0,32000.0,45000.0,250000.0};
    fflush(stdin);
    printf("\nEnter place code (eg: LL, JK)\n");
    scanf(" %[^\n]s",place);
    char choice;
    fflush(stdin);
    printf("\nWould You Like to Confirm Booking?\n[1] - Yes\n[2] - No\n");
    scanf("%c",&choice);
    float price;
    if(choice!='1')
        return;
    if(strcmp(place,"LL")==0)
        price=pricelist[0];
    else if(strcmp(place,"JK")==0)
        price=pricelist[1];
    else if(strcmp(place,"SK")==0)
        price=pricelist[2];
    else if(strcmp(place,"SHM")==0)
        price=pricelist[3];
    else if(strcmp(place,"AND")==0)
        price=pricelist[4];
    else if(strcmp(place,"BHB")==0)
        price=pricelist[5];
    else if(strcmp(place,"AG")==0)
        price=pricelist[6];
    else if(strcmp(place,"ND")==0)
        price=pricelist[7];
    else if(strcmp(place,"RJ")==0)
        price=pricelist[8];
    else if(strcmp(place,"SI")==0)
        price=pricelist[9];
    else
    {
        printf("That tour code doesn't exist\n");
        return;
    }
    printf("Enter the number of tickets you want to book?\n");
    scanf("%d",&h->numtick);
    if(h->numtick==0)
        return;
    strcpy(h->place,place);
    h->price=price;
    WriteToFile(t);
    printf("Bookings Done!!\n");
    system("PAUSE");
    
}

void PrintTicket(user *h)
{
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(!strcmp(h->place,"\0") || h->price==0.0 || h->numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    float total=0.0;
    total=(h->price)*(h->numtick);
    FILE *fp;
    char filename[50];
    strcpy(filename,h->username);
    strcat(filename,"_ticket.txt");
    fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("Problem opening the file\n");
        return;
    }
    if(fgetc(fp)==EOF)
    {
        fprintf(fp,"TOURISM TICKET\n===============\n\n");
    }
    fprintf(fp,"Email ID: %s\nTour Code: %s\nTicket Cost: Rs %f\nNumber of tickets: %d\nTotal Cost: Rs %f\n",h->username,h->place,h->price,h->numtick,total);
    fclose(fp);
}
//TMS1353f
void CancelTicket(user *h)
{
    user *t=h;
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }

    int flag=-1;

    if(h==NULL)
        printf("No such user\n");

    if(strcmp(h->place,"LL")==0)
        flag++;
    else if(strcmp(h->place,"JK")==0)
        flag++;
    else if(strcmp(h->place,"SK")==0)
        flag++;
    else if(strcmp(h->place,"SHM")==0)
        flag++;
    else if(strcmp(h->place,"AND")==0)
        flag++;
    else if(strcmp(h->place,"BHB")==0)
        flag++;
    else if(strcmp(h->place,"AG")==0)
        flag++;
    else if(strcmp(h->place,"ND")==0)
        flag++;
    else if(strcmp(h->place,"RJ")==0)
        flag++;
    else if(strcmp(h->place,"SI")==0)
        flag++;
    else
    {
        printf("You haven't booked a tour yet\n");
        return;
    }
    if(flag==0)
    {
        printf("Your ticket has been successfully cancelled\nA refund of Rs %f for Tour Code %s for %d tickets will soon be made to your original source of purchase\n",h->price,h->place,h->numtick);
        strcpy(h->place,"N/A");
        h->price=0.0;
        h->numtick=0;
        WriteToFile(t);
    }
}

void ChangePassword(user *h)
{
    user *t=h;
    char passcurr[100];
    fflush(stdin);
    printf("Enter your current password to continue:\n");
    scanf(" %[^\n]s",passcurr);
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(h==NULL)
        return;
    if(!strcmp(passcurr,h->password))
    {
        printf("Enter new password:\n");
        scanf(" %[^\n]s",h->password);
    }
    WriteToFile(t);
}

void LogoutUser()
{
    if(currentstate==menu || strcmp(currentuser,"\0")==0)
    {
        printf("You must be logged in to logout\n");
        return;
    }
    strcpy(currentuser,"\0");
    currentstate=menu;
    printf("You have been successfully logged out\n");
}

void ExitProgram()
{
    printf("Exiting...\nDeveloped By Ankan Das, Kolkata\n\nBrought To You By code-projects.org\n\nPress \"Enter/Return\" to exit");
    char exitprog;
    fflush(stdin);
    scanf("%c",&exitprog);
}
