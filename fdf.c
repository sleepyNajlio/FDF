/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:55:21 by nloutfi           #+#    #+#             */
/*   Updated: 2022/11/13 23:18:08 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_img(void *mlx, void *mlx_win)
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;

	path = "./img.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 1, 1);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2 || (open(av[1], O_RDONLY, 0) == -1))
		return (1);
	vars = parse(av[1]);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1000, 1000, "Fil De Fer");
	vars->g_img = mlx_new_image(vars->mlx, 1000, 1000);
	draw(vars);
	draw_img(vars->mlx, vars->mlx_win);
	mlx_hook(vars->mlx_win, 2, (1L << 0), btn_press, vars);
	mlx_hook(vars->mlx_win, 17, 0L, destroy_window, vars);
	mlx_loop(vars->mlx);
	free(vars);
}
