#ifndef PROCESS_CHAR_H_
	#define PROCESS_CHAR_H_

char present_char(int num);
int get_present_number(char present);


int get_present_number(char present)
{
	if(isdigit(present))
		return present - '0';

	//if present is not digit
	return (present - 'A') + 10;
}


char present_char(int num)
{
	if(num < 10)
		return num + '0';

	//if num >= 10
	return ((num - 10) % 26) + 'A';
}

#endif