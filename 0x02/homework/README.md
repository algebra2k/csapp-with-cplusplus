## 2.57

show_bytes的思路：
1. 取原始数据类型的地址（&v, v is int)
2. 将原始地址转为char*, 告诉编译器将该数据看作字节序列. 
   > C语言强制类型转化为 `(char *)(&v);`, C++中, 对于template 范型参数, 使用 `reinterpret_cast<char*>` 进行转换. 
   关于 reinterpret_cast 的更多详情: [reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast) 
3. 对于字节序列v, v可以看成一个由字节组成的向量 [v1, v2, v3,...vn], 使用下标访问就是每一个字节的地址. 使用 `<cstdio>` 的 `std::printf("%.2x", v[i])` 输出地址信息. 

使用C++ template实现多个数据类型的 `show_bytes`. [show_bytes_template.cc](show_bytes_template.cc)

## 2.58
