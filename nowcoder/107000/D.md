# D. 小红开灯（三，hard）

## 题目描述

（本题和easy版本的唯一区别是，本题小红可以改变任意 $k$ 盏灯的状态）  
有 $n$ 盏灯排成一列，初始为全部都是“开启”状态。  

小红每次操作可以改变任意 $k$ 盏灯的状态（开启变关闭，关闭变开启），她想知道，进行任意次操作后，可以形成多少种不同的灯的状态？由于答案可能过大，请对 $10^9+7$ 取模。  
  


## 输入描述

两个正整数 $n,k$ ，用空格隔开。  
$1\leq k\leq n \leq 10^5$   


## 输出描述

一个整数，代表最终状态数对 $10^9+7$ 取模的答案。  


## 样例

### 样例 1
**输入**:
```
3 2
```

**输出**:
```
4
```

**说明**:  

可以形成"111"、"100"、"010"、"001"这四种状态。  


