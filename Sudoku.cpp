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
				cout<< D[i][j] <<" ";
			else
				cout<< D[i][j]<<endl;			
		}
}
void Sudoku::readIn()
{
	int i,j;
	int H[9][9]={0};
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			cin>>H[i][j];
			K[i][j]=H[i][j];
			A[i][j]=H[i][j];
			Q[i][j]=H[i][j];
			T[i][j]=H[i][j];
		}
}
bool Sudoku::check(int O[9][9],int nextblank, int num)
{
	int i;
	int col=nextblank%9;
	int row=nextblank/9;
	for(i=0;i<9;i++)
		if(O[row][i]==num||O[i][col]==num)
			return false;	
	for(i=0;i<3;i++)
		if(O[(row/3)*3][i+(col/3)*3]==num||O[i+(row/3)*3][(col/3)*3]==num)
			return false;
	return true;
}
int Sudoku::findblank(int blank)
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
	if(firstcheck()==1)
		return ;
	solvesudoku(0);
	print(C);
}
int Sudoku::firstcheck()
{
	   int i,j;
	      for(i=0;i<9;i++)
			  for(j=0;j<9;j++)
			  {
				  if(T[i][j]!=0)
				  {
					  Q[i][j]=-1;
					  if(!check(Q,i*9+j,T[i][j]))
					  {
						  cout<<0<<endl;
						  return 1;
					  }
					  Q[i][j]=T[i][j];
				  }
			  }
		  return 0;
}
int Sudoku::finalcheck()
{
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			V[i][j]=A[i][j];
	S[i][j]=A[i][j];
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			V[i][j]=-1;
			if(!check(V,i*9+j,S[i][j]))																			              
			{				
				cout<<0<<endl;
				return 1;
			}
			V[i][j]=S[i][j];
		}
	return 0;
}
int Sudoku::solvesudoku(int blank)
{
	int nextblank=findblank(blank);
	int i,j,num;
	if(p>1)
		return 0;
	if(nextblank==81)
	{
		if(firstcheck()==0)
		{
			p++;
			for (i=0; i<9; i++)
				for (j=0; j<9; j++)
					C[i][j]=A[i][j];
			return 0;
		}
		else 
			return 0;
	}
	for(num=1;num<=9;num++)
	{
		if(check(A,nextblank,num))
		{
			A[nextblank/9][nextblank%9]=num;
			if(solvesudoku(nextblank+1)==1)
				return 1;
			A[nextblank/9][nextblank%9]=0;
		}
	}
	return 0;
}
void Sudoku::print(int G[9][9])
{
	int i,j;
	cout << p << endl;
	if(p==0||p==2)
		return;				
	output(G);
}
void Sudoku::changeNum(int a, int b)
{
	int i, j, B[9][9]={0};
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			B[i][j]=K[i][j];
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(B[i][j]==a)
				K[i][j]=b;	 	  
			if(B[i][j]==b)
				K[i][j]=a;
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
					B[0][j]=K[k+6][j];
					K[k+6][j]=K[k][j];
					K[k][j]=B[0][j];
				}	   
				else if(a+b==2)
				{		   
					B[0][j]=K[k+6][j];
					K[k+6][j]=K[k][j]; 
					K[k][j]=B[0][j];
				}			 
				else if(a+b==3)
				{
					B[0][j]=K[k+6][j];
					K[k+6][j]=K[k+3][j];
					K[k+3][j]=B[0][j];
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
					B[i][0]=K[i][k+3];
					K[i][k+3]=K[i][k];
					K[i][k]=B[i][0];


				
				}	
				else if(a+b==2)	
				{
					B[i][0]=K[i][k+6];
					K[i][k+6]=K[i][k];
					K[i][k]=B[i][0];
				}
				else if(a+b==3)
				{    
					B[i][0]=K[i][k+6];
					K[i][k+6]=K[i][k+3];
					K[i][k+3]=B[i][0];
				}
			}   
		}
}
void Sudoku::rotate(int n)
{
	int i,j,k, B[9][9]={0};
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			B[i][j]=K[i][j];	
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(n%4==2) 
				K[j][8-i]=B[i][j];
			else if(n%4==3)
				K[8-i][8-j]=B[i][j];
			else if(n%4==0)
				K[8-j][i]=B[i][j]; 
		}
}
void Sudoku::flip(int n)
{
	int i,j,k, B[9][9]={0};
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			B[i][j]=K[i][j];	
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			if(n==0) 
				K[8-i][j]=B[i][j];
			else if(n==1){
				K[i][8-j]=B[i][j];}
		}
}	
void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
void Sudoku::transform()
{
	change();
	output(K);
}
