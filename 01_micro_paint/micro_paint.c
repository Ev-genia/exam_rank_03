/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:17:11 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/15 15:02:46 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int	main(int argc, char **argv)
{
	FILE			*fp;
	s_window		win;
	s_rectasngle	rect;
	char			**map;
	int				i;
	int				j;
	int				count;

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
	count = fscanf(fp, "%d %d %c\n", &win.width, &win.hight, &win.back);
	if (count != 3 || win.width <= 0 || win.width > 300 || win.hight <= 0 || win.hight > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	map = (char **) malloc(sizeof(char *) * win.hight + 1);
	i = 0;
	while (i < win.hight)
	{
		map[i] = (char *) malloc(sizeof(char) * win.width + 1);
		memset(map[i], win.back, win.width);
		i++;
	}
	map[i] = NULL;
	while ((count = fscanf(fp, " %c %f %f %f %f %c\n", &rect.rect, &rect.horiz_poz, &rect.vertic_poz, &rect.rect_width, &rect.rect_higth, &rect.paint_rect)) != -1)
	{
		if (count != 6 || rect.rect_higth <= 0.0f || rect.rect_width <= 0.0f || (rect.rect != 'r' && rect.rect != 'R'))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		i = 0;
		while (i < win.hight)
		{
			j = 0;
			while (j < win.width)
			{
				if (j >= rect.horiz_poz && j <= (rect.horiz_poz + rect.rect_width) && i >= rect.vertic_poz && i <= (rect.vertic_poz + rect.rect_higth))
					if (rect.rect == 'R' || j < rect.horiz_poz + 1 || j > (rect.horiz_poz + rect.rect_width - 1) || i < rect.vertic_poz + 1 || i > (rect.vertic_poz + rect.rect_higth - 1))
						map[i][j] = rect.paint_rect;
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (i < win.hight)
	{
		j = 0;
		while (j < win.width)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < win.width)
	{
		free(map[i]);
		i++;
	}
	free(map);
	fclose(fp);
	return (0);
}