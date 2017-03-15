#include<stdio.h>
#include<conio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int uc=0,lc=0,no=0,sc=0;
	char ch;
	//clrscr();

	fp=fopen("test.txt","r");
	if(fp==NULL)
	{
		printf("File opening error\n");
		return 0;
	}
       //	i=0;
	while(feof(fp)==0)
	{

		fscanf(fp,"%c\n",&ch);
		printf("%d ",ch);
		if(ch>='A' && ch<='Z')
		 {	uc++;
			}
		else if(ch>='a' && ch<='z')
		  {	lc++;}
		else if(ch>='0' && ch<='9')
		  {	no++; }
		else
			sc++;
	}
	fclose(fp);
	printf("\nUppercase characters - %d",uc);
	printf("\nLowercase characters - %d",lc);
	printf("\nSpecial characters - %d",sc);
	printf("\nNumerals - %d",no);
	getch();
	return 0;
}
