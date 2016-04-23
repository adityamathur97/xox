#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char matrix[3][3],p='x',c='o';

void matrixFill();
void playerMove();
void compMove();
void dispGame();
void mainMenu();
void logo();
char checkStatus();

void logo()
{
	printf("\n\t\t\t\t\t\t\t\t\tXOX-By Cronox\n");
}

void mainMenu()
{
	printf("\n\t\t\t\t\t\t\t!Welcome to game of Tic-Tac-Toe!\n");
	printf("Enter your Symbol Choice (x-o):- ");
	scanf("%c",&p);
	if (p=='o')
	c='x';
	//clrscr();
}

void matrixFill()
{
	int i,j;
	for (i=0;i<3;i++)
	for (j=0;j<3;j++)
	matrix[i][j]=' ';
}

void dispGame()
{
	int i;
	for (i=0;i<3;i++)
	{
		printf("  %c |  %c | %c ",matrix[i][0],matrix[i][1],matrix[i][2]);
		if(i!=2)
		printf("\n----|----|----\n");
	}
	printf("\n");
}

/*void compMove()
{
	int i,j,flag=1;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		if (matrix[i][j]==' ')
		break;
	}
	if (flag)
	{
		printf("DRAW");
		exit(0);
	}
	else
	{
		label_2:
		i=rand();
		j=rand();
		if (i>=3 || j>=3 || matrix[i][j]==' ')
		goto label_2;
		matrix[i][j]=c;
    } 
}*/

void compMove()
{
	int i,j;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		if (matrix[i][j]==' ')
		break;
		if (matrix[i][j]==' ')
		break;
	}
	if (i*j==9)
	{
		printf("DRAW!");
		exit(0);
	}
	else
	matrix[i][j]=c;
}

void playerMove()
{
	int x,y;
	char sep;
	label_1:
	printf("Enter X & Y co-ordinate of your move :- ");
	scanf("%d%c%d",&x,&sep,&y);
	x--;
	y--;
	if (matrix[x][y]!=' ')
	{
		printf("Invalid Move!");
		goto label_1;
	}
	else
	matrix[x][y]=p;
}

char checkStatus()
{
	int i;
	for (i=0;i<3;i++)
	if (matrix[i][0]==matrix[1] && matrix[i][1]==matrix[i][2])
	return matrix[i][0];
	for (i=0;i<3;i++)
	if (matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i])
	return matrix[0][i];
	if ((matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2]) || (matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0]))
	return matrix[1][1];
}

int main()
{
	char flag=' ';
	logo();
	matrixFill();
	mainMenu();
	do
	{
		//clrscr();
		logo();
		dispGame();
		playerMove();
		flag=checkStatus();
		if (flag!=' ')
		break;
		compMove();
		flag=checkStatus();
	}while(flag==' ');
	if (flag==p)
	printf("YOU WON!");
	else
	printf("I WON!");
	logo();
	dispGame();
	return 0;
}
