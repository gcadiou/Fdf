/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:31:37 by gcadiou           #+#    #+#             */
/*   Updated: 2017/10/26 21:25:09 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfdf.h"

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		size_line;
//	struct s_pixel	pixel;
	struct s_img	img;
	union u_pixel	pixel;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	img.adr = mlx_new_image(mlx, 400, 400);
	img.data = mlx_get_data_addr(img.adr, &(img.bpp), &(img.size_line), &(img.endian));
	pixel.i = 0x00FFFFFF;
	y = 50;
//	printf("%u\n", (unsigned int)0x00FFFF00);
//	printf("%u\n", pixel.i);
//	printf("%u\n", pixel.tab[2]);
	while (y < 150)
	{
		x = 100;
		while (x < 150)
		{
		//	mlx_pixel_put(mlx, win, x, y, pixel.i);
			put_pixel_to_img(&img, x, y, &pixel);
			/*string[(y * 400 + x) * (bpp / 8)] = 0xFF;
			string[(y * 400 + x) * (bpp / 8) + 1] = 0xFF;
			string[(y * 400 + x) * (bpp / 8) + 2] = 0xFF;
			string[(y * 400 + x) * (bpp / 8) + 3] = 0x00;*/
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img.adr, 0, 0);
	mlx_loop(mlx);
	return (0);
}