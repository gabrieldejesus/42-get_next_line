/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-jesu <gde-jesu@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:44:08 by gde-jesu          #+#    #+#             */
/*   Updated: 2023/09/17 19:25:32 by gde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	temp = (char *) s;
	while (temp[i] != (char)c)
	{
		if (temp[i] == '\0')
			return (0);
		i++;
	}
	return (&temp[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_value;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	new_value = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new_value)
		return (0);
	while (s1[i] != '\0')
	{
		new_value[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_value[i++] = s2[j++];
	new_value[i] = '\0';
	free(s1);
	return (new_value);
}

char	*read_line(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*remove_read_line(char *stash)
{
	int		c1;
	int		c2;
	char	*new_stash;

	c1 = 0;
	while (stash[c1] && stash[c1] != '\n')
		c1++;
	if (!stash[c1])
	{
		free(stash);
		return (NULL);
	}
	if (stash[c1] == '\0')
		new_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - c1 + 1));
	else
		new_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - c1 + 2));
	if (!new_stash)
		return (NULL);
	c1++;
	c2 = 0;
	while (stash[c1])
		new_stash[c2++] = stash[c1++];
	new_stash[c2] = '\0';
	free(stash);
	return (new_stash);
}
