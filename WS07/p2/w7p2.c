/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  : Jiaheng Wang
Student ID#: 180562217
Email      : jwang522@myseneca.ca
Section    : NNN

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


#define MAX_PATH_LEN 70
#define MIN_PATH_LEN 10
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MULTIPLE 5

struct PlayerInfo
{
    int lives;                  //number of lives
    char symbol;                //character symbol
    int treasures;              //number of treasures
    int history[MAX_PATH_LEN];  //number of places
};

struct GameInfo
{
    int moves;      //number of moves
    int path_length; //number of places
    int Bombs[MAX_PATH_LEN];
    int Treasures[MAX_PATH_LEN];
};

void BombPlacement(struct GameInfo* g)
{
    int i, j, x = 0, state = 1;
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example:");
    for (i = 0; i < MULTIPLE; i++)
        if (state == 1) { printf(" 1"); state = 2; }
        else if (state == 2) { printf(" 0"); state = 3; }
        else if (state == 3) { printf(" 0"); state = 4; }
        else if (state == 4) { printf(" 1"); state = 1; }
    printf(") NOTE: there are% d to set!\n", g->path_length);
    for (i = 0; i < g->path_length / MULTIPLE; i++)
    {
        printf("   Positions [%2d-%2d]: ", MULTIPLE * i + 1, MULTIPLE * (i + 1));
        for (j = 0; j < MULTIPLE; j++)
            scanf("%d", &g->Bombs[x++]);
    }
    printf("BOMB placement set\n\n");
    return;
}

void TreasurePlacement(struct GameInfo* g)
{
    int i, j, x = 0, state = 1;
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example:");
    for (i = 0; i < MULTIPLE; i++)
        if (state == 1) { printf(" 1"); state = 2; }
        else if (state == 2) { printf(" 0"); state = 3; }
        else if (state == 3) { printf(" 0"); state = 4; }
        else if (state == 4) { printf(" 1"); state = 1; }
    printf(") NOTE: there are% d to set!\n", g->path_length);
    for (i = 0; i < g->path_length / MULTIPLE; i++)
    {
        printf("   Positions [%2d-%2d]: ", MULTIPLE * i + 1, MULTIPLE * (i + 1));
        for (j = 0; j < MULTIPLE; j++)
            scanf("%d", &g->Treasures[x++]);
    }
    printf("TREASURE placement set\n\n");
    return;
}

void DisplayConfiguration(struct PlayerInfo* p, struct GameInfo* g)
{
    int i;
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", p->symbol);
    printf("   Lives      : %d\n", p->lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", g->path_length);
    printf("   Bombs      : ");
    for (i = 0; i < g->path_length; i++)
        printf("%d", g->Bombs[i]);
    printf("\n   Treasure   : ");
    for (i = 0; i < g->path_length; i++)
        printf("%d", g->Treasures[i]);
    return;
}

void DisplayLine1(int r, int p, char s)
{
    int i;
    printf("  ");
    for (i = 0; i < p; i++)
        if (r == i)
        {
            printf("%c", s);
            break;
        }
        else printf(" ");
    printf("\n");
    return;
}

void DisplayLine2(int p, int h[MAX_PATH_LEN], int b[MAX_PATH_LEN], int t[MAX_PATH_LEN])
{
    int i;
    printf("  ");
    for (i = 0; i < p; i++)
    {
        if (h[i] == 0)
            printf("-");
        else if (b[i] == 1 && t[i] == 0)
            printf("!");
        else if (b[i] == 0 && t[i] == 1)
            printf("$");
        else if (b[i] == 1 && t[i] == 1)
            printf("&");
        else
            printf(".");
    }
    printf("\n");
    return;
}

void DisplayLine34(int p)
{
    int i;
    printf("  ");
    for (i = 0; i < p; i++)
        if ((i + 1)% 10 == 0) printf("%d", (i + 1)/ 10);
        else printf("|");
    printf("\n  ");
    for (i = 0; i < p; i++)
        if ((i+1) % 10 == 0) printf("0");
        else printf("%d", (i+1) % 10);
    printf("\n");
    return;
}

int main(void)
{
    struct PlayerInfo player = { 0, '\0', 0, {0} };
    struct GameInfo game = { 0, 0, {0}, {0} };
    int theMove = -1, treasuresFound = 0, i, j=0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < MIN_LIVES || player.lives > MAX_LIVES)
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
    } while (player.lives < MIN_LIVES || player.lives > MAX_LIVES);
    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ",
            MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);
        scanf("%d", &game.path_length);
        if (game.path_length < MIN_PATH_LEN || game.path_length > MAX_PATH_LEN ||
            game.path_length % MULTIPLE)
            printf("     Must be a multiple of %d and between %d-%d!!!\n",
                MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);
    } while (game.path_length < MIN_PATH_LEN || game.path_length > MAX_PATH_LEN ||
        game.path_length % MULTIPLE);
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if (game.moves < player.lives || game.moves >(int)(0.75 * game.path_length))
            printf("    Value must be between %d and %d\n",
                player.lives, (int)(0.75 * game.path_length));
    } while (game.moves < player.lives || game.moves >(int)(0.75 * game.path_length));
    printf("\n");
    BombPlacement(&game);
    TreasurePlacement(&game);
    printf("GAME configuration set-up is complete...\n\n");
    DisplayConfiguration(&player, &game);
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    DisplayLine2(game.path_length, player.history, game.Bombs, game.Treasures);
    DisplayLine34(game.path_length);
    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
        player.lives, treasuresFound, game.moves);
    printf("+---------------------------------------------------+\n");
    do {
        do {
            printf("Next Move [1-%2d]: ", game.path_length);
            scanf("%d", &theMove);
            if (theMove < 1 || theMove > game.path_length)
                printf("  Out of Range!!!\n");
        } while (theMove < 1 || theMove > game.path_length);        
        if (game.Bombs[theMove - 1] == 1)
            player.lives -= 1;
        if (game.Treasures[theMove - 1] == 1)
            treasuresFound += 1;
        game.moves--;
        printf("\n===============> ");
        for (i = 0; i < game.path_length; i++)
            if (player.history[theMove - 1] == theMove)
            {
                printf("Dope! You've been here before!\n\n");
                game.moves += 1;
                break;
            }               
            else
            {
                if (game.Bombs[theMove - 1] == 1 && game.Treasures[theMove - 1] == 0)
                {
                    printf("[!] !!! BOOOOOM !!! [!]\n\n");
                    if (player.lives == 0)
                        printf("No more LIVES remaining!\n\n");
                    break;
                }
                else if (game.Bombs[theMove - 1] == 0 && game.Treasures[theMove - 1] == 1)
                {
                    printf("[$] $$$ Found Treasure! $$$ [$]\n\n");
                    break;
                }
                else if (game.Bombs[theMove - 1] == 1 && game.Treasures[theMove - 1] == 1)
                {
                    printf("[&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    break;
                }
                else
                {
                    printf("[.] ...Nothing found here... [.]\n\n");
                    break;
                }
            }
        player.history[theMove - 1] = theMove;
        j++; 
        DisplayLine1(theMove - 1, game.path_length, player.symbol);
        DisplayLine2(game.path_length, player.history, game.Bombs, game.Treasures);
        DisplayLine34(game.path_length);
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
            player.lives, treasuresFound, game.moves);
        printf("+---------------------------------------------------+\n");
    } while (player.lives > 0 && game.moves > 0);
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}
