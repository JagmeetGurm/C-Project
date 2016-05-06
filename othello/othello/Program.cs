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
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
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
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
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
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (board[i, j] == ' ')
                        {//If legal,
                            cell c = new cell();
                            c.x = i; c.y = j;
                            if (validMove(c))
                                board[i, j] = 'X';
                            else goto done;

                            turn = 'O';
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
                    done:
                        ;//;

                    }
                }
                return r2;
            }


            if (player == 'O')
            {
                bestValue = 10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (board[i, j] == ' ')
                        {//If legal,
                            cell c = new cell();
                            c.x = i; c.y = j;
                            if (validMove(c))
                                board[i, j] = 'O';
                            else goto done2;
                            turn = 'X';
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
                    done2: ;
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
          //    r1 = minimax(0, 0, 'X');
              
            r1 = prunning(0, 0, 'X', -10, 10);
            c.x = r1.x;
            c.y = r1.y;
             // if (validMove(c))
             // {
                  if (r1.val == 1 || r1.val == 0)
                      board[r1.x, r1.y] = 'X';
                  else board[r1.x, r1.y] = 'O';
             // }
           //   else move(1);
            //board[r1.x, r1.y] = r1.val;
            return c;
        }
        public bool validMove(cell c)
        {int a=c.x;
        bool decision = false;
            int b=c.y;
            if (board[a, b] != ' ')
                decision = false; ;
            int y = b + 1;
            //horizontal right side(+ve)
            if (y>=0 && y <= 7 && board[a, y] == turnOpp())
            {
              //  board[a, y] = turn;
               // y++;
                for (int e = y ; e <= 7; e++)
                {
                    if (board[a, e] == turn)
                    {
                        int temp = e-1;
                        while (temp != y-1)
                        {
                            if (board[a, temp] == turnOpp())
                            {
                                decision = true;
                            }
                            else decision = false;
                            temp--;
                        }
                    }
                }
            }
            //  board[x, b] = turn;
            //horizontal left side(-ve)
            y = b - 1;
            if ( y>=0 && y<=7 && board[a, y] == turnOpp())
            {
         //       board[a, y] = turn;
           //     y--;
                for (int e = y ; e <= 7; e++)
                {
                    if (board[a, e] == turn)
                    {
                        int temp = e+1;
                        while (temp<8 && temp != y+1)
                        {
                            if (board[a, temp] == turnOpp())
                            {
                                decision = true;
                            }
                            else decision = false;
                            temp++;
                        }
                    }
                }
            }
            //    board[x, b] = turn;
            //vertical down(+ve)
            int x = a + 1;
            if ( x >= 0 && x <= 7 && board[x, b] == turnOpp())
            {
                for (int e = x ; e <= 7; e++)
                {
                    if (board[e, b] == turn)
                    {
                        int temp = e-1;
                        while (temp != x-1)
                        {
                            if (board[temp, b] == turnOpp())
                            {
                                decision = true;
                            }
                            else decision = false;
                            temp--;
                        }
                    }
                }
                    //  board[x, b] = turn;
                    //x++;
                    
            }
            //diagonal left up
            x = a - 1; y = b - 1;
            if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                for (int e = x; e >=0; e--)
                {
                  //  for (int f = y; f >=0; e--)
                    //{


                        if (board[e, e] == turn)
                        {
                            int temp = e + 1;//, temp2 = f + 1;

                            while (temp != x +1 )
                            {
                                if (board[temp, temp] == turnOpp())
                                {
                                    decision = true;
                                }
                                else decision = false;
                                temp++;// temp2++;
                            }
                        }
                    }
              //  }
                //  board[x, b] = turn;
                //x++;

            }
            //diagonal down right
            x = a + 1; y = b + 1;
            if (x >= 0 && x <= 7 &&  y>=0 && y<=7 && board[x, y] == turnOpp())
            {
                for (int e = x; e <= 7; e++)
                {
                  //  for (int f = y; f <= 7; f++)
                    //{


                        if (board[e, e] == turn)
                        {
                            int temp = e - 1;

                            while (temp != x - 1 )
                            {
                                if (board[temp, temp] == turnOpp())
                                {
                                    decision = true;
                                }
                                else decision = false;
                                temp--; 
                            }
                        }
                    }
                }
                //  board[x, b] = turn;
                //x++;

           // }
            //diagonal left down
            x = a - 1; y = b + 1;
            if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                for (int e = x, f=y; e >= 0 && f<=7; e--, f++)
                {
                    //for (int f = y; f <= 7; f++)
                    //{


                        if (board[e, f] == turn)
                        {
                            int temp = e + 1, temp2 = f - 1;

                            while (temp != x + 1 && temp2 != y - 1)
                            {
                                if (board[temp, temp2] == turnOpp())
                                {
                                    decision = true;
                                }
                                else decision = false;
                                temp++; temp2--;
                            }
                        }
                    }
                
                //  board[x, b] = turn;
                //x++;

            }
//diagonal right up
            x = a + 1; y = b - 1;
            if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                for (int e = x, f=y; e <= 7 && f>=0; e++, f--)
                {
                  //  for (int f = y; f >=0; f--)
                   // {


                        if (board[e, f] == turn)
                        {
                            int temp = e - 1, temp2 = f + 1;

                            while (temp != x - 1 && temp2 != y + 1)
                            {
                                if (board[temp, temp2] == turnOpp())
                                {
                                    decision = true;
                                }
                                else decision = false;
                                temp--; temp2++;
                            }
                        }
                  //  }
                }
                //  board[x, b] = turn;
                //x++;

            }
            //  board[a, y] = turn;
            //verticl up(-ve)
            x = a -1;
            if (x >= 0 && x <= 7 && board[x, b] == turnOpp())
            {
          //      board[x, b] = turn;
            //    x--;
                for (int e = x ; e <= 7; e++)
                {
                    if (board[e, b] == turn)
                    {
                        int temp = e+1;
                        while (temp != x+1)
                        {
                            if (board[temp, b] == turnOpp())
                            {
                                decision = true;
                            }
                            else decision = false;
                            temp++;
                        }
                    }
                }
            }
           return decision;
            
        }
        //the player makes the move followed by printing the board
        public cell playerMove()
        {
            cell c = new cell();
            // Trace.Assert(turn == 'O');
            // char move = ' ';
            Console.WriteLine("enter your move: ");
            string t = Console.ReadLine();
            string[] moveMade = t.Split(',');
            int x = int.Parse(moveMade[0]);
            int y = int.Parse(moveMade[1]);
            c.x = x;
            c.y = y;
            if (validMove(c))
                board[x, y] = 'O';
            else
                move(0);
        //    Trace.Assert(board[x, y] == 'O');
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
            else
                return 'O';
        }
        public void action(cell c, char turn)
        { 
            int a = c.x ; //c.x is x coordinate
            int b = c.y;
            int y=b+1;
            //horizontal right side(+ve)
            while (y >= 0 && y <= 7 && board[a, y] == turnOpp())
            {
                board[a, y] = turn;
                y++;
            }
          //  board[x, b] = turn;
            //horizontal left side(-ve)
            y = b - 1;
            while (y >= 0 && y <= 7 && board[a, y] == turnOpp())
            {
                board[a, y] = turn;
                y--;
            }
        //    board[x, b] = turn;
            //vertical up(+ve)
            int x = a + 1;
            while (x >= 0 && x <= 7 && board[x, b] == turnOpp())
            {
                board[x, b] = turn;
                x++;

            }
          //  board[a, y] = turn;
            //verticl down(-ve)
            x = a - 1;
            while (x >= 0 && x <= 7 && board[x, b] == turnOpp())
            {
                board[x, b] = turn;
                x--;
            }
         //   board[a, y] = turn;

            //diagonal up left
            x = a + 1; y = b + 1;
            while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                board[x, y] = turn;
                x++; y++;
            }

            //diagonal down right
            x = a - 1; y = b -1;
            while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                board[x, y] = turn;
                x--; y--;
            }
            
            //diagonal down up left
            x = a + 1; y = b - 1;
            while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                board[x, y] = turn;
                x++; y--;
            }

            x = a - 1; y = b + 1;
            while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                board[x, y] = turn;
                x--; y++;
            }

        }
        //decides whose move is it going to be-computer's or user's 
        public void move(int i)
        {
            if (i % 2 == 0)
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
            string w = winnerOfGame().winner;
            if (w == "computer")
            {
                return 1;
            }
            else if (w == "user")
                return -1;
            else return 0;
          
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
                    g.board[i, j] = ' ';
                }
            }
        //    g.currentBoard();
            g.board[3, 3] = 'X';
            g.board[3, 4] = 'O';
            g.board[4, 3] = 'O';
            g.board[4, 4] = 'X';

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

