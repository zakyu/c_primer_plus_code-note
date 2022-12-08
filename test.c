#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 1000000   // 评测的最大长度
char str[MAXLEN];
bool vis[1000005];
int n;

int getNext(int i) {
    //将字符的序号（A到F依次对应 1 到 6 ）与下标相加作为新的下标值，如果下标大于等于 n，将其对 n 求余
    return (i + str[i] - 'A' + 1) % n;
}

int main(void)
{
    fgets(str, MAXLEN, stdin);   // 读取一行字符串
    n = strlen(str)-1;  // 获取字符串长度 （字符串最后一位是'\0'）

    for (int i = 0; i < 1e6 + 5; i++)  
        vis[i] = false;

    // 这里的x和y指的是当前的字符位置，其实和i和j很相似但是意义不同
    int i = 0, j = 1, len = 0, x = 0, y = 1; // 这里的i,j指的是以第几个字符为首的字符串
    vis[0] = true, vis[1] = true;// 标记前两种的字符串已经比较了
    while (i < n && j < n && len < n)
    {
        int t = str[x] - str[y]; // 当前位置的两个字符的大小情况
        if (!t)// 如果相等，则i和j不变，x和y则需要移动
        {
            x = getNext(x);
            y = getNext(y);
            len++;
        }
        else
        {// 谁的字符串所在位置的字符大，则需要换成新的字符串进行比较了
            if (t > 0)
            {
                int temp = i;
                while (temp != x)
                {
                    vis[temp] = true;
                    temp = getNext(temp);
                }
                while (vis[i])
                    i++;
                vis[i] = true;
            }
            else
            {
                int temp = j;
                while (temp != y)
                {
                    vis[temp] = true;
                    temp = getNext(temp);
                }
                while (vis[j])
                    j++;
                vis[j] = true;
            }
            x = i, y = j; // x和y只有在当前待比较的两个字符不等时才会被i和j更新
        }
    }

    printf("%d\n", i<j?i:j);   // 打印最小值
    return 0;
}
