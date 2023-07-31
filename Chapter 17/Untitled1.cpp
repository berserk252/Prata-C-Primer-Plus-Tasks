#include<iostream>
#include<algorithm>
#include<set>
#define SIZE 7
int n, deg[SIZE] = {0}, dom[SIZE][SIZE] = {0}, temp = 0;
void odd(int kost[][2], int n);
using namespace std;
int main() {
	cin >> n;
	int kost[n + 1][2];
	for(int i = 0; i != n; i++)
	{
		int x, y;
		cin >> x >> y;
		dom[x][deg[x]] = i + 1;
		dom[y][deg[y]] = i + 1;
		deg[x]++;
		deg[y]++;
		kost[i][0] = x;
		kost[i][1] = y;
		
	}
	int k = 0;
	for (int i = 0; i < SIZE; i++) 
		if (deg[i] % 2 == 1) 
			k++;
	if (k != 0 && k != 2) 
		cout << "No solution" << endl;
	
	int fold = 0;
	for(int i = 0; i < SIZE; i++)
	{
		if(deg[i] % 2 == 1 && deg[i] < deg[temp]);
		{
			fold++;
			temp = i;
		}
	}
	/*for(int i = 0; i < n; i++)
	{
		for(int y = 0; y < 2; y++)
		{
			cout << kost[i][y] << " ";
		}
		cout << endl;
	}
	cout << fold << " " << temp;*/
	if(fold > 0)
	{
		odd(kost, n);
	}
	else
	{
		
	}
	
	return 0;
}

void odd(int kost[][2], int n)
{
	int x, y, count1 = 0, count2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(kost[i][0] == temp)
		{
			x = i + 1;
			y = 0;
			break;
		}
		else if(kost[i][1] == temp)
		{
			x = i + 1;
			y = 1;
			break;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(y == 0)
		{
			cout << x << " +";
			temp = kost[x - 1][1];
		}
		else
		{
			cout << x << " -";
			temp = kost[x - 1][0];
		}
		cout <<endl;
		for(int i = 0; i < SIZE; i++) // delete array num x + 1
		{
			for(int j = 0; j < SIZE; j++)
			{
				if(dom[i][j] == x)
				{
					dom[i][j] = 0;
				}
			}
		}
		
		for(int l = 0; 1;l++)
		{
			int temp2;
			count1 = 0;
			count2 = 0;
			for(int i = 0;i < SIZE;i++)
			{
				if(dom[temp][i] > 0)
				{
					count1++;
					if(count1 == 1)
					{
						temp2 = dom[temp][i + l];
					}
					
				}
				
			}
			for(int i = 0;i < SIZE;i++)
			{
				if(dom[temp2][i] > 0)
				{
					count2++;
				}
			}
			if(count1 >= 1 && count2 > 1)
			{
				x = dom[temp][temp2 - 1] - 1;
				if(kost[x][0] == temp)
				{	
					y = 0;
				}
				else if(kost[x][1] == temp)
				{
					y = 1;
				}
				break;
			}
			else if(count1 < 1 && count2 < 1 && l != n)
			{
				cout << "No solution";
				break;
			}else if(count1 == 1 && count2 == 0 && l == n - 1)
			{
				x = dom[temp][temp2 - 1] - 1;
				if(kost[x][0] == temp)
				{	
					y = 0;
				}
				else if(kost[x][1] == temp)
				{
					y = 1;
				}
				break;
			}
			
			
		}
	
	}
	
	
	
	
}
