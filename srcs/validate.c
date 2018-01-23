/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:43:53 by egreen            #+#    #+#             */
/*   Updated: 2018/01/23 08:05:27 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				check_width(char **str)
{
	int			width;

	width = 0;
	while (str[width])
		width++;
	return (width);
}

void			check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((ft_isalpha(str[i]) == 1) || ((str[i] == '-' &&
						ft_isdigit(str[i + 1]) != 1) || str[i] == '\t'))
			ft_error("Error: invalid content");
		i++;
	}
}

void			get_data(t_data *raw, t_values *val)
{
	int		time;

	time = 0;
	while ((val->res = get_next_line(raw->fd, &val->line)) > 0)
	{
		check(val->line);
		if ((raw->str = ft_strsplit(val->line, ' ')) == NULL)
			ft_error("Error: invalid file size");
		((raw->width == 0) ? (raw->width = check_width(raw->str)) :
				(val->w2 = check_width(raw->str)));
		if (time > 1 && val->w2 != raw->width)
			ft_error("Error: invalid width");
		while (raw->str[val->i2])
		{
			free(raw->str[val->i2]);
			val->i2++;
		}
		free(val->line);
		val->i++;
		time++;
	}
	if (time == 0 || val->res == -1)
		ft_error("Error: invalid file content");
	raw->x = val->i;
}

void			validate(char *argv, t_data *raw)
{
	t_values	*val;
	int			len;

	len = ft_strlen(argv);
	if (argv[len - 1] != 'f' && argv[len - 2]
		!= 'd' && argv[len - 3] != 'f' && argv[len - 4] != '.')
		ft_error("Please use a .fdf file extension");
	if ((raw->fd = open(argv, O_RDONLY)) < 0)
		ft_error("Could not open");
	raw->width = 0;
	val = (t_values *)malloc(sizeof(t_values));
	val->i = 0;
	val->w2 = 0;
	val->i2 = 0;
	get_data(raw, val);
	close(raw->fd);
	raw->fd = 0;
}
