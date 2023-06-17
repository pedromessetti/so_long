/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmessett <pmessett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 08:55:37 by pmessett          #+#    #+#             */
/*   Updated: 2023/05/29 13:05:45 by pmessett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies n bytes from memory area src to
memory area dest. The memory areas may overlap: copying
takes place as though the bytes in src are first copied into
a temporary array that does not overlap src or dest, and the
bytes are then copied from the temporary array to dest.

Returns a pointer to dest.*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*memsrc;
	char		*memdest;

	memsrc = (const char *)src;
	memdest = (char *)dest;
	if (dest > src)
	{
		while (n--)
			memdest[n] = memsrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
