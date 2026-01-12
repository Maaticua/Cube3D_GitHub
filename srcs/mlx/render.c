/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:54:48 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/12 14:21:59 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int	create_color(int r, int g, int b)
{
	return ((int)((r << 16) | (g << 8) | b));
}

void	render_floor_n_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;

	x = 0;
	y = 0;
	floor_color = create_color(game->floor.r, game->floor.g, game->floor.b);
	ceiling_color = create_color(game->ceiling.r, game->ceiling.g,
			game->ceiling.b);
	while (y < WINDOW_HEIGHT)
	{
		while (x < WINDOW_WIDTH)
		{
			if (y < (WINDOW_HEIGHT / 2))
				put_pixel(game->img, x, y, ceiling_color);
			else if (y >= (WINDOW_HEIGHT / 2))
				put_pixel(game->img, x, y, floor_color);
			x++;
		}
		x = 0;
		y++;
	}
}

int	render_frame(void *game_ptr)
{
	t_game	*game;

	game = (t_game *)game_ptr;
	update_pos_n_dir(game);
	render_floor_n_ceiling(game);
	ray_casting(game);
	render_sprites(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_ptr, 0, 0);
	return (0);
}
