#include <iostream>
#include <stack>

using namespace std;

struct TP
{
	unsigned short num;
	short left;
	short right;

	void method(void)
	{
		left = -1;
		right = -1;
		return;
	}
};

TP persons[3002];
short n;

void Define(short ind)
{
	short def = 0;
	while (1)
	{
		if (persons[def].num > persons[ind].num)
		{
			if (persons[def].left >= 0)
			{
				def = persons[def].left;
			}
			else
			{
				persons[def].left = ind;
				return;
			}
		}
		else
		{
			if (persons[def].right >= 0)
			{
				def = persons[def].right;
			}
			else
			{
				persons[def].right = ind;
				return;
			}
		}
	}
}

int main(void)
{
	cin >> n;

	for (int i=n-1; i>=0; i--)
	{
		cin >> persons[i].num;
		persons[i].method();
	}

	for (int i=1; i<n; i++)
		Define(i);

	stack<int> S;
	stack<bool> W;

	S.push(0);
	int i = 1;
	while (i < n)
	{
		if (persons[S.top()].right >= 0)
		{
			S.push(persons[S.top()].right);
			W.push(true);
		}
		else if (persons[S.top()].left >= 0)
		{
			S.push(persons[S.top()].left);
			W.push(false);
		}
		else
		{
			cout << persons[S.top()].num << " ";
			S.pop();
			if (W.top())
				persons[S.top()].right = -1;
			else
				persons[S.top()].left = -1;
			W.pop();
			i++;
		}
	}
	cout << persons[0].num;

	return 0;
}