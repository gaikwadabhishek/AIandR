#include<iostream>
using namespace std;
#define MAX -10000
#define MIN 10000

int minimax(int depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta)
{

	if(depth == 3)
	{
		return values[nodeIndex];
	}

	if(maximizingPlayer)
	{
		int best = MAX;
		for(int i = 0; i < 2 ; i++)
		{
			int val = minimax(depth+1,nodeIndex*2+i,false,values,alpha,beta);
			best = max(val,best);
			alpha = max(best,alpha);

			if (beta<=alpha)
				break;
		}
		return best;
	}

	else
	{
			int best = MIN;
			for(int i = 0; i < 2 ; i++)
			{
				int val = minimax(depth+1,nodeIndex*2+i,true,values,alpha,beta);
				best = min(val,best);
				beta = min(best,alpha);

				if (beta<=alpha)
					break;
			}
			return best;
		}
	}


int main()
{
	int values[8] = { 3, 5, 6, 9, 1, 2, 0, -1 };
	cout <<"The optimal value is : "<< minimax(0, 0, true, values, MAX, MIN);;
    return 0;
}