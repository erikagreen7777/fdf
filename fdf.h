/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:18:23 by egreen            #+#    #+#             */
/*   Updated: 2018/01/23 08:18:25 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define BLUE95 	0x00e6f0ff
# define BLUE85		0x00b3ccff
# define BLUE75		0x0080b3ff
# define BLUE65 	0x004d88ff
# define BLUE50		0x000066ff
# define BLUE40		0x000052cc
# define BLUE35		0x00003cb3
# define BLUE20		0x00002966
# define GREEN95	0x00e6ffe6
# define GREEN90	0x00ccffcc
# define GREEN85	0x00b3ffcc
# define GREEN80	0x0099ff99
# define GREEN75	0x0080ff80
# define GREEN70	0x0066ff66
# define GREEN65	0x004dff88
# define GREEN60	0x0033ff33
# define GREEN55	0x001aff1a
# define GREEN50	0x0000ff00
# define GREEN45	0x0000e600
# define GREEN40	0x0000cc00
# define GREEN35	0x0000b33c
# define GREEN30	0x00009900
# define GREEN25	0x00008000
# define GREEN20	0x00006600
# define RADIAN(x)	(x * PI / 180)
# define W_SIZE		1000
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define PI			3.14159265
# define XANG		(PI / 180) * 45
# define ZANG		(PI / 180) * 45
# define ZOOM			20
# define C_W	(W_SIZE/2) - (raw->width * ZOOM/2) + 500
# define C_H	(W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x 


//42.fdf, 10-2.fdf, basictest, elem
/*# define ZOOM			20
# define C_W	((W_SIZE/2) - (raw->width * ZOOM/2))
# define C_H	((W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x)*/

//100-6.fdf
/*# define W_SIZE		1500
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define PI			3.14159265
# define XANG		(PI / 180) * 45
# define ZANG		(PI / 180) * 45
# define ZOOM			10
# define C_W	((W_SIZE/2) - (raw->width * ZOOM/2) + (1000))
# define C_H	((W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x)*/

//20-60
/*# define ZOOM			10
# define C_W	((W_SIZE/2) - (raw->width * ZOOM/2))
# define C_H	((W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x)*/

//50-4
/*# define W_SIZE		1500
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define PI			3.14159265
# define XANG		(PI / 180) * 45
# define ZANG		(PI / 180) * 45
# define ZOOM			15
# define C_W	(W_SIZE/2) - (raw->width * ZOOM/2) + 800
# define C_H	(W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x*/

//mars
/*# define W_SIZE		2500
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define PI			3.14159265
# define XANG		(PI / 180) * 45
# define ZANG		(PI / 180) * 45
# define ZOOM			8
# define C_W	(W_SIZE/2) - (raw->width * ZOOM/2) 
# define C_H	(W_SIZE/2) - ((raw->x * ZOOM)/2) - 1400*/

//pentenegos, plat, pnp_flat
/*# define W_SIZE		1000
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define PI			3.14159265
# define XANG		(PI / 180) * 45
# define ZANG		(PI / 180) * 45
# define ZOOM			30
# define C_W	(W_SIZE/2) - (raw->width * ZOOM/2) 
# define C_H	(W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x*/

//pylone
/*# define W_SIZE		2000
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define PI			3.14159265
# define XANG		(PI / 180) * 45
# define ZANG		(PI / 180) * 45
# define ZOOM			20
# define C_W	(W_SIZE/2) - (raw->width * ZOOM/2) + 1000
# define C_H	(W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x - 500*/

//pyra
/*# define W_SIZE		1000
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define PI			3.14159265
# define XANG		(PI / 180) * 45
# define ZANG		(PI / 180) * 45
# define ZOOM			20
# define C_W	(W_SIZE/2) - (raw->width * ZOOM/2) + 500
# define C_H	(W_SIZE/2) - ((raw->x * ZOOM)/2) - raw->x */
typedef struct	s_axes
{
	int			i;
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			swap;
	int			z;
	int			res;
}				t_axes;

typedef struct	s_values
{
	int			res;
	int			w2;
	int			i;
	int			i2;
	char		*line;
}				t_values;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_data
{
	void		*id;
	void		*win;
	void		*img;
	int			fd;
	int			width;
	int			x;
	char		*name;
	t_coord		**data;
	char		**str;
}				t_data;

void 			color_picker(t_data *raw, t_axes *points);
void			contrast(t_data *raw, t_axes *points);
int				main(int ac, char **av);
int				mlx_exit(int keycode);
void			validate(char *av, t_data *raw);
void			check(char *str);
int				check_width(char **data);
t_coord			**parse(char *str, t_data *raw);
void			draw(t_data *raw, t_coord **data);
void			draw_line(t_coord *a, t_coord *b, t_data *raw);
int				destroy_window(t_data *raw);
#endif
