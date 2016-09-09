using namespace std;

bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	int comp = 0;
	int temp = x;
	while (temp != 0)
	{
		comp = comp * 10 + temp % 10;
		temp = temp / 10;
	}
	return comp == x;
}

int main()
{
	isPalindrome(123321);
	return 0;
}