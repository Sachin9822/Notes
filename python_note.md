Python 
======
> Sachin Padwalkar | 21-07-2021

-----------------------------------------

Note
-------
when the length of variable exceed it will go to the start of the varaible

`:=` is same as `=`
`-~x` increments the value of x
`-~-x` decrements the value of x

Array and list
------------
use `array[:-1]` to remove the last element

use `array[::-1]` to reverse the string

`list[<start>:<stop>:<step>]`

to print in hexadecimal format use 
```python
result = "{:02x}".format(a+b)
```

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


re Module 
-----

To search text 
```python3
import re

m = re.search(r"HTB{.*?}",TEXT)
print(m.group()) // to print
```

requests Module
----

Get request
```python3
import requests

r = requests.get("{URL}")

s = requests.Session() # this will create a session

# to pass params
r = requests.get("{URL}", params= {
    "VARIABLE" : "VALUES",
    })

```

Crypto Module 
------

To use inverse and long_to_bytes 
```python3
from Crypto.Util.number import inverse, long_to_bytes

a = inverse(2,7) # inverse of 2 then mod 7
b = long_to_bytes(312879247182346) # this will convert it to string bytes

```


libnum module
------
`n2s` converts number to strings
`s2n` converts string to number 

Gmpy2 module
------
**do this before installation**
```bash
sudo apt install libmpc-dev
```
It is useful when you are working with large numbers

use `gmpy.iroot(9,2)` which is equivalent to 9^1/2
It returns to value first is the number and second boolean (true if it is perfect root)