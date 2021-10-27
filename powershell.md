# Powershell Script

>Sachin Padwalkar | 05-10-21
-----------------------------------

`Cmdlet` - are lightweight command which are actually the classes and object of .Net Framework  

## Creating a folder & Files in ps
We use 	`New-Item` cmdlet to create the folder  
```powershell
New-Item -Path 'D:\temp\Test Folder' -ItemType Directory
```
To create new file 
```powershell
New-Item -Path 'D:\temp\Test Folder\test.txt' -ItemType File
```
To install exe file without gui 
```powershell
Start-Process -Wait -ArgumentList "/silent" -PassThru -FilePath 'C:\Users\filename.exe'
```
to Set Environment Variable
```powershell
$ENV:PATH="$ENV:PATH;c:\path\to\folder"
# the path are stored in Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment -Name  Path

#First store all the old path in the varible and then add the new path
$oldpath = (Get-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment').path
$newpath = "$oldpath;c:\Path_to_files"
Set-ItemProperty -Path 'Registry::HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment' -Name Path -Value $newpath
```

|Cmdlets|Discriptions|
|---------|------------|
|Bit-Transfer|gets file through https with download bar|
|Get-ItemProperty| get the values from registries|
|Set-ItemProperty| set the values of the registries takes three values -Value -Path and -Name|