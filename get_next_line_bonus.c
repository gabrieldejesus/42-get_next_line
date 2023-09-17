/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 07:32:55 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/17 19:25:14 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = remove_read_line(stash[fd]);
	return (line);
}
