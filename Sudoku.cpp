#include "Sudoku.h"
void Sudoku::giveQuestion()
{
	int i,j;
	int E[9][9]={{0,2,1,0,6,0,5,9,0},
		{0,0,0,0,0,0,0,0,2},
		{4,0,0,2,0,5,0,6,3},
		{3,0,7,6,0,0,0,0,0},
		{0,9,5,0,0,0,3,2,0},
		{0,0,0,0,0,3,7,0,1},
		{9,3,0,4,0,2,0,0,7},
		{5,0,0,0,0,0,0,0,0},
		{0,1,2,0,9,0,0,3,0},};
	output(E);
}
void Sudoku::output(int D[][9])
{
    int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(j!=8)
				cout<<" "<< D[i][j] ;
			else
				cout<<" "<< D[i][j]<<endl;			
		}
}
void Sudoku::readIn()
{
	int i,j;
	int F[9][9]={0};
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			cin>>A[i][j];
}
bool Sudoku::check(int A[][9], int nextblank, int num)
{
	int i;
	int col=nextblank%9;
	int row=nextblank/9;
	for(i=0;i<9;i++)
		if(A[row][i]==num||A[i][col]==num)
			return false;	
	for(i=0;i<3;i++)
		if(A[(row/3)*3][i+(col/3)*3]==num||A[i+(row/3)*3][(col/3)*3]==num)
			return false;
	return true;
}
int Sudoku::findblank(int A[][9],int blank)
{
	int nextblank;
	for(nextblank=blank;nextblank<81;nextblank++)
	{
		if(A[nextblank/9][nextblank%9]==0)
			return nextblank;
	}
	return 81;
}	
void Sudoku::solve()
{
	solvesoduku(A,0);
	print(C);
}
int Sudoku::solvesoduku(int A[][9],int blank)
{
    int nextblank=findblank(A,blank);
	int i,j,num;
	if(p>1)
		return 0;
	if(nextblank==81)
	{
		p++;
		for (i=0; i<9; i++)
			for (j=0; j<9; j++)
				C[i][j]=A[i][j];
		return 0;
	}
	for(num=1;num<=9;num++)
	{
		if(check(A,nextblank,num))
		{
			A[nextblank/9][nextblank%9]=num;
			if(solve(A,nextblank+1)==1)
				return 1;
			A[nextblank/9][nextblank%9]=0;
		}

	}
	return 0;
}
void Sudoku::print(int A[][9])
{
	int i,j;
	cout << p << endl;
	if(p==0)
		return 0;				
	output(A);
}
void Sudoku::changeNum(int a, int b)
{
	int i, j, B[9][9]={0};
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			B[i][j]=A[i][j];
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(B[i][j]==a)
				A[i][j]=b;	 	  
			if(B[i][j]==b)
				A[i][j]=a;
	    }
}
void Sudoku::changeRow(int a, int b)
{
    int i,j,k, B[9][9]={0};
   	for(k=0;k<3;k++)
	 for(j=0;j<9;j++)
	 { 
		 if(a==b)
			 break;
		 else
		 {
			 if(a+b==1)
			 {
				 B[0][j]=A[k+6][j];
				 A[k+6][j]=A[k][j];
				 A[k][j]=B[0][j];
			 }	   
			 else if(a+b==2)
			 {		   
				 B[0][j]=A[k+6][j];
				 A[k+6][j]=A[k][j]; 
				 A[k][j]=B[0][j];
			 }			 
			 else if(a+b==3)
			 {
				 B[0][j]=A[k+6][j];
				 A[k+6][j]=A[k+3][j];
				 A[k+3][j]=B[0][j];
			 }
		 }
	 }      	 
}
void Sudoku::changeCol(int a,int b)
{
	int i,j,k, B[9][9]={0};
	for(i=0;i<9;i++)
		for(k=0;k<3;k++)
		{ 
			if(a==b)
				break;	
			else
			{	
				if(a+b==1)
				{
					B[i][0]=A[i][k+3];						
					A[i][k+3]=A[i][k];
					A[i][k]=B[i][0];
		
				}	
				else if(a+b==2)	
				{
					B[i][0]=A[i][k+6];
					A[i][k+6]=A[i][k];
					A[i][k]=B[i][0];
				}
				else if(a+b==3)
				{    
					B[i][0]=A[i][k+6];
					A[i][k+6]=A[i][k+3];
					A[i][k+3]=B[i][0];
				}
			}   
		}
}
void Sudoku::rotate(int n)
{
	int i,j,k, B[9][9]={0};
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			B[i][j]=A[i][j];	
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(n%4==2) 
				A[j][8-i]=B[i][j];
			else if(n%4==3)
				A[8-i][8-j]=B[i][j];
			else if(n%4==0)
				A[8-j][i]=B[i][j]; 
		}
}
void Sudoku::flip(int n)
{
	int i,j,k, B[9][9]={0};
    for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			B[i][j]=A[i][j];	
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(n==0)
			{ 
				A[8-i][j]=B[i][j];}
			else if(n==1){
				A[i][8-j]=B[i][j];}
		}
}	
void Sudoku::transform()
{
    readIn();
    change();
	output(A);
}
void Sudoku::change()
{
	srand((Null)):
	changeNun(rand()%9+1,rand()%9+1);
	changerow(rand()%3,rand()%3);
	changerow(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
