#include <stdio.h>
#include <string.h>
//访问内存中的数据 将复杂格式转换为字节，方便通信
// float a = 1.23 转换为字节数组
void float2byte(float a, unsigned char *b) {
    memcpy(b, &a, sizeof(float));
}

//将字节数组转换为float
void byte2float(unsigned char *b, float *a) {
    memcpy(a, b, sizeof(float));
}

int main() {
    float a = 1.23;
    unsigned char b[4];
    float2byte(a, b);
    for (size_t i = 0; i < 4; i++)
    {
        printf("%d = 0x%02x ", b[i],b[i]);
    }
    
    float c;
    byte2float(b, &c);
    printf("%f\n", c);
    return 0;
}