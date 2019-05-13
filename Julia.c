/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:43:37 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/12 15:48:47 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void juliadraw(t_env *env)
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
			env->x = env->cre;
			env->y = env->cim;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4 && env->iter < env->max)
			{
				env->xnew = env->x * env->x - env->y * env->y + (env->jul_cre);
				env->y = 2 * env->x * env->y + (env->jul_cim);
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < env->max)
				env->mlx_data[env->row * WIN_W + env->col] = env->colors[env->iter % 24];
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
