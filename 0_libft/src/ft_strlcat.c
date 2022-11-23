/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:20:05 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/22 09:46:32 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (src[i] != '\0')
		i++;
	src_len = i;
	j = 0;
	while (dest[j] != '\0')
		j++;
	dest_len = j;
	if (size <= dest_len || size == 0)
		return (size + src_len);
	k = 0;
	while (src[k] != '\0' && k < size - dest_len - 1)
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}
