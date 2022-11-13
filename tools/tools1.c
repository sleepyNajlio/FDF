/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:10:38 by nloutfi           #+#    #+#             */
/*   Updated: 2022/11/13 15:13:21 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	btn_press(int key, t_vars *vars)
{
	if (key == 53)
		destroy_window();
	if (key == 126)
		vars->move_y -= 50;
	if (key == 125)
		vars->move_y += 50;
	if (key == 123)
		vars->move_x -= 50;
	if (key == 124)
		vars->move_x += 50;
	mlx_clear_window(vars->mlx, vars->mlx_win);
	draw(vars);
	return (0);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

