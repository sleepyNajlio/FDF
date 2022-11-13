/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:55:21 by nloutfi           #+#    #+#             */
/*   Updated: 2022/11/13 15:10:08 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2 || (open(av[1], O_RDONLY, 0) == -1))
		return(1);
	vars = parse(av[1]);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1000, 1000, "Fil De Fer");
	vars->g_img = mlx_new_image(vars->mlx,1000,1000);
	vars->g_data = (int *)mlx_get_data_addr(vars->g_img,&vars->tab[0],&vars->tab[1],&vars->tab[2]);

	draw(vars);
	//system("leaks fdf");
	mlx_hook(vars->mlx_win, 2, (1L << 0), btn_press, vars);
	mlx_hook(vars->mlx_win, 17, 0L,destroy_window, vars);
	mlx_loop(vars->mlx);
	free(vars);
}