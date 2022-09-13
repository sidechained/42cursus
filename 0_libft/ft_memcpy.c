/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:08:01 by gbooth            #+#    #+#             */
/*   Updated: 2022/08/20 23:29:01 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_src;
	char	*c_dest;

	c_src = (char *)src;
	c_dest = (char *)dest;
	while (n--)
		*c_dest++ = *c_src++;
	return (c_dest);
}
