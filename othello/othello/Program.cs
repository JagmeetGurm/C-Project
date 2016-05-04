using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace othello
{
    class win{
public string winner;
        public int value;
    }
    class cell
    {
        public int x, y;
    }
    //the return values are wrapped around this result class
    class result
    {
        public int val, x, y;
    }

    //game class represent the one tictac toe game
    class game
    {
        public win winnerOfGame(){
            win w=new win();
            int userCount=0, compCount=0;
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(board[i,j]=='O')
                        userCount++;
                    if(board[i,j]=='X')
                        compCount++;
                }
            }
            if(compCount==userCount){
                w.value=userCount;
                w.winner="draw";
            }
            else{
            w.value=userCount>compCount? userCount:compCount;
            w.winner=userCount>compCount? "user":"computer";
            }
            return w;
        }
        //board represents the board of the game
        public char[,] board = new char[8, 8];

        char turn;
        public void setTurn(char t)
        {
            turn = t;
        }

        // Algorithm Referenced from: 
        //Java Graphic Tutorial, http://www3.ntu.edu.sg/home/ehchua/programming/java/javagame_tictactoe_ai.html
        //PLAYING WITH GAME THEORY, https://gangsterveggies.wordpress.com/tag/alpha-beta-pruning/
        //algorithm helps the computer to pick best next move possible
        public result minimax(int a, int b, char player)
        {
            result r2 = new result();
            int x1 = -1, y1 = -1;
            int bestValue = (player == 'X') ? -10 : 10;
            if (checkResult() != 0)
            {
                r2.x = a;
                r2.y = b;
                r2.val = checkResult();
                return r2;
            }
            if (player == 'X')
            {
                bestValue = -10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i, j] == ' ')
                        {//If legal,
                            board[i, j] = 'X';


                            int score = minimax(i, j, 'O').val;
                            if (score > bestValue)
                            {
                                bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            board[i, j] = ' ';//
                        }

                    }
                }
                return r2;
            }


            if (player == 'O')
            {
                bestValue = 10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i, j] == ' ')
                        {//If legal,
                            board[i, j] = 'O';

                            int score = minimax(i, j, 'X').val;
                            if (score < bestValue)
                            {
                                bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            board[i, j] = ' ';//
                        }

                    }
                }
                //    return r2;
            }
            //    r2.x = x1;
            //   r2.y = y1;
            // r2.val = bestValue;
            return r2;
        }
        // Algorithm Referenced from: 
        //Java Graphic Tutorial, http://www3.ntu.edu.sg/home/ehchua/programming/java/javagame_tictactoe_ai.html
        //PLAYING WITH GAME THEORY, https://gangsterveggies.wordpress.com/tag/alpha-beta-pruning/

        //improving the prunning algorithm
        public result prunning(int a, int b, char player, int alpha, int beta)
        {
            result r2 = new result();
            int x1 = -1, y1 = -1;
            int bestValue = (player == 'X') ? -10 : 10;
            if (checkResult() != 0)
            {
                r2.x = a;
                r2.y = b;
                r2.val = checkResult();
                return r2;
            }
            if (player == 'X')
            {
                bestValue = -10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i, j] == ' ')
                        {//If legal,
                            board[i, j] = 'X';


                            int score = prunning(i, j, 'O', alpha, beta).val;
                            if (score > alpha)
                            {
                                alpha = score;
                                //      bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            board[i, j] = ' ';//
                            if (alpha >= beta) break;
                        }

                    }
                }
                return r2;
            }


            if (player == 'O')
            {
                bestValue = 10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i, j] == ' ')
                        {//If legal,
                            board[i, j] = 'O';

                            int score = prunning(i, j, 'X', alpha, beta).val;
                            if (score < beta)
                            {
                                beta = score;
                                //  bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;

                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            board[i, j] = ' ';//
                            if (alpha >= beta) break;
                        }

                    }
                }
                //    return r2;
            }
            //    r2.x = x1;
            //   r2.y = y1;
            // r2.val = bestValue;
            return r2;
        }

        //the computer makes the move through this function by calling minimax
        //does accept any parameter, nor gives an output
        public cell computerMove()
        {
            cell c = new cell();
            result r1 = new result();
            //   r1 = minimax(0, 0, 'X');
            r1 = prunning(0, 0, 'X', -10, 10);
            if (r1.val == 1 || r1.val == 0)
                board[r1.x, r1.y] = 'X';
            else board[r1.x, r1.y] = 'O';
            //board[r1.x, r1.y] = r1.val;
            return c;
        }

        //the player makes the move followed by printing the board
        public cell playerMove()
        {
            cell c = new cell();
            // Trace.Assert(turn == 'O');
            // char move = ' ';
            Console.WriteLine("enter your move: ");
            string t = Console.ReadLine();
            string[] move = t.Split(',');
            int x = int.Parse(move[0]);
            int y = int.Parse(move[1]);
            c.x = x;
            c.y = y;
            board[x, y] = 'O';
            Trace.Assert(board[x, y] == 'O');
            return c;
        }

        //prints the current state fo the board
        public void currentBoard()
        {
            string temp = "";
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    temp = temp + board[i, j] + "  |  ";
                    
                }
                temp = temp + "\n \n";
            }
            Console.WriteLine(temp); 
        }
        public char turnOpp()
        {
            if (turn == 'O')
                return 'X';
            else return 'O';
        }
        public void action(cell c, char turn)
        { 
            int a = c.x + 1; //c.x is x coordinate
            int b = c.y;
            int x=a+1;
            //horizontal right side(+ve)
            while (board[x, b] != turn)
            {
                board[x, b] = turnOpp();
                x++;
            }
            //horizontal left side(-ve)
            x = a - 1;
            while (board[x, b] != turn)
            {
                board[x, b] = turnOpp();
                x--;
            }
            //vertical up(+ve)
            int y = b + 1;
            while (board[a, y] != turn)
            {
                board[a, y] = turnOpp();
                y++;

            }
            //verticl down(-ve)
            y = b + 1;
            while (board[a, y] != turn)
            {
                board[a, y] = turnOpp();
                y--;
            }

        }
        //decides whose move is it going to be-computer's or user's 
        public void move(int i)
        {
            if (i % 2 == 1)
            {

                turn = 'O';
             cell c=   playerMove();
                action(c, turn);
                currentBoard();

            }
            else
            {
                turn = 'X';
                cell c= computerMove();
                action(c, turn);
                Console.WriteLine("computer move: ");
                currentBoard();
            }
        }



        //checks if we have reached the final state or some body wins
        public int checkResult()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (board[i, j] == ' ')
                       return 0;

                }
            }
          return -1;  
        }

    }






    class Program
    {
        static void Main(string[] args)
        {
            
            //computer is X, player is O
            //computer is going first
            int choice = 2;//player is 2nd
            //computer is 1, player is -1
            game g = new game();
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    g.board[i, j] = 'i';
                }
            }
        //    g.currentBoard();

            for (int i = 0; i < 60; i++)
            {
                if (g.checkResult() == 0)
                {
                    g.move(i);

                }
                else i = 60;
            }
         win w=   g.winnerOfGame();

            
                Console.WriteLine("The winner is:"+ w.winner+" and the value is: "+ w.value);
            
            Console.ReadLine();
       
            Console.ReadLine();
        }
    }
}

