/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:53:04 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/08 12:02:09 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		calc(double start, double end, double zoom)
{
	return((start) + (end - start) * zoom);
}

void		zoom(t_env *env, double mouseRe, double mouseIm, double zoomFactor)
{
	double interpolation;

	interpolation = 1.0 / zoomFactor;
	env->minre = calc(mouseRe, env->minre, interpolation);
	env->minim = calc(mouseIm, env->minim, interpolation);
	env->maxre = calc(mouseRe, env->maxre, interpolation);
	env->maxim = calc(mouseIm, env->maxim, interpolation);
}

void		images(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->mlx_win);
	mlx_destroy_image(env->mlx_ptr, env->mlx_img);
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &(env->bpp),
											 &(env->size_l), &(env->endian));
}

void mandeldraw(t_env *env)
{
	images(env);	
	env->row = -1;
	while (++env->row < WIN_W)
	{
		env->col = -1;
		while (++env->col < WIN_H)
		{
			env->cre = (env->col - WIN_W / 2.0) * 4.0 / WIN_W;
			env->cim = (env->row - WIN_H / 2.0) * 4.0 / WIN_W;
			env->x = 0;
			env->y = 0;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4 && env->iter < 500)
			{
				env->xnew = env->x * env->x - env->y * env->y + (env->cre * (1.1 + env->z));
				env->y = 2 * env->x * env->y + (env->cim * (1.1 + env->z));
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < 500)
				env->mlx_data[env->row * 600 + env->col] = rgb(255, 255, 255);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
