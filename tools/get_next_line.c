/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:30:49 by fel-fil           #+#    #+#             */
/*   Updated: 2022/11/13 23:50:25 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "get_next_line.h"

char	*read_ln(int fd, char *str, char *buf)
{
	int			re;
	char		*tmp;

	re = 1;
	while (re > 0)
	{
		re = read(fd, buf, BUFFER_SIZE);
		if (re == -1)
			return (NULL);
		buf[re] = 0;
		tmp = str;
		str = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(str))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*str ;
	char		*ret;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = read_ln(fd, str, buf);
	free(buf);
	ret = select_left(str);
	tmp = str;
	str = select_right(tmp);
	free(tmp);
	return (ret);
}
