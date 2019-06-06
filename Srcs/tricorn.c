/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:04:08 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 20:09:15 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inclds/fractol.h"

void		*tricorndraw1(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
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
			iter = tridraw(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		*tricorndraw2(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
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
			iter = tridraw(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		*tricorndraw3(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
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
			iter = tridraw(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		*tricorndraw4(void *arg)
{
	t_threads	thread;
	t_env		*env;
	int			iter;
	int			row;
	int			col;

	env = (t_env *)arg;
	row = W / 2;
	while (++row <= W)
	{
		col = H / 2;
		while (++col <= H)
		{
			thread.cre = env->mnre + ((env->mxre - env->mnre) / W) * col;
			thread.cim = env->mnim + ((env->mxim - env->mnim) / H) * row;
			env->x = 0;
			env->y = 0;
			iter = tridraw(env, thread);
			if (iter < env->max)
				env->mlx_data[row * W + col] =
					env->colors[iter % 24];
		}
	}
	pthread_exit(NULL);
}

void		tricorndraw(t_env *env)
{
	int			i;
	pthread_t	thread[4];

	images(env);
	i = 0;
	pthread_create(&thread[0], NULL, tricorndraw1, (void *)env);
	pthread_create(&thread[1], NULL, tricorndraw2, (void *)env);
	pthread_create(&thread[2], NULL, tricorndraw3, (void *)env);
	pthread_create(&thread[3], NULL, tricorndraw4, (void *)env);
	while (i < 4)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->mlx_win, env->mlx_img, 0, 0);
}
