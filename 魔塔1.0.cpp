#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_FLOOR 10
#define MAP_SIZE 10

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

Player hero = { 1000, 20, 10, 0, 1, 1, 1, 0, '.' };
char global_msg[100] = "欢迎来到魔塔！站在楼梯或商店上按 [回车] 交互。";

Monster slime = { 'M', "绿史莱姆", 50, 15, 5, 10 };
Monster bat = { 'B', "小蝙蝠", 120, 30, 12, 25 };

// --- 完整地图数据 (禁止偷懒，全部输出) ---
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
    { // 3F: 商店层
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
    { // 7F: 第二个商店
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
    { // 9F: 进入播报剧情
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
    { // 10F: 终点 V
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
        printf("         神秘商店 - 提升属性            \n");
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
    printf("----------------------------------------\n");
}

void handleInput() {
    int nextX = hero.x, nextY = hero.y;
    char ch = _getch();
    
    if (ch == '\r') {
        if (hero.under_char == 'U' && hero.floor < MAX_FLOOR - 1) {
            tower[hero.floor][hero.x][hero.y] = 'U';
            hero.floor++;
            // 九层播报检测
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

//    // 只有移动操作会清空“普通消息”，但不会立刻覆盖“剧情消息”
//    if (ch=='w'||ch=='W'||ch=='s'||ch=='S'||ch=='a'||ch=='A'||ch=='d'||ch=='D') {
//        if (strstr(global_msg, "剧情") == NULL) strcpy(global_msg, "");
//    } else return;

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

int main() {
    system(""); // 开启 ANSI 支持
    printf("\e[?25l"); // 隐藏光标
    while (1) {
        drawMap();
        handleInput();
    }
    return 0;
}
