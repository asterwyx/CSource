#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned char *bytes = (unsigned char *)malloc(100);
    printf("Unsigned char ptr: %p\n", bytes);
    bytes++;
    printf("Unsigned char ptr++: %p\n", bytes);
    bytes += 1;
    printf("Unsigned char ptr+1: %p\n", bytes);
    unsigned short *sptr = (unsigned short *)bytes + 12;
    printf("(unsigned char ptr -> unsigned short ptr) + 12: %p\n", sptr);
    sptr = (unsigned short *)(bytes + 12);
    printf("(unsigned char ptr + 12) -> unsigned short ptr: %p\n", sptr);
    sptr++;
    printf("Unsigned short ptr++: %p\n", sptr);
    sptr += 1;
    printf("Unsigned short ptr+1: %p\n", sptr);
    sptr += 12;
    printf("Unsigned short ptr+12: %p\n", sptr);
    printf("%d\n", sizeof(sptr));
    system("pause");
    return 0;

}
/*
笔记：指针变量只能和整数相加减，得到的结果和指针的类型息息相关，其意义是将指针偏移整数位，
    但这里的位并不是指字节，而是指向的数据，也就是指针实际变化的字节是加减的整数乘以指针指向
    数据类型占用大小
    指针的占用大小在64位机上是8个字节
*/