/**
* get_int - get the int
* @num: number to convert
* Return: pointer to string
*/
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = base_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_buffer(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
* _abs - absolute
* @i: integer
* Return: abs(i)
*/
unsigned int _abs(int i)
{
	if (i < 0)
		return ((unsigned int)i * -1);
	return ((unsigned int)i);
}

/**
* base_len - length of a buffer
* @num: number to need for length
* @base: base to convert to
* Return: the length
*/
int base_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
* fill_buffer - fills buffer
* @num: the number to convert
* @base: base to convert to
* @buff: buffer to fill
* @buff_size: size of the buffer
*/
void fill_buffer(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
* int_error - invalid use of push
* @line_number: line number
* Return: EXIT_FAILURE
*/
int int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
