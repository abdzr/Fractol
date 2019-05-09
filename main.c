/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:26:56 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/09 13:35:33 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	values(t_env *env)
{
	env->minre = (0 - WIN_W / 2.0) * 4.0 / WIN_W;
	env->maxre = (WIN_W - WIN_W / 2.0) * 4.0 / WIN_W;
	env->minim = (0 - WIN_H / 2.0) * 4.0 / WIN_W;
	env->maxim = (WIN_H - WIN_H / 2.0) * 4.0 / WIN_W;
}

int main()
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx_ptr = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx_ptr, WIN_W, WIN_H, "testing");
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &env->bpp, &env->size_l, &env->endian);
	env->z = 0;
	env->max = 30;
	values(env);
	mandeldraw(env);
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
	mlx_hook(env->mlx_win, 2, 0, &key_stroke, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
