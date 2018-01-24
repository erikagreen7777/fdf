/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:36:33 by egreen            #+#    #+#             */
/*   Updated: 2018/01/23 16:43:01 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	twenty(t_data *raw, t_coord **data)
{
	int				i;
	int				y;
	static int		x;

	y = 0;
	i = -1;
	data[x] = (t_coord *)ft_memalloc(sizeof(t_coord) * (raw->width + 1));
	if (x > raw->x)
		x = 0;
	while (y < raw->width)
	{
		data[x][y].z = ft_atoi(raw->str[y]);
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) * \
					20)) + ((600) - (raw->width * 5));
		data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x *\
					cos(ZANG) * cos(XANG) - (data[x][y].z) \
					* sin(XANG)) * 5) + ((500) - ((raw->x * 10) - raw->x));
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}

void	fifty(t_data *raw, t_coord **data)
{
	int				i;
	int				y;
	static int		x;

	y = 0;
	i = -1;
	data[x] = (t_coord *)ft_memalloc(sizeof(t_coord) * (raw->width + 1));
	if (x > raw->x)
		x = 0;
	while (y < raw->width)
	{
		data[x][y].z = ft_atoi(raw->str[y]);
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) *\
					20)) + ((950) - (raw->width * 8) / 2);
		data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * \
					cos(ZANG) * cos(XANG) - (data[x][y].z) *\
					sin(XANG)) * 20) + ((350) - ((raw->x * 8) - raw->x) / 2);
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}

void	mars(t_data *raw, t_coord **data)
{
	int				i;
	int				y;
	static int		x;

	y = 0;
	i = -1;
	data[x] = (t_coord *)ft_memalloc(sizeof(t_coord) * (raw->width + 1));
	if (x > raw->x)
		x = 0;
	while (y < raw->width)
	{
		data[x][y].z = ft_atoi(raw->str[y]);
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) * \
					8)) + ((1250) - (raw->width * 4) / 2);
		data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x *\
					cos(ZANG) * cos(XANG) - (data[x][y].z) * \
					sin(XANG)) * 8) + ((300) - ((raw->x * 4)) / 2);
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}

void	pees(t_data *raw, t_coord **data)
{
	int				i;
	int				y;
	static int		x;

	y = 0;
	i = -1;
	data[x] = (t_coord *)ft_memalloc(sizeof(t_coord) * (raw->width + 1));
	if (x > raw->x)
		x = 0;
	while (y < raw->width)
	{
		data[x][y].z = ft_atoi(raw->str[y]);
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) \
					* 40)) + ((600) - (raw->width * 10));
		data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * \
					cos(ZANG) * cos(XANG) - (data[x][y].z) * \
					sin(XANG)) * 40) + ((400) - ((raw->x * 10) - raw->x));
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}

void	pyra(t_data *raw, t_coord **data)
{
	int				i;
	int				y;
	static int		x;

	y = 0;
	i = -1;
	data[x] = (t_coord *)ft_memalloc(sizeof(t_coord) * (raw->width + 1));
	if (x > raw->x)
		x = 0;
	while (y < raw->width)
	{
		data[x][y].z = ft_atoi(raw->str[y]);
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) * \
					20)) + ((800) - (raw->width * 10));
		data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * cos(ZANG) * \
			cos(XANG) - (data[x][y].z) * sin(XANG)) * 20) \
			+ ((500) - ((raw->x * 10) - raw->x));
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}
