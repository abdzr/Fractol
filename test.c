/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:01:17 by azarzor           #+#    #+#             */
/*   Updated: 2019/04/24 10:50:17 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
    t_env env;
    env.mlx_img = mlx_new_image(env.mlx_ptr, 1000,1000);
    env.mlx_data = mlx_get_data_addr(env.mlx_img, env.bpp, env.size_l, env.endian);




    return(0);
}