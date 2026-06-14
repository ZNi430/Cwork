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

// 全局变量
Player hero = { 1000, 20, 10, 0, 1, 1, 1, 0, '.' };
char global_msg[100] = "欢迎来到魔塔！";
Monster slime = { 'M', "绿史莱姆", 50, 15, 5, 10 };
Monster bat = { 'B', "小蝙蝠", 120, 30, 12, 25 };

// 全地图数据 (绝对无省略)
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
    { // 3F: 商店
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
    { // 7F: 商店
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

// --- 存档逻辑 ---
void saveGame() {
    FILE *fp = fopen("save.dat", "wb");
    if (fp) {
        fwrite(&hero, sizeof(Player), 1, fp);
        fwrite(tower, sizeof(char), MAX_FLOOR * MAP_SIZE * MAP_SIZE, fp);
        fclose(fp);
        strcpy(global_msg, "【系统】进度已成功保存！按任意键继续...");
        return;
    }
    strcpy(global_msg, "【错误】无法写入存档文件！");
}

int loadGame() {
    FILE *fp = fopen("save.dat", "rb");
    if (!fp) return 0;
    fread(&hero, sizeof(Player), 1, fp);
    fread(tower, sizeof(char), MAX_FLOOR * MAP_SIZE * MAP_SIZE, fp);
    fclose(fp);
    return 1;
}

// --- 核心工具 ---
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
        printf(GREEN "========= 神秘商店 =========\n" RESET);
        printf(" 金币: %d\n", hero.gold);
        printf(" 1. 生命+800 (20金) | 2. 攻击+4 (20金) | 3. 防御+4 (20金) | Esc 离开\n");
        choice = _getch();
        if (choice == 27) break;
        if (hero.gold < 20) continue;
        if (choice == '1') hero.hp += 800;
        else if (choice == '2') hero.atk += 4;
        else if (choice == '3') hero.def += 4;
        hero.gold -= 20;
    }
    strcpy(global_msg, "交易完成！");
}

int battle(Monster *m, int tx, int ty) {
    int dmgM = hero.atk - m->def;
    int dmgH = (m->atk - hero.def > 0) ? (m->atk - hero.def) : 0;
    if (dmgM <= 0) { strcpy(global_msg, "破不了防，别送死！"); return 0; }
    int rounds = (m->hp + dmgM - 1) / dmgM;
    int total = (rounds - 1) * dmgH;
    if (hero.hp > total) {
        hero.hp -= total; hero.gold += m->gold_drop;
        movePlayer(tx, ty, '.');
        sprintf(global_msg, "击败%s，损失生命%d", m->name, total);
        return 1;
    }
    strcpy(global_msg, "生命值不足，打不过！");
    return 0;
}

void drawMap() {
    system("cls");
    printf("魔塔 第 %d 层  |  [P] 存档\n", hero.floor + 1);
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            char c = tower[hero.floor][i][j];
            if (c == '@') printf(CYAN "@ " RESET);
            else if (c == 'M' || c == 'B') printf(RED "%c " RESET, c);
            else if (c == '$' || c == 'V') printf(GREEN "%c " RESET, c);
            else if (c == 'K' || c == 'D') printf(YELLOW "%c " RESET, c);
            else if (c == 'R' || c == 'G' || c == 'A') printf(MAGENTA "%c " RESET, c);
            else if (c == 'U' || c == 'N') printf(CYAN "%c " RESET, c);
            else printf("%c ", c);
        }
        if (i == 1) printf("  HP:  %d", hero.hp);
        if (i == 2) printf("  ATK: %d", hero.atk);
        if (i == 3) printf("  DEF: %d", hero.def);
        if (i == 4) printf("  GOLD:%d", hero.gold);
        if (i == 5) printf("  KEY: %d", hero.key);
        printf("\n");
    }
    printf("---------------------------\n【播报】%s\n", global_msg);
}

void handleInput() {
    int nx = hero.x, ny = hero.y;
    char ch = _getch();
    
    if (ch == 'p' || ch == 'P') { saveGame(); return; }
    if (ch == '\r') {
        if (hero.under_char == 'U' && hero.floor < 9) {
            tower[hero.floor][hero.x][hero.y] = 'U'; hero.floor++;
            if (hero.floor == 8) strcpy(global_msg, "【剧情】空气变得沉重，胜利就在眼前！");
            for(int i=0; i<10; i++) for(int j=0; j<10; j++) if(tower[hero.floor][i][j] == 'N') { nx=i; ny=j; }
            hero.x=nx; hero.y=ny; hero.under_char='N'; tower[hero.floor][nx][ny]='@';
        } else if (hero.under_char == 'N' && hero.floor > 0) {
            tower[hero.floor][hero.x][hero.y] = 'N'; hero.floor--;
            for(int i=0; i<10; i++) for(int j=0; j<10; j++) if(tower[hero.floor][i][j] == 'U') { nx=i; ny=j; }
            hero.x=nx; hero.y=ny; hero.under_char='U'; tower[hero.floor][nx][ny]='@';
        } else if (hero.under_char == '$') shopLoop();
        return;
    }

    if (ch == 'w' || ch == 'W') nx--; else if (ch == 's' || ch == 'S') nx++;
    else if (ch == 'a' || ch == 'A') ny--; else if (ch == 'd' || ch == 'D') ny++; else return;
    
    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) return;
    char t = tower[hero.floor][nx][ny];
    if (strstr(global_msg, "剧情") == NULL) strcpy(global_msg, ""); // 非剧情消息移动即清

    switch (t) {
        case '.': movePlayer(nx, ny, '.'); break;
        case 'K': hero.key++; movePlayer(nx, ny, '.'); break;
        case 'R': hero.atk += 2; movePlayer(nx, ny, '.'); break;
        case 'G': hero.def += 2; movePlayer(nx, ny, '.'); break;
        case 'A': hero.hp += 200; movePlayer(nx, ny, '.'); break;
        case 'U': movePlayer(nx, ny, 'U'); break;
        case 'N': movePlayer(nx, ny, 'N'); break;
        case '$': movePlayer(nx, ny, '$'); break;
        case 'M': battle(&slime, nx, ny); break;
        case 'B': battle(&bat, nx, ny); break;
        case 'D': if (hero.key > 0) { hero.key--; movePlayer(nx, ny, '.'); } break;
        case 'V': movePlayer(nx, ny, 'V'); drawMap(); printf("\n" GREEN "【结局】英雄战胜了魔塔！" RESET); _getch(); exit(0);
    }
}

int main() {
    system(""); printf("\e[?25l");
    printf("1. 新游戏  2. 读取存档\n选择: ");
    if (_getch() == '2' && loadGame()) strcpy(global_msg, "进度已载入");
    while (1) { drawMap(); handleInput(); }
    return 0;
}
