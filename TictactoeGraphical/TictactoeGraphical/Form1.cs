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

    public partial  class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
           // justtry();
        }
        public void justtry() { 
            string initialState = "";
            string start = "player";
            char type = 'O';
            int player = 1;
            int opponent = 2;
            //computer is X, player is O
            //computer is going first
            int choice = 2;//player is 2nd
            //computer is 1, player is -1
          //  game g = new game();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    game.boardJim[i, j] = ' ';
                }
            }
            for (int i = 0; i < 9; i++)
            {
                if (game.checkResult() == 0)
                {
                    // g.move(i);
                    if (i % 2 == 0)
                    {


                       game. playerMove();
                       game. currentBoard();

                    }
                    else
                    {
                    result r=   game. computerMove();
                        computerClick(r.x, r.y);
                        Console.WriteLine("computer move: ");
                      game.  currentBoard();
                    }
                }
                else i = 9;
            }
            if (game.checkResult() == 1)
            {
                Console.WriteLine("Computer won. You lost.");
            }
            else if (game.checkResult() == -1)
            {

                Console.WriteLine("You won. congrats.");
            }
            else
                Console.WriteLine("Its a draw.");
            Console.ReadLine();
        
    }

        private void buttonClick(object sender, EventArgs e)
        {
            Button myButton = (Button)sender;
            myButton.Text = "O";
            myButton.Enabled = false;
            userTurn(myButton.Name);
        }
private void userTurn(string name)
        {
            if (name == button1.Name)
                game.boardJim[0, 0] = 'O';

            else if (name == button2.Name)
                game.boardJim[0, 1] = 'O';

            else if (name == button3.Name)
                game.boardJim[0, 2] = 'O';

            else if (name == button4.Name)
                game.boardJim[1, 0] = 'O';

            else if (name == button5.Name)
                game.boardJim[1, 1] = 'O';

            else if (name == button6.Name)
                game.boardJim[1, 2] = 'O';

            else if (name == button7.Name)
                game.boardJim[2, 0] = 'O';

            else if (name == button8.Name)
                game.boardJim[2, 1] = 'O';

            else game.boardJim[2, 2] = 'O';

        }
        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("A TicTacToe game played between two players");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        public void computerClick(int x, int y)
        {
            if (x == 0 && y == 0)
            {
                    button1.Text = "X";
            }
            else if(x==0 && y==1)
                button2.Text = "X";

            else if (x == 0 && y == 2)
                button3.Text = "X";

            else if (x == 1 && y == 0)
                button4.Text = "X";

            else if (x == 1 && y == 1)
                button5.Text = "X";

            else if (x == 1 && y == 2)
                button6.Text = "X";

            else if (x == 2 && y == 0)
                button7.Text = "X";

            else if (x == 2 && y == 1)
                button8.Text = "X";

            else 
                button9.Text = "X";

        }
    }
    class result
    {
        public int val, x, y;
    }


  static  class game
    {
       
        //board represents the board of the game
        public  static char[,] boardJim = new char[3, 3];

     static   char turn;
        public static void  setTurn(char t)
        {
            turn = t;
        }

        // Algorithm Referenced from: 
        //Java Graphic Tutorial, http://www3.ntu.edu.sg/home/ehchua/programming/java/javagame_tictactoe_ai.html
        //PLAYING WITH GAME THEORY, https://gangsterveggies.wordpress.com/tag/alpha-beta-pruning/
        //algorithm helps the computer to pick best next move possible
        public static result minimax(int a, int b, char player)
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
                        if (boardJim[i, j] == ' ')
                        {//If legal,
                            boardJim[i, j] = 'X';


                            int score = minimax(i, j, 'O').val;
                            if (score > bestValue)
                            {
                                bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            boardJim[i, j] = ' ';//
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
                        if (boardJim[i, j] == ' ')
                        {//If legal,
                            boardJim[i, j] = 'O';

                            int score = minimax(i, j, 'X').val;
                            if (score < bestValue)
                            {
                                bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            boardJim[i, j] = ' ';//
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
        public static result prunning(int a, int b, char player, int alpha, int beta)
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
                        if (boardJim[i, j] == ' ')
                        {//If legal,
                            boardJim[i, j] = 'X';


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
                            boardJim[i, j] = ' ';//
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
                        if (boardJim[i, j] == ' ')
                        {//If legal,
                            boardJim[i, j] = 'O';

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
                            boardJim[i, j] = ' ';//
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
        public static result computerMove()
        {
            result r1 = new result();
            //   r1 = minimax(0, 0, 'X');
            r1 = prunning(0, 0, 'X', -10, 10);
            if (r1.val == 1 || r1.val == 0)
                boardJim[r1.x, r1.y] = 'X';
            else boardJim[r1.x, r1.y] = 'O';
            //board[r1.x, r1.y] = r1.val;
            //  Form1 f = new Form1();
            //f.computerClick(r1.x, r1.y);
            return r1;
        }

        //the player makes the move followed by printing the board
        public static void playerMove()
        {
            // Trace.Assert(turn == 'O');
            // char move = ' ';
            Console.WriteLine("enter your move: ");
     //       string t = Console.ReadLine();
    //        string[] move = t?.Split(',');
     //       int x = int.Parse(move[0]);
      //      int y = int.Parse(move?[1]);
       //     board[x, y] = 'O';
       //     Trace.Assert(board[x, y] == 'O');
        }

        //prints the current state fo the board
        public static void currentBoard()
        {

            Console.WriteLine(boardJim[0, 0] + " | " + boardJim[0, 1] + " | " + boardJim[0, 2] + " | ");
            Console.WriteLine(boardJim[1, 0] + " | " + boardJim[1, 1] + " | " + boardJim[1, 2] + " | ");
            Console.WriteLine(boardJim[2, 0] + " | " + boardJim[2, 1] + " | " + boardJim[2, 2] + " | ");


        }

        //decides whose move is it going to be-computer's or user's 
        public static void move(int i)
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
        public static int checkResult()
        {
            if ((boardJim[0, 0] == boardJim[0, 1] && boardJim[0, 0] == boardJim[0, 2] && boardJim[0, 0] == 'X') ||
                           (boardJim[1, 0] == boardJim[1, 1] && boardJim[1, 0] == boardJim[1, 2] && boardJim[1, 0] == 'X') ||
                        (boardJim[2, 0] == boardJim[2, 1] && boardJim[2, 0] == boardJim[2, 2] && boardJim[2, 0] == 'X') ||
                        (boardJim[0, 0] == boardJim[1, 0] && boardJim[0, 0] == boardJim[2, 0] && boardJim[0, 0] == 'X') ||
                         (boardJim[0, 1] == boardJim[1, 1] && boardJim[0, 0] == boardJim[2, 1] && boardJim[0, 1] == 'X') ||
                          (boardJim[0, 2] == boardJim[1, 2] && boardJim[0, 2] == boardJim[2, 2] && boardJim[0, 2] == 'X') ||

                           (boardJim[0, 0] == boardJim[1, 1] && boardJim[0, 0] == boardJim[2, 2] && boardJim[0, 0] == 'X') ||
                            (boardJim[0, 2] == boardJim[1, 1] && boardJim[0, 2] == boardJim[2, 0] && boardJim[0, 2] == 'X'))
                return 1;
            else if ((boardJim[0, 0] == boardJim[0, 1] && boardJim[0, 0] == boardJim[0, 2] && boardJim[0, 0] == 'O') ||
                (boardJim[1, 0] == boardJim[1, 1] && boardJim[1, 0] == boardJim[1, 2] && boardJim[1, 0] == 'O') ||
             (boardJim[2, 0] == boardJim[2, 1] && boardJim[2, 0] == boardJim[2, 2] && boardJim[2, 0] == 'O') ||
             (boardJim[0, 0] == boardJim[1, 0] && boardJim[0, 0] == boardJim[2, 0] && boardJim[0, 0] == 'O') ||
              (boardJim[0, 1] == boardJim[1, 1] && boardJim[0, 0] == boardJim[2, 1] && boardJim[0, 1] == 'O') ||
               (boardJim[0, 2] == boardJim[1, 2] && boardJim[0, 2] == boardJim[2, 2] && boardJim[0, 2] == 'O') ||

                (boardJim[0, 0] == boardJim[1, 1] && boardJim[0, 0] == boardJim[2, 2] && boardJim[0, 0] == 'O') ||
                 (boardJim[0, 2] == boardJim[1, 1] && boardJim[0, 2] == boardJim[2, 0] && boardJim[0, 2] == 'O'))
                return -1;
            else return 0;
        }

    }



    
}
