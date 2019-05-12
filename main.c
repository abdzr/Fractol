/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:26:56 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/11 15:54:35 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_mlx_keys.h"

double ft_abs(double x)
{
	if (x < 0)
		return (-x);
	else if (x > 0)
		return (x);
	return (0);
}

void values(t_env *env)
{
	env->minre = (0 - WIN_W / 2.0) * 4.0 / WIN_W;
	env->maxre = (WIN_W - WIN_W / 2.0) * 4.0 / WIN_W;
	env->minim = (0 - WIN_H / 2.0) * 4.0 / WIN_W;
	env->maxim = (WIN_H - WIN_H / 2.0) * 4.0 / WIN_W;
}

double ft_map(double n, double start, double min, double max)
{
	double percent;

	percent = n / start;
	return (min + (max - min) * percent);
}

int mouse_zoom(int button, int x, int y, void *param)
{
	t_env *env;
	double newx;
	double newy;

	env = (t_env *)param;
	newx = ft_map(x, WIN_W, env->minre, env->maxre);
	newy = ft_map(y, WIN_H, env->minim, env->maxim);
	if (button == 4)
	{
		env->minre = (env->minre - newx) * env->scale + newx;
		env->maxre = (env->maxre - newx) * env->scale + newx;
		env->minim = (env->minim - newy) * env->scale + newy;
		env->maxim = (env->maxim - newy) * env->scale + newy;
	}
	else if (button == 5)
	{
		env->minre = (env->minre - newx) / env->scale + newx;
		env->maxre = (env->maxre - newx) / env->scale + newx;
		env->minim = (env->minim - newy) / env->scale + newy;
		env->maxim = (env->maxim - newy) / env->scale + newy;
	}
	burningshipdraw(env);
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_env *env;
	double newx;
	double newy;

	env = (t_env *)param;
	newx = ft_map(x, WIN_W, -2, 2);
	newy = ft_map(y, WIN_H, -2, 2);
	env->jul_cre = newx;
	env->jul_cim = newy;
	juliadraw(env);
	return (0);
}

int main()
{
	t_env *env;

	// if (argc != 2)
	// 	ft_putendl("Usage : type Mandelbrot, Julia");
	// if ()
	env = (t_env *)malloc(sizeof(t_env));
	env->mlx_ptr = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx_ptr, WIN_W, WIN_H, "testing");
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &env->bpp, &env->size_l, &env->endian);
	env->z = 0;
	env->max = 30;
	env->scale = 1.1;
	values(env);
	// mandeldraw(env);
	// juliadraw(env);
	burningshipdraw(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
	mlx_hook(env->mlx_win, 2, 0, &key_stroke, env);
	mlx_hook(env->mlx_win, 4, 0, &mouse_zoom, env);
	// mlx_hook(env->mlx_win, 6, 0, &mouse_move, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
