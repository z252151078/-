#include<iostream>
using namespace std;
void text(int a = 0, int b = 0, int c = 0)
{
	if (a > 1 && b == 0)
		c = c + a;
	if (a == 2 || c > 1)
		c++;
	cout << c;
}
int main()
{
	text(2, 0, 3);
	return 0;
}