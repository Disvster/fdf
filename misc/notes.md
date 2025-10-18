# FdF notes

## compiling

You will need the `minilibx-{OS}` directory. `cd` into it and run `./configure`. If you run into problems try replacing the `CC` variable inside the makef
iles to `clang`. After mlx compiles you'll end up with 2 files: `libmlx.a` and `libmlx_{Linux/Mac}`.

### adding mlx as a lib in your pc

I added the **minilibx** library to my laptop environment, according to the README.md in the minilib repo.

- copied `libmlx.a` and `libmlx_linux.a` into `/usr/local/lib`
- copied `mlx.h` into `/usr/local/include`
- copied `man/man3/mlx*.3` into `/usr/local/man/man3`

I can include **mlx.h** in my `src/*.c` files with:
```C
#include <mlx.h>
//OR
#include "mlx.h"

int main()
[...]
```
and compile with:
```sh
cc src/*.c -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
```

### running mlx inside the FdF repo

To use and compile it **without adding it into the actual environment**, you will have to compile your `src/*.c` files and mlx `.a` files all together, while including the `.h` files from `minilib/`.

Include **mlx.h** in `src/*.c` files with:
```C
#include "mlx.h"

int main()
[...]
```

and compile with:
```sh
# cc src/*.c libmlx.a libmlx_{LINUX/MAC}.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# in 42 env below
ccw src/*.c libmlx.a libmlx_Linux.a libft.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -I incs/ -g 
```
