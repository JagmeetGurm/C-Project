﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicTacToe
{
   
/*
    public class node{
        public string turn;
public char[,] state=new char[3,3];
public char type;
        public int level;
        public int score;
     public   bool visited;
    public List<node>adjList=new List<node>();  
        
  

    }
    public class game
    {public string status=" ";
        public string winner = " ";
        public game(string start, char t)
        {
            //create a new node
            node n = new node();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    n.state[i, j] = ' ';
                }
            }
            n.turn = start;
            n.level = 0;
            n.type = t;
            dfs(ref n);

        }

        public int minimax(ref node t)
        {
            if (Terminal(t))
            {
                Console.WriteLine(winner);
                status = "done";

                return t.score;
            }
            else if (t.type == 'X')
            {
                int max = -5;
                for (int i = 0; i < t.adjList.Count; i++)
                {
                    if (max < t.adjList[i].score)
                    {
                        max = t.adjList[i].score;
                    }
                }
                return max;
            }
            else
            {
                int min = 5;
                for (int i = 0; i < t.adjList.Count; i++)
                {
                    if (min > t.adjList[i].score)
                    {
                        min = t.adjList[i].score;
                    }
                }
                return min;
            }
        }
        public int checkScore(node n)
        {
            if ((n.state[0, 0] == n.state[0, 1] && n.state[0, 0] == n.state[0, 2] && n.state[0, 0] == 'X') ||
                (n.state[1, 0] == n.state[1, 1] && n.state[1, 0] == n.state[1, 2] && n.state[1, 0] == 'X') ||
             (n.state[2, 0] == n.state[2, 1] && n.state[2, 0] == n.state[2, 2] && n.state[2, 0] == 'X') ||
             (n.state[0, 0] == n.state[1, 0] && n.state[0, 0] == n.state[2, 0] && n.state[0, 0] == 'X') ||
              (n.state[0, 1] == n.state[1, 1] && n.state[0, 0] == n.state[2, 1] && n.state[0, 1] == 'X') ||
               (n.state[0, 2] == n.state[1, 2] && n.state[0, 2] == n.state[2, 2] && n.state[0, 2] == 'X') ||

                (n.state[0, 0] == n.state[1, 1] && n.state[0, 0] == n.state[2, 2] && n.state[0, 0] == 'X') ||
                 (n.state[0, 2] == n.state[1, 1] && n.state[0, 2] == n.state[2, 0] && n.state[0, 2] == 'X'))
                return 1;
            else if ((n.state[0, 0] == n.state[0, 1] && n.state[0, 0] == n.state[0, 2] && n.state[0, 0] == 'O') ||
                (n.state[1, 0] == n.state[1, 1] && n.state[1, 0] == n.state[1, 2] && n.state[1, 0] == 'O') ||
             (n.state[2, 0] == n.state[2, 1] && n.state[2, 0] == n.state[2, 2] && n.state[2, 0] == 'O') ||
             (n.state[0, 0] == n.state[1, 0] && n.state[0, 0] == n.state[2, 0] && n.state[0, 0] == 'O') ||
              (n.state[0, 1] == n.state[1, 1] && n.state[0, 0] == n.state[2, 1] && n.state[0, 1] == 'O') ||
               (n.state[0, 2] == n.state[1, 2] && n.state[0, 2] == n.state[2, 2] && n.state[0, 2] == 'O') ||

                (n.state[0, 0] == n.state[1, 1] && n.state[0, 0] == n.state[2, 2] && n.state[0, 0] == 'O') ||
                 (n.state[0, 2] == n.state[1, 1] && n.state[0, 2] == n.state[2, 0] && n.state[0, 2] == 'O'))
                return -1;
            else return 0;

        }
        public void dfs(ref node n){
            n.visited = true;
            Action(ref n);
            n.score = checkScore(n);
            for (int i = 0; i < n.adjList.Count; i++)
            {
                if (n.adjList[i].visited == false)
                {
                    node temp = new node();
                    temp = n.adjList[i];
                    
                 n.score=   minimax(ref temp);
                 if (status == "done")
                 {
                     goto Done;
                 }
                    dfs(ref temp);
                }
            }
        Done:
            Console.WriteLine("done");       //here;
        }

        public void Action(ref node n)
        {


            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    node nn = new node();

                    if (n.type == 'X')
                    {
                        if (n.state[i, j] != 'X' && n.state[i, j] != 'O')
                        {
                            for (int k = 0; k < 3; k++)
                            {
                                for (int l = 0; l < 3; l++)
                                {
                                    nn.state[k, l] = n.state[k,l];
                                }
                            }
                                nn.state[i, j] = 'X';
                            nn.type = 'O';
                        }

                    }
                    else
                    {
                        if (n.state[i, j] != 'X' && n.state[i, j] != 'O')
                        {
                            for (int k = 0; k < 3; k++)
                            {
                                for (int l = 0; l < 3; l++)
                                {
                                    nn.state[k, l] = n.state[k,l];
                                }
                            }
                            nn.state[i, j] = 'O';
                            nn.type = 'X';
                        }

                    }

                    n.adjList.Add(nn);
                }

            }
       //     return n.adjList;
        }
        public bool Terminal(node n)
        {
            if ((n.state[0, 0] == n.state[0, 1] && n.state[0, 0] == n.state[0, 2]) ||
                (n.state[1, 0] == n.state[1, 1] && n.state[1, 0] == n.state[1, 2]) ||
             (n.state[2, 0] == n.state[2, 1] && n.state[2, 0] == n.state[2, 2]) ||
             (n.state[0, 0] == n.state[1, 0] && n.state[0, 0] == n.state[2, 0]) ||
              (n.state[0, 1] == n.state[1, 1] && n.state[0, 0] == n.state[2, 1]) ||
               (n.state[0, 2] == n.state[1, 2] && n.state[0, 2] == n.state[2, 2]) ||

                (n.state[0, 0] == n.state[1, 1] && n.state[0, 0] == n.state[2, 2]) ||
                 (n.state[0, 2] == n.state[1, 1] && n.state[0, 2] == n.state[2, 0]) ||
                  (n.state[0, 0] != ' ' && n.state[0, 1] != ' ' && n.state[0, 2] != ' ' &&
                  n.state[1, 0] != ' ' && n.state[1, 1] != ' ' && n.state[1, 2] != ' '
                  && n.state[2, 0] != ' ' && n.state[2, 1] != ' ' && n.state[2, 2] != ' ')
                  )
            {

                return true;
            }

              //return true;
            else return false;


        }

        public string Player(string start, int currentLevel)
        {

            //reurn the player who has return;
            if (start == "PC" && currentLevel % 2 == 0)
            {
                return "PC";

            }
            else return "player";
            //      }

            //func action/dfs{
            //}
            //func terminalTest{
            //}
            //func utility{
            //}
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string initialState = "";
            string start="player";
            char type = 'O';
            int player = 1;
            int opponent = 2;
            game g=new game(start, type);
            Console.ReadLine();
        }
    }
 *///the return values are wrapped around this result class
    class result
    {
     public   int val, x, y;
    }
    class game
    {
        public char[,] board = new char[3, 3];
   
        public void Action(ref List<char[,]>adj, char player){
            if (player == 'X')
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i, j] == ' ')
                        {
                            board[i, j] = 'X';
                        }
                    }
                }
            }
            if (player == 'O')
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i, j] == ' ')
                        {
                            board[i, j] = 'O';
                        }

                    }
                }
            }
        }

        // Algorithm Referenced from: 
        //Java Graphic Tutorial, http://www3.ntu.edu.sg/home/ehchua/programming/java/javagame_tictactoe_ai.html
        //PLAYING WITH GAME THEORY, https://gangsterveggies.wordpress.com/tag/alpha-beta-pruning/

        public result minimax(int a, int b, char player)
        {result r2=new result();
        int x1 = -1, y1 = -1;
            int bestValue=(player=='X') ? -10: 10;
            if(checkResult()!=0)
            {
                r2.x = a;
               r2.y = b;
              r2.  val = checkResult();
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
                        if (board[i,j] == ' ')
                    {//If legal,
                          board[i, j] = 'X';
                       
                       
                            int score= minimax(i, j, 'O').val;
                            if (score > bestValue)
                            {
                                bestValue = score;
                                r2.val = score;
                               r2. x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                        board[i,j] = ' ';//
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

                            int score= minimax(i, j, 'X').val;
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
public void computerMove()
        {
            result r1=new result();
         //   r1 = minimax(0, 0, 'X');
            r1 = prunning(0, 0, 'X', -10, 10);
            if (r1.val == 1 || r1.val == 0)
                board[r1.x, r1.y] = 'X';
            else board[r1.x, r1.y] = 'O';
            //board[r1.x, r1.y] = r1.val;
        }
public void playerMove()
        {
           // char move = ' ';
            Console.WriteLine("enter your move: ");
            string t = Console.ReadLine();
            string[] move= t.Split(',');
            int x = int.Parse(move[0]);
            int y = int.Parse(move[1]);
            board[x, y] = 'O';

        }
public void currentBoard()
        {
            
                    Console.WriteLine(board[0,0]+ " | "+ board[0,1]+" | "+ board[0,2]+" | ");
                    Console.WriteLine(board[1, 0] + " | " + board[1, 1] + " | " + board[1, 2] + " | ");
                    Console.WriteLine(board[2, 0] + " | " + board[2, 1] + " | " + board[2, 2] + " | ");

            
        }



    class Program
    {
        static void Main(string[] args)
        {
            string initialState = "";
            string start = "player";
            char type = 'O';
            int player = 1;
            int opponent = 2;
            //computer is X, player is O
            //computer is going first
            int choice = 2;//player is 2nd
            //computer is 1, player is -1
            game g = new game();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    g.board[i, j] = ' ';
                }
            }
            for (int i = 0; i < 9; i++)
            {
                if (g.checkResult() == 0)
                    g.move(i);
                else i = 9;
            }
            if (g.checkResult() == 1)
            {
                Console.WriteLine("Computer won. You lost.");
            }
            else if (g.checkResult() == -1)
            {

                Console.WriteLine("You won. congrats.");
            }
            else
                Console.WriteLine("Its a draw.");
            Console.ReadLine();
        }
    }
}

