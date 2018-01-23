/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 07:31:06 by egreen            #+#    #+#             */
/*   Updated: 2018/01/23 07:49:53 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	assign_points(t_data *raw, t_coord **data)
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
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) * ZOOM)) + C_W / 2;
		(ft_strstr(raw->name, "maps/42.fdf") || ft_strstr(raw->name,
				"maps/10-70.fdf") || ft_strstr(raw->name, "maps/100-6.fdf"))
			? (data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * cos(ZANG) * \
			cos(XANG) - (data[x][y].z / 4) * sin(XANG)) * ZOOM) + C_H / 2) :
			(data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * cos(ZANG) * \
			cos(XANG) - (data[x][y].z) * sin(XANG)) * ZOOM) + C_H / 2);
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}

static void	first_maps(t_data *raw, t_coord **data)
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
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) * 20)) + ((600) - (raw->width * 10))/* / 2*/;
		(ft_strstr(raw->name, "maps/42.fdf")) ? (data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * cos(ZANG) * \
			cos(XANG) - (data[x][y].z / 4) * sin(XANG)) * 20) + ((500) - ((raw->x * 10) - raw->x))) :
			(data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * cos(ZANG) * \
			cos(XANG) - (data[x][y].z) * sin(XANG)) * 20) + ((500) - ((raw->x * 10) - raw->x)));
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}

static void hundred(t_data *raw, t_coord **data)
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
		data[x][y].x = (((y * cos(ZANG) - x * sin(ZANG)) * 10)) + ((1950) - (raw->width * 20) + (1500)) / 2;
		data[x][y].y = ((y * sin(ZANG) * cos(XANG) + x * cos(ZANG) * \
			cos(XANG) - (data[x][y].z) * sin(XANG)) * 10) + ((1100) - ((raw->x * 20) - raw->x) / 2);
		y++;
	}
	while (raw->str[++i])
		free(raw->str[i]);
	x++;
}
static void	map_picker(t_data *raw, t_coord **data)
{
	if (ft_strstr(raw->name, "maps/42.fdf") || ft_strstr(raw->name, "maps/10-2.fdf") || ft_strstr(raw->name, "maps/basictest.fdf") ||
		ft_strstr(raw->name, "maps/elem.fdf"))
		first_maps(raw, data);
	else if (ft_strstr(raw->name, "maps/100-6.fdf"))
		hundred(raw, data);
}
t_coord	**parse(char *str, t_data *raw)
{
	int			ret;
	int			i;
	char		*line;
	t_coord		**data;

	i = 0;
	line = NULL;
	if ((raw->fd = open(str, O_RDONLY)) < 0)
		ft_error("Error: could not open");
	data = (t_coord **)ft_memalloc(sizeof(t_coord *) * raw->x);
	while ((ret = get_next_line(raw->fd, &line)) > 0)
	{
		raw->str = ft_strsplit(line, ' ');
		map_picker(raw, data);
		// assign_points(raw, data);
		ft_strdel(&line);
	}
	if (ret == -1)
		ft_error("get_next_line error");
	close(raw->fd);
	return (data);
}
