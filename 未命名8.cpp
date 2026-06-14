#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_FLOOR 10
#define MAP_SIZE 10
#define SAVE_FILE "save.dat"

// 颜色定义
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

typedef struct {
    int hp, atk, def, gold, key;
    int x, y, floor;
    char under_char; 
} Player;

typedef struct {
    char symbol;
    char name[20];
    int hp, atk, def, gold_drop;
} Monster;

// 初始数据
Player hero = { 1000, 20, 10, 0, 1, 1, 1, 0, '.' };
char global_msg[100] = "欢迎来到魔塔！按 [P] 键保存进度。";

Monster slime = { 'M', "绿史莱姆", 50, 15, 5, 10 };
Monster bat = { 'B', "小蝙蝠", 120, 30, 12, 25 };

// 地图数据
char tower[MAX_FLOOR][MAP_SIZE][MAP_SIZE] = {
    { // 1F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','@','.','K','#','R','.','M','.','#'},
        {'#','.','#','.','#','.','#','#','.','#'},
        {'#','M','#','.','D','.','.','B','.','#'},
        {'#','.','.','.','#','#','#','#','.','#'},
        {'#','#','B','#','G','.','.','A','.','#'},
        {'#','A','.','.','.','#','#','#','U','#'},
        {'#','#','#','#','.','.','.','.','.','#'},
        {'#','R','.','.','.','.','M','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 2F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','K','#','K','.','A','.','#'},
        {'#','#','#','D','#','#','#','#','.','#'},
        {'#','R','.','.','.','M','.','#','.','#'},
        {'#','#','#','#','#','#','D','#','.','#'},
        {'#','A','.','B','.','G','.','.','.','#'},
        {'#','.','#','#','#','#','#','#','D','#'},
        {'#','.','.','M','.','.','.','.','U','#'},
        {'#','R','K','.','.','.','B','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 3F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','.','.','.','.','.','K','#'},
        {'#','.','#','#','D','#','#','#','.','#'},
        {'#','.','#','$','.','.','.','#','.','#'},
        {'#','.','#','#','#','D','#','#','.','#'},
        {'#','.','.','M','.','.','.','M','.','#'},
        {'#','#','#','#','D','#','#','#','.','#'},
        {'#','K','R','.','.','B','.','.','.','#'},
        {'#','A','G','.','.','.','.','.','U','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 4F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','M','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','D','#'},
        {'#','K','R','G','A','.','.','.','.','#'},
        {'#','D','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','B','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','D','#'},
        {'#','U','.','.','.','.','.','M','.','#'},
        {'#','K','.','.','.','B','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 5F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','.','#','R','G','#','.','#'},
        {'#','.','#','.','D','.','.','D','.','#'},
        {'#','M','#','.','#','#','#','#','M','#'},
        {'#','.','D','.','.','.','B','.','.','#'},
        {'#','B','#','.','#','#','#','#','B','#'},
        {'#','.','D','.','.','.','M','.','.','#'},
        {'#','M','#','.','D','#','#','#','.','#'},
        {'#','.','.','.','#','A','K','.','U','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 6F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','M','.','.','B','.','.','#'},
        {'#','#','#','#','#','#','#','#','D','#'},
        {'#','K','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','D','#'},
        {'#','K','.','.','R','.','.','G','.','#'},
        {'#','#','#','#','#','#','#','#','D','#'},
        {'#','U','.','.','A','.','.','B','.','#'},
        {'#','K','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 7F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','M','.','R','.','M','.','#'},
        {'#','.','#','#','D','#','#','#','.','#'},
        {'#','.','#','$','.','.','.','#','.','#'},
        {'#','.','#','#','#','D','#','#','.','#'},
        {'#','G','.','B','.','G','.','B','.','#'},
        {'#','#','#','#','D','#','#','#','.','#'},
        {'#','A','R','A','.','.','.','.','.','#'},
        {'#','K','K','K','.','.','.','.','U','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 8F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','B','.','B','.','B','.','#'},
        {'#','#','D','#','#','#','#','D','#','#'},
        {'#','R','.','G','.','R','.','G','.','#'},
        {'#','#','D','#','#','#','#','D','#','#'},
        {'#','M','.','M','.','M','.','M','.','#'},
        {'#','#','D','#','#','#','#','D','#','#'},
        {'#','A','.','A','.','A','.','A','.','#'},
        {'#','K','.','.','.','.','.','.','U','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 9F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','.','.','#','.','.','.','#'},
        {'#','#','#','#','.','#','.','#','#','#'},
        {'#','R','G','.','.','D','.','.','A','#'},
        {'#','#','#','#','.','#','.','#','#','#'},
        {'#','M','B','M','.','#','.','B','M','#'},
        {'#','#','#','#','.','#','.','#','#','#'},
        {'#','K','K','.','.','#','.','.','U','#'},
        {'#','.','.','.','.','#','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 10F
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','.','.','.','.','.','.','#'},
        {'#','.','#','#','#','#','#','#','.','#'},
        {'#','.','#','R','G','R','#','.','.','#'},
        {'#','.','#','G','V','G','#','.','.','#'},
        {'#','.','D','.','.','.','.','.','B','#'},
        {'#','.','#','A','K','A','#','.','.','#'},
        {'#','.','#','K','K','K','#','.','.','#'},
        {'#','.','.','.','.','.','.','.','B','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    }
};

// --- 功能函数 ---

void saveGame() {
    FILE *fp = fopen(SAVE_FILE, "wb");
    if (fp == NULL) {
        strcpy(global_msg, RED "存档失败：无法创建文件。" RESET);
        return;
    }
    fwrite(&hero, sizeof(Player), 1, fp);
    fwrite(tower, sizeof(tower), 1, fp);
    fclose(fp);
    strcpy(global_msg, GREEN "进度已保存！" RESET);
}

int loadGame() {
    FILE *fp = fopen(SAVE_FILE, "rb");
    if (fp == NULL) return 0;
    fread(&hero, sizeof(Player), 1, fp);
    fread(tower, sizeof(tower), 1, fp);
    fclose(fp);
    return 1;
}

void movePlayer(int tx, int ty, char next_under) {
    tower[hero.floor][hero.x][hero.y] = hero.under_char;
    hero.x = tx; hero.y = ty;
    hero.under_char = next_under;
    tower[hero.floor][hero.x][hero.y] = '@';
}

void shopLoop() {
    char choice;
    while (1) {
        system("cls");
        printf(GREEN "========================================\n" RESET);
        printf("          神秘商店 - 提升属性            \n");
        printf("  当前金币: " YELLOW "%d\n\n" RESET, hero.gold);
        printf("  1. 增加 800 生命 (20金币)\n");
        printf("  2. 增加 4 攻击   (20金币)\n");
        printf("  3. 增加 4 防御   (20金币)\n");
        printf("  " RED "[Esc]" RESET " 离开商店\n");
        choice = _getch();
        if (choice == 27) break;
        if (hero.gold < 20) { printf("\n" RED "金币不足！" RESET); _getch(); continue; }
        switch (choice) {
            case '1': hero.hp += 800; hero.gold -= 20; break;
            case '2': hero.atk += 4;  hero.gold -= 20; break;
            case '3': hero.def += 4;  hero.gold -= 20; break;
        }
    }
    strcpy(global_msg, "能力提升了！继续前进吧。");
}

int battleLogic(Monster *m, int tx, int ty) {
    int dmgM = hero.atk - m->def;
    int dmgH = (m->atk - hero.def > 0) ? (m->atk - hero.def) : 0;
    if (dmgM <= 0) { sprintf(global_msg, "无法破防 %s!", m->name); return 0; }
    int rounds = (m->hp + dmgM - 1) / dmgM;
    int totalDmg = (rounds - 1) * dmgH;
    if (hero.hp > totalDmg) {
        hero.hp -= totalDmg; hero.gold += m->gold_drop;
        movePlayer(tx, ty, '.');
        sprintf(global_msg, "击败 %s! 损失 HP: %d", m->name, totalDmg);
        return 1;
    } else { sprintf(global_msg, "HP不足以击败 %s!", m->name); return 0; }
}

void drawMap() {
    system("cls");
    printf("========================================\n");
    printf("   " CYAN "魔塔 (Magic Tower)" RESET "  第 %d 层\n", hero.floor + 1);
    printf("========================================\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            char item = tower[hero.floor][i][j];
            switch (item) {
                case '@': printf(CYAN "@ " RESET); break;
                case 'M': case 'B': printf(RED "%c " RESET, item); break;
                case '$': printf(GREEN "$ " RESET); break;
                case 'V': printf(GREEN "V " RESET); break;
                case 'K': case 'D': printf(YELLOW "%c " RESET, item); break;
                case 'R': printf(MAGENTA "R " RESET); break;
                case 'G': printf(BLUE "G " RESET); break;
                case 'A': printf(RED "A " RESET); break;
                case 'U': case 'N': printf(CYAN "%c " RESET, item); break;
                case '#': printf("■ "); break; // 墙壁美化
                default:  printf("%c ", item); break;
            }
        }
        if (i == 1) printf("   [ 勇者状态 ]");
        if (i == 2) printf("   生命: " RED "%d" RESET, hero.hp);
        if (i == 3) printf("   攻击: " MAGENTA "%d" RESET, hero.atk);
        if (i == 4) printf("   防御: " BLUE "%d" RESET, hero.def);
        if (i == 5) printf("   金币: " YELLOW "%d" RESET, hero.gold);
        if (i == 6) printf("   黄钥匙: " YELLOW "%d" RESET, hero.key);
        printf("\n");
    }
    printf("----------------------------------------\n");
    printf(YELLOW "【播报】" RESET "%s\n", global_msg);
    printf(CYAN "[WASD]移动 [Enter]交互 [P]存档 [Esc]退出\n" RESET);
    printf("----------------------------------------\n");
}

void handleInput() {
    int nextX = hero.x, nextY = hero.y;
    int ch = _getch();
    
    // 存档逻辑
    if (ch == 'p' || ch == 'P') {
        saveGame();
        return;
    }
    if (ch == 27) exit(0); // ESC 退出

    if (ch == '\r') {
        if (hero.under_char == 'U' && hero.floor < MAX_FLOOR - 1) {
            tower[hero.floor][hero.x][hero.y] = 'U';
            hero.floor++;
            if (hero.floor == 8) strcpy(global_msg, "感受到一股强大的威压，胜利就在前方！");
            else sprintf(global_msg, "上到第 %d 层。", hero.floor + 1);
            
            for(int i=0; i<MAP_SIZE; i++) for(int j=0; j<MAP_SIZE; j++)
                if(tower[hero.floor][i][j] == 'N') { nextX = i; nextY = j; }
            hero.x = nextX; hero.y = nextY; hero.under_char = 'N'; 
            tower[hero.floor][hero.x][hero.y] = '@';
        } 
        else if (hero.under_char == 'N' && hero.floor > 0) {
            tower[hero.floor][hero.x][hero.y] = 'N';
            hero.floor--;
            sprintf(global_msg, "回到了第 %d 层。", hero.floor + 1);
            for(int i=0; i<MAP_SIZE; i++) for(int j=0; j<MAP_SIZE; j++)
                if(tower[hero.floor][i][j] == 'U') { nextX = i; nextY = j; }
            hero.x = nextX; hero.y = nextY; hero.under_char = 'U'; 
            tower[hero.floor][hero.x][hero.y] = '@';
        } 
        else if (hero.under_char == '$') shopLoop();
        return;
    }

    if (ch == 'w' || ch == 'W') nextX--; else if (ch == 's' || ch == 'S') nextX++;
    else if (ch == 'a' || ch == 'A') nextY--; else if (ch == 'd' || ch == 'D') nextY++;

    if (nextX < 0 || nextX >= MAP_SIZE || nextY < 0 || nextY >= MAP_SIZE) return;

    char target = tower[hero.floor][nextX][nextY];
    switch (target) {
        case '.': movePlayer(nextX, nextY, '.'); break;
        case 'K': hero.key++; sprintf(global_msg, "获得钥匙！"); movePlayer(nextX, nextY, '.'); break;
        case 'R': hero.atk += 2; sprintf(global_msg, "攻击+2！"); movePlayer(nextX, nextY, '.'); break;
        case 'G': hero.def += 2; sprintf(global_msg, "防御+2！"); movePlayer(nextX, nextY, '.'); break;
        case 'A': hero.hp += 200; sprintf(global_msg, "生命+200！"); movePlayer(nextX, nextY, '.'); break;
        case 'U': sprintf(global_msg, "按回车切换到上一层。"); movePlayer(nextX, nextY, 'U'); break;
        case 'N': sprintf(global_msg, "按回车切换到下一层。"); movePlayer(nextX, nextY, 'N'); break;
        case '$': sprintf(global_msg, "按回车进入神秘商店。"); movePlayer(nextX, nextY, '$'); break;
        case 'V': 
            movePlayer(nextX, nextY, 'V');
            drawMap();
            printf("\n" GREEN "你抵达了魔塔终点！黑暗被驱散，英雄的名字将被铭记！\n" RESET);
            printf("按任意键退出游戏...");
            _getch(); exit(0);
        case 'M': battleLogic(&slime, nextX, nextY); break;
        case 'B': battleLogic(&bat, nextX, nextY); break;
        case 'D': if (hero.key > 0) { hero.key--; sprintf(global_msg, "门开了。"); movePlayer(nextX, nextY, '.'); }
                  else sprintf(global_msg, "你需要一把钥匙！"); break;
    }
}

void showMainMenu() {
    while (1) {
        system("cls");
        printf(CYAN "================================================\n" RESET);
        printf(CYAN "||                                            ||\n" RESET);
        printf(CYAN "||" YELLOW "          魔 塔 : 传 奇 冒 险 (C版)         " CYAN "||\n" RESET);
        printf(CYAN "||                                            ||\n" RESET);
        printf(CYAN "================================================\n" RESET);
        printf("\n");
        printf("            " GREEN "1. 开始新游戏\n" RESET);
        printf("            " YELLOW "2. 读取旧进度\n" RESET);
        printf("            " RED "3. 退出游戏\n" RESET);
        printf("\n");
        printf(CYAN "================================================\n" RESET);
        printf("          请输入选项 [1-3]: ");
        
        char choice = _getch();
        if (choice == '1') {
            break; 
        } else if (choice == '2') {
            if (loadGame()) {
                strcpy(global_msg, "欢迎回来，勇者！进度加载成功。");
                break;
            } else {
                printf("\n" RED "      未找到存档文件！请先开始新游戏。" RESET);
                _getch();
            }
        } else if (choice == '3') {
            exit(0);
        }
    }
}

int main() {
    system(""); // 开启 ANSI 支持
    printf("\e[?25l"); // 隐藏光标
    
    showMainMenu(); // 显示主菜单

    while (1) {
        drawMap();
        handleInput();
    }
    return 0;
}
