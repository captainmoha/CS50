/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// empty space position
int empty_pos[2];
int tile_pos[2];

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

// helper prototypes
void setEmptyPos(short x, short y);
bool set_tile_pos(int tile);
void swap_tiles(short flag);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {   
                if (i == empty_pos[0] && j == empty_pos[1])
                {
                    fprintf(file, "0");
                }
                else
                {
                    fprintf(file, "%i", board[i][j]);
                }

                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        // usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{   
    int max_num = d * d - 1;

    // initialise the board with values from max_num until 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = max_num;
            max_num--;
        }
        
    }

    // put the value of an underscore in the last cell(tile)
    short last_index = d - 1;
    board[last_index][last_index] = (int) '-';

    // set the position of the empty tile
    setEmptyPos(last_index, last_index);

    // swap last two tiles if we have an odd number of tiles
    if ((d % 2) == 0)
    {   
        int temp = board[last_index][last_index - 1];
        board[last_index][last_index - 1] = board[last_index][last_index - 2];
        board[last_index][last_index - 2] = temp;
    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{   
    short seperator = '|';
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {   

            if (i == empty_pos[0] && j == empty_pos[1])
            {
                printf("%-4c%-6c%c", seperator, board[i][j], seperator);
            }

            else
            {
                printf("%-4c%-6i%c", seperator, board[i][j], seperator);
            }
            
        }

        printf("\n");
    }

    printf("\n");
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{   
    // set tile_pos to the position of the tile the user wants to move
    if (set_tile_pos(tile))
    {
        if ((tile_pos[0] + 1 == empty_pos[0]) && (tile_pos[1] == empty_pos[1]))
        {
            swap_tiles(0);
            return true;
        }
        // left
        else if ((tile_pos[0] - 1 == empty_pos[0]) && (tile_pos[1] == empty_pos[1]))
        {
            swap_tiles(0);
            return true;
        }

        // up
        else if ((tile_pos[1] + 1 == empty_pos[1]) && (tile_pos[0] == empty_pos[0]))
        {
            swap_tiles(1);
            return true;
        }

        // down
        else if ((tile_pos[1] - 1 == empty_pos[1]) && (tile_pos[0] == empty_pos[0]))
        {
            swap_tiles(1);
            return true;
        }
    }

    // printf("x = %i\ny = %i\n", tile_pos[0], tile_pos[1]);
    // printf("x = %i\ny = %i\n", empty_pos[0], empty_pos[1]);

    // check if the move is legal by looking in the four directions for the empty space
    
    // right
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{   

    for (short i = 0; i < d - 1; i++)
    {
        for (short j = 0; j < d - 1; j++)
        {   
            int current = board[i][j];
            int next = board[i][j + 1];

            // printf("current: %i -- next: %i\n", current, next);

            if ((next - current) != 1)
            {   
                return false;
            } 
        }
    }

    // return true if all the elements are in ascending order and the last tile is empty
    return (board[d - 1][d - 1] == 45); 
}

/*
    Sets empty_pos global value to the position of the empty tile
*/

void setEmptyPos(short x, short y)
{
    empty_pos[0] = y;
    empty_pos[1] = x;
}
bool set_tile_pos(int tile)
{   
    for (short i = 0; i < d; i++)
    {
        for (short j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                tile_pos[0] = i;
                tile_pos[1] = j;
                return true;
            }
        }
    }
    return false;
}

void swap_tiles(short flag)
{   
    
    /*
        swaps two tiles on the board
    */

    // flag is a variable that is 0 if we need to swap x_pos and 1 if we need to swap y_pos
    if (flag == 0)
    {   
        // update global varibales only the x pos
        int temp_x = empty_pos[0];
        empty_pos[0] = tile_pos[0];
        tile_pos[0] = temp_x;
    }

    else
    {   
        // update global varibales only the y pos
        int temp_y = empty_pos[1];
        empty_pos[1] = tile_pos[1];
        tile_pos[1] = temp_y;
    }

    // swap the tiles on the board
    int temp = board[empty_pos[0]][empty_pos[1]];
    board[empty_pos[0]][empty_pos[1]] = board[tile_pos[0]][tile_pos[1]];
    board[tile_pos[0]][tile_pos[1]] = temp;
}