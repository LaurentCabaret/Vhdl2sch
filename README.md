THIS PROGRAM IS NO LONGER MAINTENED
========
A python version was developped (https://github.com/LaurentCabaret/pyVhdl2Sch).
This C++ version stays here as (dirty) reference.

Vhdl2sch
========
Vhdl2sch stand for VHDL to schematic converter.

If you need to create a illustration schematic of your VHDL entities Vhdl2Sch is made for you.

It parse your file, find the entity and create the corespondant schematic with Latex/Tikz.

Result
======
The result is a pdf (if latex is installed) with a very narrow bounding box so you can import it in a latex document easily.

Supported OS
============
Linux
Not yet windows
Not yet MacOs

How to use it
=============
Requirements
------------
- QT 4.8 (not tested on 5.0 and 5.2)
- lualatex
- Aegyptus font installed 
- 
    cd fonts

    sudo cp Aegyptus.ttf /usr/share/fonts/truetype/aegyptus/
    
    sudo mkdir /usr/share/fonts/truetype/aegyptus


Compilation
-----------
    cd exe/
    make

Test
----
just execute Vhdl2LatexSch
It will produce demo.pdf

    ./Vhdl2LatexSch

If it is ok you now can use Vhdl2LatexSch.

Install
-------
Copy Vhdl2LatexSch to /usr/bin/ or elsewhere in your path

Usage
-----

    Vhdl2LatexSch test.vhd 

with "test.vhd" your file to convert

How to improve it
=================
Requirements
------------
qtcreator
on debian/ubuntu

    apt-get install qtcreator

open the source/Vhdl2LatexSch.pro
and configure your project to build in exe/

What could be very cool to implement (help required)
------------------------------------
  * Auto finding of component usage and global schematic (with sub files) generation
  * Multiple schematic theme (using keywords to select look and feel like in beamer)
  * A clean way to install it (a package ?)


