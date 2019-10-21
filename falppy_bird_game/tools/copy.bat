@echo  off

copy C:\Users\Administrador\Desktop\Flappy-Bird\falppy_bird_game\lib\raylib-2.5.0-Win32-msvc15\bin\raylib.dll C:\Users\Administrador\Desktop\Flappy-Bird\falppy_bird_game\bin\"%2"\ /y
mkdir "C:\Users\Administrador\Desktop\Flappy-Bird\falppy_bird_game\bin\"%2"\assets" /y
xcopy "C:\Users\Administrador\Desktop\Flappy-Bird\falppy_bird_game\res\assets" C:\Users\Administrator\Desktop\Flappy-Bird\falppy_bird_game\bin\"%2"\assets /y /s

echo archivos copiados