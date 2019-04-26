# SDL-RPG-Game (DEPRECATED)
SDL Game (DEPRECATED)

# Why Deprecate?
This was supposed to be a fun summer project, but as I got further and further into developing the game engine, it became increasingly difficult and I realised the scale of what I was trying to do to. As summer ended, I realised that if I were to ever finish this project, it would take an absurd amount of time and dedication, both of which could be given to my studies instead.

# What Did I Learn?
* Make sure you understand the scale and difficulty of the project beforehand.
* Object-Oriented Programming can become quickly convuluted, and it is incredibly useful to plan the file and class structure before starting the project
* Developing a game engine from a low level library by oneself is extremely time consuming


# Contributors
Developers - JapanPanda

Artists - aechu bha3 XRayXD Minhs2

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
