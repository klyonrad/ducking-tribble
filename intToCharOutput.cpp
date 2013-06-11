#include <iostream>

void intToChar(int value, char *buffer){
	int foo, length;
	int i = 0;
	if (value == 0){
		buffer[i++] = '0';
		buffer[i] = 0;
	}
	if (value > 0){
		while (value != 0)
		{
			foo = value % 10;
			value = value / 10;
			buffer[i++] = '0' + foo;
		}
		length = i-1;
		int k = length;
		i = 0;
		while (i < k)
		{
			buffer[i] ^= buffer[k];
			buffer[k] ^= buffer[i];
			buffer[i] ^= buffer[k];
			i++;
			k--;
		}
		buffer[length+1] = 0;
	}
	if (value < 0)
	{
		buffer[i++] = '-';
		value = value * -1;
		while (value != 0)
		{
			foo = value % 10;
			value = value / 10;
			buffer[i++] = '0' + foo;
		}
	}
}

void intOutput(int number){
	char buffer[12]; // biggest 32bit has 11 digits; one more for '\0'
	intToChar (number, buffer);
	std::cout << buffer << std::endl;
}

int main (void){
	intOutput(1249);
	intOutput(0x80000000); // -2147483648
	intOutput(0x7FFFFFFF);
	return 0;
}