set PATH="R:\Dev\applications\cmake-3.16.3-win64-x64\bin\";%PATH%
cmake -H. -Bbuild -G "MinGW Makefiles" -DSDL2_LIB_DIR="R:\Dev\Libraries\C++\SDL2-2.0.10\lib\x86" -DSDL2_INCLUDE_DIR="R:\Dev\Libraries\C++\SDL2-2.0.10\include"
//pause
cd build
compile_pause.bat