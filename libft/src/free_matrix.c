/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:13:58 by pedro             #+#    #+#             */
/*   Updated: 2023/06/18 13:14:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Free the allocated memory for a bidimensional array*/
void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!*matrix || !**matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}
