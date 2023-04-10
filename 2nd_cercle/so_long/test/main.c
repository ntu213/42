





#include "../mlx/mlx_int.h"
#include "../mlx/mlx.h"

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*imgg;
}				t_data;

void	retourne(int i)
{
	exit(i);
}

int	destroy(t_data *img)
{
//	mlx_destroy_image(img->mlx, img->imgg);
//	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_image(img->mlx, img->imgg);
	mlx_destroy_display(img->mlx);
	(void)img;
	free(img->mlx);
	free(img);
	exit (0);
}

int	destroy2(int key, t_data *img)
{
	printf("%d\n", key);
//	mlx_destroy_image(img->mlx, img->imgg);
//	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_image(img->mlx, img->imgg);
	mlx_destroy_display(img->mlx);
	(void)key;
	(void)img;
	free(img->mlx);
	free(img);
	exit (0);
}

int	main(void)
{
	t_data	*img;
	char	*relative_path = "../textures/wall.xpm";
	int		img_width;
	int		img_height;

	img = malloc(sizeof(t_data));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
//	img->imgg = mlx_new_image(img->mlx, 50, 50);
	img->imgg = mlx_xpm_file_to_image(img->mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgg, 0, 0);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgg, 50, 0);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgg, 0, 50);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgg, 50, 50);
	mlx_hook(img->mlx_win, 17, 1L << 0, destroy, img);
	mlx_hook(img->mlx_win, 2, 1L << 0, destroy2, img);
	mlx_loop(img->mlx);
	retourne(0);
}
