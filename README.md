
<p align="right">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jblackiex/42_so_long?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/jblackiex/42_so_long?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jblackiex/42_so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jblackiex/42_so_long?color=black" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jblackiex/42_so_long?color=green" />
</p>

# 42_so_long 🧙 
* The aim of this project is to create a small 2D game where players have to pick up all collectables and go to the exit; then you WIN!

-->> Prior to starting with this project, clone the repository, then go into it and clone this repository:
Clone https://github.com/42Paris/minilibx-linux into ``42_so_long`` dir.
MiniLibX is the simple graphic library that we use at 42 and it's useful to deal with images in this project.

<img src="https://github.com/jblackiex/42_so_long/blob/7e1f813eb4925cdf4e53cff1a007f151f6e4a9d5/textures/so_long.gif" alt="map_enemy3.ber" style="width:220px;height:220px;" border="3">

## 📜 Index
* [How to play 🕹️](#How-to-play)
* [What's a wrong input? ❌](#Testing)
* [map_enemy3.ber 🗝](#map_enemy3)
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
| C | Collectible. |
| E | Exit. |
| P | Player starting position. |
| F | Cloning enemy. With each move, some enemies are appearing and disappearing, while others are duplicating |

* The map must be a rectangle surrounded by walls ‘1’.
* It must have one exit ‘E’ and at least one collectable ‘C’. And only one player ‘P’.

---> see some examples in the ``maps/`` folder of this project. TRY ---> [Puzzle-map 🗝](#map_enemy3)

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

👾 Enemies move after you do, or maybe NOT.. you'll find out! They move after you one tile at a time BUT some of them move two or even more tiles at a time, and will kill you when you move into their tile or they move into yours. After picking up all "magic-balls", the exit open and you may leave to see how many moves you’ve used to solve the map.

* ☢️ IFFFF you want there's something even more harder, DANGEROUS instead... it's IMPOSSIBLE to WIN with ``./so_long_bonus map_enemy3.ber`` ---> [Puzzle-map 🗝](#What-you-need-to-know)

You can exit the game with esc.

## map_enemy3
<img src="https://github.com/jblackiex/42_so_long/blob/757f2d3404e1e4f54b0cafbff9ee7d6018773c2a/map_enemy3.png" alt="map_enemy3.ber" style="width:250px;height:100px;" border="3">

``map_enemy3.ber`` it's NOT a game, it's a ``WAR``  🗡️

---> Solve the map within a time frame that is suitable for a human being.. How?
<hr>

###### How
* Don't panic
###### What you need to know
| Object | What if ? |
| - | - |
| C or Collectible | if you pick up ``max_collectibles``/2 you achive the ``"X status"``
| X status ✗| if you achive this status you are almost done, BUT now if you eat a "magic-ball" next to enemy AND you are in "X mode" you lose |
| LAST Collectible ⚗️| if you pick up ``all - 1`` collectibles you are fine |
| FIRST Collectible and the next one.. | if you start mind your last game |
| F or Enemy 💎| Cloning enemy. With each move, some enemies are appearing and disappearing, while others are duplicating, MIND your next move |
| Best Rule | if you lost, maybe don't trust me 100%, trust me 98% |
