/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:30:14 by azarzor           #+#    #+#             */
/*   Updated: 2019/04/27 16:13:56 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_env t_env;
struct s_env
{
    int         row;
    int         col;
    double      cre;
    double      cim;
    double      x;
    double      y;
    double      xnew;
    int         iter;
    int         *mlx_data;
    int         bpp;
    int         endian;
    int         size_l;
    void        *mlx_ptr;
    void        *mlx_win;
    void        *mlx_img;
};

#endif
