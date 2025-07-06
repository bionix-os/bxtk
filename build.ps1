cmake -B bxtk-build -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=bxtk-install bxtk
cmake --build bxtk-build --config Release
cmake --install bxtk-build