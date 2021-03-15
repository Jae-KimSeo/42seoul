/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:26:50 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/18 15:27:51 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define PIXEL_SIZE   3
#define PIXEL_ALIGN  4

t_bitmapfileheader		get_file_header(void)
{
	t_bitmapfileheader	bmp_f_h;

	bmp_f_h.bf_type1 = (unsigned char)'B';
	bmp_f_h.bf_type2 = (unsigned char)'M';
	bmp_f_h.bf_size = 54 + 3 * g_width * g_height;
	bmp_f_h.bf_reserved1 = 0;
	bmp_f_h.bf_reserved2 = 0;
	bmp_f_h.bf_off_bits = 54;
	return (bmp_f_h);
}

t_bitmapinfoheader		get_info_header(void)
{
	t_bitmapinfoheader	bmp_i_h;

	bmp_i_h.bi_size = 40;
	bmp_i_h.bi_width = g_width;
	bmp_i_h.bi_height = -g_height;
	bmp_i_h.bi_planes = 1;
	bmp_i_h.bi_bit_count = 24;
	bmp_i_h.bi_compression = 0;
	bmp_i_h.bi_size_image = 3 * g_width * g_height;
	bmp_i_h.bi_x_pels_per_meter = 0;
	bmp_i_h.bi_y_pels_per_meter = 0;
	bmp_i_h.bi_cir_used = 0xffffff;
	bmp_i_h.bi_cir_used = 0;
	return (bmp_i_h);
}

static void				draw_img(const int fd, t_info *info, int padding)
{
	int					i;
	int					j;

	i = -1;
	while (++i < g_height)
	{
		j = -1;
		while (++j < g_width)
			write(fd, &info->img.data[i * g_width + j], 3);
		j = -1;
		while (++j < padding)
			write(fd, "\x00", 1);
	}
}

void					save_bmp(t_info *info)
{
	t_bitmapfileheader	bmp_f_h;
	t_bitmapinfoheader	bmp_i_h;
	int					fd;
	int					padding;

	padding = (PIXEL_ALIGN - ((g_width * PIXEL_SIZE) % PIXEL_ALIGN)) \
	% PIXEL_ALIGN;
	fd = open("cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	bmp_f_h = get_file_header();
	bmp_i_h = get_info_header();
	write(fd, &bmp_f_h, 14);
	write(fd, &bmp_i_h, 40);
	draw_img(fd, info, padding);
	write(1, "cub.bmp file has been saved\n", 28);
	close(fd);
}
