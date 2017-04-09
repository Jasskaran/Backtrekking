#include <iostream>
#include <vector>

using namespace std;

bool fillBoard(vector<vector<int> > &board,int n,int row,int col,int step)
{
	if(step==(n*n)+1)
		return true;
	if(row<0 || row>=n || col<0 || col>=n || board[row][col]!=0)
		return false;

	board[row][col]=step;

	if(fillBoard(board,n,row+2,col+1,step+1))
		return true;
	if(fillBoard(board,n,row+2,col-1,step+1))
		return true;
	if(fillBoard(board,n,row-2,col+1,step+1))
		return true;
	if(fillBoard(board,n,row-2,col-1,step+1))
		return true;
	if(fillBoard(board,n,row+1,col+2,step+1))
		return true;
	if(fillBoard(board,n,row-1,col+2,step+1))
		return true;
	if(fillBoard(board,n,row+1,col-2,step+1))
		return true;
	if(fillBoard(board,n,row-1,col-2,step+1))
		return true;
	board[row][col]=0;
	return false;
}

void printBoard(vector<vector<int> > &board,int n)
{
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<n;j++)
			cout<<board[i][j]<<"	";
		cout<<endl;
	}
}

void solveKT(int n)
{
	vector<vector<int> > board(n,vector<int>(n));
	if(fillBoard(board,n,0,0,1)==false)
		return ;
	printBoard(board,n);
}

int main()
{
	int n;
	cin>>n;
	solveKT(n);
}