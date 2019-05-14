/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:26:56 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/13 16:37:26 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_mlx_keys.h"

void choice(t_env *env)
{
	if (env->c == 1)
		mandeldraw(env);
	if (env->c == 2)
		juliadraw(env);
	if (env->c == 3)
		burningshipdraw(env);
}

int	printerror(int c)
{
	if (c == 1)
	{
		ft_putendl("Usage : ./fractol Mandelbrot, Julia, Burningship");
		return (0);
	}
	if (c == 2)
	{
		ft_putendl("Usage : ./fractol Mandelbrot, Julia, Burningship");
		exit(0);	
	}
	return(0);
}
void values(t_env *env)
{
	env->minre = (0 - WIN_W / 2.0) * 4.0 / WIN_W;
	env->maxre = (WIN_W - WIN_W / 2.0) * 4.0 / WIN_W;
	env->minim = (0 - WIN_H / 2.0) * 4.0 / WIN_W;
	env->maxim = (WIN_H - WIN_H / 2.0) * 4.0 / WIN_W;
}

int main(int argc, char **argv)
{
	t_env *env;
	env = (t_env *)malloc(sizeof(t_env));

	if (argc != 2)
		printerror(1);
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		env->c = 1;
	else if (ft_strcmp(argv[1], "Julia") == 0)
		env->c = 2;
	else if (ft_strcmp(argv[1], "Burningship") == 0)
		env->c = 3;
	else
		printerror(2);
	env->mlx_ptr = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx_ptr, WIN_W, WIN_H, "testing");
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &env->bpp, &env->size_l, &env->endian);
	env->z = 0;
	env->max = 30;
	env->scale = 1.1;
	values(env);
	choice(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
	mlx_hook(env->mlx_win, 2, 0, &key_stroke, env);
	mlx_hook(env->mlx_win, 4, 0, &mouse_zoom, env);
	mlx_hook(env->mlx_win, 6, 0, &mouse_move, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
