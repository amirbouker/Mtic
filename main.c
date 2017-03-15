#include<stdio.h>
#include<stdlib.h>
int Sod[10][10];
int Game[10];
//print matri 
void affiche(int Mat[10][10])
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		printf("\n_____________________________________________\n");
		for (j = 0; j < 9; j++)
		{

			printf("| %d |", Mat[i][j]);
		}
		printf("\n");
		printf("_____________________________________________");
	}
}
//creat matrix 
void creat(int Mat[10][10])
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			Mat[i][j] = 0;
		}
	}
}
//Test the Line 
int test1(int n,int Sod[10][10], int i)
{
	int k, test;
	test = 1;
	for (k = 0; k < 9; k++)
	{
		if (n == Sod[i][k])
		{
			test = 0;
		}
	}
	return test;
}
//test the colon
int test2(int n, int Sod[10][10], int j)
{
	int l, test;
	test = 1;
	for (l = 0; l < 9; l++)
	{
		if (n == Sod[l][j])
		{
			test = 0;
		}
	}
	return test;
}
//test matrice
int test3(int n, int Sod[10][10], int i, int j)
{
	int k, l, test, h, d;
	switch (i)
	{
	case 0 :
		k = 0;
		break;
	case 1:
		k = 0;
		break;
	case 2:
		k = 0;
		break;
	case 3:
		k = 3;
		break;
	case 4:
		k = 3;
		break;
	case 5:
		k = 3;
		break;
	case 6:
		k = 6;
		break;
	case 7:
		k = 6;
		break;
	case 8:
		k = 6;
		break;
	default:
		break;
	}
	switch (j)
	{
	case 0:
		l = 0;
		break;
	case 1:
		l = 0;
		break;
	case 2:
		l = 0;
		break;
	case 3:
		l = 3;
		break;
	case 4:
		l = 3;
		break;
	case 5:
		l = 3;
		break;
	case 6:
		l = 6;
		break;
	case 7:
		l = 6;
		break;
	case 8:
		l = 6;
		break;
	default:
		break;
	}
	test = 1;
	for (h = k; h < k+3; h++)
	{
		for (d = l; d < l+3; d++)
		{
			if (n == Sod[h][d])
			{
				test = 0;
				
			}

		}
	}
	return test;
}
//test last value
int test4(int Sod[10][10], int i)
{
	int k, s, test;
	s = 0;
	test = 1;
	for ( k = 0; k< 8; k++)
	{
		s = s + Sod[i][k];
	}
	s = 45 - s;
	if (test2(s, Sod, 8) == 0 )
	{
		test=0;
	}
	return test;
}
//level
void prep(int mat[10][10], int n)
{
	int i, j;
	int k = 0;
	do
	{
		i = rand() % 10;
		j = rand() % 10;
	} while (i==0||j==0);

	while (k <= n)
	{
		Game[i][j] = mat[i][j];
		do
		{
			i = rand() % 10;
			j = rand() % 10;
		} while (Game[i][j]!=0||i==9||j==9);
		k = k + 1;
	}
}
//check if it is true 
int check(int Game[10][10], int Sod[10][10], int i, int j, int n)
{
	if (Game[i][j] == Sod[j][j])
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
//ask for a position and a number 
void Ask(int Sod[10][10])
{
	int i, j, n;
	do
	{
		printf("donner la ligne a ? : \n");
		scanf_s("%d", &i);

	} while (i<9&&i>0);
	do
	{
	printf("donner la colone  ? : \n");
	scanf_s("%d", &j);
	} while (j>9 && j<0);
	do
	{
		printf("donner le nombre pour ligne %d colone %d",i,j);
		scanf_s("%d", &n);
	} while (n>9 && n< 0 && check(Game,Sod,i,j,n)==1);
}
//game end 
int finsh(int Sod[10][10], int Game[10][10])
{
	int j, i, test;
	test = 1;
	for ( i = 0; i < 9; i++)
	{
		for ( j = 0; j < 9; j++)
		{
			if (Game[i][j] != Sod[i][j]);
			{
				test = 0;
			}
		}
	}
	return test;
}

//main 
//--------------Game preparation ------------------
int main()
{
	
	int	i, j, n, c, lvl, dim;
	creat(Sod);

	for (i = 0; i < 9; i++)
	{
		j = 0;
		while (j<9)
		{
			c = 0;
			if ((j == 8) && (test4(Sod,i) == 0))
			{
				for (j = 0; j <9; j++)
				{
					Sod[i][j] = 0;
				}
				j = 0;

			}
			do
			{
				c = c + 1;
				n = rand()%10;
				if (c==50)
				{
					for (j = 0; j <9; j++)
					{
						Sod[i][j] = 0;
					}
					j = 0;

				}
			} while ((n == 0) ||
				(test1(n, Sod, i) == 0) ||
				(test2(n, Sod, j) == 0) ||
				(test3(n, Sod, i, j) == 0)
				);
			Sod[i][j]=n;
			j++;
		}
	}
	do
	{

		printf("Pick your level :\n");
		printf("	1:Easy\n");
		printf("	2:Medium\n");
		printf("	3:Hard \n");
		printf("	4:diabolical\n");
		printf("Please answer with [1,2,3,4]");
		scanf_s("%d", &lvl);

	} while (lvl<0&&lvl>5);
	switch (lvl)
	{
	case 1:
		dim= 40;
		break;
	case 2:
		dim = 35;
		break;
	case 3:
		dim = 30;
		break;
	case 4:
		dim = 20;
		break;
	default:
		break;
	}
	creat(Game);
	prep(Sod,dim);

	
	//--------------Thee Game ------------------
	printf("New Game ");
	affiche(Game);
	do
	{
		printf("\n");
		Ask(Sod);
		affiche(Game);
	} while (finsh==0);
	
	
	
	
	
	
	
	scanf_s("%d", &n);
}
