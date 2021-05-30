/*
    This File is used for Encoding maze and print it on the console
*/

// Include All libraries which we need
#include<stdio.h>
/*
    All declaration of functions are here and Definition are under the main function
*/
// This function is used for encoding maze and display it on the console screen
void printEncodeMaze(int[], unsigned char);
// This function is used for encoding maze and display with path for path I used * character
void printEncodeMazeWithPath(int[], int[], unsigned char);
// This function will encode the 2d char array Maze into 1d int array
void encode8by8Maze(char inputMaze[8][8], int encodedMaze[8]);
// This function is used to Merge all 4 side into final Maze
void merge8by8Mazes(int topLeft[8], int topRight[8], int bottomLeft[8], int bottomRight[8], int finalMaze[14]);
// This function check if maze have a path or not
char isPathInMaze(int[], int[], unsigned char);


// This is our main function.
int main()
{
    printf("<-------------------------------------------------------------------------------------------------------------------------------------------------------->\n");
    printf("                                          <<<***>>>           Maze Assignment            <<<***>>>\n");
    printf("<-------------------------------------------------------------------------------------------------------------------------------------------------------->\n\n\n");
    // hard code maze
    /*
        Task No 1
            Hard Code The full Maze as 32 int array
    */
    int maze[32] = {
        -1,
        -2146430423,
        -1525661045,
        -1602496045,
        -1358950569,
        -1451509759,
        -1927115297,
        -1578180479,
        -1354977603,
        -1476294999,
        -2084818261,
        -1163749757,
        -1964319689,
        -1341614619,
        -1750141691,
        -1256060945,
        -1515522751,
        -1204136611,
        -1955867371,
        -1190652827,
        -1553272339,
        -1100839163,
        -1999963019,
        -631368865,
        -1882138047,
        -1172944163,
        -1412279803,
        -1567107339,
        -164346691,
        -2138762879,
        -1
    };

    /*
        Task No 2
            Print The Encoded Maze
    */
    printf(">>> Output of Task 1 and 2 \n");
    printEncodeMaze(maze, 32);
    printf("\n");


    /*
        Task 3
            Print the encoded maze with path
    */
    // hard code path
    int path[32] = {
        0, 0, 0, 0, 12, 8, 56, 32, 8032, 4416, 134115648, 67354944, 67109184, 67109312, 133169152, 1048576, 1835008, 262144, 458752, 65536, 65536, 65536, 65536, 983040, 67633152,
        67633152, 201850880, 164102144, 259522560, 0
    };

    printf(">>> Output of Task 3 \n");
    printEncodeMazeWithPath(maze, path, 32);
    printf("\n");

    /*
        Task 4
            Encode the 8x8 maze into single int array of 8
    */
    // Hard code the Mazes
    char MAZE1[8][8] = {
                        {'1','1','1','1','1','1','1','1'},
                        {'1','0','0','0','1','0','0','1'},
                        {'1','0','1','0','1','1','0','1'},
                        {'1','0','1','0','0','0','0','1'},
                        {'1','0','1','1','1','1','0','1'},
                        {'1','0','0','0','0','0','0','1'},
                        {'1','0','1','0','1','0','1','1'},
                        {'1','1','1','1','1','1','1','1'}
                    };
    char MAZE2[8][8] = {
                        {'1','1','1','1','1','1','1','1'},
                        {'1','0','0','0','0','1','0','1'},
                        {'1','1','1','1','0','1','0','1'},
                        {'1','0','0','1','0','1','1','1'},
                        {'1','1','0','0','0','0','0','1'},
                        {'1','1','1','1','0','1','1','1'},
                        {'1','0','0','0','0','1','0','1'},
                        {'1','1','1','1','1','1','1','1'}
                    };
    char MAZE3[8][8] = {
                        {'1','1','1','1','1','1','1','1'},
                        {'1','0','1','0','0','0','1','1'},
                        {'1','0','1','0','1','0','0','1'},
                        {'1','0','1','0','1','0','1','1'},
                        {'1','0','1','0','1','0','1','1'},
                        {'1','0','1','0','1','0','1','1'},
                        {'1','0','0','0','1','0','0','1'},
                        {'1','1','1','1','1','1','1','1'}
                    };
    char MAZE4[8][8] = {
                        {'1','1','1','1','1','1','1','1'},
                        {'1','0','1','0','1','0','1','1'},
                        {'1','0','1','0','0','0','0','1'},
                        {'1','0','0','0','1','1','1','1'},
                        {'1','1','1','0','1','0','0','1'},
                        {'1','0','0','0','0','0','1','1'},
                        {'1','1','0','1','1','0','0','1'},
                        {'1','1','1','1','1','1','1','1'}
                    };
    int encodedMaze[8];

    printf(">>> Output of Task 4 \n");
    encode8by8Maze(MAZE1, encodedMaze);
    printEncodeMaze(encodedMaze, 8);
    printf("\n");

    encode8by8Maze(MAZE2, encodedMaze);
    printEncodeMaze(encodedMaze, 8);
    printf("\n");

    encode8by8Maze(MAZE3, encodedMaze);
    printEncodeMaze(encodedMaze, 8);
    printf("\n");

    encode8by8Maze(MAZE4, encodedMaze);
    printEncodeMaze(encodedMaze, 8);
    printf("\n");


    /*
        Task 5
            Merge 8 by 8 maze
    */

    int topLeft[8]; int topRight[8]; int bottomLeft[8]; int bottomRight[8];
    int finalMaze[14];

    encode8by8Maze(MAZE1, topLeft);
    encode8by8Maze(MAZE2, topRight);
    encode8by8Maze(MAZE3, bottomLeft);
    encode8by8Maze(MAZE4, bottomRight);

    merge8by8Mazes(topLeft, topRight, bottomLeft, bottomRight, finalMaze);
    printf(">>> Output of Task 5 \n");
    printEncodeMaze(finalMaze, 14);
    printf("\n");


    /*
        Task 6 and Task 7
        Task 6 : generate all 256 combinations and print the merge maze with the combination
        Task 7:  check if path exist on the maze then write sentence, 8 maze should have the path.
    */

    int combination_counter = 0;
    int fitted_counter = 0;
    int testPath[] = {0, 4096, 4096, 4096, 4096, 7936, 256, 256, 448, 112, 16, 28, 6, 0};
    int *sides_array[] = {testPath,topLeft, topRight, bottomLeft, bottomRight};

    printf(">>> Output of Task 6 and 7 \n");

    for(int a=1; a<=4; a++)
    {
        for(int b=1; b<=4; b++)
        {
            for(int c=1; c<=4; c++)
            {
                for(int d=1; d<=4; d++)
                {
                    combination_counter++;
                    printf("===========================================================  Maze No :  %d  =============================================================\n",combination_counter);
                    printf("Maze Combination :    %d, %d, %d, %d \n",a,b,c,d);
                    merge8by8Mazes(sides_array[a], sides_array[b], sides_array[c], sides_array[d], finalMaze);
                    printEncodeMaze(finalMaze, 14);
                    char Is_path = isPathInMaze(finalMaze, sides_array[0], 14);
                    if (Is_path == '1'){
                        fitted_counter++;
                        printf("****************************************************************************************************************************\n");
                        printf(">>> The Path is Fitted On this Maze <<< \n");
                        printf(" %d  : are matched with the path. \n",fitted_counter);
                        printf("****************************************************************************************************************************\n\n\n");
                    }
                    printf("\n");

                }
            }
        }
    }

    return 0;
}

void printEncodeMaze(int maze[] , unsigned char dimension)
{
    /*
        This function takes two parameters
        maze: which is int array which have the encoded maze
        dimension: which is unsigned char which means it could have 0-255 possible combination because 2^8 is 255

        output: This function does not return something but it decode the maze and print it console
    */
    // loop through each row of maze
    //printf("start \n");
    for(int i=0; i<dimension ;i++)
    {
        //printf("i : %d", i);
        // decode the maze using bitwise operator
        for(int j=dimension-1 ; j>=0 ; j--)
        {
            //printf(" %d ",j);
            int is_wall  = maze[i] >> j;

            // if its wall then it will be 1 so 1 and 1 is true
            if(is_wall & 1)
            {
                // print wall
                printf("@");
            }
            else
            {
                // print space
                printf(" ");
            }
        }
        // move to next row
        printf("\n");
    }
}

void printEncodeMazeWithPath(int maze[], int path[], unsigned char dimension)
{

    /*
        This function takes three parameters
        maze: which is int array which have the encoded maze
        path: which is int array and it have the encoded path
        dimension: which is unsigned char which means it could have 0-255 possible combination because 2^8 is 255

        output: This function does not return something but it decode the maze and print the maze and path in console
    */

    // loop through each row of maze
    for(int i=0; i<dimension ;i++)
    {
        // decode the maze and path
        for(int j=dimension-1 ; j>=0 ; j--)
        {
            int is_wall  = maze[i] >> j;
            int is_path = path[i] >> j;

            // if it is path on the maze then it will be 1
            if(is_path & 1)
            {
                // obviously the path will have zero for each bit that corresponds to a wall so no need to check it.
                printf(".");
            }
            else
            {
                if(is_wall & 1)
                {
                    // wall
                    printf("@");
                }
                else
                {
                    // open space
                    printf(" ");
                }
            }

        }
        // move to next row
        printf("\n");
    }
}

void encode8by8Maze(char inputMaze[8][8], int encodedMaze[8])
{
    /*
        This function takes two parameters
        maze: which is 2d array which have the maze
        encodedMaze: which is int array and this function will populate it with encoded maze

    */
    for(int row=0; row<=7 ; row++)
    {
        int sum = 0;
        int bit_number = 1;
        for(int col=7; col>=0; col--)
        {
            int bit = (inputMaze[row][col] -48);
            //printf(" %d ",bit);
            sum += bit * bit_number;

            //printf(" %d ",bit_number);
            bit_number = bit_number + bit_number;

        }
        encodedMaze[row] = sum;
    }
}

void merge8by8Mazes(int topLeft[8], int topRight[8], int bottomLeft[8], int bottomRight[8], int finalMaze[14])
{
    /*
        This function takes 5 parameters
        First four parameters are encoded maze and this function will merge them and make final maze which is argument no 5
    */

    unsigned int bit_shift;
    int sum, bit_number, bit;

    for(int f_row=0; f_row<14; f_row++)
    {
        sum = 0;
        bit_number = 1;

        if(f_row>=0 && f_row<=6)
        {
            for(int f_col=13; f_col>=0; f_col--)
            {
                if(f_col>=0 && f_col<=6)
                {
                    bit_shift = abs(f_col - 7);
                    bit = topLeft[f_row] >> bit_shift;
                    if(bit & 1)
                    {
                        bit = 1;
                    }
                    else
                    {
                        bit = 0;
                    }

                    sum += bit * bit_number;
                }
                else
                {
                        bit_shift = abs(f_col-13);
                        // Get the bit
                        bit = topRight[f_row] >> bit_shift;

                        if(bit & 1)
                        {
                            bit = 1;
                        }
                        else
                        {
                            bit = 0;
                        }
                        // find its value and add it into the sum
                        sum += bit * bit_number;
                }
                // Update the bit value
                bit_number =  bit_number + bit_number;
            }
        }
        else
        {
            for(int f_col=13; f_col>=0; f_col--)
            {
                if(f_col>=0 && f_col<=6)
                {
                    bit_shift = abs(f_col - 7);
                    bit = bottomLeft[f_row-6] >> bit_shift;
                    if(bit & 1)
                    {
                        bit = 1;
                    }
                    else
                    {
                        bit = 0;
                    }

                    sum += bit * bit_number;
                }
                else
                {
                        bit_shift = abs(f_col - 13);
                        // Get the bit
                        int bit = bottomRight[f_row-6] >> bit_shift;
                        // find its value and add it into the sum
                        if(bit & 1)
                        {
                            bit = 1;
                        }
                        else
                        {
                            bit = 0;
                        }

                        sum += bit * bit_number;
                }
                // Update the bit value
                bit_number =  bit_number + bit_number;
            }

        }
        //printf("Sum : %d \n",sum);
        finalMaze[f_row] = sum;
    }
}


char isPathInMaze(int encodedMaze[], int path[], unsigned char dimension)
{
    /*
        This function takes three parameters
        encodedMaze : which is int array which have the encoded maze.
        path: which is int array and it have the encoded path.
        dimension: which is unsigned char which means it could have 0-255 possible combination because 2^8 is 255

        output: This function return 1 if path exist on the maze if not then return 0
    */

    for(int i=0; i<dimension ;i++)
    {
        // decode the maze and path
        for(int j=dimension-1 ; j>=0 ; j--)
        {
            int is_wall  = encodedMaze[i] >> j;
            int is_path = path[i] >> j;

            // if path not exist
            if( (is_path&1) && (is_wall&1) )
            {
                return '0';
            }
        }
    }
    return '1';
}


