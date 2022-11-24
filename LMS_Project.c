#include<stdio.h>
#include<conio.h>
static int n=0;
struct STUDENT
{
	int age,roll_no,maths,physics,chemistry,eng,total;
	char name[10];
	float avg;
};
//------------------------------------
int main()
{
	void add();
	void password();
	void displayAll();
	void record();
	void del();
	void marksheet();
	void modify();
	void changePassword();
	int i,count=0,a,n=0,r,m,ms;
	printf("\n\t\t\t\t========================================================\n");
	printf("\n\t\t\t\t\t\t   STUDENT RECORDS\n");
	printf("\n\t\t\t\t========================================================\n");
	while(1)
	{
		printf("\n----------------------");
		printf("\nChoose an option below");
		printf("\n----------------------");
		printf("\n1.Add a record");
		printf("\n2.Delete a record");
		printf("\n3.Modify a record");
		printf("\n4.Generate marksheet");
		printf("\n5.Search a record");
		printf("\n6.Display all records");
		printf("\n7.Change password");
		printf("\n8.Exit");
		printf("\n----------------------\n");
		printf("\nEnter your Choice to Perform the task : ");
		scanf("%d",&a);
		printf("\n");
		switch (a)
		{
			case 1:
			{
				password();
				add();	
				break;
			}
			case 2:
			{	
				password();
				del();
				break;
			}
			case 3:
			{
				password();
				modify();
				break;
			}
			case 4:
			{
				marksheet();
				break;	
			}
			case 5:
			{
				record();
				break;
			}
			case 6:
			{
				displayAll();
				break;
			}
			case 7:
			{
				password();
				changePassword();
				break;
			}
			case 8:
			{
				exit(0);
			}
				
		}
	}	
}
//-------------------------------------------------

void add()
{
		int i;
		struct STUDENT s;
		int size;
		FILE *fp;
		size=sizeof(s);
		fp=fopen("LMS_Project.DAT","ab");
 		printf("\n\nEnter Roll no. for record : ");
		scanf("%d",&s.roll_no);
		printf("Enter Name : ");
		scanf("%s",s.name);
		printf("Enter Age : ");
		scanf("%d",&s.age);
		printf("Enter English marks : ");
		scanf("%d",&s.eng);
		printf("Enter Maths marks : ");
		scanf("%d",&s.maths);
		printf("Enter Physics marks : ");
		scanf("%d",&s.physics);
		printf("Enter Chemistry marks : ");
		scanf("%d",&s.chemistry);
		
		s.total=s.eng+s.maths+s.physics+s.chemistry;
		s.avg=s.total/4.0;
		fwrite(&s,size,1,fp);
		fclose(fp);	
		printf("\nRecord successfully added (: \n");
}
//-------------------------------------------------

void password()
{
	FILE *fp;
	int i=0,count=0;
//	printf("\n");
	printf("Enter password : ");
	char ch[6],c[6],a,b;
	fp=fopen("password.txt","r");
	while((b=getc(fp))!=EOF)
	{
		c[i]=b;
		i++;
	}
	for(i=0;i<6;i++)
	{
		a=getch();
		ch[i]=a;
		printf("*");
		if(ch[i]==c[i])
		{
			count++;
		}
	}
	if(count==6)
	{
		printf("\nLogin success\n");
	}
	else
	{
		printf("\nLogin failed!! Re- ");
		password();
	}
	fclose(fp);
}
//-------------------------------------------------

void displayAll()
{
	FILE *fp;
	struct STUDENT s;
	
	fp=fopen("LMS_Project.DAT","rb");
	
	printf("\n========================================================\n\n");
	printf("\t\t All Student Details\n\n");
	printf("========================================================\n\n");
	
	
	while(1)
	{
		fread(&s,sizeof(s),1,fp);
		
		if(feof(fp))
		{
			break;
		}
		printf("\nRollno : %d\t",s.roll_no);
		printf("Name : %s\t",s.name);
		printf("Age : %d\t",s.age);
		printf("Total : %d\n",s.total);
	}
	printf("========================================================\n\n");
	
	fclose(fp);
}
//-------------------------------------------------

void record()
{
	FILE *fp;
	struct STUDENT s;
	int id,found=0;
	fp=fopen("LMS_Project.DAT","rb");
	printf("\nEnter the Student Roll no : ");
	scanf("%d",&id);
	while(1)
	{
		fread(&s,sizeof(s),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(s.roll_no==id)
		{
			found=1;
			printf("\n========================================================\n\n");
			printf("\t\t Student Record of %d\n\n",s.roll_no);
			printf("========================================================\n\n");
		
			printf("Rollno : %d\t",s.roll_no);
			printf("Name : %s\t",s.name);
			printf("Age : %d\t",s.age);
			printf("Total : %d\n",s.total);
		
			printf("========================================================\n\n");
		}
	}
	if(found==0)
	{
		printf("\nSorry!! No Record Found ): ");
	}
	fclose(fp);
}
//-------------------------------------------------

void del()
{
	FILE *fp,*fp1;
	struct STUDENT s,s1;
	int id,found=0;
	
	fp=fopen("LMS_Project.DAT","rb");
	fp1=fopen("temp.dat","wb");
	
	printf("\nEnter Student Roll no. you want to Delete : ");
	scanf("%d",&id);
	while(1)
	{
		fread(&s,sizeof(s),1,fp);
		
		if(feof(fp))
		{
			break;
		}
		if(s.roll_no==id)
		{
			found=1;
			printf("\nDeleted Student data of Roll no. %d\n",id);
		}
		else
		{
			fwrite(&s,sizeof(s),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	if(found==0)
	{
		printf("Sorry!! No Record Found ):\n\n");
	}
	else
	{
		fp=fopen("LMS_Project.DAT","wb");
		fp1=fopen("temp.dat","rb");
	
		while(1)
		{
			fread(&s,sizeof(s),1,fp1);
			
			if(feof(fp1))
			{
				break;
			}
			fwrite(&s,sizeof(s),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
//-------------------------------------------------

void marksheet()
{
	FILE *fp;
	struct STUDENT s;
	int id,found=0;
	fp=fopen("LMS_Project.DAT","rb");
	printf("\nEnter the Student Roll no. : ");
	scanf("%d",&id);
	while(1)
	{
		fread(&s,sizeof(s),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(s.roll_no==id)
		{
			found=1;
			printf("\n========================================================\n\n");
			printf("\t\t Student Marksheet of Roll No. %d\n\n",s.roll_no);
			printf("========================================================\n\n");
		
			printf("Rollno :%d\t",s.roll_no);
			printf("Name :%s\t\t",s.name);
			printf("English :%d\t",s.eng);
			printf("Maths :%d\t",s.maths);
			printf("Physics :%d\t",s.physics);
			printf("Chemistry :%d\t",s.chemistry);
			printf("Total :%d\t",s.total);
			printf("Average :%0.2f\n",s.avg);
		
			printf("========================================================\n\n");
		}
	}
	if(found==0)
	{
		printf("\nSorry!! No Record Found ): ");
	}
	fclose(fp);
}
//-------------------------------------------------

void modify()
{
	FILE *fp,*fp1;
	struct STUDENT s;
	int id,found=0;
	
	fp=fopen("LMS_Project.DAT","rb");
	fp1=fopen("temp.dat","wb");
	
	printf("\nEnter Student Roll no. you want to Modify : ");
	scanf("%d",&id);
	
	while(1)
	{
		fread(&s,sizeof(s),1,fp);
		
		if(feof(fp))
		{
			break;
		}
		if(s.roll_no==id)
		{
			found=1;
			printf("\nEnter Roll no. for record : ");
			scanf("%d",&s.roll_no);	
			printf("Enter Name : ");
			scanf("%s",s.name);
			printf("Enter Age : ");
			scanf("%d",&s.age);
			printf("Enter English marks : ");
			scanf("%d",&s.eng);
			printf("Enter Maths marks : ");
			scanf("%d",&s.maths);
			printf("Enter Physics marks : ");
			scanf("%d",&s.physics);
			printf("Enter Chemistry marks : ");
			scanf("%d",&s.chemistry);
			s.total=s.maths+s.physics+s.chemistry;
			s.avg=s.total/3;
			fwrite(&s,sizeof(s),1,fp1);
		}
		else
		{
			fwrite(&s,sizeof(s),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	if(found==0)
	{
		printf("Sorry!! No Record Found ):\n\n");
	}
	else
	{
		fp=fopen("LMS_Project.DAT","wb");
		fp1=fopen("temp.dat","rb");
	
		while(1)
		{
			fread(&s,sizeof(s),1,fp1);
			
			if(feof(fp1))
			{
				break;
			}
			fwrite(&s,sizeof(s),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
//-------------------------------------------------

void changePassword()
{
	FILE *fp;
	int i;
	char ch[6],c[6],count=0;
	fp=fopen("password.txt","w");
	printf("\nEnter New password with 6 character : ");
	scanf("%s",ch);
	printf("\nRe-enter password : ");
	scanf("%s",c);
	for(i=0;i<6;i++)
	{
		if(ch[i]==c[i])
		count++;
	}
	if(count==6)
	{
		fprintf(fp,"%s",ch);
		printf("\nPassword successfully changed (:");
	}
	else
	{
		printf("\nNot matching!!\n");
		changePassword();
	}	
	fclose(fp);
}


 

