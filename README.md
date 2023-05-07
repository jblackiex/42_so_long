
<p align="right">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jblackiex/42_so_long?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/jblackiex/42_so_long?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jblackiex/42_so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jblackiex/42_so_long?color=black" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jblackiex/42_so_long?color=green" />
</p>

# 42_so_long 🧙 
* The aim of this project is to create a small 2D game where players have to pick up all collectables and go to the exit; then you WIN!

## ![gif1.gif](https://drive.google.com/file/d/1y8DQA48qQZwwJsFFF6G2oWR3vney_w3v/view?usp=sharing)

## 📜 Index
* [How to play 🕹️](#How-to-play)
* [What's the wrong input? ❌](#Testing)
* [map_enemy3.ber 🗝](#map_enemy3.ber)
* [Maps 🗺](#Maps)

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

### Maps
🗺 The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |
| F | Cloning enemy. With each move, some enemies are appearing and disappearing, while others are duplicating |

* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

---> see some examples in the ``maps/`` folder of this project. TRY ---> [Puzzle-map 🗝](#Puzzle-game)

### Testing

❌ Try a wrong map in the directory map/ inside the 42_so_long dir. For Example:
```shell
** ./so_long_bonus maps/map_err1.ber **
```
if everything works fine a message like this will appear:

```
🛑ERROR:
The E/C is unreachable.
```
if you want you can try with your own map, find out how here:

* [Maps](#Maps)

## How to play
🕹️ Use WASD or arrows to move one tile at a time.

* Feel free to move in a safe space as the game with no-bonus ---> type ``make`` to create ``./so_long`` 
* Feel free to try something cooler with enemies patrol ---> type ``make bonus`` to create ``./so_long_bonus``

👾 Enemies move after you do, or maybe NOT.. you'll find out! They move after you one tile at a time BUT some of them move two or even more tiles at a time, and will kill you when you move into their tile or they move into yours. After picking up all "magic-balls", the exits open and you may leave to see how many moves you’ve used to solve the map.

* ☢️ IFFFF you want there's something even more harder, DANGEROUS instead... it's IMPOSSIBLE to WIN with ``./so_long_bonus map_enemy3.ber`` ---> [Puzzle-map 🗝](#Puzzle-game)

You can exit the game with esc.

## map_enemy3.ber
``map_enemy3.ber`` it's NOT a game, it's a ``WAR``

Solve the map within a time frame that is suitable for a human being.. How?
#### How
