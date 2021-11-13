This is the README file for ex02
--------------------------------

Created by:
    Netanel Bondar, 207211848 & Bar Oren, 206548752

Program Explanation:
    This program consists of 3 levels (small, medium and large). In each level you need to make the king (K) reach the throne (@).
    But you will need the help of the trusty group: mage (M), warrior (W) and the maybe not so trusty thief (T).
    They will help the king by killing trolls, grabbing keys to open gates and putting out fires.

List of files:
    Sources:
        King.cpp, Warrior.cpp, Mage.cpp, Thief.cpp
        Files with functions to control the movement of the objects, check tiles on board and check perform special actions.

        io.cpp
        Functions that control the cursor and positions of printing on the console.

        Board.cpp
        Functions that control the board itself, print it and destroy special tiles.

        GameController.cpp
        Functions that control the process of the game. call print functions of the other classes, checks for winning condition,
            print msgs and so on.

        main.cpp
        The main file, creates 3 GameController objects for each level and prints final msg.

    Include:
        Board.h, GameController.h, io.h, King.h, Location.h, Mage.h, Thief.h, Warrior.h
        KeyValues.h - structs with const values for arrow keys and ESC.

    Resources:
        Board_1.txt, Board_2.txt, Board_3.txt - text files for the 3 levels.


Data Structures:

    The Board class uses a 2D int array to link all pairs of teleports.

    The GameController class uses char array to organize and store letters of all pc's.


Exceptional Algorithms:

    

Known bugs:
        Not that we know of 🙂


Other comments:
    If you want to create your own levels, make sure to specify and size of board, in new line
        draw the board in prepared format.