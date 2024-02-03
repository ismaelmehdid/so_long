<h1 align="center">
	✏️ so_long (mini 2d game)
</h1>

## 💡 About the project

> This project is a minigame, you have to take all the collectibles to be able to leave.
> If you touch an enemy you lose!

## 🛠️ Usage

### Requirements

The project is written in the C language and requires the **`gcc` compiler** to run.

### Instructions

**1. Compiling so_long**

To compile, go to the project folder and run :

```shell
$ make bonus
```

**2. Playing so_long**

```shell
./so_long srcs_bonus/maps/map.ber
```
In the **"map"** directory, there are three maps that you can customize.

Inside the "map.ber" files, **the walls are represented as "1", empty spaces as "0", player spawn as "P", collectibles as "C", enemies as "A", and the exit as "E"**.

Remember that **the map must be surrounded by walls**, **contain only one player spawn (P)**, **one exit (E)**, **and one or more collectibles (C)**.

Additionally, **the map must form a rectangle and be playable**, meaning that the player must be able to access all collectibles and the exit. Otherwise, you will not be able to start the game.

