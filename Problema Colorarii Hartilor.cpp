#include <iostream>
using namespace std;
int x[100], k, n, m, as, es, a[100][100], i, j;
void valid(int x[], int k, int& es)
{
	int i;
	es = 1;
	for (i = 1; i <= k - 1; i++)
		if (a[k][i] == 1 && x[i] == x[k])
			es = 0;
}
void succ(int x[], int k, int& as)
{
	if (x[k] < m)
	{
		x[k]++;
		as = 1;
	}
	else
		as = 0;
}
void afis(int x[], int k)
{
	int i;
	for (i = 1; i <= k; i++)
		cout << x[i] << " ";
	cout << endl;
}
int main()
{
	cout << "Number of countries="; cin >> n;
	cout << "The relationship between countries: \n";
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
		{
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	cout << "Number of colors to be used="; cin >> m;
	k = 1;
	x[k] = 0;
	while (k > 0)
	{
		do
		{
			succ(x, k, as);
			if (as)
				valid(x, k, es);
		} while (as && !es);
		if (as)
		{
			if (k == n)
				afis(x, k);
			else
			{
				k++;
				x[k] = 0;
			}
		}
		else
			k--;
	}
}

