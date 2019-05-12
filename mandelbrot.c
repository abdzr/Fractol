/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:53:04 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/11 05:52:13 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libft/libft.h"


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
	env->colors = clrs(env);
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
				env->y = 2 * env->x * env->y + (env->cim);
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < env->max)
				env->mlx_data[env->row * WIN_W + env->col] = env->colors[env->iter % 24];
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}

void juliadraw(t_env *env)
{
	env->colors = clrs(env);
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

void burningshipdraw(t_env *env)
{
	env->colors = clrs(env);
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