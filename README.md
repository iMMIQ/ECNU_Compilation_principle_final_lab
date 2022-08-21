# 华东师范大学编译原理期末项目

# East China Normal University Compiler Design Final Project

## 环境

## Environment

> llvm-dev
>
> opt
>
> llvm-link
>
> gflags

## 编译

## Build

> cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release && cd build && ninja

## 使用

## Use

> Usage: ./compiler [options]
>
> Generates binary executables by default
>
> Options:
>
> -c <file>     source file
>
> -o <file>     output file
>
> -O optimize
>
> -C output bitcode IR
>
> -S output text IR
>
> -s output assembly
>
> -help show help message
>
> -version show version

## 例子

## Example

```c
int i=10;
int j=100;
int n=1;
int sum=0;
int mult=1;
{
while (i>0) {n=n+1;i=i-1;}
if (j>=50) then sum=sum+j; else {mult=mult*(j+1);sum=sum+i;}
if (i<=10) then sum=sum-i; else mult=mult+i/2;
if (i==j) then sum=sum-j; else mult=mult-j/2;
if (n>1) then n=n-1; else n=n+1;
if (n<2) then n=n+2; else n=n-2;
}
```

> ./compiler -c a.toy -o a -O

> ./a

Output:

> i: 0
>
> j: 100
>
> mult: -49
>
> n: 8
>
> sum: 100
