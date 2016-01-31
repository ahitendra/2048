/*Hitendra Arvapalli*/
/*19/08/2014*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4

int main()
{
	srand(time(0));
	char dir;
	int i,j,k,l,flag,cnt,win,ch,r,ctr,into,r1,r2,len,menu;
	int mat[N][N];
	long int score,high;
	win=0;
	cnt=0;
	ctr=1;
	score=0;
	high=0;
	menu=0;
	FILE *fp;
	fp=fopen("2048_highest_score.txt","r");
	len=0;
	if (fp != NULL)
	{
		fscanf(fp,"%ld",&high);
	}
	fclose(fp);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			mat[i][j]=0;
		}
	}
	for(1;1;1)
	{
		r=rand()%5;
		if(r==4||r==2)
		{
			r1=rand()%N;
			r2=rand()%N;
			if(mat[r1][r2]==0)
			{
				mat[r1][r2]=r;
				cnt=cnt+1;
			}
		}
		if(cnt==2)
		break;
	}
		
	for(1;1;1)
	{
		into=0;
		ch=0;
		system("clear");
		cnt=0;
		if(menu==0)
		{
			printf("\tW-->Up\n");
			printf("A-->Left\tD-->Right\t\t\n");
			printf("\tS-->Down\nExit-->5\t\t  Score : %ld\tHighest Score : %ld",score,high);
		}
		menu++;
		if(high<score)
		high=score;
		if(menu>1)
		printf("\n\n\nExit-->5\t\t  Score : %ld\tHighest Score : %ld",score,high);				
		printf("\n\n\n\t\t\t\t");
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				printf("%d    ",mat[i][j]);
			}
			printf("\n\n\t\t\t\t");
		}
		
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(mat[i][j]==2048)
				{
					win=1;
					break;
				}
			}			
		}
		scanf("%c",&dir);
		if(dir=='5')
		break;
		else if(dir=='d'||dir=='D')
		{
			//printf("it is right\n");
			into=1;
			for(i=0;i<N;i++)
			{
				for(j=N-1;j>0;j--)
				{
					if(mat[i][j]==mat[i][j-1]&&mat[i][j]!=0)
					{
						mat[i][j]=mat[i][j]*2;
						mat[i][j-1]=0;
						ch=1;
						score=score+mat[i][j];
					}
					else if(mat[i][j-1]==0&&mat[i][j]!=0)
					{
						flag=0;
						for(l=j-1;l>=0;l--)
						{
							if(mat[i][l]!=0)
							{
								if(mat[i][j]==mat[i][l])
								{
									flag=1;
									break;
								}
								else 
								{
									flag=0;
									break;
								}
							}
						}
						if(flag)
						{
							mat[i][j]=mat[i][j]*2;
							mat[i][l]=0;
							ch=1;
							score=score+mat[i][j];
						}
					}
					
				}	
				for(j=N-1;j>0;j--)
				{
					flag=0;
					if(mat[i][j]==0)
					{
						for(l=j;l>=0;l--)
						{
							if(mat[i][l]!=0)
							{
								flag=1;
								break;
							}
						}
						
						if(flag)
						{
							mat[i][j]=mat[i][l];
							mat[i][l]=0;
							ch=1;
						}
					}
				}
			}
		}
	
		else if(dir=='a'||dir=='A')
		{
			into=1;
			//printf("it is left\n");
			for(i=0;i<N;i++)
			{
				for(j=0;j<N-1;j++)
				{
					if(mat[i][j]==mat[i][j+1]&&mat[i][j]!=0)
					{
						mat[i][j]=mat[i][j]*2;
						mat[i][j+1]=0;
						ch=1;
						score=score+mat[i][j];
					}
					else if(mat[i][j+1]==0&&mat[i][j]!=0)
					{
						flag=0;
						for(l=j+1;l<N;l++)
						{
							if(mat[i][l]!=0)
							{
								if(mat[i][j]==mat[i][l])
								{
									flag=1;
									break;
								}
								else
								{
									flag=0;
									break;
								}
							}
						}
						if(flag)
						{
							mat[i][j]=mat[i][j]*2;
							mat[i][l]=0;
							ch=1;
							score=score+mat[i][j];
						}
					}
				}
				for(j=0;j<N-1;j++)
				{
					flag=0;
					if(mat[i][j]==0)
					{
						for(l=j;l<N;l++)
						{
							if(mat[i][l]!=0)
							{
								flag=1;
								break;
							}
						}
						if(flag)
						{
							mat[i][j]=mat[i][l];
							mat[i][l]=0;
							ch=1;
						}
					}
				}
			}
		}
	
		else if(dir=='w'||dir=='W')
		{
			into=1;
			//printf("it is up\n");
			for(j=0;j<N;j++)
			{
				for(i=0;i<N-1;i++)
				{
					if(mat[i][j]==mat[i+1][j]&&mat[i][j]!=0)
					{
						mat[i][j]=mat[i][j]*2;
						mat[i+1][j]=0;
						ch=1;
						score=score+mat[i][j];
					}
					else if(mat[i+1][j]==0&&mat[i][j]!=0)
					{
						flag=0;
						for(l=i+1;l<N;l++)
						{
							if(mat[l][j]!=0)
							{
								if(mat[i][j]==mat[l][j])
								{
									flag=1;
									break;
								}
								else
								{
									flag=0;
									break;
								}
							}
						}
						if(flag)
						{
							mat[i][j]=mat[i][j]*2;
							mat[l][j]=0;
							ch=1;
							score=score+mat[i][j];
						}
					}
				}

				for(i=0;i<N-1;i++)
				{
					flag=0;
					if(mat[i][j]==0)
					{
						for(l=i;l<N;l++)
						{
							if(mat[l][j]!=0)
							{
								flag=1;
								break;
							}
						}
						if(flag)
						{
							mat[i][j]=mat[l][j];
							mat[l][j]=0;
							ch=1;
						}
					}
				}
			}
		}
	
		else if(dir=='s'||dir=='S')
		{
			into=1;
			//printf("it is down\n");
			for(j=0;j<N;j++)
			{
				for(i=N-1;i>0;i--)
				{
					if(mat[i][j]==mat[i-1][j]&&mat[i][j]!=0)
					{
						mat[i][j]=mat[i][j]*2;
						mat[i-1][j]=0;
						ch=1;
						score=score+mat[i][j];
					}
					else if(mat[i-1][j]==0&&mat[i][j]!=0)
					{
						flag=0;
						for(l=i-1;l>=0;l--)
						{
							if(mat[l][j]!=0)
							{
								if(mat[i][j]==mat[l][j])
								{
									flag=1;
									break;
								}
								else
								{
									flag=0;
									break;
								}
							}
						}
						if(flag)
						{
							mat[i][j]=mat[i][j]*2;
							mat[l][j]=0;
							ch=1;
							score=score+mat[i][j];
						}
					}
				}
				for(i=N-1;i>0;i--)
				{
					flag=0;
					if(mat[i][j]==0)
					{
						for(l=i;l>=0;l--)
						{
							if(mat[l][j]!=0)
							{
								flag=1;
								break;
							}
						}
						if(flag)
						{
							mat[i][j]=mat[l][j];
							mat[l][j]=0;
							ch=1;
						}
					}
				}
			}
		}
		if(into==1)
		{
			ctr=0;
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
				{
					if(mat[i][j]==0)
					{
						ctr=1;
						break;
					}
				}			
			}
			cnt=0;
			if(ctr==1&&ch==1)
			{
				while(cnt<1)
				{
					r=1+rand()%4;
					if(r==2||r==4)
					{
						r1=rand()%N;
						r2=rand()%N;
						if(mat[r1][r2]==0)
						{
							mat[r1][r2]=r;
							cnt=cnt+1;
						}
					}
				}
			}
		}
		if(ctr==0)
		{
			break;
		}
	}
	if(high>=score)
	{
		fp=fopen("2048_highest_score.txt","wb");
		fprintf(fp,"%ld\n",high);
		fclose(fp);
	}
	if(win==1)
	{
		printf("\n\n\t\t\tYOU WIN!!!\n\n");
		return 0;
	}
	if(dir=='5')
	{
		printf("\n\n\t\t\tBye! Bye!\n\n");
		return 0;
	}
	else
	{
		printf("\n\n\t\t\tYOU LOOSE :/\n\n");
		return 0;
	}
}