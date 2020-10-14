# test_boost

for test of boost-python.

## compile option (on my docker env.)
``` bash
g++ -I /usr/include/python3.6m -DPIC -shared -fPIC -o CModule.so CModule.cpp -lboost_python3
```

## make
``` bash
$ cd build
$ cmake ..
$ cmake --build .
```