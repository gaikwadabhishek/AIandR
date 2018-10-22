#include <iostream>
using namespace std;

int calcCost (int ArrayOfCities[], const int NUM_CITIES) 
{
	int c = 0;
	for (int i = 0; i < NUM_CITIES; ++i)
	{
		for (int j = i + 1; j < NUM_CITIES; ++j)
		{
			if (ArrayOfCities[j] < ArrayOfCities[i])
			{
				c++;
				
			}
		}
	}
	cout<<"cost is :"<<c<<"\n";
	return c;
}

void SwapElements (int ArrayOfCities[], int i, int j)
{
	int temp = ArrayOfCities[i];
	ArrayOfCities[i] = ArrayOfCities[j];
	ArrayOfCities[j] = temp;
}

int main()
{
	const int CITIES =6;
	int iIndex = 1;
	int ArrayOfCities[CITIES];

	for (int i = 0; i < CITIES; ++i)
	{

		cout << "Enter distance for city " << iIndex << endl;
		cin >> ArrayOfCities[i];
		++iIndex;
	}

	int bestCost = calcCost(ArrayOfCities, CITIES);
	int iNewCost = 0, iSwaps = 0;
	while (bestCost > 0) 
	{
		for (int i = 0; i < CITIES - 1; ++i)
		{
			SwapElements(ArrayOfCities, i, i + 1);
			iNewCost = calcCost(ArrayOfCities, CITIES);
			if (bestCost > iNewCost)
			{
				++iSwaps;
				cout << "Performing Swap: " << iSwaps << endl;
				for (int i = 0; i < CITIES; ++i)
				{
					cout << ArrayOfCities[i] << "->";
				}

				cout << "\n";
				bestCost = iNewCost;
			}
			else
			{
				SwapElements(ArrayOfCities, i, i + 1);
			}
		}
	}
	
	cout << "\nFinal Route: \n";
	for (int i = 0; i < CITIES; i++)
	{
		cout << ArrayOfCities[i] << endl;
	}
}