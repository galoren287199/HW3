#define SUCCESS 1
#define OUT
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int FormatNumberString(int* prime_components, char** OUT prime_factors_by_format, int number_of_components);
void convert_int_to_str(int num, char** OUT str);
int main()
{

	int x = 12347890;
	char* string;
	convert_int_to_str(x, &string);
	printf("%s", string);
}


void my_strcpy(char* dest, char* src)
{
	int i = 0;
	for (;src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i]= src[i];
}
int FormatNumberString(int* prime_components, char** OUT prime_factors_by_format, int number_of_components )
{
	const int max_len_component_string = 10;
	int i = 0;
	
	char* tmp_string = "The prime factors of %d are: ";
	//--int-string--len (string)->big_strin
	int val = (int)strlen(tmp_string) + (int)(number_of_components * 2 * max_len_component_string)  + 1;
	char* str = (char*)calloc(val,sizeof(char));
	int poistion = strlen(tmp_string);
	memcpy(str, tmp_string, poistion);
	for (int i = 0; i < number_of_components; i++)
	{
		sprintf_s(str + poistion, poistion, "%d", prime_components[i]);
		poistion = strlen(str);
		str[poistion++] = ',';
	}
	str[poistion - 1] = '\0';
	*prime_factors_by_format = str;
	return SUCCESS;
}

int find_len_number(int num)
{
	int counter = 0;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return counter;
}

