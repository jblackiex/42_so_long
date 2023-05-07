
<p align="right">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jblackiex/42_so_long?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/jblackiex/42_so_long?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jblackiex/42_so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jblackiex/42_so_long?color=black" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jblackiex/42_so_long?color=green" />
</p>

# 42_so_long
* The aim of this project is to create a small 2D game where players have to pick up all collectables and go to the exit; then you WIN!

## 📜 Index
* [How to play](#How-to-play)
* [Tile map](#Tile-map)
* [Player and Input](##Testing)
* [Enemies](#Enemy-Behaviour)
* [Animation](#Render,-Animation-and-VFX)
* [Structs and Data](#Structs-and-Data)

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
## ❌ Testing, what is the wrong input?

Try a wrong map in the directory map/ inside the 42_so_long dir. For Example:
```shell
** ./so_long_bonus maps/map_err1.ber **
```
if everything works fine a message like this will appear:

```shell
🛑ERROR:
The E/C is unreachable.
```
