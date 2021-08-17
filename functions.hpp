#include <iostream>
#include "classes.cpp"

void validatePosition(int row, int column, char sign);
Board game;

void PlayGame()
{

   /* Testing Values
	validatePosition(1,1,'x');
	validatePosition(2,2,'x');
	validatePosition(3,3,'x');
	validatePosition(0,1,'x');

	game.printBoard();
	std::cout<<game.determineWinner();
*/
   int row, column;
   char sign;
   while (game.determineWinner() == 'z')
   {
      game.printBoard();
      std::cout << "X: ";
      std::cin >> row >> column;
      validatePosition(row, column, 'x');

      game.printBoard();
      std::cout << "O: ";
      std::cin >> row >> column;
      validatePosition(row, column, 'o');
   }
   game.printBoard();
   std::cout << "\n"
             << "Winner: " << game.determineWinner() << "\n";
}

void validatePosition(int row, int column, char sign)
{
   int valid = game.setPosition(row, column, sign);

   if (valid == -1)
   {
      std::cout << "Position already taken."
                << "\n";
   }
}
