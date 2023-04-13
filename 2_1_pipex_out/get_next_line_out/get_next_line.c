/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:30:36 by gbooth            #+#    #+#             */
/*   Updated: 2023/01/09 08:52:37 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_for_newline(char **buffer, char **next_line)
{
	char	*tmpbuf;
	int		i;

	i = 0;
	while ((*buffer)[i])
	{
		if ((*buffer)[i] == '\n')
		{
			*next_line = ft_substr(*buffer, 0, i + 1);
			tmpbuf = *buffer;
			*buffer = ft_substr(tmpbuf, i + 1, ft_strlen(*buffer));
			free(tmpbuf);
			tmpbuf = NULL;
			return ;
		}
		i++;
	}
	return ;
}

void	free_all(char **chars_from_file, char **buffer, char **next_line)
{
	free(*chars_from_file);
	free(*next_line);
	free(*buffer);
	*buffer = NULL;
}

int	read_me(int fd, char **chars_from_file, char **buffer, char **next_line)
{
	int			num_chars_read;

	num_chars_read = read(fd, *chars_from_file, BUFFER_SIZE);
	if (num_chars_read == -1)
	{
		free_all(chars_from_file, buffer, next_line);
		return (0);
	}
	if (num_chars_read == 0)
	{
		free(*chars_from_file);
		check_for_newline(buffer, next_line);
		if (*next_line != NULL)
			return (1);
		if (*buffer[0] != '\0')
		{
			*next_line = *buffer;
			*buffer = NULL;
			return (1);
		}
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	return (2);
}

int	get_next_line2(int fd, char **buffer, char **next_line)
{
	char		*chars_from_file;
	char		*tmpbuf;
	int			i;
	int			j;

	*next_line = NULL;
	chars_from_file = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!chars_from_file)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE + 1)
		chars_from_file[i++] = '\0';
	j = read_me(fd, &chars_from_file, buffer, next_line);
	if (j == 0)
		return (0);
	if (j == 1)
		return (1);
	tmpbuf = *buffer;
	*buffer = ft_strjoin(tmpbuf, chars_from_file);
	free(chars_from_file);
	free(tmpbuf);
	check_for_newline(buffer, next_line);
	if (*next_line)
		return (2);
	return (3);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	while (1)
	{
		j = get_next_line2(fd, &buffer, &next_line);
		if (j == 0)
			return (NULL);
		if (j == 1)
			return (next_line);
		if (j == 2)
			break ;
	}
	return (next_line);
}
