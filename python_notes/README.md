Python 
======
> Sachin Padwalkar | 21-07-2021

-----------------------------------------

Array 
----
use `array[:-1]` to remove the last element

use `array[::-1]` to reverse the string

`list[<start>:<stop>:<step>]`
    
To take arguments in python 
---------------------------
```python
import sys 
 1st_argument = sys.argv[1]
```
Files in python 
---------------
To open
```python
with open("filename","r") as f:
```
if you use `with` then you dont have to use `close()`
| mode | Description |
| --- | --- |
| r | open file to read  |
| w | open file to write it will create a new file if it dosen't exist |
| x | To create a new file |
| a | open to append in the file  |
| t | open in text mode (basically everything) |
| b | open in binary mode |
| + | open file for updating |

Convertion 
------------------
`ord()` to convert ascii to text <br/>
`chr()` to convert text to ascii <br/>
`hex()` to convert to hex   <br/>
`bytearray.fromhex(HEX_VALUE)` to convert hex to string<br/>

PWNTOOLS 
-----

First import   
```python3
from pwn import *
```
| Funtions | Use |
| -- | -- |
| r = remote('link','port') | to establish connection |
| r.recvuntil("STRING") | run until we get that string from the server | 
| r.send | send the input to the server | 

| r.recvline() | to get the text from the line |
