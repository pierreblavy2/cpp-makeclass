#!/bin/sh


#--- win32 ---

copy_dll32(){
  cp "/usr/i686-w64-mingw32/sys-root/mingw/bin/$1" "makeclass-win32/$1"
}


copy_upx_dll32(){
  copy_dll32 "$1"
  upx "makeclass-win32/$1"
}


rm -rf makeclass-win32
rm -f  makeclass-win32.zip
mkdir  makeclass-win32

rm -f makeclass.exe
i686-w64-mingw32-g++ -O3 -o makeclass.exe main.cpp
upx makeclass.exe

mv makeclass.exe makeclass-win32/makeclass.exe
upx makeclass.exe

copy_dll32     libgcc_s_dw2-1.dll
copy_dll32     libwinpthread-1.dll
copy_upx_dll32 libstdc++-6.dll


zip -rm9 makeclass-win32.zip makeclass-win32







#--- win64 ---
copy_dll64(){
  cp "/usr/x86_64-w64-mingw32/sys-root/mingw/bin/$1" "makeclass-win64/$1"
}

copy_upx_dll64(){
  copy_dll64 "$1"
  upx "makeclass-win64/$1"
}


rm -rf makeclass-win64
rm -f  makeclass-win64.zip
mkdir  makeclass-win64

rm -f makeclass.exe
x86_64-w64-mingw32-g++ -O3 -o makeclass.exe main.cpp

mv makeclass.exe makeclass-win64/makeclass.exe
upx makeclass.exe

copy_dll64     libwinpthread-1.dll
copy_upx_dll64 libgcc_s_seh-1.dll
copy_upx_dll64 libstdc++-6.dll

zip -rm9 makeclass-win64.zip makeclass-win64
