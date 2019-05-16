/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:04:08 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/16 13:05:50 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void		tricorndraw(t_env *env)
{
	images(env);
	while (++env->row < WIN_W)
	{
		env->col = -1;
		while (++env->col < WIN_H)
		{
			env->cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * env->col;
			env->cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * env->row;
			env->x = 0;
			env->y = 0;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4
					&& env->iter < env->max)
			{
				env->xnew = env->x * env->x - env->y * env->y + (env->cre);
				env->y = -2 * env->x * env->y + (env->cim);
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < env->max)
				env->mlx_data[env->row * WIN_W + env->col] =
					env->colors[env->iter % 24];
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}