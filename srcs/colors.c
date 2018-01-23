/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:27:19 by egreen            #+#    #+#             */
/*   Updated: 2018/01/23 08:10:04 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		ten_two(t_data *raw, t_axes *vb)
{
	if (vb->z <= -5)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00660000);
	else if (vb->z == -4)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00800000);
	else if (vb->z == -3)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00990000);
	else if (vb->z == -2)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00b30000);
	else if (vb->z == -1)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00cc0000);
	else if (vb->z == 0)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00e60000);
	else if (vb->z == 1)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00ff0000);
	else if (vb->z == 2)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00ff1a1a);
	else if (vb->z == 3)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00ff3333);
	else if (vb->z == 4)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00ff6666);
	else if (vb->z >= 5)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00ff9999);
	else
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, 0x00ffcccc);
}

static void		green2(t_data *raw, t_axes *vb)
{
	if (vb->z >= 6 && vb->z < 14)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN70);
	else if (vb->z >= 14 && vb->z < 22)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN75);
	else if (vb->z >= 22 && vb->z < 30)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN80);
	else if (vb->z >= 30 && vb->z < 38)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN85);
	else if (vb->z >= 38 && vb->z < 46)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN90);
	else if (vb->z >= 46)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN95);
}

static void		green(t_data *raw, t_axes *vb)
{
	if (vb->z < -66)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN20);
	else if (vb->z >= -66 && vb->z < -58)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN25);
	else if (vb->z >= -58 && vb->z < -50)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN30);
	else if (vb->z >= -50 && vb->z < -42)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN35);
	else if (vb->z >= -42 && vb->z < -34)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN40);
	else if (vb->z >= -34 && vb->z < -26)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN45);
	else if (vb->z >= -26 && vb->z < -18)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN50);
	else if (vb->z >= -18 && vb->z < -10)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN55);
	else if (vb->z >= -10 && vb->z < -2)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN60);
	else if (vb->z >= -2 && vb->z < 6)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, GREEN65);
	else
		green2(raw, vb);
}

static void		blue(t_data *raw, t_axes *vb)
{
	if (vb->z < -10)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE20);
	else if (vb->z >= -10 && vb->z < -7)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE35);
	else if (vb->z >= -7 && vb->z < -4)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE40);
	else if (vb->z >= -4 && vb->z < 0)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE50);
	else if (vb->z >= 0 && vb->z < 4)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE65);
	else if (vb->z >= 4 && vb->z < 7)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE75);
	else if (vb->z >= 7 && vb->z <= 10)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE85);
	else if (vb->z > 10)
		mlx_pixel_put(raw->id, raw->win, vb->x, vb->y, BLUE95);
}

void			color_picker(t_data *raw, t_axes *vb)
{
	if (ft_strstr(raw->name, "maps/100-6.fdf"))
		ten_two(raw, vb);
	else if (ft_strstr(raw->name, "maps/10-2.fdf") ||
			ft_strstr(raw->name, "maps/50-4.fdf"))
		contrast(raw, vb);
	else if (ft_strstr(raw->name, "maps/10-70.fdf") ||
			ft_strstr(raw->name, "maps/20-60.fdf") ||
			ft_strstr(raw->name, "maps/elem.fdf"))
		green(raw, vb);
	else
		blue(raw, vb);
}
