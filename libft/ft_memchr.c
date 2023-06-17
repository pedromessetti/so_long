/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:17:06 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/29 13:02:59 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Scans the initial n bytes of the memory area 
pointed to by s for the first instance of c.

Returns a pointer to the matching byte or NULL
if c does not occur in the given memory area.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		a;

	i = -1;
	str = s;
	a = c;
	while (++i < n)
	{
		if (str[i] == a)
			return ((char *)str + i);
	}
	return (NULL);
}

// int	main(void)
// {
// 	const void *s = "Hello World!";
// 	int c = 32;

// 	printf(":%s:\n", (const char *)s);
// 	printf(":%c:\n", c);
// 	printf(":%s:\n", (char *)ft_memchr(s, c, 13));
// }