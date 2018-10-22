#define N 8
#include<iostream>

using namespace std;

void printSolution(int board[N][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

bool isSafe(int board[N][N], int row, int col){
	int i,j;

	for(i = row, j = 0; j < col; j++)
		if(board[i][j] == 1) return false;

	for(i = row, j = col; i >=0 && j >= 0; i--,j--)
		if(board[i][j] == 1) return false;

	for(i = row, j = col; i < N && j >=0; i++, j--)
		if(board[i][j] == 1) return false;
	
	return true;
}


bool solveNQUtil(int board[N][N], int col){
	//int i,j;

	if(col >= N)
		return true;

	for(int i = 0; i < N; i++){
		if(isSafe(board,i,col))
		{
			board[i][col] = 1;
			if(solveNQUtil(board, col+1))
				return true;
			board[i][col] = 0;
		}	
	}
	return false;
}

bool solveNQ(){
	int board[N][N] = {0};
	if(!solveNQUtil(board,0)){
		cout<<"\nSolution for the given problem does not exist..."<<endl;
		return false;
	}
	
	printSolution(board);
	return true;
}


int main(void){
	
	solveNQ();
	return 0;
}
