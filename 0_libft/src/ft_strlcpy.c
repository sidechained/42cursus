/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:21:11 by gbooth            #+#    #+#             */
/*   Updated: 2022/11/28 09:53:20 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (src[i] == '\0')
		return (0);
	while ((i < (size - 1)) && (src[i] != '\0'))
	{
		printf("here\n");
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
