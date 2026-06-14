#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// 颜色转义码定义
#define RESET   "\033[0m"
#define RED     "\033[31m"      // 怪物、血瓶
#define GREEN   "\033[32m"      // 商店
#define YELLOW  "\033[33m"      // 钥匙、金币、门
#define BLUE    "\033[34m"      // 蓝宝石（防御）
#define CYAN    "\033[36m"      // 勇者、楼梯
#define MAGENTA "\033[35m"      // 红宝石（攻击）

#define MAX_FLOOR 3
#define MAP_SIZE 10

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
char global_msg[100] = "WASD移动，站在楼梯或商店($)上按 [回车]。";

// 地图数据，在第一层(0层)加入了商店 '$'
char tower[MAX_FLOOR][MAP_SIZE][MAP_SIZE] = {
    { // 0层
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','@','.','K','#','R','.','M','.','#'},
        {'#','.','#','.','#','.','#','#','.','#'},
        {'#','M','#','$','D','.','.','B','.','#'}, // [3,3] 是商店
        {'#','.','.','.','#','#','#','#','.','#'},
        {'#','#','B','#','G','.','.','A','.','#'},
        {'#','A','.','.','.','#','#','#','U','#'},
        {'#','#','#','#','.','.','.','.','.','#'},
        {'#','R','.','.','.','.','M','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 1层 (省略其他层，保持逻辑一致)
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','.','.','M','.','.','K','#'},
        {'#','.','#','#','#','#','#','#','.','#'},
        {'#','R','#','A','.','B','.','#','.','#'},
        {'#','.','#','.','#','#','.','#','.','#'},
        {'#','.','D','.','M','D','.','D','.','#'},
        {'#','.','#','.','#','#','.','#','.','#'},
        {'#','G','#','.','.','.','.','#','.','#'},
        {'#','K','.','.','.','M','.','.','U','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    },
    { // 2层
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','N','.','.','R','R','R','.','.','#'},
        {'#','.','#','#','#','#','#','#','.','#'},
        {'#','.','#','K','K','K','#','.','.','#'},
        {'#','.','#','#','#','#','#','.','#','#'},
        {'#','.','.','.','.','.','.','.','.','#'},
        {'#','.','#','#','#','#','#','D','#','#'},
        {'#','.','#','G','G','G','#','.','.','#'},
        {'#','.','.','.','.','.','.','.','B','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    }
};

Monster slime = { 'M', "绿史莱姆", 300, 30, 10, 20 };//生命，攻击，防御，金币 
Monster bat = { 'B', "小蝙蝠", 100, 50, 10, 20 };

void drawMap();
void handleInput();
void movePlayer(int tx, int ty, char next_under);

// 商店界面循环
void shopLoop() {
    char choice;
    while (1) {
        system("cls");
        printf(GREEN"========================================\n");
        printf("         21层魔塔 - 神秘商店            \n");
        printf("========================================\n"RESET);
        printf("  店主：只要你有金币，我能让你变强！\n\n");
        printf("  当前金币: "YELLOW"%d\n\n"RESET, hero.gold);
        printf("  1. 增加 800 生命 (" YELLOW "花费 20 金币" RESET ")\n");
        printf("  2. 增加 4 攻击   (" YELLOW "花费 20 金币" RESET ")\n");
        printf("  3. 增加 4 防御   (" YELLOW "花费 20 金币" RESET ")\n");
        printf("  4.[Esc]. 离开商店\n");
        printf("========================================\n");
        printf("请按数字键选择: ");
        
        choice = _getch();
        if (choice == 27) break;

        if (hero.gold < 20) {
            printf("\n" RED "【提示】金币不足！去打怪攒钱吧" RESET);
            _getch();
            continue;
        }

        switch (choice) {
            case '1': hero.hp += 800; hero.gold -= 20; break;
            case '2': hero.atk += 4;  hero.gold -= 20; break;
            case '3': hero.def += 4;  hero.gold -= 20; break;
        }
    }
    strcpy(global_msg, "欢迎下次光临！");
}

void movePlayer(int tx, int ty, char next_under) {
    tower[hero.floor][hero.x][hero.y] = hero.under_char;
    hero.x = tx;
    hero.y = ty;
    hero.under_char = next_under;
    tower[hero.floor][hero.x][hero.y] = '@';
}

int battleLogic(Monster *m, int tx, int ty) {
    int dmgM = hero.atk - m->def;
    int dmgH = (m->atk - hero.def > 0) ? (m->atk - hero.def) : 0;
    if (dmgM <= 0) {
        sprintf(global_msg, "无法破防 %s!", m->name);
        return 0;
    }
    int rounds = (m->hp + dmgM - 1) / dmgM;
    int totalDmg = (rounds - 1) * dmgH;

    if (hero.hp > totalDmg) {
        hero.hp -= totalDmg;
        hero.gold += m->gold_drop;
        movePlayer(tx, ty, '.'); 
        sprintf(global_msg, "消灭 %s! 损失 HP: %d", m->name, totalDmg);
        return 1;
    } else {
        sprintf(global_msg, "HP不足以击败 %s!", m->name);
        return 0;
    }
}

void handleInput() {
    int nextX = hero.x, nextY = hero.y;
    char ch = _getch();

    // 回车键：处理上下楼梯和商店
    if (ch == '\r') {
        if (hero.under_char == 'U' && hero.floor < MAX_FLOOR - 1) {
            tower[hero.floor][hero.x][hero.y] = 'U';
            hero.floor++;
            for(int i=0; i<MAP_SIZE; i++)
                for(int j=0; j<MAP_SIZE; j++)
                    if(tower[hero.floor][i][j] == 'N') { nextX = i; nextY = j; }
            hero.x = nextX; hero.y = nextY;
            hero.under_char = 'N';
            tower[hero.floor][hero.x][hero.y] = '@';
            sprintf(global_msg, "进入第 %d 层。", hero.floor + 1);
        } else if (hero.under_char == 'N' && hero.floor > 0) {
            tower[hero.floor][hero.x][hero.y] = 'N';
            hero.floor--;
            for(int i=0; i<MAP_SIZE; i++)
                for(int j=0; j<MAP_SIZE; j++)
                    if(tower[hero.floor][i][j] == 'U') { nextX = i; nextY = j; }
            hero.x = nextX; hero.y = nextY;
            hero.under_char = 'U';
            tower[hero.floor][hero.x][hero.y] = '@';
            sprintf(global_msg, "进入第 %d 层。", hero.floor + 1);
        } else if (hero.under_char == '$') {
            shopLoop(); // 进入商店函数
        }
        return;
    }

    strcpy(global_msg, "");
    if (ch == 'w' || ch == 'W') nextX--;
    else if (ch == 's' || ch == 'S') nextX++;
    else if (ch == 'a' || ch == 'A') nextY--;
    else if (ch == 'd' || ch == 'D') nextY++;
    else return;

    if (nextX < 0 || nextX >= MAP_SIZE || nextY < 0 || nextY >= MAP_SIZE) return;

    char target = tower[hero.floor][nextX][nextY];
    switch (target) {
        case '.': movePlayer(nextX, nextY, '.'); break;
        case 'K': hero.key++; sprintf(global_msg, "获得黄钥匙!"); movePlayer(nextX, nextY, '.'); break;
        case 'R': hero.atk += 2; sprintf(global_msg, "攻击力 +2!"); movePlayer(nextX, nextY, '.'); break;
        case 'G': hero.def += 2; sprintf(global_msg, "防御力 +2!"); movePlayer(nextX, nextY, '.'); break;
        case 'A': hero.hp += 200; sprintf(global_msg, "生命值 +200!"); movePlayer(nextX, nextY, '.'); break;
        case 'U': sprintf(global_msg, "站在上楼梯上，按回车(Enter)切换。"); movePlayer(nextX, nextY, 'U'); break;
        case 'N': sprintf(global_msg, "站在下楼梯上，按回车(Enter)切换。"); movePlayer(nextX, nextY, 'N'); break;
        case '$': sprintf(global_msg, "进入商店，按回车(Enter)确认。"); movePlayer(nextX, nextY, '$'); break;
        case 'M': battleLogic(&slime, nextX, nextY); break;
        case 'B': battleLogic(&bat, nextX, nextY); break;
        case 'D': 
            if (hero.key > 0) { 
                hero.key--; sprintf(global_msg, "门已开启。"); movePlayer(nextX, nextY, '.'); 
            } else sprintf(global_msg, "缺少黄钥匙!");
            break;
    }
}

void drawMap() {
    system("cls");
    printf("========================================\n");
    printf("   " CYAN "魔塔 (Magic Tower)" RESET "  第 %d 层\n", hero.floor + 1);
    printf("========================================\n");

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            char item = tower[hero.floor][i][j];
            
            // 根据字符类型上色
            switch (item) {
                case '@': printf(CYAN "@ " RESET); break;      // 勇者
                case 'M': 
                case 'B': printf(RED "%c " RESET, item); break; // 怪物
                case '$': printf(GREEN "$ " RESET); break;     // 商店
                case 'K': 
                case 'D': printf(YELLOW "%c " RESET, item); break; // 钥匙和门
                case 'R': printf(MAGENTA "R " RESET); break;   // 红宝石
                case 'G': printf(BLUE "G " RESET); break;      // 蓝宝石
                case 'A': printf(RED "A " RESET); break;       // 血瓶
                case 'U': 
                case 'N': printf(CYAN "%c " RESET, item); break; // 楼梯
                default:  printf("%c ", item); break;          // 墙壁和空地
            }
        }
        
        // 侧边栏属性也加上颜色，更醒目
        if (i == 1) printf("   [ 勇者属性 ]");
        if (i == 2) printf("   生命: " RED "%d" RESET, hero.hp);
        if (i == 3) printf("   攻击: " MAGENTA "%d" RESET, hero.atk);
        if (i == 4) printf("   防御: " BLUE "%d" RESET, hero.def);
        if (i == 5) printf("   金币: " YELLOW "%d" RESET, hero.gold);
        if (i == 6) printf("   钥匙: " YELLOW "%d" RESET, hero.key);
        printf("\n");
    }
    printf("----------------------------------------\n");
    printf(YELLOW "【消息】" RESET "%s\n", global_msg);
    printf("----------------------------------------\n");
}

int main() {
    printf("\e[?25l"); 
    while (1) {
        drawMap();
        handleInput();
    }
    return 0;
}
