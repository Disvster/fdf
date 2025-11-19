# to-do

## 19/11/2025

- [ ] fix arrow hooks behaviour

## 18/11/2025

- [X] on error like file not found I should free everything before (or not even) exit
    - I'm not freeing memory from previously created maps
    - see `valgrind --leak-check=full --show-leak-kinds=all ./fdf test_maps/elem.fdf test_maps/basictest.fdf test_maps/10-2` <- lacks `.fdf`
- [X] solved still reachable in fdf_dlist_clear (init_data_array ptr)


## 14/11/2025

- [X] BONUS: list are implemented but hooks are not working properly,  ~~and there are two windows being opened~~

## 12/11/2025

- [X] check if map is .fdf
- [X] check all the maps
- [X] create bonus branch

## 11/11/2025

- [X] maps with colors are get drawn with shitty colors
- [X] big maps are taking too long to open
    - might be because of static variable
    - [X] solving this 

- [X] pylone is not rectangular so it fucks projection

## 10/11/2025

- for bonus:
    - [ ] rotations
    - [ ] change colors
    - [ ] draw on the opposite side when map goes out of bounds
    - [ ] flinging map with mouse
    - [X] loading more maps in the same window

- [X] check if exits are returning the correct number

- here is a list of all the maps that don't work as they should:
    - [X] elem-fract - wating then doesnt open
    - [X] julia - same as above
    - [X] pylone - is shifting the X coords to the side UPDATE: it stays like that idc
    - [X] t1 - invalid color format
    - [X] t2 - invalid color format

## 08/11/2025

- [X] set up hooks
- [X] close program safely

## 05/11/2025

- [X] pylone working but there is a ghost point
    - [X] error was on set point, xline was given split after free and should exit
    * post-NOTE: error was on `xi` val calculation. changed xi to static and to increment between func calls
- [X] implement z height variable
- [X] render_map changed to previous code for testing - post-NOTE: either version works fine so far

## 03/11/2025

* ASAP - max prio:
- [X] correct norm on everything
- [X] segfault on pylone
- [X] must center and resize every map
- ~**TRY** to apply xiaowu vertice on lines~
- [X] exit the map parsing safely

## 21/10/2025

- [X] understand xiaolin wu algo
- [X] understand how to use mlx to draw

## 21/10/2025

- [X] watch xiaolin wu algo for drawing lines

## 19/10/2025

- [X] fix libft makefile re-linking

## 17(18)/10/2025

- [X] parsed map to points into `t_point *data` array
    - [X] 1 byte still reachable from gnl - fixed by calling gnl one more time
    - [X] fix size of funcs

- [X] unite points
- [X] check why and how I should use math equations
