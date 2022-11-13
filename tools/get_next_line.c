/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:57:18 by nloutfi           #+#    #+#             */
/*   Updated: 2022/11/13 15:12:06 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "get_next_line.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		str = malloc(1);
	else if (ft_strlen(s) <= start + len)
		str = malloc(ft_strlen(s) - start + 1);
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
	{
		while (s[i] && j < len)
			str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}

void line_changer(char **save , char **line, char *temp)
{
	temp = *save;
	*line = ft_substr(*save, 0, ft_strchr(*save, '\n') + 1);
	*save = ft_substr(*save, (ft_strchr(*save, '\n') + 1), ft_strlen(*save));
	ft_free(temp);
} 

char *get_next_line(fd)
{
	static char *stock;
	char *line;
	char *buff;
	int l;
	char *temp;
	
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buff)
		return NULL;
	while(ft_strchr(stock,'\n') == -1)
	{
		l = read(fd, buff, BUFFER_SIZE);
        if(l == -1 || l == 0)
		{
			ft_free(buff);
			if (stock == NULL)
				return NULL;
			line = stock;
			stock = NULL;
			return (line);
		}   
		buff[l] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		ft_free(temp);
	}
	ft_free(buff);
	line_changer( &stock,  &line, temp);
	return (line);
}