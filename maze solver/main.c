//Import required packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int x;              // The horizontal/vertical size of the map
    int y;
    int error = 0;      // If an error is ever enocuntered, set to 1 and quit
    int xtemp = 0;      // A temp veriable used throughout to represent x
    int ytemp = 0;
    char a;             // 'a' is a temp variable used to hold arbitrary chars
    char temp[99];      // 'temp' is a temporary string used to store input

    //Read the first line and second lines, and convert to integers
    fgets(temp, 99, stdin);
    y = atoi(temp);
    fgets(temp, 99, stdin);
    x = atoi(temp);

    //Declare character array of specified size to hold map
    char maze[y][x];

    // Fills array row by row. Since fgets needs to read the newline character
    // the '+2" is used to ensure that the entire line gets written and the
    // buffer is ready to move to the next line after



    // Find the landing site and target
    // Each variable is initialized to -1 in order to allow duplicate checking
    int iX = -1; // Initial X/Y position (start point)
    int iY = -1;
    int fX = -1; // Final X/Y position (end point)
    int fY = -1;

    // Loop through the entire array checking eact element individually
    for(ytemp = 0;ytemp < y; ytemp++){
        for(xtemp = 0;xtemp < x; xtemp++){
            a = maze[ytemp][xtemp];
            if(a == 'L' && iX == -1){       // Check if start point AND that
                iX = xtemp;                 // start has not been set already
                iY = ytemp;
            }else if(a == 'L' && iX != -1){ // if iX != -1, then has been set
                error = 1;
            }

            if(a == 'X' && fX == -1){       // Check if end point AND that
                fX = xtemp;                 // start has not been set already
                fY = ytemp;
            }else if(a == 'X' && fX != -1){ // if iX != -1, then has been set
                error = 1;
            }

            // If a character other than X, L, ., or # is encountered, mark the
            // error and stop the program from running
            if(a != 'X' && a !=  'L' && a !=  '.' && a !=  '#'){
                error = 1;
            }
        }
    }

    if(iX == -1){
        error = 1;
    }

    if(fX == -1){
        error = 1;
    }

    if(error == 1){
        fprintf(stderr,"invalid input\n");
    }

    // Map is now filled, verified, and start/end locations are knows
    // Now we will search through to find the path
    int xP = iX;        // xP = 'x position'. iX = 'initial x'
    int yP = iY;

    // 'Flood' used to store integers corresponding to the distance from
    // the starting location. The maze will be 'flooded' out from the start.
    int flood[y][x];

    // Fill 'Flood' Map with -1s.
    for(ytemp = 0;ytemp < y; ytemp++){
        for(xtemp = 0;xtemp < x; xtemp++){
            flood[ytemp][xtemp] = -1;
        }
    }

    // Set the starting point to 0. At this point all others are -1.
    flood[iY][iX] = 0;


    int found = 0;
    int moves = 0;
    int itt = 1;        // 'Itteration' increments as the bot 'floods' outwards
    int moremoves = 1;

    //This is the main loop that 'floods' the maze
    while(found != 1 && moves < 150 && error == 0 && moremoves == 1){
        moremoves = 0;      // Assume no more moves. If more moves, set to 1

        // Loop through every grid space individually
        for(ytemp = 0;ytemp < y; ytemp++){
            for(xtemp = 0;xtemp < x; xtemp++){
                xP = xtemp;
                yP = ytemp;

                // If the boundary of the "flooding" is found...
                if(flood[ytemp][xtemp] == (itt - 1)){

                    // Move the 'flooding' up if the move is valid and not
                    // hitting a wall.
                    if(
                        ((char)maze[yP-1][xP] == '.' ||
                        (char)maze[yP-1][xP] == 'L' ||
                        (char)maze[yP-1][xP] == 'X')
                        && (yP - 1) >= 0
                        && flood[yP-1][xP] == -1
                    ){
                        flood[yP-1][xP] = itt;  // Make this the new boundary
                        moremoves = 1;

                        // If target is found, let the program can stop looping.
                        // Since the location of the is already known from
                        // initial scan, the flooding job is done.
                        if((char)maze[yP-1][xP] == 'X'){
                            flood[yP-1][xP] = itt;
                            found = 1;
                        }
                    }

                    //Same as above, but checking flooding Down
                    if(
                        ((char)maze[yP+1][xP] == '.' ||
                        (char)maze[yP+1][xP] == 'L' ||
                        (char)maze[yP+1][xP] == 'X')
                        && (yP + 1) < y
                        && flood[yP+1][xP] == -1
                    ){
                        flood[yP+1][xP] = itt;
                        moremoves = 1;
                        if((char)maze[yP+1][xP] == 'X'){
                            flood[yP+1][xP] = itt;
                            found = 1;
                        }
                    }

                    //Same as above, but checking flooding Left
                    if(
                        ((char)maze[yP][xP-1] == '.' ||
                        (char)maze[yP][xP-1] == 'L' ||
                        (char)maze[yP][xP-1] == 'X')
                        && (xP - 1) >= 0
                        && flood[yP][xP - 1] == -1
                    ){
                        flood[yP][xP - 1] = itt;
                        moremoves = 1;
                        if((char)maze[yP][xP-1] == 'X'){
                            flood[yP][xP-1] = itt;
                            found = 1;
                        }
                    }

                    //Same as above, but checking flooding Right
                    if(
                        ((char)maze[yP][xP+1] == '.' ||
                        (char)maze[yP][xP+1] == 'L' ||
                        (char)maze[yP][xP+1] == 'X')
                        && (xP + 1) < x
                        && flood[yP][xP + 1] == -1
                    ){
                        flood[yP][xP + 1] = itt;
                        moremoves = 1;
                        if((char)maze[yP][xP+1] == 'X'){
                            flood[yP][xP+1] = itt;
                            found = 1;
                        }
                    }

                }



            }// End Inner For Loop
        }//End Outer For Loop

        itt++;
        moves++;


    }//End Main While Loop


    /*
     * THE MAP IS FLOODED! IF NOT FOUND END HERE.
     * IF FOUND, WE CAN NOW FIND THE DIRECTION
     */

    int complete = 0;
    int directions[150] = {};
    int i = 0;


    if(found == 0 && error == 0){
        printf("no path\n");
    }else if(error == 0){
        xP = fX;
        yP = fY;

        while(complete == 0){

            // Since the numbers increase spanning out from zero, we can check
            // on all sides FROM the target, and count down to work back to the
            // start. When the loop gets back to the end, it is all finished
            if(flood[yP-1][xP] == flood[yP][xP] - 1 && (yP - 1) >= 0
                ){
                    yP--;
                    directions[i] = 3;  // 3 means south
                    i++;
                    if(flood[yP][xP] == 0){
                        complete = 1;
                    }
            }
            else if(flood[yP+1][xP] == flood[yP][xP] - 1 && (yP + 1) < y
                ){
                    yP++;
                    directions[i] = 1;  // 1 means north
                    i++;
                    if(flood[yP][xP] == 0){
                        complete = 1;
                    }
            }
            else if(flood[yP][xP-1] == flood[yP][xP] - 1 && (xP - 1) >= 0
                ){
                    xP--;
                    directions[i] = 2;  // 2 means east
                    i++;
                    if(flood[yP][xP] == 0){
                        complete = 1;
                    }
            }
            else if(flood[yP][xP+1] == flood[yP][xP] - 1 && (xP + 1) < x
                ){
                    xP++;
                    directions[i] = 4;  // 4 means west
                    i++;
                    if(flood[yP][xP] == 0){
                        complete = 1;
                    }
            }

        }//End While

    }//End If

    // Print output in reverse order
    if(error == 0){

        for(;i>=0;i--){
            if(directions[i]==1){
                printf("North\n");
            }else if(directions[i]==2){
                printf("East\n");
            }else if(directions[i]==3){
                printf("South\n");
            }else if(directions[i]==4){
                printf("West\n");
            }



        }
    }


    if(error == 1){
        return 1;
    }else{
        return 0;
    }
}
