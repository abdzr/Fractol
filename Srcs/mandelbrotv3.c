/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotv3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:35:29 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 20:08:38 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

void			*mandeldrawv31(void *args)
{
	t_env		*env;
	t_threads	thread;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)args;
	row = -1;
	while (++row <= W / 2)
	{
		col = -1;
		while (++col <= H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / H) * row;
			env->x = 0;
			env->y = 0;
			iter = mandelv3calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			*mandeldrawv32(void *args)
{
	t_env		*env;
	t_threads	thread;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)args;
	row = -1;
	while (++row <= W / 2)
	{
		col = H / 2;
		while (++col <= H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / H) * row;
			env->x = 0;
			env->y = 0;
			iter = mandelv3calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			*mandeldrawv33(void *args)
{
	t_env		*env;
	t_threads	thread;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)args;
	row = W / 2;
	while (++row <= W)
	{
		col = -1;
		while (++col <= H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / H) * row;
			env->x = 0;
			env->y = 0;
			iter = mandelv3calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			*mandeldrawv34(void *args)
{
	t_env		*env;
	t_threads	thread;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)args;
	row = W / 2;
	while (++row <= W)
	{
		col = W / 2;
		while (++col <= H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / H) * row;
			env->x = 0;
			env->y = 0;
			iter = mandelv3calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void			mandeldrawv3(t_env *env)
{
	int			i;
	pthread_t	thread[4];

	images(env);
	i = 0;
	pthread_create(&thread[0], NULL, mandeldrawv31, (void *)env);
	pthread_create(&thread[1], NULL, mandeldrawv32, (void *)env);
	pthread_create(&thread[2], NULL, mandeldrawv33, (void *)env);
	pthread_create(&thread[3], NULL, mandeldrawv34, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
