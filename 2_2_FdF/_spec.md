
 linking various points (x, y, z) thanks to line segments (edges).
- must use the MiniLibX, makefile

# Rendering
- The coordinates of the landscape are stored in a .fdf file passed as a parameter to your program

Each number represents a point in space:
• horizontal pos = axis.
• vertical pos = ordinate.
• value pos = altitude.

Use libft get_next_line(), ft_split() to read data from the file in a quick and simple way

# Graphic Management 
- display image in a window
• The management of your window must remain smooth (changing to another window, minimizing, and so forth).
• Pressing ESC must close the window and quit the program in a clean way.
• Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
• The use of the images of the MiniLibX is mandatory

# MiniLibX

## Installation

- unzip minilibx-linux.tgz
- cd in and call ./configure (no need to install dependencies)
- rename folder from "minilibx_linux" to "mlx_linux"
- use following line to compile and example project (taken from tutorial here: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#introduction and named minilibx-test.c)
$ cc minilibx-test.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz && ./a.out

## Basic Operation

- `mlx_init` function returns a void * which holds the location of our current MLX instance
- `mlx_new_window` function (height, width and a title) returns a pointer to the window
- `mlx_loop` initiates the window rendering
- `mlx_pixel_put` pushes pixels to the window (and is very slow)
- instead we use `mlx_new_image` (mlx instance, width, height) to buffer pixels to an image, which we then push to the window
- to write to the image, we get the memory address on which we will mutate the bytes accordingly
- img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
- the bytes are not aligned, meaning the line_length differs from the actual window width, so we calc memory offset with `mlx_get_data_addr` using this formula
- `int offset = (y * line_length + x * (bits_per_pixel / 8));`
- now we create a 'my_mlx_pixel_put' function to do all the above for us (see `minilibx-test.c`)
- Note:0x00FF0000 is the hex representation of ARGB(0,255,0,0).

## Terminology

Isometric projection is a method for visually representing three-dimensional objects in two dimensions in technical and engineering drawings. It is an axonometric projection in which the three coordinate axes appear equally foreshortened and the angle between any two of them is 120 degrees.

## Thinking About The Problem
- we are essentially drawing lines between pre-determined coordinates
- negative numbers must be handled
- when the whole map is zero we just have a flat grid
- when a single point is raised we see a peak
- Q: do some points occlude others?
- Q: can we use the 

There will be an angle of rotation around which the diagram will be plotted
Our horizontal position in the table will move along the x axis of this
Our horizontal position in the table will move along the y axis of this
How far we move depends on our viewpoint
If viewed from above we just see a grid

000
010
000

 x  y
[0][0]: x = , y = , z = 
[1][0]: x = , y = , z = 
[2][0]: x = , y = , z = 
[0][1]: x = , y = , z = 
[1][1]: x = , y = , z = 
[2][1]: x = , y = , z = 
[0][2]: x = , y = , z = 
[1][2]: x = , y = , z = 
[2][2]: x = , y = , z = 

0000
0110
0000

0000
0110
0110
0000

## Simply the Methods We Will Use:

1. Plot a 3d point on a 2d plane (the screen).
where the 3d are the coords in the text file

destination.x = source.x + cos(angle) * source.z - cos(angle) * source.y
destination.y = -source.y * sin(angle) - source.z * sin(angle)

2. Plot lines between the points using Bresenham's line algorithm

## Write 

https://beginnersbook.com/2014/01/2d-arrays-in-c-example/



# Resources

https://github.com/ailopez-o/42Barcelona-FdF
https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
https://www.scratchapixel.com/lessons/3d-basic-rendering/rasterization-practical-implementation/rasterization-stage.html
https://git.42l.fr/Fabien/fdf