/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 13:26:56 by azarzor           #+#    #+#             */
/*   Updated: 2019/04/27 16:23:26 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int rgb(int r, int g, int b)
{
	char clr[4];
	clr[0] = b;
	clr[1] = g;
	clr[2] = r;
	clr[3] = 1;
	return (*(int *)clr);
}

int main()
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx_ptr = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx_ptr, 600, 600, "testing");
	env->mlx_img = mlx_new_image(env->mlx_ptr, 600, 600);
	env->mlx_data = (int *)mlx_get_data_addr(env->mlx_img, &env->bpp, &env->size_l, &env->endian);
	env->row = -1;
	while (++env->row < 600)
	{
		env->col = -1;
		while (++env->col < 600)
		{
			// must be optimised.
			env->cre = (env->col - 600 / 2.0) * 4.0 / 600;
			env->cim = (env->row - 600 / 2.0) * 4.0 / 600;

			env->x = 0;
			env->y = 0;
			env->iter = 0;
			while (env->x * env->x + env->y * env->y <= 4 && env->iter < 30)
			{
				env->xnew = env->x * env->x - env->y * env->y + env->cre;
				env->y = 2 * env->x * env->y + env->cim;
				env->x = env->xnew;
				env->iter++;
			}
			if (env->iter < 30)
				env->mlx_data[env->row * 600 + env->col] = rgb(255, 255, 255);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
	mlx_loop(env->mlx_ptr);
	return (0);
}
