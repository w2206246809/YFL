# YFL-Alg

> by 王一凡

## 说明

本文档属于YFL-Lab的分支，主要记录计算机算法问题。

# 数学类算法问题

## 大数取余

问题描述：当面对一个很大的数字时，long long int 都无法对其存储，我们要对其取余。

解决方法：我们主要基于同余定理，完成算法：对于一个大数要对 x 取余（使用数组存储数字的每一位），第一位（最高位）对 x 取余，获得余数 i ，对于之后位数，我们用上一位的余数 i 乘以10加上这一位的数字得到结果 n ，用 n 对 x 取余然后得到新的余数，直到最低位。

```c++
int BigNumMod(int BigNum[], int c, int length){
    int ans = 0;
    for(int i = 0; i < length; i++)
        ans = ((ans * 10) + BigNum[i]) % c;
    return ans;
}

int main()
{
    int BigNum[7] = {1,2,3,4,5,6,7};
    int c = 3;
    printf("%d\n", BigNumMod(BigNum, c, 7));
    return 0;
}
```

## 快幂算法

问题描述：自定义求幂函数。

解决方法：x 的 y 次方等于 x 的 y/2 次方的平方 或 x 的 y/2 下取整次方的平方乘以 x。

```c++
double myPow(double base, int n){
	if(n == 0) return 1;
	if(n == 1) return base;
    double rs = myPow(base, n / 2); // 这里n/2也有n>>1的说法
    if( n % 2 == 0){
        rs = rs * rs;
    }
    else{
        rs = rs * rs * base;
    }
    return rs;
}
```



## 快幂取模

问题描述：自定义求幂函数，如果数字太大有时要求做取模处理。（即求 a 的 b 次方 mod c ）

解决方法：基于数论，有：(a * b) mod c = ( (a mod c) * ( b mod c ) ) mod c。进而有 ( a ^ b ) mod c = ( a mod c ) ^ b mod c。

```c++
int pow_mod(int a, int b, int c){ // ( a ^ b ) mod c
    int ans = 1;
    int base = a % c;
    while(b){
        if(b & 1){
            ans = (ans * base) % c;
        }
        base = (base * base) % c;
        b = b >> 1;
    }
    return ans;
}
```

# 底层数据处理

## 整型数转化为二进制

问题描述：获得整型数的二进制存储的每一位。

解决方法：通过移位操作，按位与 1 来获得二进制表示的每一位。

```c++
void func(int aim){
    list<int> L;
    while(aim){
        L.push_front(aim & 1) // 取出 aim 的最低位，也可以写作：aim % 2
        aim = aim >> 1;
    }
}
```

