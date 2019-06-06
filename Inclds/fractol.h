/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarzor <azarzor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:08:50 by azarzor           #+#    #+#             */
/*   Updated: 2019/06/06 20:38:14 by azarzor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include "./ft_mlx_keys.h"
# include <math.h>
# include <pthread.h>
# define W 650
# define H 650

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	int				tab[24];
	int				*colors;
	int				max;
	int				row;
	int				col;
	int				iter;
	int				*mlx_data;
	int				bpp;
	int				endian;
	int				size_l;
	int				c;
	int				k;
	double			xx;
	double			yy;
	double			dx;
	double			dy;
	double			mnre;
	double			mxre;
	double			mnim;
	double			mxim;
	double			z;
	double			cre;
	double			cim;
	double			x;
	double			y;
	double			xnew;
	double			scale;
	double			jul_cre;
	double			jul_cim;
}					t_env;

typedef	struct		s_threads
{
	double			x;
	double			y;
	double			xnew;
	double			cre;
	double			cim;
	double			jul_cre;
	double			jul_cim;
}					t_threads;

/*
**		JULIA
*/

int					julia1calc(t_env *env, t_threads thread);
void				juliadraw(t_env *env);
void				*juliadraw1(void *arg);
void				*juliadraw2(void *arg);
void				*juliadraw3(void *arg);
void				*juliadraw4(void *arg);

/*
**		MANDELDBROT
*/

int					mandelcalc(t_env *env, t_threads thread);
void				mandeldraw(t_env *env);
void				*mandeldraw1(void *arg);
void				*mandeldraw2(void *arg);
void				*mandeldraw3(void *arg);
void				*mandeldraw4(void *arg);

/*
**		MANDELDBROT V3
*/

int					mandelv3calc(t_env *env, t_threads thread);
void				mandeldrawv3(t_env *env);
void				*mandeldrawv31(void *args);
void				*mandeldrawv32(void *args);
void				*mandeldrawv33(void *args);
void				*mandeldrawv34(void *args);

/*
**		MANDELDBROT V4
*/

int					mandeldrawv4calc(t_env *env, t_threads thread);
void				mandeldrawv4(t_env *env);
void				*mandeldrawv41(void *args);
void				*mandeldrawv42(void *args);
void				*mandeldrawv43(void *args);
void				*mandeldrawv44(void *args);

/*
**		BURNINSHIP
*/

int					burningshipcalc(t_env *env, t_threads thread);
void				burningshipdraw(t_env *env);
void				*burningshipdraw1(void *arg);
void				*burningshipdraw2(void *arg);
void				*burningshipdraw3(void *arg);
void				*burningshipdraw4(void *arg);

/*
**		JULIA V3
*/

int					juliav3calc(t_env *env, t_threads thread);
void				juliadrawv3(t_env *env);
void				*juliadrawv31(void *arg);
void				*juliadrawv32(void *arg);
void				*juliadrawv33(void *arg);
void				*juliadrawv34(void *arg);

/*
**		JULIA V4
*/
int					juliav4calc(t_env *env, t_threads thread);
void				juliadrawv4(t_env *env);
void				*juliadrawv31(void *arg);
void				*juliadrawv32(void *arg);
void				*juliadrawv33(void *arg);
void				*juliadrawv34(void *arg);

/*
**		TRICORN
*/

int					tridraw(t_env *env, t_threads thread);
void				tricorndraw(t_env *env);
void				*tricorndraw2(void *arg);
void				*tricorndraw3(void *arg);
void				*tricorndraw4(void *arg);
void				*tricorndraw5(void *arg);

/*
** MLX events and image processing
*/

void				images(t_env *env);

/*
**	KEY AND MOUSE HANDLING
*/

int					mouse_move(int x, int y, void *param);
int					key_stroke(int key, void *test);
int					mouse_zoom(int button, int x, int y, void *param);
void				key_stroke2(int key, void *test);
void				mouse(t_env *env);

/*
** Colours
*/

int					rgb(int r, int g, int b);
int					*color1(t_env *env);
int					*color2(t_env *env);
int					*color3(t_env *env);
int					*color4(t_env *env);
int					*color5(t_env *env);
int					*color6(t_env *env);
int					*color7(t_env *env);
int					*color8(t_env *env);

/*
** needed funcs for calculation or initialisation of values
*/

double				ft_abs(double x);
double				ft_map(double n, double start, double min, double max);
void				choice(t_env *env);
void				values(t_env *env);
#endif
