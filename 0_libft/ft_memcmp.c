/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grm <grm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:07:47 by gbooth            #+#    #+#             */
/*   Updated: 2022/08/20 23:29:00 by grm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;
	size_t				i;

	c_s1 = s1;
	c_s2 = s2;
	i = 0;
	while (i < n)
	{
		if (c_s1[i] != c_s2[i])
			return (c_s2[i] - c_s1[i]);
		i++;
	}
	return (0);
}
