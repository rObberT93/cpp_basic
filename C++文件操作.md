# 文件操作

本质上文件都是二进制文件。  
文件内容的每个字节对应一个字符的ASCII码值，并且这些ASCII值对应的字节组成的文字内容是有意义的。  

---

不管是读文件写文件，先要建立或打开这个文件，就相当于建立了一个与该文件相关联的流。

---
## 文本文件的输入输出

### 输入到文本文件里
---
>文件输出流成员函数的三种类型
1. open ：吧流与一个特定的磁盘文件关联 需要指定打开模式
2. put ：把一个字符写到输出流中
3. write ：把内存中的一块内容内道一个文件输出流中
4. seekp tellp ：操作文件流的内部指针 **(慎用)**
5. close ：关闭与一个文件输出流关联的磁盘文件
6. 错误处理函数 ：
   
>
---

> step0：包含头文件#include< fstream >  

> step1：打开文件  

两种初始化的方法
  
  第一种：

``ofstream 变量名("文件名");``
个人习惯用ofile 表示从程序out出去到文件里，把程序里的东西写入文件  
```c++
ofstream ofile("test.txt",ios::out);
```  
ofstream是数据类型，文件名是一个字符串，告诉计算机这个输出文件流对应磁盘上哪个文件。  

第二种：
如果要打开多个文件，需要用这种方式。    
```c++
ofstream ofile;//声明一个静态文件输出流对象
ofile.open("file_test/test.txt",ios::out);//打开文件，是流对象与文件建立联系
```
>文件打开模式:
```c++
ios::in 为输入(读)而打开文件;  
ios::out 为输出(写)而打开文件;  
ios::ate 初始位置：文件尾;  
ios::app 所有输出附加在文件末尾;    
ios::trunc 如果文件已存在则先删除该文件;  
ios::binary 二进制方式;  
ios::nocreate：不建立文件，所以文件不存在时打开失败;  
ios::noreplace：不覆盖文件，所以打开文件时如果文件存在失败;  
```
```c++
ofstream 默认方式 ios::out | ios::trunc
ifstream 默认方式 ios::in
fstream 默认方式 ios::in | ios::out
//只有当函数被调用时没有声明方式参数的情况下，默认值才会被采用。如果函数被调用时声明了任何参数，默认值将被完全改写，而不会与调用参数组合。
```
> step2：检查是否正确打开文件
```c++
if(!ofile)
{
    cerr<<"open file fail";
    exit(1);
}
```
```c++
状态标志符的验证(Verification of state flags)
除了eof()以外，还有一些验证流的状态的成员函数（所有都返回bool型返回值）：

bad()
如果在读写过程中出错，返回 true 
    例如：当我们要对一个不是打开为写状态的文件进行写入时，或者我们要写入的设备没有剩余空间的时候。

fail()
除了与bad() 同样的情况下会返回 true 以外，格式错误时也返回true 
    例如当想要读入一个整数，而获得了一个字母的时候。

eof()
如果读文件到达文件末尾，返回true。

good()
这是最通用的：如果调用以上任何一个函数返回true 的话，此函数返回 false 

要想重置以上成员函数所检查的状态标志，你可以使用成员函数clear()，没有参数。
```
exit(0)---------程序结束返回0给系统，正常退出  
exit(非0的n)---程序结束返回n给系统，异常退出  


这样系统看返回值就能知道是怎么退出的了，是正常退出还是出现错误。  
**可以用不同n区分错误类型**
> step3：输出到文本文件里

>三种从程序输出到文本文档的方式
```c++
ofile<<"hello? it is still a test file, please tell me what you can see on the screen";
//全部都能输进去
```
```c++
char ch='a';
while(ch<='z')
{
ofile.put(ch);
ch++;
}//put只能操作一个字符
```
```c++
char st[]="hello, you are an idiot";
cout<<sizeof(st);//sizeof算了字符串数组后面的\0 所以输出给buffer的长度为sizeof的时候 还是会多一个NULL
ofile.write(st,sizeof(st)-1);//遇到空字符不会停止 所以这样会输出一堆NULL
```
> 
> step4：关闭文件
```c++
ofile.close();
```
文件不用的时候一定要关闭，再用再打开。
清空buffer（恢复缓存空间）

## 从文本文件输出
>step0：包含头文件#include< fstream >  

>step1：打开文件
```c++
ifstream ifile("file_test/test.txt",ios::in)
//个人习惯ifile 表示用程序进入file 从文件里输出到屏幕，即用文件来in
```
> step2：检查是否正确打开文件   


> step3：读取文本文件里的内容  
> 
四种读文件的方式

```c++
char str[100]={0};
ifile.read(str,100);//只要数组开的够大，可以一直输出
cout<<str;
```

```c++
char str[100]={0};
ifile>>str;读到空格和换行就会停
```
```c++
char str1[100]={0};
char str2[100]={0};
ifile.getline(str1,100);读一行
ifile.getline(str2,100);读一行
cout<<str1<<endl;读第一行
cout<<str2<<endl;读第二行
```
```c++
char x;
while(ifile.get(x))//get(char)是读一个字符 把ifile的一个字符读到char x
{
    // ifile.get(x);
    cout<<x;
    x++;//给x++
}
```  

>step4：判断文件结束  

``ifile.eof()``即end of file，类型是bool，文件结束返回true，否则返回false

**看徐明星ppt 这里有个小问题**

> step5：关闭文件

```c++
ifile.close();
```
---
## 二进制文件的读写 
setmod 
写用write 读用read
>二进制文件读取

输出 ofile.write()  
输入 ifile.read()


### 二进制模式输出
```c++
ofile.write(首地址,长度);
```   
outfile从程序out出去写入到文件里  
write：内存到文件
### 二进制模式输入
```c++
ifile.read(首地址,长度);
```
//首地址是个指针

读文件 read：文件原封不动写到内存中

## 从不同位置读取文件内容
文件开头用ios_base::beg  
尾部位置用ios_base::end  
当前位置用ios_base::cur

## 文件格式
文件内容都是二进制串  
操作系统.exe  
问题是怎么解释二进制串  
.bmp 一个字节8个bit
## 对齐
`sizeof(变量名/类型名)`  
占多少字节
pragma pack(1);
## 端
多字节数据在内存中的存放顺序  
小端：地位放在低地址  
大端：高位放在低地址  

## 文件概念的扩展
视频播放器收到前端的一串二进制数，一个字节一个字节的读，按一个规定的解压缩算法，解析出图像。  
键盘、随机数发生器也是文件，找你要数据，你能给我一个ASCII码。  
共性：
# 函数指针


# devc++工程


# 输出.bmp
```c++
#include<iostream>
#include<fstream>
using namespace std;
#pragma pack(1)//不写内存会自动对齐
struct BmpFileHeader{
    char bf[2];
    int size;
    short res1,res2;
    int offset;
}r;

struct BmpInfoHeader{
    int hsize;//结构体大小
    int width;
    int height;
    short plane;
    short bpp;
    int compress;
    int isize;
    int hres;
    int vres;
    int palette;
    int icolor;
};

struct Pixel{
    unsigned char b,g,r;//0~255
};

Pixel content[600][800];//二维数组 直接画

int main(){
    int w=800,h=600;//宽度和高度 width 和 height
    ofstream fbmp("color.bmp",ios::out | ios::binary);
    BmpFileHeader bfh={{'B','M'},
    //w*h*3+sizeof(BmpFileHeader)+sizeof(BmpInfoHeader),//一个像素三字节 w*3*h
    w*h*3+0x36,
    0,
    0,
    0x36};//16进制0
    BmpInfoHeader bih={0x28,//此结构体大小？
    w,h,
    1,24,0,(w*3)*h,0,0,0,0};
    fbmp.write((char*)&bfh,sizeof(bfh));//取bfh首地址 往第一个地址里写
    fbmp.write((char*)&bih,sizeof(bih));

    for(int y=h-1; y>=0; y--)//先走行再走列//左下角 y表示行
    {
        for(int x=0; x<w; x++){//从左往右 x表示列
            content[y][x].r=255;
            content[y][x].g=255;
            content[y][x].b=255;
        }
    }//白底

    for(int y=199; y>=100; y--)
    {
        for(int x=100; x<200; x++){
            content[y][x].r=0;
            content[y][x].g=0;
            content[y][x].b=255;
        }
    }
    
    for(int y=h-1; y>=0; y--)
    {
        for(int x=0; x<w; x++){
            fbmp.write((char*)&content[y][x],sizeof(Pixel));
        } 
        char tmp='\0';
        int padding=3-(w*3+3)%4;//补齐 分四种情况
        //如果是4不用补 是3补一个字节 是2补两个字节 是1补三个字节
        //写公式
        for(int i=0;i<padding;++i)
            fbmp.write(&tmp,1);//不能直接把\0写进去
    }
    fbmp.close();
    return 0;
    }
```

---
文件写入和读取
---

> 写文件
```c++
#include<iostream>
#include<fstream>//引入头文件fstream
#include<cstdlib>
using namespace std;
int main()
{
    int ar[]={1,2,3,4,5,6,7,8,9};
    ofstream ofile;//1.定义输出流 创建流文件
    //ofile是自己起的名字 也可以叫fout等等
    ofile.open("test1.txt",ios::out);//2.打开流文件
    //从程序往外放信息 站在程序的角度是out
    //第一步和第二步可以合并
    //ofstream ofile("test1.txt",ios::out);
    if(!ofile)//打开失败 如果打开成功 ofile指向的是一个不为NULL的地址
    {
        cerr<<"open file fail"<<endl;//
        exit(1);
    }
    for(int i=0;i<sizeof(ar)/sizeof(int);++i)//往文件里写入相关内容
    {
        //cout<<ar[i];
        ofile<<ar[i]<<" ";
    }
    ofile.close();//关闭流文件
}

//站在程序的角度看问题 打开文件
//ifstream ifile只输入流 即读文件
//ofstream ofile只输出流 即写文件
//fstream iofile既输入又输出流
//ios类 in读文件 out写文件
```
> 读文件
```c++
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;    
int main()
{
    int ar[10];
    ifstream ifile;//读文件
    ifile.open("test1.txt",ios::in);//从文件往程序里导入信息 所以是in
    //可以合并为ifstream ifile("test1.txt",ios::in);
    if(!ifile)
    {
        cerr<<"open file fail"<<endl;
        exit(1);
    }
    for(int i=0;i<9;++i)
    {
        ifile>>ar[i];
        cout<<ar[i];
    }
    ifile.close();
}
```

---

# 动态链接库
## 链表读文件
```c++
// This program illustrates the building
// and traversal of a linked list.
#include <iostream>
#include <fstream>
using namespace std;
struct ListNode
{
    double value;
    ListNode *next;
    // Constructor
    ListNode(double value1, ListNode *next1 = nullptr)
    {
        value = value1;
        next = next1;
    }
};

int main()
{
    double number; // Used to read the file
    ListNode *numberList = nullptr; // List of numbers
    // Open the file
    ifstream numberFile("numberFile.txt");
    if (!numberFile)
    {
        cout << "Error in opening the file of numbers.";
        exit (1);
    }
    //Read the file into a linked list
    cout << "The contents of the file are: " << endl;
    while (numberFile >> number)
    {
        cout << number << " ";
        // Create a node to hold this number
        numberList = new ListNode(number, numberList);
    }
    // Traverse the list while printing
    cout << endl << "The contents of the list are: " << endl;
    ListNode *ptr = numberList;
    while (ptr != nullptr)
    {
        cout << ptr->value << " "; // Process node
        ptr = ptr->next; // Move to next node
    }
    return 0;
}
```

> 例题
```c++
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    //打开文件 这个文件已经有了 如果再写一个就会发生覆盖
    ifstream ifile("file_test/prime.txt",ios::in);
    //！？绝对路径和相对路径
    //如果文件不存在 打开会失败
    if(!ifile)
    {
        cerr<<"open file fail"<<endl;
        exit(1);
    }
    int n=0;
    //文件读取
    //cin>>n;是从键盘读
    //ifile>>n是从文件里读 读到的是ascii码
    cin>>n;
    int p=-1;
    //文件未结束
    while(n>p && ifile.eof())//ifile.eof() 是end of file 判断文件有没有结束
    //ifile.eof()的类型是bool 文件结束的时候返回true 否则返回false
    //恰恰好读完的时候不是true 还是false 再读一次才是true
    //有时候要看文件末尾有没有回车
    {
        //从文件读一个数到p
        ifile>>p;
    }
    if(n==p)
    {
        cout<<"是素数"<<endl;
    }
    else
    {
        cout<<"不是素数"<<endl;
    }
    //关闭文件
    ifile.close();
    return 0;
}
//对每一个n 因为是线性查找 这个复杂度是o（n）
//因为是线性查找 可以折半查找吗? 文本文件都是二进制串
//字节越来越长跳到第几多少个字节可不是一半 
//拿二进制模式输入输出会好一些
```
```c++
//输出这么多数 看屏幕上闪过这些数需要相当的一段时间
//但思考：为什么不超时呢？这些数据是先生成的 只是输出慢
//怎么把这些数保存下来呢？用文件
#include<iostream>
#include<fstream>
using namespace std;
const int n=1000000;
bool isprime[n+1];
int main()
{
    //打开文件
    //文件拓展名没有限制 因为都是二进制写的

    //拓展名是骗人的
    ofstream ofile("file_test/../prime.txt",ios::out);
    //往下一层地址写用/或者\\ 两种斜杠都可以 但\一个杠是转义符 必须要写俩 所以一般写/
    //在当前cpp的文件夹下的文件夹file_test里新建一个prime.txt
    //双引号里面可以写路径 向上一层目录写用..一直找路径
    //如果写/../就又变成当前目录了 记得写..后面的那个/ 不然文件名就变了
    //ofstream是输出文件类 
    if(!ofile)
    {
        cerr<<"open file fail"<<endl;
        exit(1);
    }
    for(int i=2;i<=n;i++)
    {
        isprime[i]=1;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=i+i;j<=n;j+=i)
            {
                isprime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            //从输出到屏幕改成输出到屏幕
            ofile<<i<<endl;
            //cout<<i<<endl;
            //cout是输出到屏幕上的 没写cout屏幕上啥也没有 但输出到文件里了 文件里有东西了
        }
    }
    //关闭文件
    ofile.close();
    //这个. 是访问对象类的方法 ofile是个类
    return 0;
}
```