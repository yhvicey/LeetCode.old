#include <string>
using namespace std;

int romanToInt(string s)
{
	string groups[4]{ "","","","" };
	int len = s.length();
	int i = 0;
	for (; (i < len) && (s[i] == 'M'); i++)
	{
		groups[0] += s[i];
	}
	for (; (i < len) && (s[i] == 'C' || s[i] == 'D' || s[i] == 'M'); i++)
	{
		groups[1] += s[i];
	}
	for (; (i < len) && (s[i] == 'X' || s[i] == 'L' || s[i] == 'C'); i++)
	{
		groups[2] += s[i];
	}
	for (; (i < len) && (s[i] == 'I' || s[i] == 'V' || s[i] == 'X'); i++)
	{
		groups[3] += s[i];
	}

	int result = 0;
	if (groups[0] == "")
	{
		result += 0;
	}
	if (groups[0] == "M")
	{
		result += 1000;
	}
	if (groups[0] == "MM")
	{
		result += 2000;
	}
	if (groups[0] == "MMM")
	{
		result += 3000;
	}

	if (groups[1] == "")
	{
		result += 0;
	}
	if (groups[1] == "C")
	{
		result += 100;
	}
	if (groups[1] == "CC")
	{
		result += 200;
	}
	if (groups[1] == "CCC")
	{
		result += 300;
	}
	if (groups[1] == "CD")
	{
		result += 400;
	}
	if (groups[1] == "D")
	{
		result += 500;
	}
	if (groups[1] == "DC")
	{
		result += 600;
	}
	if (groups[1] == "DCC")
	{
		result += 700;
	}
	if (groups[1] == "DCCC")
	{
		result += 800;
	}
	if (groups[1] == "CM")
	{
		result += 900;
	}

	if (groups[2] == "")
	{
		result += 0;
	}
	if (groups[2] == "X")
	{
		result += 10;
	}
	if (groups[2] == "XX")
	{
		result += 20;
	}
	if (groups[2] == "XXX")
	{
		result += 30;
	}
	if (groups[2] == "XL")
	{
		result += 40;
	}
	if (groups[2] == "L")
	{
		result += 50;
	}
	if (groups[2] == "LX")
	{
		result += 60;
	}
	if (groups[2] == "LXX")
	{
		result += 70;
	}
	if (groups[2] == "LXXX")
	{
		result += 80;
	}
	if (groups[2] == "XC")
	{
		result += 90;
	}

	if (groups[3] == "")
	{
		result += 0;
	}
	if (groups[3] == "I")
	{
		result += 1;
	}
	if (groups[3] == "II")
	{
		result += 2;
	}
	if (groups[3] == "III")
	{
		result += 3;
	}
	if (groups[3] == "IV")
	{
		result += 4;
	}
	if (groups[3] == "V")
	{
		result += 5;
	}
	if (groups[3] == "VI")
	{
		result += 6;
	}
	if (groups[3] == "VII")
	{
		result += 7;
	}
	if (groups[3] == "VIII")
	{
		result += 8;
	}
	if (groups[3] == "IX")
	{
		result += 9;
	}

	return result;
}

int main()
{
	romanToInt("DCXXI");
}