# Powershell Script

>Sachin Padwalkar | 05-10-21
-----------------------------------

`Cmdlet` - are lightweight command which are actually the classes and object of .Net Framework  

## Creating a folder & Files in ps
We use 	`New-Item` cmdlet to create the folder  
```ps1
New-Item -Path 'D:\temp\Test Folder' -ItemType Directory
```
To create new file 
```ps1
New-Item -Path 'D:\temp\Test Folder\test.txt' -ItemType File
```
