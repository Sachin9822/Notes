CFT 
> Sachin Padwalkar | 22-07-2021
------------------------


Web
----
`cewl` is a cool tool to create a wordlist
[hookbin](https://hookbin.com/) to send http response
	



General Skills 
===========
| Tools | Description |
| --- | --- |
| `strings` | to find readable txt in file |
| `exiftool` | show you more info about the file | 
| `xxd` | dumps data in hexadecimal format | 
| `binwalk` | searches for embedded files and executable code | 
| `hexedit` | to edit the hex |

Forensics
-----
use **olevba** to find hidden macros


Decoding and encoding
--------------
decode
```bash
echo encoded_txt | base 64 -d
```
encode 
```bash
echo Txt_to_encode | base64
```

RSA Decoding 
-----

if `d` is small then we can use **wiener attack**
Use this [owiener](https://github.com/orisano/owiener) to find d 
due to small value of `d`  
`d = phi`


**formula => c = m^e mod n**  
if c = m x e is small therfore we can bruteforce it 

`n` is modulas
`p` and `q` are prime factors of `n` 
use factordb.com to find p and q
`c` is chipher 
`phi = (q - 1) * (p - 1)`

`d = 1/e mod phi ` use python Crypto.Util.number inverse(e,phi)

`decrypted message = pow(c,d,phi)`

