
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep)
{
    char*   res;
    int     i;
    int     j
    int     res_size;
    int     sep_size;
    
    if (size == 0)
    {
        res = (char*)malloc((char *));
        *res = 0;
        return (res);
    }
    res_size = 0;
    i = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j])
            j++;
        res_size += j;
    }
    sep_size = 0;
    while (sep[sep_size])
        sep_size++;
    res_size += sep_size * (size - 1);
    res = (char*)malloc((char*) * res_size);
    i = 0;
    while (i < size)
    {
        j = 0;
        while(strs[i][j])
        {
            res[res_size] = strs[i][j];
            res_size++;
            j++;
        }
        i++;
        if (i == size)
            continue;
        j = 0;
        while (sep[j])
        {
            res[res_size] = sep[j];
            res_size++;
            j++;
        }
    }
    return (res);
}
