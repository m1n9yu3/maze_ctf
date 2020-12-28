// 迷宫地图实现.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// 地图显示
void show(int(*a)[10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", a[i][i]);
        }
        printf("\n");
    }
}

void changemap(int(*a)[10], int* s_coor,int* d_coor) {
    a[s_coor[0]][s_coor[1]] = 0; // 清除原来的 坐标点
    a[d_coor[0]][d_coor[1]] = 2; // 标记新的 坐标点
}




void maze() {
    printf("\n开始我们的迷宫游戏!!!\n");
    int a[10][10] = { 0 };
    // 控制方向
    int coor[2] = { 0,0 };  // coor[0] 表示横坐标 coor[1] 表示纵坐标 
    while (true) {
        show(a);
        int tmp[2] = { coor[0],coor[1] };
        char flag = getchar();
        getchar();   // 接收回车输入
        switch (flag)
        {
        case 'a':
        {
            coor[0] -= 1;
            break;
        }
        case 'd':
        {
            coor[0] += 1;
            break;
        }
        case 'w':
        {
            coor[1] -= 1;
            break;
        }
        case 's':
        {
            coor[1] += 1;
            break;
        }
        default: {
            // 输入其他， 不做任何处理
        }
               break;
        }
        // 判断 人 是否越界 
        if (coor[0] < 0 || coor[0] >= 10 || coor[1] < 0 || coor[1] >= 10) {
            printf("\nsoory,您撞墙了，请重新开始游戏.\n");
            break;
        }
        // 判断 人 是否在正确的路线上
        if (a[coor[0]][coor[1]] != 1) {
            printf("\n您不在正确的道路\n");
            //break;
        }

        // 打印我们的坐标
        printf("x: %d y:%d\n", coor[0], coor[1]);
        changemap(a, tmp, coor);
    }

    printf("游戏结束");
}


int main()
{
    maze();
}

