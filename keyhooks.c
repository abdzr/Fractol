/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:53:28 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/10 22:26:20 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_stroke(int key, void *test)
{
    t_env *env;

    env = (t_env *)test;
    (key == 53) ? exit(0) : 1;
    if (key == 126)
        env->max = env->max + 5;
    mandeldraw(env);
    return (0);
}