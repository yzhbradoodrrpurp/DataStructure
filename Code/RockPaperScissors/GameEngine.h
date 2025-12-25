//
// Created by 易治行 on 2025/12/22.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <random>
#include <chrono>


class GameEngine {
private:
    typedef enum {rock, scissors, paper} Move;

    int winCount;
    int evenCount;
    int loseCount;

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
    GameEngine() {
        winCount = 0;
        evenCount = 0;
        loseCount = 0;
        rng.seed(static_cast<unsigned long>(std::chrono::steady_clock::now().time_since_epoch().count()));
    }

    ~GameEngine() = default;

    void run() {
        std::uniform_int_distribution<int> dist(0, 2);
        std::cout << "输入 1 (石头), 2 (剪刀), 3 (布), 输入 0 退出游戏.\n";
        while (true) {
            std::cout << "请输入你的选择: ";
            int input;
            std::cin >> input;

            if (input == 0) {
                break;
            }

            if (input < 1 || input > 3) {
                std::cout << "无效输入, 请输入 0~3.\n";
                continue;
            }

            Move player = static_cast<Move>(input - 1);
            Move computer = static_cast<Move>(dist(rng));

            std::cout << "你出: " << moveToString(player) << ", 电脑出: " << moveToString(computer) << std::endl;

            int res = compare(player, computer);

            if (res > 0) {
                ++winCount;
                std::cout << "你赢了！\n";
            } else if (res == 0) {
                ++evenCount;
                std::cout << "平局。\n";
            } else {
                ++loseCount;
                std::cout << "你输了～\n";
            }

            std::cout << std::endl;
        }

        std::cout << "\n游戏结束。统计：\n";
        std::cout << "胜利：" << winCount << "\n";
        std::cout << "平局：" << evenCount << "\n";
        std::cout << "失败：" << loseCount << "\n";
    }

};

#endif //GAMEENGINE_H
