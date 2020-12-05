
#include <stdlib.h>

char    *ft_str_chunk(char *str, int start, int end)
{
    char    *res;
    int     index;

    res = (char*)malloc(sizeof(char) * (end - start + 1));
    index = 0;
    while (start + index < end)
    {
        res[index] = str[start + index];
        index++;
    }
    res[index] = '\0';
    return (res);
}

int ft_count_chars(char *str, char *charset)
{
    int i;
    int j;
    int n;

    i = 0;
    j = 0;
    n = 0;
    while (str[i])
    {
        while (charset[j] && str[i] != charset[j])
            j++;
        if (charset[j] != 0)
            n++;
        i++;
    }
    return n;
}

char    **ft_split(char *str, char *charset)
{
    int     i;
    int     j;
    int     n;
    int     chunk;
    char    **res;

    res = (char**)malloc(sizeof(char*)*(ft_count_chars(str, charset) + 1));
    i = 0;
    j = 0;
    n = 0;
    chunk = 0;
    while (str[i])
    {
        while (charset[j] && (str[i] == charset[j]))
            j++;
        if (charset[j] != 0)
        {
            res[chunk] = ft_str_chunk(str, n, i);
            n = i;
            chunk++;
        }
    }
    res[chunk] = ft_str_chunk(str, n, i);
    return (res);
}
