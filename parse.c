/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:07:54 by nloutfi           #+#    #+#             */
/*   Updated: 2022/11/13 23:19:01 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(char *file_name)
{
	int		width;
	int		fd;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	width = 0;
	str = get_next_line(fd);
	width = word_counter(str, ' ');
	free(str);
	return (width);
}

int	count_height(char *file_name)
{
	char	*str;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	str = get_next_line(fd);
	while (str)
	{
		height++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (height);
}

void	fill_map(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

t_vars	*parse(char *file_name)
{
	t_vars	*vars;
	int		fd;
	char	*str;
	int		i;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->width = count_width(file_name);
	vars->height = count_height(file_name);
	vars->map = (int **)malloc(sizeof(int *) * (vars->height + 1));
	i = 0;
	while (i <= vars->height)
		vars->map[i++] = (int *)malloc(sizeof(int) * (vars->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		fill_map(vars->map[i], str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	close(fd);
	return (vars);
}
