using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TictactoeGraphical
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonClick(object sender, EventArgs e)
        {

        }
    }
    class result
    {
        public int val, x, y;
    }


    class game
    {
        //board represents the board of the game
        public char[,] board = new char[3, 3];

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
        public void computerMove()
        {
            result r1 = new result();
            //   r1 = minimax(0, 0, 'X');
            r1 = prunning(0, 0, 'X', -10, 10);
            if (r1.val == 1 || r1.val == 0)
                board[r1.x, r1.y] = 'X';
            else board[r1.x, r1.y] = 'O';
            //board[r1.x, r1.y] = r1.val;
        }

        //the player makes the move followed by printing the board
        public void playerMove()
        {
            // Trace.Assert(turn == 'O');
            // char move = ' ';
            Console.WriteLine("enter your move: ");
            string t = Console.ReadLine();
            string[] move = t.Split(',');
            int x = int.Parse(move[0]);
            int y = int.Parse(move[1]);
            board[x, y] = 'O';
       //     Trace.Assert(board[x, y] == 'O');
        }

        //prints the current state fo the board
        public void currentBoard()
        {

            Console.WriteLine(board[0, 0] + " | " + board[0, 1] + " | " + board[0, 2] + " | ");
            Console.WriteLine(board[1, 0] + " | " + board[1, 1] + " | " + board[1, 2] + " | ");
            Console.WriteLine(board[2, 0] + " | " + board[2, 1] + " | " + board[2, 2] + " | ");


        }

        //decides whose move is it going to be-computer's or user's 
        public void move(int i)
        {
            if (i % 2 == 1)
            {


                playerMove();
                currentBoard();

            }
            else
            {
                computerMove();
                Console.WriteLine("computer move: ");
                currentBoard();
            }
        }


        //checks if we have reached the final state or some body wins
        public int checkResult()
        {
            if ((board[0, 0] == board[0, 1] && board[0, 0] == board[0, 2] && board[0, 0] == 'X') ||
                           (board[1, 0] == board[1, 1] && board[1, 0] == board[1, 2] && board[1, 0] == 'X') ||
                        (board[2, 0] == board[2, 1] && board[2, 0] == board[2, 2] && board[2, 0] == 'X') ||
                        (board[0, 0] == board[1, 0] && board[0, 0] == board[2, 0] && board[0, 0] == 'X') ||
                         (board[0, 1] == board[1, 1] && board[0, 0] == board[2, 1] && board[0, 1] == 'X') ||
                          (board[0, 2] == board[1, 2] && board[0, 2] == board[2, 2] && board[0, 2] == 'X') ||

                           (board[0, 0] == board[1, 1] && board[0, 0] == board[2, 2] && board[0, 0] == 'X') ||
                            (board[0, 2] == board[1, 1] && board[0, 2] == board[2, 0] && board[0, 2] == 'X'))
                return 1;
            else if ((board[0, 0] == board[0, 1] && board[0, 0] == board[0, 2] && board[0, 0] == 'O') ||
                (board[1, 0] == board[1, 1] && board[1, 0] == board[1, 2] && board[1, 0] == 'O') ||
             (board[2, 0] == board[2, 1] && board[2, 0] == board[2, 2] && board[2, 0] == 'O') ||
             (board[0, 0] == board[1, 0] && board[0, 0] == board[2, 0] && board[0, 0] == 'O') ||
              (board[0, 1] == board[1, 1] && board[0, 0] == board[2, 1] && board[0, 1] == 'O') ||
               (board[0, 2] == board[1, 2] && board[0, 2] == board[2, 2] && board[0, 2] == 'O') ||

                (board[0, 0] == board[1, 1] && board[0, 0] == board[2, 2] && board[0, 0] == 'O') ||
                 (board[0, 2] == board[1, 1] && board[0, 2] == board[2, 0] && board[0, 2] == 'O'))
                return -1;
            else return 0;
        }

    }



    
}
