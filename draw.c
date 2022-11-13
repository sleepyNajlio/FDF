/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:46:16 by nloutfi           #+#    #+#             */
/*   Updated: 2022/11/13 15:09:51 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham2(float x, float y, t_vars *vars)
{
	float	x_step;
	float	y_step;
	int		max;

	x += vars->move_x;
	y += vars->move_y;
	vars->x_next += vars->move_x;
	vars->y_next += vars->move_y;
	x_step = vars->x_next - x;
	y_step = vars->y_next - y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - vars->x_next) || (int)(y - vars->y_next))
	{
		 mlx_pixel_put(vars->mlx, vars->mlx_win, x + 200, y + 200, vars->color);
		//vars->g_data[(int)(1000 * (y + 200) + (x + 200) )] = vars->color;
		x += x_step;
		y += y_step;
		
	}
}

void	 bresenham_law(float x, float y, int bool, t_vars *vars)
{
	int	z;
	int	z_next;

	if (bool)
	{
		vars->x_next = x + 1;
		vars->y_next = y;
	}
	else
	{
		vars->x_next = x;
		vars->y_next = y + 1;
	}
	z = vars->map[(int)y][(int)x];
	z_next = vars->map[(int)vars->y_next][(int)vars->x_next];
	x *= ZOOM;
	y *= ZOOM;
	vars->x_next *= ZOOM;
	vars->y_next *= ZOOM;
	ft_isometric(&x, &y, z);
	ft_isometric(&vars->x_next, &vars->y_next, z_next);
	vars->color = 0xfffffff;
	if (z || z_next)
		vars->color = 0xffff00;
	bresenham2(x, y, vars);
}

void	draw(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (x < vars->width - 1)
				bresenham_law(x, y, 1, vars);
			if (y < vars->height - 1)
				bresenham_law(x, y, 0, vars);
			x++;
		}
		y++;
	}

	//mlx_put_image_to_window(vars->mlx,vars->mlx_win,vars->g_image,0,0);
	//mlx_destroy_image(vars->mlx,vars->g_image);
}
