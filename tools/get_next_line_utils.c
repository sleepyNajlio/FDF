/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-fil <fel-fil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:38:01 by fel-fil           #+#    #+#             */
/*   Updated: 2022/02/19 23:13:10 by fel-fil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l;
	char	*s;
	int		j;

	j = 0;
	l = 0;
	if (s1)
		l = ft_strlen(s1);
	if (s2)
		l += ft_strlen(s2);
	s = (char *)malloc(l + 1);
	if (!s)
		return (NULL);
	l = 0;
	while (s1 && s1[l])
	{
		s[l] = s1[l];
		l++;
	}
	while (s2[j])
		s[l++] = s2[j++];
	s[l] = 0;
	return (s);
}

int	ft_strchr(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*select_left(char *s)
{
	int		i;
	char	*ret;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	ret = (char *)malloc(i + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		ret[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i++] = 0;
	return (ret);
}

char	*select_right(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (ft_strlen(s) == i)
		return (NULL);
	ret = (char *)malloc(ft_strlen(s) - i);
	if (!ret)
		return (NULL);
	i++;
	while (s[i])
		ret[j++] = s[i++];
	ret[j++] = 0;
	return (ret);
}
