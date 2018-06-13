#include<stdio.h>

int moc=10;

void rowop(float*,int,int,int,int);

void row0(float*,int,int);

void rowic(float*,int,int,int);

int main()
{
	float a[moc][moc];
	int n[2],i,j,r1,r2,c;
	printf("Enter number of rows:");
	scanf("%d",&n[0]);
	printf("Enter number of coloums:");
	scanf("%d",&n[1]);
	for(i=0;i<n[0];i++)
	{
		for(j=0;j<n[1];j++)
		{
			printf("Enter (%d,%d) element",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	/*r1=0;
	r2=1;
	c=0;
	rowop(&a[0][0],r1,r2,c,n);
	row0(&a[0][0],n);*/
	/*
	for(r1=0;r1<n;r1++)
	{
		row0(&a[0][0],n);
		for(c=0;c<n;c++)
		{
			if(a[r1][c]!=0)
			{
				for(r2=r1+1;r2<n;r2++)
				{
					if(a[r2][c]!=0)
					{
						rowop(&a[0][0],r1,r2,c,n);
					}
				}
				c=n;
			}
		}
	}
	*/
	for(c=0,r1=0;c<n[1];c++)
	{
		row0(&a[0][0],n[0],n[1]);
			if(a[r1][c]==0)
			{
				for(r2=r1+1;r2<n[0];r2++)
				{
					if(a[r2][c]!=0)
					{
						rowic(&a[0][0],r1,r2,n[1]);
						r2=n[0];
					}
				}
			}
		if(a[r1][c]!=0)
		{
			for(r2=r1+1;r2<n[1];r2++)
			{
				if(a[r2][c]!=0)
				{
					rowop(&a[0][0],r1,r2,c,n[1]);
				}
			}
			r1++;
		}
	}
	for(i=0;i<n[0];i++)
	{
		for(j=0;j<n[1];j++)
		{
			printf("%f\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void rowop(float *a,int r1,int r2,int c,int n)
{
	int c1;
	float x;
	x=(*((a+r2*moc)+c))/(*((a+r1*moc)+c));
	for(c1=0;c1<n;c1++)
	{
		*((a+r2*moc)+c1)=(*((a+r2*moc)+c1))-((*((a+r1*moc)+c1))*x);
	}
}

void row0(float *a,int n1,int n)
{
	int count,i,j;
	for(count=0,i=0;i<n1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*((a+i*moc)+j)!=0)
			{
				count++;
			}
		}
		if(count==0)
		{
			for(j=0;j<n;j++)
			{
				*((a+i*moc)+j)=(*((a+i*moc)+j))+(*((a+(n-1)*moc)+j));
				*((a+(n-1)*moc)+j)=(*((a+i*moc)+j))-(*((a+(n-1)*moc)+j));
				*((a+i*moc)+j)=(*((a+i*moc)+j))-(*((a+(n-1)*moc)+j));
			}
		}
	}
	
}

void rowic(float *a,int r1,int r2,int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		*((a+r1*moc)+j)=(*((a+r1*moc)+j))+(*((a+r2*moc)+j));
		*((a+r2*moc)+j)=(*((a+r1*moc)+j))-(*((a+r2*moc)+j));
		*((a+r1*moc)+j)=(*((a+r1*moc)+j))-(*((a+r2*moc)+j));
	}
}

