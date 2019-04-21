#include <mlx.h>
// int     rgb(int r, int g, int b)
// {
//   unsigned char   clr[4];

//   clr[0] = b;
//   clr[1] = g;
//   clr[2] = r;
//   clr[3] = 0;
//   return (*(int *)clr);
// }

// int     *color1(int *tab)
// {
//     tab[0] = rgb(238, 205, 163);
//     return (tab);
// }

int main()
{
    void *mlx_ptr;
    void *mlx_win;
    void *mlx_img;
    int *mlx_data;
    int bpp;
    int endian;
    int size_l;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 800, 800, "test");
    mlx_img = mlx_new_image(mlx_ptr, 800, 800);
    mlx_data = (int *)mlx_get_data_addr(mlx_img, &bpp, &size_l, &endian);
    int x = 0;
    while (x < 800)
    {
        int y = 0;
        while (y < 800)
        {
            mlx_data[x * 200 * y] = 0xFFFFFF;
            x++;
            y++;
        }
    }
    mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
    mlx_loop(mlx_ptr);
    return (0);
}