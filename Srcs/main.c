/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:26:56 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 20:09:15 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

void		choice(t_env *env)
{
	if (env->c == 1)
		mandeldraw(env);
	if (env->c == 2)
		juliadraw(env);
	if (env->c == 3)
		burningshipdraw(env);
	if (env->c == 4)
		juliadrawv3(env);
	if (env->c == 5)
		juliadrawv4(env);
	if (env->c == 6)
		mandeldrawv3(env);
	if (env->c == 7)
		mandeldrawv4(env);
	if (env->c == 8)
		tricorndraw(env);
}

int			printerror(int c)
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
	return (0);
}

void		mlxinit(t_env *env)
{
	env->z = 0;
	env->k = 1;
	env->max = 30;
	env->scale = 1.1;
	env->colors = color1(env);
	values(env);
	choice(env);
}

int			main(int argc, char **argv)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	env->colors = (int *)malloc(sizeof(int) * 24);
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
	env->mlx_win = mlx_new_window(env->mlx_ptr, W, H, "testing");
	env->mlx_img = mlx_new_image(env->mlx_ptr, W, H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &env->bpp,
	&env->size_l, &env->endian);
	mlxinit(env);
	mouse(env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
