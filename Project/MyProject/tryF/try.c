#include <stdio.h>
#include <string.h>


struct user
{
	char name[20];
	char pass[20];
	float price;
};

struct user u1;

void displayrec();
void insert_record();

void main(){

	int ch;
	printf("Enter choice :");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
		insert_record();

		case 2:
		displayrec();
	}
}


void insert_record()
{
	FILE *fp;

	fp =fopen("try.txt","a");

	printf("Pahile ka Record\n");
	displayrec();
	fflush(stdin);
	printf("Enter useranem :");
	scanf("%s",u1.name);
	printf("\npass :");
	scanf("%s",u1.pass);

	fprintf(fp,"%s %s \n",u1.name,u1.pass);

	printf("hogaya insert\n ");

	fclose(fp);

	printf("Update \n");
	displayrec();
}


void displayrec()
{
	FILE *fp;

	fp=fopen("try.txt","rb");


	while(fread(&u1,sizeof(u1),1,fp)==1)
	{
		printf("Password : %s\nUsername :%s \n",u1.pass,u1.name);
	}
	
fclose(fp);
}
