
<p align="right">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jblackiex/42_so_long?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/jblackiex/42_so_long?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jblackiex/42_so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jblackiex/42_so_long?color=black" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jblackiex/42_so_long?color=green" />
</p>

# 42_so_long
* The aim of this project is to create a small 2D game where players have to pick up all collectables and go to the exit; then you WIN!

## 📜 Instruction set

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`

<hr>

Compile with:
```shell
make
```
or
```shell
** make bonus ** 
--> this is better, trust me :->
```
<hr>

Execute with:
```shell
./so_long_bonus maps/name_of_a_map.ber
```
## ❌ Testing

Try a wrong map in the directory map/ inside the 42_so_long dir. For Example:
```shell
** ./so_long_bonus maps/map_err1.ber **
```
if everything works fine a message like this will appear:

```shell
🛑ERROR:
The E/C is unreachable.
```
