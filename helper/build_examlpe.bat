cd ..
mkdir build

cd build
conan install ../example
cmake ../example

cd ../example
cmake --build ../build

cd ../build/bin
main.exe

pause