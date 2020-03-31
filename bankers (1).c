#include<stdio.h>
int n,m,s,count=0,ss[100],fi[100],p[100],all[100][100],max[100][100],need[100][100],ava[100],work[100];
int func(int i)
{
	int j;
	for(j=0;j<m;j++)
	{
		if(need[i][j]>work[j])
			return 0;	
	}
	return 1;
}
int main()
{
	printf("enter number of process\n");
	scanf("%d",&n);
	printf("Enter number of resources\n");
	scanf("%d",&m);
	int i,j,a;
	printf("Enter the numbers of process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		fi[i]=0;
	}
	printf("Enter the resources alloted for each process accordingly\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the resources alloted for p[%d]\n",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&all[i][j]);
		}
		printf("\n");
	}
	printf("Enter the maximum no.of resources needed for each process accordingly\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the maximum no.of resources needed for p[%d]\n",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
		printf("\n");
	}
	printf("enter the available resources\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&ava[i]);	
	}
	for(i=0;i<m;i++)
	{
		work[i]=ava[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-all[i][j];
		}
	}
	printf("process\t\tallocation\t\tmax\t\t\tneed\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",p[i]);
		for(j=0;j<m;j++)
		{
			printf("%d ",all[i][j]);
		}
		printf("\t\t");
		for(j=0;j<m;j++)
		{
			printf("%d ",max[i][j]);
		}
		printf("\t\t");
		for(j=0;j<m;j++)
		{
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
	//for safe sequence
	while(count<n)
	{
		s=0;
		for(i=0;i<n;i++)
		{
			a=func(i);
			if(fi[i]==0 && a==1)
			{
				for(j=0;j<m;j++)
				{
					work[j]=work[j]+all[i][j];
				}
				ss[count]=i;
				count++;
				fi[i]=1;
				s=1;
			}
		}
		if(s==0)
		{
			printf("\nSystem is not in safe sequence\n");
			break;
		}
	}
	if(s==1)
	{
		printf("\nSystem is in safe sequence and the sequence is: <");	
	}
	for(i=0;i<n;i++)
		{
				printf("p[%d],",ss[i]);
			
		}
	printf("\n");
	
	return 0;
}

