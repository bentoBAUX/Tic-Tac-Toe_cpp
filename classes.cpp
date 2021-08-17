#include <iostream>
#include <string>

class Board
{

   char gameBoard[4][4];
   char winner;

public:
   Board()
   {

      winner = 'z';

      for (int i = 0; i < 4; i++)
      {
         std::cout << "\n";
         for (int j = 0; j < 4; j++)
         {
            gameBoard[i][j] = '-';
         }
      }
   }

   int setPosition(int row, int column, char sign)
   {
      if (gameBoard[row][column] == '-')
      {
         gameBoard[row][column] = sign;
         return 0;
      }
      else
      {

         return -1;
      }
   }

   char checkRows()
   {
      int countX = 0;
      int countO = 0;

      for (int i = 0; i < 4; i++)
      {

         for (int j = 0; j < 4; j++)
         {
            if (gameBoard[i][j] == 'x')
            {
               countX++;
            }
            else if (gameBoard[i][j] == 'o')
            {
               countO++;
            }
            if (countX == 4)
            {
               return 'x';
            }
            else if (countO == 4)
            {
               return 'o';
            }
         }
         countX = 0;
         countO = 0;
      }

      return 'z';
   }

   char checkColumns()
   {
      int countX = 0;
      int countO = 0;

      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            if (gameBoard[j][i] == 'x')
            {
               countX++;
            }
            else if (gameBoard[j][i] == 'o')
            {
               countO++;
            }
            if (countX == 4)
            {
               return 'x';
            }
            else if (countO == 4)
            {
               return 'o';
            }
         }
         countX = 0;
         countO = 0;
      }

      return 'z';
   }

   char checkDiagonals()
   {
      int countX = 0;
      int countO = 0;

      //left to right
      for (int i = 0; i < 4; i++)
      {
         if (gameBoard[i][i] == 'x')
         {
            countX++;
         }
         else if (gameBoard[i][i] == 'o')
         {
            countO++;
         }
         if (countX == 4)
         {
            return 'x';
         }
         else if (countO == 4)
         {
            return 'o';
         }
      }

      countX = 0;
      countO = 0;

      //right to left
      for (int i = 0; i < 4; i++)
      {

         for (int j = 3; j >= 0; j--)
         {
            if (gameBoard[i][j] == 'x' && (i + j) == 3)
            {
               countX++;
            }
            else if (gameBoard[i][j] == 'o' && (i + j) == 3)
            {
               countO++;
            }
            if (countX == 4)
            {
               return 'x';
            }
            else if (countO == 4)
            {
               return 'o';
            }
         }
      }

      return 'z';
   }

   void printBoard()
   {
      for (int i = 0; i < 4; i++)
      {
         std::cout << "\n";
         for (int j = 0; j < 4; j++)
         {
            std::cout << gameBoard[i][j] << "\t";
         }
      }
      std::cout << "\n\n";
   }

   char determineWinner()
   {
      winner = checkRows();
      if (winner == 'z')
         winner = checkColumns();
      if (winner == 'z')
         winner = checkDiagonals();
      return winner;
   }
};
