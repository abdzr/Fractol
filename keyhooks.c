/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:53:28 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/08 22:43:29 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_stroke(int key, void *test)
{
    t_env *env;

    env = (t_env *)test;
    // mlx_clear_window(env->mlx_ptr, env->mlx_win);
    (key == 53) ? exit(0): 1;
    if (key == 126)
        env->z = env->z - 0.1;
    mandeldraw(env);
    return (0);
}

// int     mouse_hook(int mouse, int x, int y, t_env *env)
// {
//     if (mouse == 4)
//     {
//         zoom(x, y 0.9, env)
        
//     }
// }