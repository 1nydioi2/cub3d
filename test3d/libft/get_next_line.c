/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:47:36 by jutocche          #+#    #+#             */
/*   Updated: 2025/05/19 11:36:39 by jutocche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*process_remainder(char **remainder_ptr)
{
	char	*line;
	char	*new_remainder;
	char	*newline_pos;
	char	*new_line;

	if (!(*remainder_ptr))
		return (NULL);
	newline_pos = ft_strchr(*remainder_ptr, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(*remainder_ptr);
		new_remainder = ft_strdup(newline_pos + 1);
		free(*remainder_ptr);
		*remainder_ptr = new_remainder;
		new_line = ft_strjoin(line, "\n");
		free(line);
		return (new_line);
	}
	line = ft_strdup(*remainder_ptr);
	free(*remainder_ptr);
	*remainder_ptr = NULL;
	return (line);
}

char	*process_buffer(char *line, char *buffer, char **remainder_ptr)
{
	char	*result;
	char	*newline_pos;
	char	*temp;

	if (!line)
		result = ft_strdup(buffer);
	else
	{
		result = ft_strjoin(line, buffer);
		free(line);
	}
	newline_pos = ft_strchr(result, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		*remainder_ptr = ft_strdup(newline_pos + 1);
		temp = ft_strjoin(result, "\n");
		free(result);
		return (temp);
	}
	return (result);
}

char	*read_and_process(int fd, char *line, char **remainder_ptr)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (line);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		line = process_buffer(line, buffer, remainder_ptr);
		if (*remainder_ptr)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainders[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = process_remainder(&remainders[fd]);
	if (line && ft_strchr(line, '\n'))
		return (line);
	line = read_and_process(fd, line, &remainders[fd]);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
