# A. A+B Problem

## 题目描述

给你一个正整数 $n$ ，请你按字典序从小到大输出前 $n$ 个大写字母全排列 $\texttt{Problem}$ 。  

  
【广义的字典序比较】从字符串的第一个字符开始逐个比较，直到找到第一个不同的位置，通过比较这个位置字符的 $\sf Ascii$ 码大小得到字符串的大小，称为<u>字典序比较</u>。例如，字符串 $\texttt{$ 和  
$\texttt{$ 比较时，由于第一个字符不相同，所以 $\texttt{$ 。  
  
  


## 输入描述

第一行有一个正整数 $1 \leq n \leq 4$ 。  


## 输出描述

输出有 $n!$ 行，第 $i$ 行表示字典序第 $i$ 小的答案。  


## 样例

### 样例 1
**输入**:
```
1
```

**输出**:
```
A Problem
```

### 样例 2
**输入**:
```
4
```

**输出**:
```
A+B+C+D Problem
A+B+D+C Problem
A+C+B+D Problem
A+C+D+B Problem
A+D+B+C Problem
A+D+C+B Problem
B+A+C+D Problem
B+A+D+C Problem
B+C+A+D Problem
B+C+D+A Problem
B+D+A+C Problem
B+D+C+A Problem
C+A+B+D Problem
C+A+D+B Problem
C+B+A+D Problem
C+B+D+A Problem
C+D+A+B Problem
C+D+B+A Problem
D+A+B+C Problem
D+A+C+B Problem
D+B+A+C Problem
D+B+C+A Problem
D+C+A+B Problem
D+C+B+A Problem
```

### 样例 3
**输入**:
```
3
```

**输出**:
```
A+B+C Problem
A+C+B Problem
B+A+C Problem
B+C+A Problem
C+A+B Problem
C+B+A Problem
```

