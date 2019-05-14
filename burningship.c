/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:11:02 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/13 16:13:07 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_abs(double x)
{
	if (x < 0)
		return (-x);
	else if (x > 0)
		return (x);
	return (0);
}

void burningshipdraw(t_env *env)
{
	env->colors = aqua_blue(env);
	images(env);	
	env->row = -1;
	while (++env->row < WIN_W)
	{
		env->col = -1;
		while (++env->col < WIN_H)
		{
			env->cre = env->minre + ((env->maxre - env->minre) / WIN_W) * env->col;
			env->cim = env->minim + ((env->maxim - env->minim) / WIN_H) * env->row;
			env->x = 0;
			env->y = 0;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4 && env->iter < env->max)
			{
				env->xnew = env->x * env->x - env->y * env->y + (env->cre);
				env->y = ft_abs(2 * env->x * env->y)+ (env->cim);
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < env->max)
				env->mlx_data[env->row * WIN_W + env->col] = env->colors[env->iter % 24];
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}