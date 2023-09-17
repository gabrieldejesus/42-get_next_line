/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:49:46 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/17 19:23:14 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *stash)
{
	int		counter;
	char	*line;

	if (stash[0] == '\0')
		return (NULL);
	counter = 0;
	while (stash[counter] && stash[counter] != '\n')
		counter++;
	line = (char *)malloc(sizeof(char) * (counter + 2));
	line[counter + 1] = '\0';
	while (counter >= 0)
	{
		line[counter] = stash[counter];
		counter--;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = remove_read_line(stash);
	return (line);
}
