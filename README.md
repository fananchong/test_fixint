## 基准测试

目前加了基准测试，只支持 linux 版本


执行基准测试：

```vim
cd build
make config=release_x64
cd ../bin
./testfixint 1
```

测试结果：

![images/1.jpg](images/1.jpg)