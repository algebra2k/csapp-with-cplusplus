## 2.58
一个w位的整数, 表示为 [x_{w-1}, x_{w-2},...x_1,x_0] 其中 x_{w-1}是最高有效位. 
- big endian  最高有效位字节在前
- little endian 最低有效位字节在前

对于无符号数1
- big endian `0000 0000 0000 0001`

- little endian `1000 0000 0000 0000`

访问第4个字节, 然后将其减去-1, 如果为0,则说明高地址在后, 是big endiang, 如果为-1说明是little endian 


## 2.59