Vhdl2sch
========
Vhdl2sch stand for VHDL to schematic converter.

If you need to create a illustration schematic of your VHDL entities Vhdl2Sch is made for you.

It parse your file, find the entitie and create the corespondant schematic with Latex/Tikz.

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

Compilation
-----------
  cd exe/
  make

Test
----
just execute Vhdl2LatexSch
It will produce demo.pdf

If it is ok you now can use Vhdl2LatexSch.

Install
-------
Copy Vhdl2LatexSch to /usr/bin/ or elsewhere in your path

Usage
-----

  Vhdl2LatexSch test.vhd 

with test.vhd your file to convert

