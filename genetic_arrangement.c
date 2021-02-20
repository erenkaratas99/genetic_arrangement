//genetik dizilim

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int i;
int j;
int n;
int k;
int genes[50][50];
int specGene[10] = {2, 2, 3, 1, 4, 1, 3, 4, 1, 2}; //special gene arrangement given 
int sum = 0;
int ratio[1000];
int org_i[1000];
int org_j[1000];
int temp;
int temp_i;
int temp_j;
int choice;
int choice_sec;
int wanted_ratio;
void Search(int z[50][50]); //the function that search the specific gene arrangement horizontally
void GenerateMatx(int x[50][50]); //the function that generates random matrix
void Display(int y[50][50]); //the function that displays the generated matrix

int main()
{	
	printf("Gene Matrix:\n");
	GenerateMatx(genes); 
	Display(genes);
	Search(genes);
	for(j=0;j<k;j++)
	{
		if(ratio[j]==10)
		{
			printf("\n!!!MATCH!!!\nHead Point(i,j) ==> (%d,%d)\t Similarity Ratio = 1\n\n",org_i[j],org_j[j]);
			temp_i = org_i[j];
			temp_i = org_i[j];
			for(n=0;n<10;n++)
			{
				printf("%d ",genes[temp_i][temp_j+n]);
			}
		}
	}
	int counter = 0;
	printf("Press '1'+Enter to see all the Similarity Ratio-Gene list.\nPress '2'+Enter to print a specific Similarity Ratio.\n");
	scanf("%d",&choice); //if choice is 1; all the list will computed with required infos.
	if(choice==1)
	{
		printf("\n\nHead points denote the current gene's zero point. CurrentGene[...][0] ---> CurrentGene[...][10]\n\n");
		for(i=0;i<k;i++)
		{
			printf("Head Point(i,j) ==> (%d,%d)\t Similarity Ratio = %.2f\n",org_i[i],org_j[i],(float)ratio[i]/10);
			temp_i = org_i[i];
			temp_j = org_j[i];
 			for(j=0;j<10;j++)
			{
				printf("%d ",genes[temp_i][temp_j+j]);
			}
			printf("\n***************\n\n");
		}
	
	}
	else if(choice==2) // if choice is 2 the program will ask the what ratio to compute
	{
		printf("Please enter the similarity ratio between 4-10. (Similarity ratios under 4 considered as non-matching)\n");
		scanf("%d",&wanted_ratio); 
		while(wanted_ratio<4 || wanted_ratio>10 )
		{
			printf("Please enter an another similarity ratio between 4-10\n");
			scanf("%d",&wanted_ratio);
		}
		for(n=0;n<k;n++)
		{
			if(ratio[n]==wanted_ratio)
			{
				counter++; //this is an feedback mechanism for checking whether if there is an match in the entered ratio
			}			
		}
		if(counter!=0) //while counter != 0 there are always at least one match
		{
			for(j=0;j<k;j++)
			{
				if(ratio[j]==wanted_ratio)
				{
					printf("\nHead Point(i,j) ==> (%d,%d)\t Similarity Ratio = %.2f\n",org_i[j],org_j[j],(float)wanted_ratio/10);
					temp_i = org_i[j];
					temp_j = org_j[j];
					n = 0;
					for(n;n<10;n++)
					{
						printf("%d ",genes[temp_i][temp_j+n]);
					}
					printf("\n***************\n\n");
					
				}
				
			}
		}
		else
		{
			printf("No match found with this ratio!\n");
			
			
		}
	}
	
	
	return 0;
}

void GenerateMatx(int x[50][50])
{
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			x[i][j] = (rand() %4) + 1;
		}
	}
}

void Display(int y[50][50])
{
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			printf("%d ",y[i][j]);
		}
		printf("\n");
	}
}

void Search(int z[50][50])
{	k=0;
	for(i=0;i<50;i++) 
	{
		for(j=0;j<50;j++)
		{
			if(z[i][j] == specGene[0] && 50-j>=10) //if function detect a match at first index...
			{										//starts searching
				n =0;
				temp = j;
				for(temp;temp-j<10;temp++)
				{
					if(z[i][temp] == specGene[0+n])
					{
						
						sum = sum+1; //when program finds another match at the same index order...
									 //adds 1 to summation; summation will give us the ratio later 			
					}
					n = n+1;
				}
				if(sum>4)
				{
					ratio[k] = sum; //if sum>=4 that means our founded gene arrangement is meaningful (given in the question)
					org_i[k] = i; //I'm storing the coordinates the first index of meaningful gene to compute later
					org_j[k] = j;
					
					k = k+1; //and increasing the index by 1 for next turn
				}
				
				sum = 0; //zeroize the sum for next turn 
			}
		}
	}
}













