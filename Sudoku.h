#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
class Sudoku
{
	public:
		void giveQuestion();
		void output(int D[][9]);
		void readIn();
		void solve();
		int finalcheck();
		int firstcheck();
		int solvesudoku(int blank);
		bool check(int O[9][9],int nextblank,int num);
		int findblank(int blank);
		void print(int G[9][9]);
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void change();
	private:
		int S[9][9],V[9][9],T[9][9],Q[9][9],K[9][9],C[9][9],A[9][9];
		int p;
};				
