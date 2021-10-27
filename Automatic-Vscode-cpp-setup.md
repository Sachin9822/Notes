# Automatic Vscode CPP setup 
>Sachin Padwalkar | 24-10-21

----------------------

## Setting up git 
[Git installation file](https://github.com/git-for-windows/git/releases/download/v2.33.1.windows.1/Git-2.33.1-64-bit.exe)


## installing Chocolatey package manager 
To install chocolatey in windows powershell use this 
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

Then using this install mingw 
```powershell
choco install mingw
```

the installed packages are stored here `C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin`