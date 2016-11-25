### C project skeleton

Source code for blog article:
"C project IDE: vim, autotools, ctags, cmocka, lcov, dejagnu, apr, doxygen, git"

https://staskobzar.blogspot.ca/2016/11/c-project-ide-partf-1-vim-autotools.html

To build and run tests:
```
./bootstrap
./configure
make check
```

To build with coverage:
```
./bootstrap
./configure --with-coverage
make clean
make cov
```


