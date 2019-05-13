/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:30:14 by azarzor           #+#    #+#             */
/*   Updated: 2019/05/12 15:48:39 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"
#include <math.h>
#define WIN_W 650
#define WIN_H 650

typedef struct s_env
{
    void *mlx_ptr;
    void *mlx_win;
    void *mlx_img;
    int tab[24];
    int *colors;
    int max;
    int row;
    int col;
    int iter;
    int *mlx_data;
    int bpp;
    int endian;
    int size_l;
    double minre;
    double maxre;
    double minim;
    double maxim;
    double z;
    double cre;
    double cim;
    double x;
    double y;
    double xnew;
    double scale;
    double jul_cre;
    double jul_cim;
} t_env;

int key_stroke(int key, void *test);
void mandeldraw(t_env *env);
void mandelcalcul(t_env *env);
void mandelcolor(t_env *env);
int rgb(int r, int g, int b);
int *clrs(t_env *env);
void juliadraw(t_env *env);
double ft_abs(double x);
void burningshipdraw(t_env *env);
int *fireorange(t_env *env);
int *aqua_blue(t_env *env);
void images(t_env *env);
int mouse_zoom(int button, int x, int y, void *param);
double ft_abs(double x);
void values(t_env *env);
double ft_map(double n, double start, double min, double max);
int mouse_move(int x, int y, void *param);
void burningshipdraw(t_env *env);
#endif
