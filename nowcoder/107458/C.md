# C. 变化的数组(Easy Version)

## 题目描述

$\hspace{15pt}$   
$\mathbf{题目两个版本的差距在于\ k\ 的范围}$   
  
对于给定的长度为 $n$ 的数组 $\{a_1,a_2,\dots,a_n\}$ 和一个整数 $m$ ，保证全部非负。你需要执行 $k$ 次操作，每一次操作如下：  
$\hspace{22.5pt}\bullet\$ 对数组中的每一个元素 $a_i$ ，投掷一次硬币，若硬币为正则将这个元素修改为 $a_i + (a_i \operatorname{and} m) + x$ ；反之，则不操作；  
$\hspace{15pt}$ 在全部 $k$ 次操作完成后，求解数组元素和的期望。  

  
$\hspace{15pt}$ 在本题中， $\operatorname{and}$ 运算即按位与运算。如果您需要更多位运算相关的知识，可以参考**OI-Wiki上的相关章节**。  
  


## 输入描述

$\hspace{15pt}$ 第一行输入四个整数 $n,x,m,k \left( 1\leqq n \leqq 10^6;\ 1 \leqq m, k \leqq 5\cdot10^3;\ 0\leqq x \leqq 10^5\right)$ 代表数组中的元素数量，修改公式中的定值 $x$ ，修改公式中的定值 $m$ ，操作次数。  
$\hspace{15pt}$ 第二行输入 $n$ 个整数 $a_1,a_2,\dots,a_n \left( 0 \leqq a_i \leqq 10^9 \right)$ 代表数组元素。  


## 输出描述

$\hspace{15pt}$ 在一行上输出一个整数，代表 $k$ 次操作完成后数组元素和的期望。  

$\hspace{15pt}$ 可以证明答案可以表示为一个不可约分数 $\tfrac{p}{q}$ ，为了避免精度问题，请直接输出整数 $\left(p \cdot q^{-1} \bmod M\right)$ 作为答案，其中 $M = (998244353)$ ， $q^{-1}$ 是满足 $q\times q^{-1} \equiv 1 \pmod{M}$ 的整数。  


## 样例

### 样例 1
**输入**:
```
2 0 6 1
3 5
```

**输出**:
```
11
```

**说明**:  

$\hspace{15pt}$ 全过程模拟如下：  
$\hspace{22.5pt}\bullet\$  $\tfrac{1}{4}$ 的概率第一个元素硬币为正、第二个元素硬币也为正，答案为 $\tfrac{1}{4} \times \big(3 + (3 \operatorname{and} m) + 0 + 5 + (5 \operatorname{and} m) + 0\big) =\tfrac{14}{4}$ ；  
$\hspace{22.5pt}\bullet\$ $\tfrac{1}{4}$ 的概率第一个元素硬币为正、第二个元素硬币为反，答案为 $\tfrac{1}{4} \times \big(3 + (3 \operatorname{and} m) + 0 + 5 \big) =\tfrac{10}{4}$ ；  
$\hspace{22.5pt}\bullet\$ $\tfrac{1}{4}$ 的概率第一个元素硬币为反、第二个元素硬币为正，答案为 $\tfrac{1}{4} \times \big(3 + 5 + (5 \operatorname{and} m) + 0 \big) =3$ ；  
$\hspace{22.5pt}\bullet\$ $\tfrac{1}{4}$ 的概率第一个元素硬币为反、第二个元素硬币也为反，答案为 $\tfrac{1}{4} \times \big(3 + 5\big) =2$ ；  
$\hspace{15pt}$ 综上，期望为 $11$ 。  


### 样例 2
**输入**:
```
10 11 4 514
0 1 2 3 4 5 6 7 8 9
```

**输出**:
```
722414145
```

**说明**:  

答案模 $998244353$ 。  


