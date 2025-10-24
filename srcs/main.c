#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

int main(void)
{
	void *mlx;
//	void *win;

	mlx = mlx_init();
	mlx_new_window(mlx, 800, 600, "Cube3D Test");
	mlx_loop(mlx);
	return (0);
}
