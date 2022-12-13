/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:21:48 by mlarra            #+#    #+#             */
/*   Updated: 2022/03/15 16:18:43 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_win
{
	int		width;
	int		hight;
	char	back;
}	t_win;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	rad;
	char	paint;
}	t_circle;

#endif