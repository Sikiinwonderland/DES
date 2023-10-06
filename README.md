# 信息安全导论des
重庆大学大数据与软件学院-信息安全导论课程实验-SDES算法的实现
本实验是在胡海波老师指导之下，由葛云恺完成
## 一.项目实现
2.1 分组长度：8-bit

2.2 密钥长度：10-bit

2.3 算法描述：

2.3.1 加密算法：C=IP^{-1}(f_{k_{2}}(SW(f_{k_{1}}(IP(P)))))

2.3.2 解密算法：P=IP^{-1}(f_{k_{1}}(SW(f_{k_{2}}(IP(C)))))

2.3.3 密钥扩展：k_{i}=P_{8}(Shift^{i}(P_{10}(K))),  (i=1,2)

## 二.项目介绍
本项目是根据《信息安全导论》课程第五讲内容实现的对SDES算法的实现，项目呈现形式主要分为加解密页面和结果页面。
加解密页面默认为加密，需要输入明文和密钥，点击“加密”按钮后，会弹出结果页面，显示加密后的密文。
也可以选择解密，输入密文和密钥，点击“解密”按钮后，会弹出结果页面，显示解密后的明文。
![image](https://github.com/Sikiinwonderland/DES/assets/147130898/37d706c0-6ce0-44d4-afad-0ec7e0730377)
以下为演示：
![image](https://github.com/Sikiinwonderland/DES/assets/147130898/9ab4406d-d35a-4e67-9606-7e5241e00948)
### 2.输入格式
按照实验基本要求的输入格式，输入明文和密钥，格式如下： 明文：8位二进制数
密钥：10位二进制数
密文：8位二进制数
密钥：10位二进制数

按照实验基本要求的输出格式，输出加密后的密文和解密后的明文，格式如下：
密文：8位数组，每一位存储1位二进制数
明文：8位数组，每一位存储1位二进制数

当明文或者密文输入格式不符合标准输入格式时，都会视为拓展输入，此时将输入作为一个长为n的字符串，n为输入的长度， 将每一位字符先转化为8位的二进制ASCII码，再对8位二进制的ASCII码进行标准格式的加密，再将加密结果视作ASCII码然后转化为字符， 将每一位转化的结果进行组合，得到新的字符串即为密文。

但是由于加密后的得到的ASCII码不可预测，有极大可能出现乱码，所以设置了限制条件保证正常输入。

### 3.组间测试
已经与黄智仕小组相互测试

### 4.暴力破解
我假设了六组明密文对来进行暴力破解求得密钥

1:

![image](https://github.com/Sikiinwonderland/DES/assets/147130898/eb8466fd-0e0c-4113-97fd-5d4ec816cc2c)

2:

![image](https://github.com/Sikiinwonderland/DES/assets/147130898/84085be2-5732-4e1e-a156-cd0690331797)

3：

![image](https://github.com/Sikiinwonderland/DES/assets/147130898/5d60e8bc-aa10-4335-9393-177310d465b0)

4：

![image](https://github.com/Sikiinwonderland/DES/assets/147130898/118f68b0-8545-4840-8b5e-a2d72deadd7f)

5：

![image](https://github.com/Sikiinwonderland/DES/assets/147130898/5ec32782-ed70-4430-84cd-b32ed05b92c4)

6：

![image](https://github.com/Sikiinwonderland/DES/assets/147130898/e9b0452a-59a5-4a81-8ff1-f9550885b24e)

效率一般

### 5.封闭测试
在进行暴力破解时，发现同一组明密文对可能存在多个密钥, 即：对于明文空间内任意给定的明文分组，确实存在可能性，即选择不同的密钥，加密可以得到相同的密文。 因此我们使用封闭测试的方法来验证我们的程序的正确性。
![image](https://github.com/Sikiinwonderland/DES/assets/147130898/0bf496ac-7041-4929-8d21-b6698e63a2e3)
![image](https://github.com/Sikiinwonderland/DES/assets/147130898/4d719f8f-b7f7-484d-9422-88dd83226014)
![image](https://github.com/Sikiinwonderland/DES/assets/147130898/6ea92b2b-1f3b-4e41-a9bd-7c06e0e796fc)

## 三.开发手册

### 1.项目结构
├── Project19                   
├── 
|── solve
│   └── Solve.h             - 暴力破解
│——— des
│   └── des.h               - S-DES算法实现
└── 源.cpp                  - 程序入口

### 2.算法实现
详情请参见des.h

### 3.测试
详情请参见Solve.h

### 4.维护与扩展
由于只有一个，比较简陋，请多多包涵，日后再进行各方面的更新。
谢谢指教









