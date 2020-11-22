	#include<stdio.h>
	#include <time.h>
	#include<stdlib.h>
	#include <string.h>
	
int curreentstate=0,loggedin; 

	//declaring sturct
	typedef struct User

	{
		char name[40];
		char pass[40];
		char place[30];
		int numtick;
		float price;
		struct user *next;
		
	}user;

	int ch;
	void Welcome();
	user signUp();
	void pause(int);
	user login();


	struct user u1,h;
	char currentuser[20];
	
	


	void main(){
		
	Welcome();
	while(1){
		if(curreentstate==0)
		{	
			
					
				printf("\nMain Menu\n");
				printf("1.Sign Up \n");
				printf("2.Login User\n");
				printf("3.Brochure\n");
				printf("4.Exit\n");

				printf("Enter Choice :");
				scanf("%d",&ch);
				
				switch(ch)
				{
					case 1:
					u1 = signUp();
					break;
					case 2:
					u1 = login();

					break;
					}
		}
				

				
		else if(curreentstate==1){
				printf("Wait\n");
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

		fp=fopen("user.txt","ab");

		printf("Enter Name :");
		scanf("%s",u1.name);
		printf("Enter Password :");
		scanf("%s",u1.pass);
		// encrypt(u1.pass,0);

		fprintf(fp, "%s %s \n",u1.name,u1.pass);
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
		FILE *fp;
		user temp;
		char name[20];
		char pass[20];
		int flag;

		fp = fopen("user.txt","r");
		printf("Enter name:");
		scanf("%s",name);
		printf("\nEnter Password :");
		scanf("%s",pass);

		

		while(fscanf(fp,"%s %s",u1.name,u1.pass)!=EOF)
		{
			
			if(strcmp(name,u1.name)==0)
			{
				
				
				curreentstate=1;

				printf("\t\nLoged in Successfuly !");
				break;
			}
			else
			{
				printf("404\n");
				break;
				
			}
		}
		
		fclose(fp);
		return u1;
		}
		
