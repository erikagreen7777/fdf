/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:07:23 by egreen            #+#    #+#             */
/*   Updated: 2018/01/23 08:15:35 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initialize_points(t_axes *points, t_coord *a, t_coord *b)
{
	int tmp;

	tmp = 0;
	points->i = 0;
	points->x = a->x;
	points->y = a->y;
	points->dx = abs(b->x - a->x);
	points->dy = abs(b->y - a->y);
	points->sx = ft_ispositive(b->x - a->x);
	points->sy = ft_ispositive(b->y - a->y);
	points->swap = 0;
	points->z = MAX(a->z, b->z);
	points->res = 2 * points->dy - points->dx;
	if (points->dy > points->dx)
	{
		ft_swap(&points->dx, &points->dy);
		points->swap = 1;
	}
}

void	contrast(t_data *raw, t_axes *points)
{
	if (points->z <= -3)
		mlx_pixel_put(raw->id, raw->win, points->x, points->y, 0x00618795);
	else if (points->z == -2)
		mlx_pixel_put(raw->id, raw->win, points->x, points->y, 0x00aae2f0);
	else if (points->z == -1)
		mlx_pixel_put(raw->id, raw->win, points->x, points->y, 0x00b1c1c7);
	else if (points->z == 0)
		mlx_pixel_put(raw->id, raw->win, points->x, points->y, 0x00ae594a);
	else if (points->z == 1)
		mlx_pixel_put(raw->id, raw->win, points->x, points->y, 0x00e8d272);
	else if (points->z == 2)
		mlx_pixel_put(raw->id, raw->win, points->x, points->y, 0x00aae2f0);
	else
		mlx_pixel_put(raw->id, raw->win, points->x, points->y, 0x00eedf9c);
}

void	draw_line(t_coord *a, t_coord *b, t_data *raw)
{
	t_axes	points;

	initialize_points(&points, a, b);
	while (points.i <= points.dx)
	{
		color_picker(raw, &points);
		while (points.res > 0)
		{
			if (points.swap)
				points.x += points.sx;
			else
				points.y += points.sy;
			points.res -= 2 * points.dx;
		}
		if (points.swap)
			points.y += points.sy;
		else
			points.x += points.sx;
		points.res += 2 * points.dy;
		points.i++;
	}
}

void	draw(t_data *raw, t_coord **data)
{
	int	x;
	int y;

	x = -1;
	while (++x < raw->x)
	{
		y = -1;
		while (++y < raw->width)
		{
			if (y + 1 < raw->width)
				draw_line(&data[x][y], &data[x][y + 1], raw);
			if (x + 1 < raw->x)
				draw_line(&data[x][y], &data[x + 1][y], raw);
		}
	}
}
