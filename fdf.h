#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define ZOOM 10

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		**map;
	int		color;
	float	x_next;
	float	y_next;
	int		move_x;
	int		move_y;
	int 	*g_data;
	void	*g_img;
	//t_img	*img;
	int 	tab[4];
}	t_vars;

int		destroy_window(void);
int		ft_atoi(const char *str);
void	*ft_memchr(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
int		btn_press(int key, t_vars *vars);
int		ft_abs(int a);
int		ft_max(int a, int b);
void	ft_isometric(float *x, float *y, float z);
void	bresenham2(float x, float y, t_vars *vars);
void	bresenham_law(float x, float y, int bool, t_vars *vars);
void	draw(t_vars *vars);
t_vars	*parse(char *file_name);
int		word_counter(char const *str, char c);
char	*get_next_line(int fd);
void	*ft_memmove(void *dst, void *src, size_t len);

#endif


