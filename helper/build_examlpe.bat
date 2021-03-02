cd ..
mkdir build
cd build
conan install ..
cmake ../example
cd ../example
cmake --build ../build
cd ../build/bin
main.exe