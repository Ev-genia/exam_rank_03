/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:19:35 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/14 17:16:30 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct t_window
{
	int		width;
	int		hight;
	char	back;
}			s_window;

typedef struct t_rectangle
{
	char	rect;
	float	horiz_poz;
	float	vertic_poz;
	float	rect_width;
	float	rect_higth;
	char	paint_rect;
}			s_rectasngle;


#endif