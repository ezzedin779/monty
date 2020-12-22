#include "monty.h"
/**
*_tokenise - the splitter of the line
*@s: string
*@delim: the delimiters
*Return: succes or error
*/
char **_tokenise(char *s, char *delim)
{
	char **w = NULL;
	int word_count, w_len, n, i = 0;

	if (s == NULL || !*s)
		return (NULL);
	word_count  = get_length(s, delim);
	if (word_count == 0)
		return (NULL);
	w = malloc((word_count + 1) * sizeof(char *));
	if (w == NULL)
		return (NULL);
	while (i < word_count)
	{
		w_len = get_w_length(s, delim);
		if (_delim(*s, delim))
			s = next(str, delims);
		w[i] = malloc((w_len + 1) * sizeof(char));
		if (w[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(w[i]);
			}
			free(w);
			return (NULL);
		}
		n = 0;
		while (n < w_len)
		{
			w[i][n] = *(s + n);
			n++;
		}
		w[i][n] = '\0';
		s = next(str, delims);
		i++;
	}
	w[i] = NULL;
	return (w);
}
/**
* _delim - checks if there is a delimitor
* @c: character in stream
* @delims: Pointer to null terminated array of delimitors
* Return: 1 (success) 0 (failure)
*/

int _delim(char c, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/**
* get_w_length - gets the word length of word
* @str: the word
* @delims: delimitors to use to delimit words
* Return: word length of current word
*/

int get_w_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}
/**
* get_length - gets the word length of a string
* @str: string
* @delims: delimitors to use to delimit words
* Return: the word count of the string
*/

int get_length(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}
/**
 * next - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */

char *next(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
