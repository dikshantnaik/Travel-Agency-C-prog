
	#include<stdio.h>
	#include <time.h>
	#include<stdlib.h>
	#include <string.h>
	#include <conio.h>	
	int loggedin=0; //using it as bool is. True or False

	
	typedef struct user //declaring user as user defined data type
	{
		char name[40];
		char pass[40];
		char place[30];
		int numtick;
		char price[20];
		struct user *next
		
	}user;

	int ch;  //choice
	void Welcome(); //welcome page
	user signUp();		//defining signup function
	
	user login();
	void BookTicket();//defining login function
	void Brochure();
	

	struct user u1;		//decalring u1 with datatype user ie.its a data type thing  
	
	
	


	void main(){
	system("color 9");
	
	Welcome();		//calling welcome
	while(1){
		if(loggedin==0)	//while user is not logged in 
		{
			
				
				printf("\nMain Menu\n");
				printf("1.Sign Up \n");
				printf("2.Login User\n");
				printf("3.Brochure\n");
				printf("4.Exit\n");

				printf("Enter Choice :");
				scanf("%d",&ch);		//get choice 
				
				switch(ch)				//switch case for choice
				{
					case 1:
					signUp();
					system("PAUSE");
					system("CLS");
					break;
					case 2:
					login();
					system("PAUSE");
					system("CLS");
					break;
					case 3:
					Brochure();
					system("PAUSE");
					system("Cls");
					break;
					case 4:
						printf("\nExiting......");
						getch();
					exit(0);
					
					break;
					}
		}
				

				
		else if(loggedin==1){
			system("color 2");
				printf("\n\t\t\t\t=========================");
		printf("\n\t\t\t\tTOURISM MANAGEMENT SYSTEM");
		printf("\n\t\t\t\t=========================\n");
		printf("\n\t\t\t\t\033[0;31mWelcome %s\n \033[0m",u1.name);
            printf("\n\t\t\t\t[1] Book Package \n\t\t\t\t[2] Check Ticket \n\t\t\t\t[3] Print Ticket \n\t\t\t\t[4] Cancel Ticket \n\t\t\t\t[5] Change Password "
                   "\n\t\t\t\tLogout User - 6\n\t\t\t\tBrochure - 7\n\t\t\t\tExit - 8\n");
            printf("\n\t\t\t\tEnter you Choice :");
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
                    printf("You have Booked pack %s for Rs %s",u1.place,u1.price);
                    system("PAUSE");
                    system("CLS");
                    break;
//                case 3:
//                    PrintTicket();
//                    system("PAUSE");
//                    system("CLS");
//                    break;
//                case 4:
//                    CancelTicket();
//                    system("PAUSE");
//                    system("CLS");
//                    break;
//                case 5:
//                    ChangePassword();
//                    system("PAUSE");
//                    system("CLS");
//                    break;
               case 6:
                   loggedin=0;
                   printf("\nLogged Out SuccesFul ......\n");
                   system("PAUSE");
                   system("CLS");
                   break;
                case 7:
                    Brochure();
                    system("PAUSE");
                    system("CLS");
                    break;
//                case 8:
//                    ExitProgram();
//                    exit(0);
//                    break;
//                default:
//                    printf("Not a valid input at this stage\n");
//        
//				break;
	}
//
	}
	else
	{
		printf("Wrong Input !!!");
	}
	
}
}





	void Welcome(){

		printf("----------------------------------------------------\n");
		printf("|            Welcome to Nita Travels               |\n");
		printf("----------------------------------------------------\n\n");
		
	}

		
	// char encrypt(char str,int flag)
		// {	
		// 		for(int i = 0; (i < 100 && str[i] != '\0'); i++)
		
		// 		{
	 //        	str[i] = str[i] + 3; //the key for encryption is 3 that is added to ASCII value
		// 		break;
		// 		}
	 //  	}
		
	user signUp(struct user u1){
		FILE *fp;
		char name[20],pass[20];
		fp=fopen("user.txt","a");
		
		
		fflush(stdin);
		fflush(fp);
		printf("Enter Name :");
		scanf(" %s",name);
		//gets(name);
		strcpy(u1.name,name);
		printf("\nEnter Password :");
		scanf(" %s",pass);
		//gets(pass);
		strcpy(u1.pass,pass);
		
		///encrypt(u1.pass,0);

		fprintf(fp, "%s %s \n",u1.name,u1.pass);
		//fwrite(&u1,sizeof(u1),1,fp);
		printf("\nSign Up Successful \n Login to Continue \n");
		fclose(fp);

		return u1;
	}

	void pause(int f){
		if(f==0)
			{ //Is Windows ??
			system("PAUSE");
			system("CLS");
		}

		else if(f==1)
		{ //Is Linux ??
			printf("Press Enter to Continue ...");
			getchar();
			system("clear");
		}

	}

	user login(){
		
		FILE *fp;		//pointer fp for file 
	
		char name[20];	//checking inputed username and pass
		char pass[20];
		int flag;		//flag

		fp = fopen("user.txt","rb");	//Open/create file and save address to fp rb =Read binary mode !
		
		
		printf("Enter name:");	
		scanf("%s",name);		//enter users name and Password
		printf("\nEnter Password :");
		scanf("%s",pass);
		

	

		while(fscanf(fp,"%s %s",u1.name,u1.pass)!=EOF)	//Read for username and pass Till the EOF ie. end of the file
		{	
			
			if(strcmp(name,u1.name)==0)	//Comapare the username if exist ??
			{
				
				if((strcmp(pass,u1.pass))==0){	//IF usrname exist check for Password ?? Is Right ?
				
				
				loggedin=1;						//logged in == True 
				
				fscanf(fp,"%s ",u1.place);
				fscanf(fp,"%s",u1.price);
				printf("\t\nLoged in Successfuly !\n"); //If yes Logged in 
				
				break;
			}
			
			else 
			{
				printf("Wrong Password !\n");			//If user and Password does not 
			
				flag=1;
				break;
			}
			
			
//				printf("\n"); //reading the next line 
//				flag=0;  //set flag tp check if found pass ??
//				
			
			
			if(flag==1){  //if Found breck and exit the LOOP
				break;
			}
			
		}
//		else if(flag==0)
//		{
//			printf("User not Found !!");
//		}
//		else
//		{
//			printf("User not Found !!\n");
//			break;
//		}
	}	
		fclose(fp); //IDK what happened but its Working :) Please dont try to undeerstand Flag .LOL
	}
	
void BookTicket(){
	int ch;
	printf("\t\t\t[1] Domestic Packs \n");
	printf(" \t\t\t[2] InterNational Travel Pack\n ");
	printf("\t\t\tEnter Choice : ");
	scanf("%d",&ch);
	
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

		}
		else if (ch==2){
			system("CLS");
			printf("\t\t\tPOPULAR INTERNATIONAL DESTINATIONS\n");
			printf("\t\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			printf("	1. DUBAI\nVALIDITY-6D/5N\nRATE- 85,000(PER/PERSON)\t\t\t\n\n");
			printf("2. SINGAPORE\nVALIDITY-5D/3N\nRATE- 65,000(PER/PERSON)\t\t\t\n\n");
			printf("3. EUROPE\nVALIDITY-8D/7N\nRATE- 95,000(PER/PERSON)\t\t\t\n\n");
			printf("4. BALI\nVALIDITY-7D/6N\nRATE- 75,000(PER/PERSON)\t\t\t\n\n");
			printf("5. MALDIVES\nVALIDITY-4D/3N\nRATE- 67,999(PER/PERSON)\t\t\t\n\n");
			printf("6. BANGKOK\nVALIDITY-7D/6N\nRATE- 59,999(PER/PERSON)\t\t\t\n\n");
			printf("7. THAILAND\nVALIDITY-5D/4N\nRATE- 70,300(PER/PERSON)\t\t\t");

		}
	}
	
	
	void Brochure(){
		
		
		int ch;
		printf("\t\t\t[1] Domestic Packs \n");
		printf(" \t\t\t[2] InterNational Travel Pack\n ");
		printf("\t\t\tEnter Choice : ");
		scanf("%d",&ch);
	
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

		}
		else if (ch==2){
			system("CLS");
			printf("\t\t\tPOPULAR INTERNATIONAL DESTINATIONS\n");
			printf("\t\t     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			printf("	1. DUBAI\nVALIDITY-6D/5N\nRATE- 85,000(PER/PERSON)\t\t\t\n\n");
			printf("2. SINGAPORE\nVALIDITY-5D/3N\nRATE- 65,000(PER/PERSON)\t\t\t\n\n");
			printf("3. EUROPE\nVALIDITY-8D/7N\nRATE- 95,000(PER/PERSON)\t\t\t\n\n");
			printf("4. BALI\nVALIDITY-7D/6N\nRATE- 75,000(PER/PERSON)\t\t\t\n\n");
			printf("5. MALDIVES\nVALIDITY-4D/3N\nRATE- 67,999(PER/PERSON)\t\t\t\n\n");
			printf("6. BANGKOK\nVALIDITY-7D/6N\nRATE- 59,999(PER/PERSON)\t\t\t\n\n");
			printf("7. THAILAND\nVALIDITY-5D/4N\nRATE- 70,300(PER/PERSON)\t\t\t");

		}
		
	}
