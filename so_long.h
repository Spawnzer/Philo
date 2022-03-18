/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:27:28 by adubeau           #+#    #+#             */
/*   Updated: 2022/02/01 12:18:18 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_pos
{
	int			play_x;
	int			play_y;
}				t_pos;

typedef struct s_state
{
	t_pos		pos;
	int			remain;
	int			moves;
	int			game_state;
}				t_state;

typedef struct s_img
{
	void		*img_ptr;
	int			*addr;
	int			size_line;
	int			bits_pixel;
	int			end;
}				t_img;

typedef struct s_obj
{
	void		*player;
	void		*collect;
	void		*wall;
	void		*exit;
}				t_obj;

typedef struct s_map
{
	t_img		img;
	char		**array;
	t_obj		objects;
	int			height;
	int			width;
}				t_map;

typedef struct s_sl
{
	void		*mlx;
	void		*win;
	t_map		map;
	int			win_height;
	int			win_width;
}				t_sl;
