/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:48:28 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 15:49:52 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

void		*juliadraw1(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = -1;
	while (++row <= WIN_W / 2)
	{
		col = -1;
		while (++col <= WIN_H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			thread.x = thread.cre;
			thread.y = thread.cim;
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		*juliadraw2(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = -1;
	while (++row <= WIN_W / 2)
	{
		col = WIN_H / 2;
		while (++col <= WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			thread.x = thread.cre;
			thread.y = thread.cim;
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		*juliadraw3(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = WIN_W / 2;
	while (++row <= WIN_W)
	{
		col = -1;
		while (++col <= WIN_H / 2)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			thread.x = thread.cre;
			thread.y = thread.cim;
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		*juliadraw4(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = WIN_W / 2;
	while (++row <= WIN_W)
	{
		col = WIN_H / 2;
		while (++col <= WIN_H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / WIN_W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / WIN_H) * row;
			thread.x = thread.cre;
			thread.y = thread.cim;
			iter = julia1calc(env, thread);
			if (iter < env->max)
				env->mlx_data[row * WIN_W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		juliadraw(t_env *env)
{
	int			i;
	pthread_t	thread[4];

	images(env);
	i = 0;
	pthread_create(&thread[0], NULL, juliadraw1, (void *)env);
	pthread_create(&thread[1], NULL, juliadraw2, (void *)env);
	pthread_create(&thread[2], NULL, juliadraw3, (void *)env);
	pthread_create(&thread[3], NULL, juliadraw4, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
