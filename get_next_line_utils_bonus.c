/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:21:58 by marvin            #+#    #+#             */
/*   Updated: 2024/05/25 02:21:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t total_len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	total_len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	str = malloc(total_len);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = s2[j];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	check_and_clear(char *line)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (flag == 1)
			line[j++] = line[i];
		if (line[i] == '\n')
			flag = 1;
		line[i++] = 0;
	}
	return (flag);
}