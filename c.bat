@echo off
if not %%DevEnvDir%% == "" goto start
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\vsdevcmd.bat"

:start
devenv gboy.sln /build

if %errorlevel% GEQ 1 goto end 
debug\gboy.exe ..\roms\DMG_ROM.bin cartbridge.bin

:end