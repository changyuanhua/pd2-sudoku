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
		int solve(int A[][9],int blank);
		bool check(int A[][9],int nextblank,int num);
		int findblank(int A[][9],int blank);
		int print(int A[][9]);
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void change;
	private:
		int C[9][9],A[][9];
		int p;
};				
