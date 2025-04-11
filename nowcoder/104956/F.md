# F. 互联网连接练习竞赛

## 题目描述

你准备承办 Internet Connection Practice Competition (互联网连接练习竞赛)。  
但是这场比赛实在太火爆了，报名队伍数远超过队伍容量，甚至一度把报名网站搞崩溃，报名完成后你决定这样分配参赛名额：  
- 每所学校最多分配 $3$ 个名额。
- 按报名时间顺序分配 $60\%$ 的名额。(类型A)
- 为互联网连接练习竞赛做出非零贡献的学校分配 $30\%$ 的名额。(类型B)
- 为网络连接在本地服务器的学校和网络连接路径遥远的学校分配 $10\%$ 的名额。(类型C)
- 以报名时间顺序为第一关键字分配名额，名额类型的优先级为 A>B>C，例如：有队伍同时满足A类名额和B类名额，则该队伍的名额类型为A类。
- **保证不会出现某类名额没有分配完的情况。**
报名网站会对每个报名队伍生成队伍编号，队伍编号越小则报名时间越早。  
你想手动分配名额，但是报名队伍数实在太多，你实在忙不过来，还有可能分配不公平。你突然想到可以编写程序来分配名额。那该怎么写呢？  


## 输入描述

第 $1$ 行输入两个整数 $n,m(10 \leq m < n \leq 10^4)$ 表示报名队伍数和队伍容量。保证 $m$ 为 $10$ 的倍数。  
第 $2$ 行至第 $n+1$ 行，每行输入以空格分隔的字符串 $school,team$ 和整数 $id(1 \leq id \leq 2 \times 10^6)$ ，分别表示学校名称、队伍名称和队伍编号。  
第 $n+2$ 行输入一个整数 $bs(1 \leq bs \leq 10^4)$ 表示可以分配B类名额的学校数量。  
第 $n+3$ 行至第 $n+bs+2$ 行，每行输入一个字符串 $school_b$ 表示可以分配B类名额的学校名称。  
第 $n+bs+3$ 行输入一个整数 $cs(1 \leq cs \leq 10^4)$ 表示可以分配 C类名额的学校数量。  
第 $n+bs+4$ 行至第 $n+bs+cs+3$ 行，每行输入一个字符串 $school_c$ 表示可以分配C类名额的学校名称。  
保证所有的学校名称和队伍名称不出现大写字母、小写字母、下划线和数字之外的字符，且字符串长度不超过 $30$ 。  
保证不出现两支队伍拥有相同的 $id$ 。  
保证输入的队伍顺序是按照 $id$ 升序排序的。

## 输出描述

第 $1$ 行输出一个整数 $a$ ，表示分配到A类名额的队伍数量。  
第 $2$ 行至第 $a+1$ 行，每行输出以空格分隔的字符串 $school,team$ 和整数 $id$ ，分别表示学校名称、队伍名称和队伍编号。  
第 $a+2$ 行输出一个整数 $b$ ，表示分配到B类名额的队伍数量。  
第 $a+3$ 行至第 $a+b+2$ 行，每行输出以空格分隔的字符串 $school,team$ 和整数 $id$ ，分别表示学校名称、队伍名称和队伍编号。  
第 $a+b+3$ 行输出一个整数 $c$ ，表示分配到C类名额的队伍数量。  
第 $a+b+4$ 行至第 $a+b+c+3$ 行，每行输出以空格分隔的字符串 $school,team$ 和整数 $id$ ，分别表示学校名称、队伍名称和队伍编号。  
你需要保证输出的队伍顺序按照 $id$ 升序排序。

## 样例

### 样例 1
**输入**:
```
15 10
NaiLong_University_A WoShiNaiLong 114514
NaiLong_University_A WoCaiShiNaiLong 114515
NaiLong_University_A JinYeXingGuangShanShan 114516
NaiLong_University_A WoAiNiDeXinManMan 114517
NaiLong_University_B XiangNiYiWanYouYiWan 114518
NaiLong_University_C BaAiNiDeXinDouTianMan 114519
NaiLong_University_D XiangChiAiQingDeKu 114520
NaiLong_University_E ZuoNiDeXiaoGongZhu 114521
NaiLong_University_B YueLiangBuShuiWoBuShui 114522
NaiLong_University_B WoShiRenJianXiaoMeiWei 114523
NaiLong_University_C XianCaBiTiHouTiKu 114524
NaiLong_University_B HouTiKuHouTiKu 114525
NaiLong_University_F CongCiZouXiangSheHuiBu 114526
NaiLong_University_F SheHuiBuSheHuiBu 114527
NaiLong_University_C CongCiZouXiangGaLei 114528
2
NaiLong_University_B
NaiLong_University_F
1
NaiLong_University_C
```

**输出**:
```
6
NaiLong_University_A WoShiNaiLong 114514
NaiLong_University_A WoCaiShiNaiLong 114515
NaiLong_University_A JinYeXingGuangShanShan 114516
NaiLong_University_B XiangNiYiWanYouYiWan 114518
NaiLong_University_C BaAiNiDeXinDouTianMan 114519
NaiLong_University_D XiangChiAiQingDeKu 114520
3
NaiLong_University_B YueLiangBuShuiWoBuShui 114522
NaiLong_University_B WoShiRenJianXiaoMeiWei 114523
NaiLong_University_F CongCiZouXiangSheHuiBu 114526
1
NaiLong_University_C XianCaBiTiHouTiKu 114524
```

**说明**:  

队伍id 名额分配情况  
114514 A类名额。  
114515 A类名额。  
114516 A类名额。  
114517 可以分配A类名额，但是同校已经分配3个名额，跳过。  
114518 同时满足A类名额和B类名额，分配A类名额。  
114519 同时满足A类名额和C类名额，分配A类名额。  
114520 A类名额。  
114521 A类名额已分配完，跳过。  
114522 B类名额。  
114523 B类名额。  
114524 C类名额。  
114525 可以分配B类名额，但是同校已经分配3个名额，跳过。  
114526 B类名额。  
114527 B类名额已分配完，跳过。  
114528 C类名额已分配完，跳过。

