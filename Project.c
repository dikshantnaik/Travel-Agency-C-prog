
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
		struct user *next;
		
	}user;

	int ch;  //choice
	void Welcome(); //welcome page
	user signUp();		//defining signup function
	//void pause(int);
	user login();		//defining login function


	struct user u1;		//decalring u1 with datatype user ie.its a data type thing  
	char currentuser[20];	//track for current user 
	
	


	void main(){
		
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
					printf("User : %s\n",u1.name);

// 					printf("Pass: %s \n",u1.pass);
// 					printf("Place %s\n ",u1.place);
// 					printf("Money %s",u1.price);
					system("PAUSE");
					system("CLS");
					
					
					break;
					}
		}
				

				
		else if(loggedin==1){
				
				printf("Wait Work in Proogress\n");
				system("PAUSE");
				break;
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
		
		if(fp==NULL){
			printf("File not Found");
			
		}
		else{
			printf("File Found ");
		}
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
		printf("user name :%s \n pass : %s\n",u1.name,u1.pass);
		///encrypt(u1.pass,0);

		fprintf(fp, "%s %s \n",u1.name,u1.pass);
		//fwrite(&u1,sizeof(u1),1,fp);
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

		fp = fopen("user.txt","rb");	//Open/create file and save address to fp
		
		if(fp==NULL)		//No use NVM..It will create a file 
		{
			printf("File not Found");
		}
		printf("Enter name:");	
		scanf("%s",name);		
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
				printf("Wrong Password !");			//If user and Password does not 
			
				flag=1;
				break;
			}
			
			{
				printf("\n");
				flag=0;
				
			}
			
			if(flag==1){
				break;
			}
			
		}
		else if(flag==1)
		{
			printf("User not Found !!");
		}
	}	
		fclose(fp); //IDK what happened but its Working :) Please dont try to undeerstand Flag .LOL
	}
		
		
