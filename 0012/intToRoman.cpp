#include <string>
using namespace std;

string intToRoman(int num)
{
	int thousand = num / 1000;
	int hundred = (num - thousand * 1000) / 100;
	int ten = (num - thousand * 1000 - hundred * 100) / 10;
	int single = num - thousand * 1000 - hundred * 100 - ten * 10;
	string result = "";

	switch (thousand)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			result += "M";
			break;
		}
		case 2:
		{
			result += "MM";
			break;
		}
		case 3:
		{
			result += "MMM";
			break;
		}
	}
	switch (hundred)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			result += "C";
			break;
		}
		case 2:
		{
			result += "CC";
			break;
		}
		case 3:
		{
			result += "CCC";
			break;
		}
		case 4:
		{
			result += "CD";
			break;
		}
		case 5:
		{
			result += "D";
			break;
		}
		case 6:
		{
			result += "DC";
			break;
		}
		case 7:
		{
			result += "DCC";
			break;
		}
		case 8:
		{
			result += "DCCC";
			break;
		}
		case 9:
		{
			result += "CM";
			break;
		}
	}
	switch (ten)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			result += "X";
			break;
		}
		case 2:
		{
			result += "XX";
			break;
		}
		case 3:
		{
			result += "XXX";
			break;
		}
		case 4:
		{
			result += "XL";
			break;
		}
		case 5:
		{
			result += "L";
			break;
		}
		case 6:
		{
			result += "LX";
			break;
		}
		case 7:
		{
			result += "LXX";
			break;
		}
		case 8:
		{
			result += "LXXX";
			break;
		}
		case 9:
		{
			result += "XC";
			break;
		}
	}
	switch (single)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			result += "I";
			break;
		}
		case 2:
		{
			result += "II";
			break;
		}
		case 3:
		{
			result += "III";
			break;
		}
		case 4:
		{
			result += "IV";
			break;
		}
		case 5:
		{
			result += "V";
			break;
		}
		case 6:
		{
			result += "VI";
			break;
		}
		case 7:
		{
			result += "VII";
			break;
		}
		case 8:
		{
			result += "VIII";
			break;
		}
		case 9:
		{
			result += "IX";
			break;
		}
	}
	return result;
}

int main()
{
	return 0;
}