### 复数库

复数格式 `a+bi`，其中 `a, b` 为整数，支持的运算：

- 加：`(a+bi)+(c+di)=(a+c)+(b+d)i​`
- 减：`(a+bi)-(c+di)=(a-c)+(b-d)i​`
- 乘：`(a+bi)*(c+di)=(ac-bd)+(ad+bc)i​`
- 除：`(a+bi)/(c+di)=((ac+bd)+(bc-ad)i)/(c^2+d^2)`，其中整数除法为 int 除法

运行代码的方式：

```shell
make run
```

每次输入一行，为复数运算表达式，例如输入 `(1+2i)*(3+4i)-(-13+-12i)/(0-2i)`会输出 `-11+16i`

可以输入任意多个空格，例如输入 `(- 1  2 +   4  i)  + ( 4   -  1 2  i )` 

等价于：`(-12+4i)+(4-12i)`，会输出 `-8-8i`

输入 `q` 退出。
