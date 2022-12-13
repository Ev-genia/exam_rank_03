/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:21:35 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/15 17:00:46 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int	main(int argc, char **argv)
{
	FILE		*fp;
	int			count;
	t_win		w;
	t_circle	c;
	char		*map;
	int			i;
	int			j;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	count = fscanf(fp, "%d %d %c\n", &w.width, &w.hight, &w.back);
	if (count != 3 || w.width <= 0 || w.width > 300 || w.hight <= 0 || w.hight > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	map = (char *) malloc(sizeof(char) * w.width * w.hight + 1);
	memset(map, w.back, w.width * w.hight);
	while ((count = fscanf(fp, " %c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.rad, &c.paint)) != -1)
	{

		if (count != 5 || c.rad <= 0.0f || (c.type != 'C' && c.type != 'c'))
		{
// printf("count: %d, c: %c, x: %f, y: %f, rad: %f, c: %c\n", count, c.type, c.x, c.y, c.rad, c.paint);
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		i = 0;
		while (i < w.hight)
		{
			j = 0;
			while (j < w.width)
			{
				if ((float) sqrt((j - c.x) * (j - c.x) + (i - c.y) * (i - c.y)) <= c.rad)
					if (c.type == 'C' || ((float) sqrt((j - c.x) * (j - c.x) + (i - c.y) * (i - c.y)) > c.rad - 1))
						map[i * w.width + j] = c.paint;
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (i < w.hight)
	{
		j = 0;
		while (j < w.width)
		{
			write(1, &map[i * w.width + j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	free(map);
	fclose(fp);
	return (0);
}