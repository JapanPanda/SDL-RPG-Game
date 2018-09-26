# SDL-RPG-Game
SDL Game

# Contributors
Developers - JapanPanda

Artists - aechu bha3 XRayXD

Makefile - Technius

# Preview
(Note: the gif's are choppy but the game runs at 60 fps on a virtually every machine)

Tilemapping and tile collision: ![Unable to load image, please contact JapanPanda](https://i.imgur.com/ILEcLxL.gif)

Projectiles (WIP): ![Unable to load image, please contact JapanPanda](https://i.imgur.com/Kiydgrp.gif)

Level Changing: ![Unable to load image, please contact JapanPanda](https://i.imgur.com/XlaQL5c.gif)

# Currently working on
- Properly implementing tile properties for ALL tiles

# How to compile
Install SDL (google it, it depends on your IDE and Operating System)

If windows, make sure you move the .dlls to the directory with the .sln

If linux, use the included Makefile (Thanks to Technius)

# What I'm using: Visual Studio 2017 
With this tutorial

http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvsnet2010u/index.php 

you can get setup pretty fast.

# Level format
First 2 integers are height and width respectively, then the next 4 strings have the filePath of the map to load next in the order up left right down, and the rest are tile types
