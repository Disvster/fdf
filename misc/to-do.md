# to-do

## 12/11/2025

- [X] maps with colors are get drawn with shitty colors
- [ ] big maps are taking too long to open
    - might be because of static variable
    - [ ] solving this 

- [ ] check if map is .fdf
- [ ] pylone is not rectangular so it fucks projection

## 11/11/2025

- for bonus:
    - [ ] rotations
    - [ ] change colors
    - [ ] draw on the opposite side when map goes out of bounds
    - [ ] flinging map with mouse
    - [ ] loading more maps in the same window

- [ ] check if exits are returning the correct number

- here is a list of all the maps that don't work as they should:
    - [X] elem-fract - wating then doesnt open
    - [X] julia - same as above
    - [ ] pylone - is shifting the X coords to the side
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
