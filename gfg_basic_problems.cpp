#include "interface.h"

int my_string_len(char *str)
{
	int i = 0;

	while (str[i] != 0)
		i++;

	return i;
}

int basic_gfg_probs::polindrome_words_count_in_sentence(char *str)
{
	int pCount = 0, k = 0, beg = 0;
	char sub_string[10];
	bool isPalindrom = true;

	while(*str != 0)
	{
		isPalindrom = true;
		if (*str == ' ')
		{
			int e = k -1;
			while (beg <= e)
			{
				char a = sub_string[beg];
				if (isupper(a))
					a = tolower(a);
				char b = sub_string[e];
				if (isupper(b))
					b = tolower(b);
				if (a == b){
					beg++;
					e--;
				}
				else{
					isPalindrom = false;
					break;
				}
			}
			if (isPalindrom == true)
				pCount ++;
			k = beg = 0;
		}
		else{
			sub_string[k] = *str;
			k++;
		}
		*str++;
	}

	//check for last word
	int e = k -1;
	while (beg <= e)
	{
		char a = sub_string[beg];
		if (isupper(a))
			a = tolower(a);
		char b = sub_string[e];
		if (isupper(b))
			b = tolower(b);
		if (a == b){
			beg++;
			e--;
		}
		else{
			isPalindrom = false;
			break;
		}
	}
	if (isPalindrom == true)
		pCount ++;

	k = beg = 0;

	return pCount;
}