#include<iostream>
#include<fstream>
using namespace std;
#pragma pack(1)
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