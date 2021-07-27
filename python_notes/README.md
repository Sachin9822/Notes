Python 
======
> Sachin Padwalkar | 21-07-2021

-----------------------------------------

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

Convertion of Ascii
------------------
`ord()` to convert ascii to text
`chr()` to convert text to ascii 
`hex()` to convert to hex 