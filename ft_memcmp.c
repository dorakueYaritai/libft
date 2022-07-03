#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(const unsigned char *)(s1 + i) != *(const unsigned char *)(s2 + i))//const unsigned char(s1[i])でも生けそうなのに。
			return (*(const unsigned char *)(s1 + i) - *(const unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}