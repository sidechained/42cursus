/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/08/20 23:28:57 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t			nbytes;
	void			*ret;
	unsigned char	*c_ret;

	nbytes = elsize * nelem;
	ret = malloc(elsize * nelem);
	c_ret = ret;
	if (ret)
		while (nbytes--)
			*c_ret++ = 0;
	return (ret);
}
