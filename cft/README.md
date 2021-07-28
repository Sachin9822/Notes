CFT 
> Sachin Padwalkar | 22-07-2021
------------------------

General Skills 
===========
| Tools | Description |
| --- | --- |
| `strings` | to find readable txt in file |
| `exiftool` | show you more info about the file | 
| `xxd` | dumps data in hexadecimal format | 
| `binwalk` | searches for embedded files and executable code | 

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
`n` is modulas
`p` and `q` are prime factors of `n`
`c` is chipher 
`phi = (q - 1) * (p - 1)`

`d = 1/e mod phi ` use python Crypto.Util.number inverse(e,phi)

`decrypted message = pow(c,d,phi)`