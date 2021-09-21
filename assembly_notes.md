Assembly Notes
===========

> Sachin Padwalkar | 1/8/2021

What is Assembly Language 
---------------
Machines only understand 0s and 1s but it is difficult for humans to remember each of the pattern so we use mnemonics 
> mnemonics are the name of the machine code instruction. It consists of 3 letters
the program which are written using mnemonics is called `Assembly Language` 

1 ARM Assembly 
-----------

1.1 Datatypes
------
There are two types of datatypes signed and unsigned(cannot store negative values but can store large values)

`ldr` is used to load the values **from** the registers 
`str` is used to load the values **into** the registers

`ldrh / strh` = load unsigned half words
`ldrsh / strsh` = load signed half words
`ldrb / strb` = load unsigned byte
`ldrsb / strsb` = load signed bytes

1.2 Endianness
-----
It is basically the way to viewing the bytes 
they are basically two types 
1. Little-Endian (LE)
2. Big-Endian (BE)

Armv8-a is LE

![](big-little-endian-1-.png)




