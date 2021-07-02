## 2.57

show_bytes的思路：
1. 取原始数据类型的地址（&v, v is int)
2. 将原始地址转为char*, 告诉编译器将该数据看作字节序列. 
   > C语言强制类型转化为 `(char *)(&v);`, C++中, 对于template 范型参数, 使用 `reinterpret_cast<char*>` 进行转换. 
   关于 reinterpret_cast 的更多详情: [reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast) 
3. 对于字节序列v, v可以看成一个由字节组成的向量 [v1, v2, v3,...vn], 使用下标访问就是每一个字节的地址. 使用 `<cstdio>` 的 `std::printf("%.2x", v[i])` 输出地址信息. 

使用C++ template实现多个数据类型的 `show_bytes`. [show_bytes_template.cc](show_bytes_template.cc)

## 2.58
一个w位的整数, 表示为 [x_{w-1}, x_{w-2},...x_1,x_0] 其中 x_{w-1}是最高有效位. 
- big endian  最高有效位字节在前
- little endian 最低有效位字节在前

对于无符号数1
- big endian `0000 0000 0000 0001`

- little endian `1000 0000 0000 0000`

访问第4个字节, 然后将其减去-1, 如果为0,则说明高地址在后, 是big endiang, 如果为-1说明是little endian 


## 2.59
