
	#include<stdio.h>
	#include <time.h>
	#include<stdlib.h>
	#include <string.h>
	#include <conio.h>
	#include <windows.h>
	int loggedin=0; //using 0 and 1  it as bool ie. True or False

	
	typedef struct user //declaring user as user defined data type
	{
		char name[40];
		char pass[40];
		char place[30];       

		char price[30];
		int NoTick;
	
		
	}user;
	int pos;
	int ch;  //choice
	void Welcome(); //welcome page
	void signup();		//defining signup function
	
	user login();
	user BookTicket();//defining login function
	int Brochure();
	void printticket();
	

	struct user u1;		//decalring u1 with datatype user ie.its a data type thing  
	
	
	


int main()
{
	system("color 9");
	
	Welcome();		//calling welcome
	while(1){
		if(loggedin==0)	//while user is not logged in 
		{
			
				
				printf("\n\n\t\t\t\t\033[0;31m  Main menu \033[0m\n");
				printf("\033[0;33m");
				printf("\n\t\t\t\t[1] Sign Up");
				printf("\n\t\t\t\t[2] Login User\n");
				printf("\t\t\t\t[3] About Us\n");
				printf("\t\t\t\t[0] Exit\n");
				printf("\033[0m");

				printf("\n\n\t\t\t\tEnter Choice--->:");
				scanf("%d",&ch);		//get choice 
				
				switch(ch)				//switch case for choice
				{
					case 1:
					signup();
					system("PAUSE");
					system("CLS");
					break;
					case 2:
					login();
					
					system("PAUSE");
					system("CLS");
					break;
					case 3:
					//aboutus();
					system("PAUSE");
					system("Cls");
					break;
					case 0:
						printf("\nExiting......\n");
						getch();
					exit(0);
					default:
						printf("Wrong Input !!\n");
						system("pause");
						system("Cls");
						
					
					break;
					}
		}
				

				
		else if(loggedin==1){
			system("color 2");
				printf("\n\t\t\t\t=========================");
		printf("\n\t\t\t\tTOURISM MANAGEMENT SYSTEM");
		printf("\n\t\t\t\t=========================\n");
		printf("\033[0;31m");
		printf("\n\t\t\t\t Welcome %s\n ",u1.name);
		printf("\033[0m");

            printf("\n\t\t\t\t[1] Book Package \n\t\t\t\t[2] Check Ticket \n\t\t\t\t[3] Print Ticket \n\t\t\t\t[4] Cancel Ticket"
                   "\n\t\t\t\t[5] Logout User \n\t\t\t\t[0] Exit\n");
            printf("\n\t\t\t\tEnter you Choice -->");

			scanf("%d",&ch);
            if (ch==8){
            	break;
			}
            
            u1.name;
            
            switch(ch)
            {
                case 1:
                    BookTicket();
      
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                	if(strcmp(u1.place," ")==0)
                	{	system("cls");
                		printf("\aYou dont have any Booked Ticket's ");
                		system("pause");
                		system("cls");
                		break;
					}
					else{
					system("cls");
                   	printf("Name : %s\n",u1.name);
					printf("--------------------\n");
					printf("Place : %s\n",u1.place);
					printf("--------------------\n");
					printf("Price : %s\n",u1.price);
					printf("--------------------\n");
					printf("Number of Ticket: %d\n",u1.NoTick);
					printf("--------------------\n");
					printf("Mode : Flight \n");
					printf("--------------------\n");
					printf("Airplane : Jet Airways\n\n\n");
					
					
					
				     system("PAUSE");
                    system("CLS");
                	}
                    break;
                case 3:
                    printticket();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                	strcpy(u1.place," ");
					strcpy(u1.price," ");
					system("cls");
                	printf("\aYour Ticket has Been Cancled SucessFully !");    
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                   loggedin=0;
                   
                   system("cls");
                   printf("\n\aLogged Out SuccesFull ......\n");
                   system("PAUSE");
                   system("CLS");
                   
                   break;
                case 0:
                    
                    exit(0);
                    break;
                default:
                    printf("\aNot a valid input at this stage\n");
        			break;
	}
//
	}
	else
	{
		printf("\aWrong Input !!!");
	}
	
}
return 0;
}





	void Welcome(){
		printf("\t\t\t\t__________________________________________________________\n\n");
		printf("\t\t\t\t---------------------------------------------------------\n");
		printf("\t\t\t\t*********************************************************\n\n");
		printf("\t\t\t\t              ++ Welcome to Yatra Travels ++              \n\n");
		printf("\t\t\t\t*********************************************************\n");
		printf("\033[0;33m");
		printf("\t\t\t\t Project by : Dikshant(1992),Rahul(2065)and Prasad(1914) \n");
		printf("\033[0m\n");
//		system("color 1");
//		printf("\t\t\t\t---------------------------------------------------\n");
//		printf("\t\t\t\t__________________________________________________________");
		
	}

		
	
		
	void signup(){
		FILE *fp;
		char name[20],pass[20];
		fp=fopen("user.txt","ab");
		
		
		
		printf("\t\t\t\tEnter Name --> ");
		fflush(stdout);
		scanf(" %s",name);
		strcpy(u1.name,name);
		printf("\n\t\t\t\tEnter Password(only strings) --> ");
		fflush(stdout);
		scanf(" %s",pass);
		strcpy(u1.pass,pass);
		


		fprintf(fp, "%s %s \n",u1.name,u1.pass);


		printf("\n\aSign Up Successful \n Login to Continue \n");
		fclose(fp);


	}

	user login(){
		
		FILE *fp;		//pointer fp for file 
	
		char name[20];	//checking inputed username and pass
		char pass[20];
		int flag;		//flag

		fp = fopen("user.txt","rb");	//Open/create file and save address to fp rb =Read binary mode !
		
		
		printf("\t\t\t\tEnter name -->");	
		scanf("%s",name);		//enter users name and Password
		printf("\n\t\t\t\tEnter Password --> ");
		scanf("%s",pass);
		

	
		strcpy(u1.pass," ");
		while(fscanf(fp,"%s %s",u1.name,u1.pass)!=EOF)	//Read for username and pass Till the EOF ie. end of the file
		{
			
			if(strcmp(name,u1.name)==0)	//Comapare the username if exist ??
			{
				
				if((strcmp(pass,u1.pass))==0){	//IF usrname exist check for Password ?? Is Right ?
				
				
				loggedin=1;					//logged in == True 
				
				strcpy(u1.place," ");
				strcpy(u1.price," ");
				system("cls");
				printf("\t\n\aLogged in Successfuly !\n"); //If yes Logged in 
				
				break;
			}
			
			else 
			{
				printf("\aWrong Password !\n");			//If user and Password does not 
			
				flag=1;
				break;
			}
			
			
			if(flag==1){  //if Found breck and exit the LOOP
				break;
			}
			
		
		}
		
		}
		
		fclose(fp); //IDK what happened but its Working :) Please dont try to undeerstand Flag .LOL	
	}	
	
	
	
	
user BookTicket(){
	int ch1;
	char ch2[10];
	
		printf("\t\t\t\t[1] Domestic Packs \n");
		printf(" \t\t\t\t[2] InterNational Travel Pack\n ");
		printf("\t\t\t\tEnter Choice --> ");
		scanf("%d",&ch);
		system("cls");
			
		if(ch==1){
			system("CLS");
			printf("\t\t\tPOPULAR DOMESTIC DESTINATIONS\n");
			printf("\t\t   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			printf("1. LONAVALA\nVALIDITY-2D/1N\nRATE- 8,000(PER/PERSON)\t\t\t\n\n");
			printf("2. MAHABALESHWAR\nVALIDITY-3D/2N\nRATE- 10,000(PER/PERSON)\t\t\t\n\n");
			printf("3. MATHERAN\nVALIDITY-3D/2N\nRATE- 15,000(PER/PERSON)\t\t\t\n\n");
			printf("4. ALIBAUG\nVALIDITY-2D/1N\nRATE- 5,000(PER/PERSON)\t\t\t\n\n");
			printf("5. SHIMLA\nVALIDITY-5D/4N\nRATE- 25,000(PER/PERSON)\t\t\t\n\n");
			printf("6. MANALI\nVALIDITY-4D/3N\nRATE- 22,000(PER/PERSON)\t\t\t\n\n");
			printf("7. KASHMIR\nVALIDITY-6D/5N\nRATE- 29,500(PER/PERSON)\t\t\t");



			printf("\nEnter Package Number --> ");
			scanf("%d",&ch1);
				
			switch(ch1){
				
				case 1:
				strcpy(u1.place,"Lonavala");
				strcpy(u1.price,"8000");
				break;
			
				case 2:
				strcpy(u1.place,"MAHABALESHWAR");
				strcpy(u1.price,"1000");
				break;
				case 3:
				strcpy(u1.place,"MATHERAN");
				strcpy(u1.price,"15000");
				break;
				case 4:
				strcpy(u1.place,"ALIBAUG");
				strcpy(u1.price,"5000");
				break;
				case 5:
				strcpy(u1.place,"SHIMLA");
				strcpy(u1.place,"25,000");
				break;
				case 6:
				strcpy(u1.place,"MANALI");
				strcpy(u1.price,"22,000");
				break;
				case 7:
				strcpy(u1.place,"KASHMIR");
				strcpy(u1.price,"29,500");
				break;
				default:
					printf("Wrong Input !!");
					
			
		}
				fflush(stdout);		
				printf("\n\nHow many Tickets ??? :");

				scanf("%d",&u1.NoTick);
		
}

		
		else if (ch==2){
			system("color 4");
			system("CLS");
			printf("\t\t\tPOPULAR INTERNATIONAL DESTINATIONS\n");
			printf("\t\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			printf("1. DUBAI\nVALIDITY-6D/5N\nRATE- 85,000(PER/PERSON)\t\t\t\n\n");
			printf("2. SINGAPORE\nVALIDITY-5D/3N\nRATE- 65,000(PER/PERSON)\t\t\t\n\n");
			printf("3. EUROPE\nVALIDITY-8D/7N\nRATE- 95,000(PER/PERSON)\t\t\t\n\n");
			printf("4. BALI\nVALIDITY-7D/6N\nRATE- 75,000(PER/PERSON)\t\t\t\n\n");
			printf("5. MALDIVES\nVALIDITY-4D/3N\nRATE- 67,999(PER/PERSON)\t\t\t\n\n");
			printf("6. BANGKOK\nVALIDITY-7D/6N\nRATE- 59,999(PER/PERSON)\t\t\t\n\n");
			printf("7. THAILAND\nVALIDITY-5D/4N\nRATE- 70,300(PER/PERSON)\t\t\t");
			system("color 6");
			printf("\nEnter Package Number --> ");
			scanf("%d",&ch1);
			system("color");
			switch(ch1){
			
			case 1:
			strcpy(u1.place,"DUBAI");
			strcpy(u1.price,"85,000");
			break;			
			case 2:
			strcpy(u1.place,"SINGAPORE");
			strcpy(u1.price,"65,000");
			break;
			case 3:
			strcpy(u1.place,"EUROPE");
			strcpy(u1.price,"95,000");
			break;

			case 4:
			strcpy(u1.place,"BALI");
			strcpy(u1.price,"75,000");
			break;
			case 5:
			strcpy(u1.place,"MALDIVES");
			strcpy(u1.price,"85,000");
			break;
			case 6:
			strcpy(u1.place,"BANGKOK");
			strcpy(u1.price,"59,999");
			break;
			case 7:
			strcpy(u1.place,"THAILAND");
			strcpy(u1.price,"70,300");
			break;
			default:
			printf("Wrong Inout !!\n");
	}
		system("color 7");
		
		fflush(stdout);		
		printf("How many Tickets ??? :");
				
		scanf("%d",&u1.NoTick);
}
system("color 4");
system("cls");
printf("\aYour Ticket has been Booked ! \n\nPlease Print your Ticket !!!\n\n\n");
system("color");	
}

void printticket(){
	char filename[20];
while(1){

	if(strcmp(u1.place," ")==0)
	{	
		system("cls");
		printf("You dont have any Booked Tickets \n\nPlease Do Book\n\n");
		system("pause");
		break;
	}
	else
	{
	
	strcpy(filename,u1.name);
	strcat(filename,"s_ticket.txt");
	time_t t;
	time(&t);
	FILE *fp = fopen(filename,"w");
	fprintf(fp,"__________________________________________________\n");
	fprintf(fp,"\n            +++ Yatra Travels Ticket +++          \n");
	fprintf(fp,"__________________________________________________\n");
	fprintf(fp,"**************************************************\n");
	
	fprintf(fp,"               %s                              ",ctime(&t));
	fprintf(fp,"--------------------------------------------------\n");
	fprintf(fp,"Name : %s\n",u1.name);
	fprintf(fp,"--------------------\n");
	fprintf(fp,"Place : %s\n",u1.place);
	fprintf(fp,"--------------------\n");
	fprintf(fp,"Price : %s\n",u1.price);
	fprintf(fp,"--------------------\n");
	fprintf(fp,"Number of Ticket: %d\n",u1.NoTick);
	fprintf(fp,"--------------------\n");
	fprintf(fp,"Mode : Flight \n");
	fprintf(fp,"--------------------\n");
	fprintf(fp,"Airplane : KingFisher Airways\n");
	fprintf(fp,"--------------------\n");
	fprintf(fp,"Booked On: %s\n",ctime(&t));

	
	fprintf(fp,"****************************************************\n");
	system("cls");
	printf("\a Your Ticket has Been Printed !\n\n Please Check Your Folder for Ticket in Txt Format !!");

	MessageBox(0,"Your Ticket has Been Pinted in your curren Folder as Txt ","Ticket",1);
	system("pause");
	fclose(fp);
	break;
}
	

}


}
