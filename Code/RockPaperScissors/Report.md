# 石头剪刀布游戏课程设计实验报告

## 问题描述

本课程设计实现一个终端交互式的“石头剪刀布”游戏（Rock-Paper-Scissors）。玩家与电脑进行对战，通过输入数字选择手势：

- 1 → 石头
- 2 → 剪刀
- 3 → 布
- 0 → 退出游戏

约束条件与目标如下：

- 玩家输入必须有效，范围为 0~3，错误输入需提示重新输入。
- 电脑出拳必须为随机结果
- 每局输出双方选择并给出胜负判断
- 游戏结束后输出累计胜、平、负统计结果
- 通过编程实现人与计算机交互式博弈过程，掌握面向对象建模及输入输出处理

## 基本要求

为了完成此课程设计，应达到以下基本要求：

1. 掌握 C++ 的类设计与成员方法实现
2. 熟悉枚举类型与随机数生成机制
3. 实现游戏交互逻辑、流程控制与异常输入处理
4. 使用循环与条件结构编写完整的人机对战过程
5. 输出详细的运行信息与统计结果

---

## 工具及准备工作

| 工具     | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| 开发语言 | C++                                                          |
| IDE      | CLion                                                        |
| 硬件支持 | MacBook Air + MacOS Terminal                                 |
| 编程知识 | 输入输出 `iostream`、枚举、类与对象、随机数引擎 `mt19937`、流程控制结构 |

## 项目实现方法分析

### 主要数据结构与算法说明

- **枚举类型 `Move`** 用于描述三种手势，提高代码可读性
- **Mersenne Twister `std::mt19937`** 随机数引擎用于保证电脑随机出拳
- **对比算法 `compare`** 返回 `1/0/-1` 表征胜负结果，简化判断逻辑
- **循环输入机制** 允许玩家多次对战，输入 `0` 退出
- **统计变量** 记录对局统计信息

### 核心类声明与算法实现

```cpp
class GameEngine {
private:
    typedef enum {rock, scissors, paper} Move;
    int winCount, evenCount, loseCount;
    std::mt19937 rng;

    static const char* moveToString(Move m) {
        switch (m) {
            case rock: return "石头";
            case scissors: return "剪刀";
            case paper: return "布";
            default: return "未知";
        }
    }

    // 返回 1: 玩家胜，0: 平局，-1: 电脑胜
    static int compare(Move player, Move computer) {
        if (player == computer) return 0;
        if ((player == rock && computer == scissors) ||
            (player == scissors && computer == paper) ||
            (player == paper && computer == rock)) return 1;
        return -1;
    }

public:
    void run() {
        std::uniform_int_distribution<int> dist(0, 2);
        std::cout << "输入 1 (石头), 2 (剪刀), 3 (布), 输入 0 退出游戏.\n";
        while (true) {
            std::cout << "请输入你的选择: ";
            int input;
            std::cin >> input;
            if (input == 0) break;
            if (input < 1 || input > 3) { std::cout << "无效输入, 请输入 0~3.\n"; continue; }

            Move player = static_cast<Move>(input - 1);
            Move computer = static_cast<Move>(dist(rng));
            std::cout << "你出: " << moveToString(player)
                      << ", 电脑出: " << moveToString(computer) << std::endl;

            int res = compare(player, computer);
            if (res > 0) { ++winCount; std::cout << "你赢了！\n"; }
            else if (res == 0) { ++evenCount; std::cout << "平局。\n"; }
            else { ++loseCount; std::cout << "你输了～\n"; }
            std::cout << "\n";
        }

        std::cout << "\n游戏结束。统计：\n胜利：" << winCount
                  << "\n平局：" << evenCount
                  << "\n失败：" << loseCount << "\n";
    }
};
