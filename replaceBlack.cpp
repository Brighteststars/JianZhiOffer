#include "iostream"

using namespace std;


void ReplaceBlack(char str[], int length)
{
	if (str == NULL || length < 0)
	{
		return;
	}

	int orignalLength = 0;
	int numberOfBlack = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		++orignalLength;
		if (str[i] == ' ')
			++numberOfBlack;
		i++;
	}

	int newLength = orignalLength + numberOfBlack * 2;

	if (newLength > length)
		return;

	int indexOfOriginal = orignalLength;
	int indexOfNew = newLength;
	while (indexOfNew != indexOfOriginal)
	{
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else{
			str[indexOfNew--] = str[indexOfOriginal];
		}
		indexOfOriginal--;
	}
}


int main()
{
	char str[100] = " Hello World ";

	cout << str << endl;

	ReplaceBlack(str, 100);

	cout << str << endl;

	system("pause");

	return 0;
}

