/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:33:02 by egreen            #+#    #+#             */
/*   Updated: 2018/01/23 16:46:12 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		destroy_window(t_data *raw)
{
	mlx_destroy_window(raw->id, raw->win);
	exit(0);
	return (0);
}

void	initialize(t_data *raw, char *str)
{
	t_values *val;

	if (!raw)
		ft_error("Error: struct initialization");
	raw->id = mlx_init();
	if (ft_strstr(raw->name, "maps/100-6.fdf") || ft_strstr(raw->name, \
				"maps/50-4.fdf") || ft_strstr(raw->name, "maps/pylone.fdf"))
		raw->win = mlx_new_window(raw->id, 1500, 1500, str);
	else if (ft_strstr(raw->name, "maps/42.fdf") || ft_strstr(raw->name, \
				"maps/10-2.fdf") || ft_strstr(raw->name, \
					"maps/basictest.fdf") || ft_strstr(raw->name,\
						"maps/elem.fdf") || ft_strstr(raw->name, \
			"maps/20-60.fdf") || ft_strstr(raw->name, "maps/pyra.fdf") \
		|| ft_strstr(raw->name, "maps/10-70.fdf"))
		raw->win = mlx_new_window(raw->id, 1000, 1000, str);
	else if (ft_strstr(raw->name, "maps/mars.fdf"))
		raw->win = mlx_new_window(raw->id, 2500, 2500, str);
	else
		raw->win = mlx_new_window(raw->id, W_SIZE, W_SIZE, str);
	raw->fd = open(str, O_RDONLY);
}

int		mlx_exit(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int ac, char **argv)
{
	t_data	*raw;

	if (ac < 2)
		ft_error("usage: ./fdf maps/[*.fdf]");
	raw = (t_data *)ft_memalloc(sizeof(t_data));
	raw->name = argv[1];
	initialize(raw, argv[1]);
	validate(argv[1], raw);
	raw->data = parse(argv[1], raw);
	draw(raw, raw->data);
	ft_putstr("finished waiting for exit command.\n");
	mlx_key_hook(raw->win, mlx_exit, NULL);
	mlx_hook(raw->win, 17, 0, destroy_window, raw);
	mlx_loop(raw->id);
	return (0);
}
