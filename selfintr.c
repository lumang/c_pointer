#include<stdio.h>
#include<assert.h>
// 函数名：ledctrl
// 参数：ledindex：led的索引，status：led的状态
// 返回值：0：成功，-1：失败
int ledctrl(int ledindex,int status)
{
    if(ledindex<0||ledindex>7||status<0||status>1)// check the led index and status
    {
        return -1;
    }
    else
    {
        //control the led
        return 0;
    }
}
int main()
{
    int ret ;
    ret=ledctrl(-3,-1);// call the function
    if (ret < 0)
    {
        printf("error\n");
        assert(0);
    }
    else
    {
        printf("success\n");
    }

    

}