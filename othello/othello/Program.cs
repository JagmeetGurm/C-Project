﻿using System;
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
                    if(board[i,j]=='b')
                        userCount++;
                    if(board[i,j]=='w')
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
        public result minimax(int a, int b, int depth, char player)
        {
            result r2 = new result();
            int x1 = -1, y1 = -1;
            int bestValue = (player == 'w') ? -10 : 10;
            if (checkResult() != 0)
            {
                r2.x = a;
                r2.y = b;
                r2.val = checkResult();
                return r2;
            }
            if (player == 'w')
            {
                sum = sum + 1;
                bestValue = -10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (board[i, j] == '.')
                        {//If legal,
                            board[i, j] = 'w';


                            int score = minimax(i, j, depth-1,'b').val;
                            if (score > bestValue)
                            {
                                bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            board[i, j] = '.';//
                        }

                    }
                }
                return r2;
            }


            if (player == 'b')
            {
                sum = sum + 1;
                bestValue = 10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (board[i, j] == '.')
                        {//If legal,
                            board[i, j] = 'b';

                            int score = minimax(i, j, depth-1,'w').val;
                            if (score < bestValue)
                            {
                                bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;
                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            board[i, j] = '.';//
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
        public result prunning(int a, int b, char player, int depth, int alpha, int beta)
        {
            result r2 = new result();
            int x1 = -1, y1 = -1;
            int bestValue = (player == 'w') ? -10 : 10;
            if ( depth==0 ||checkResult() != 0 )
            {
                r2.x = a;
                r2.y = b;
                r2.val = checkResult();
                return r2;
            }
            if (player == 'w')
            {
               // sum = sum + 1;
                bestValue = -10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (board[i, j] == '.')
                        {//If legal,
                            cell c = new cell();
                            c.x = i; c.y = j;
                            if (validMove(c))
                            {
                                board[i, j] = 'w';
                                  r2.x = i;
                                  r2.y = j;
                                //    return r2;
                                  return r2;
                                //   goto done;
                                  }
                                    else goto done;

                                turn = 'b';
                                int score = prunning(i, j, 'b', depth - 1, alpha, beta).val;
                                if (score > alpha)
                                {
                                    alpha = score;
                                    //      bestValue = score;
                                    r2.val = score;
                                    r2.x = i;
                                    r2.y = j;
                                    //  move = i;
                                }//Pick the one that's worst for the opponent
                                turn = 'b';
                                board[i, j] = '.';//
                                if (alpha >= beta) break;
                            }
                                done:
                                    ;//;

                        }
                    
                }
                return r2;
            }


            if (player == 'b')
            {
              //  sum = sum + 1;
                bestValue = 10;
                //      List<char[,]> adjList = new List<char[,]>();
                //    Action( ref adjList, player);
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (board[i, j] == '.')
                        {//If legal,
                            cell c = new cell();
                            c.x = i; c.y = j;
                            if (validMove(c))
                                board[i, j] = 'b';
                            else goto done2;
                            
                            turn = 'w';
                            int score = prunning(i, j, 'w', depth-1,alpha, beta).val;
                            if (score < beta)
                            {
                                beta = score;
                                //  bestValue = score;
                                r2.val = score;
                                r2.x = i;
                                r2.y = j;

                                //  move = i;
                            }//Pick the one that's worst for the opponent
                            turn = 'w'; 
                            board[i, j] = '.';//
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
              
            r1 = prunning(0, 0, 'w',5, -10, 10);
            c.x = r1.x;
            c.y = r1.y;
             // if (validMove(c))
             // {
              //    if (r1.val == 1 || r1.val == 0)
                      board[r1.x, r1.y] = 'w';
               //   else board[r1.x, r1.y] = 'b';
             // }
           //   else move(1);
            //board[r1.x, r1.y] = r1.val;
            return c;
        }
        public int sum=0;
public bool horRight(cell c){
int a=c.x;
      
    bool decision = false;
       //     if(turn=='X')
          //  sum =sum +1;
            int b=c.y;
           
            int y = b + 1;
            //horizontal right side(+ve)
            while (y<=7 && board[a, y] == turnOpp())
            {
                y++;
                if (y <= 7 && board[a, y] == turn)
                    decision = true;
                else decision = false;
            }
            return decision;
}

public bool horLeft(cell c)
{
    int a = c.x;

    bool decision = false;
    //     if(turn=='X')
    //  sum =sum +1;
    int b = c.y;

    int y = b - 1;
    //horizontal right side(+ve)
    while (y >= 0 && board[a, y] == turnOpp())
    {
        y--;
        if (y >= 0 && board[a, y] == turn)
            decision = true;
        else decision = false;
    }
    return decision;
}

public bool vertUp(cell c)
{
    int a = c.x;

    bool decision = false;
    //     if(turn=='X')
    //  sum =sum +1;
    int b = c.y;

   int  x = a - 1;
    while (x >= 0 && board[x, b] == turnOpp())
    {
        x--;
        if (x >= 0 && board[x, b] == turn)
            decision = true;
        else decision = false;
    }
    return decision;
}

public bool vertDown(cell c)
{
    int a = c.x;

    bool decision = false;
    //     if(turn=='X')
    //  sum =sum +1;
    int b = c.y;

    int x = a + 1;
    while (x <= 7 && board[x, b] == turnOpp())
    {
        x++;
        if (x <= 7 && board[x, b] == turn)
            decision = true;
        else decision = false;
    }
    return decision;
}


public bool DiagLeftUp(cell c)
{
    int a = c.x;
    int b = c.y;
    bool decision = false;
    //     if(turn=='X')
    //  sum =sum +1;
  int  x = a - 1, y = b - 1;
    while (x >= 0 && y >= 0 && board[x, y] == turnOpp())
    {
        x--;
        y--;
        if (x >= 0 && y >= 0 && board[x, y] == turn)
            decision = true;
        else decision = false;
    }
            

    return decision;
}


public bool DiagRightDown(cell c)
{
    int a = c.x;
    int b = c.y;
    bool decision = false;
    //     if(turn=='X')
    //  sum =sum +1;
    int x = a + 1, y = b + 1;
    while (x <= 7 && y <= 7 && board[x, y] == turnOpp())
    {
        x++;
        y++;
        if (x <= 7 && y <= 7 && board[x, y] == turn)
            decision = true;
        else decision = false;
    }


    return decision;
}

public bool DiagRightUp(cell c)
{
    int a = c.x;
    int b = c.y;
    bool decision = false;
    //     if(turn=='X')
    //  sum =sum +1;
  int  x = a - 1, y = b + 1;
  while (x >= 0 && y <= 7 && board[x, y] == turnOpp())
  {
      x--;
      y++;
      if (x >= 0 && y <= 7 && board[x, y] == turn)
          decision = true;
      else decision = false;
  }

    return decision;
}

public bool DiagDownLeft(cell c)
{
    int a = c.x;
    int b = c.y;
    bool decision = false;
    //     if(turn=='X')
    //  sum =sum +1;
 //   int x = a - 1, y = b + 1;
   int x = a + 1, y = b - 1;
    while (x <= 7 && y >= 0 && board[x, y] == turnOpp())
    {
        x++;
        y--;
        if (x <= 7 && y >= 0 && board[x, y] == turn)
            decision = true;
        else decision = false;
    }
    return decision;
}


        public bool validMove(cell c)
        {int a=c.x;
        bool decision = false;
       //     if(turn=='X')
          //  sum =sum +1;
            int b=c.y;
            if (board[a, b] != '.')
                return false;
              //  decision = false; ;
            int y = b + 1;
            //horizontal right side(+ve)
            while (y<=7 && board[a, y] == turnOpp())
            {
                y++;
                if (y <= 7 && board[a, y] == turn)
                    return true;
                else decision = false;
            }
           
            
            //  board[x, b] = turn;
            //horizontal left side(-ve)
            y = b - 1;
            while (y >= 0 && board[a, y] == turnOpp())
            {
                y--;
                if (y >= 0 && board[a, y] == turn)
                    return true;
                else decision = false;
            }
           

            //    board[x, b] = turn;
            //vertical down(+ve)
            int x = a + 1;
            while (x <= 7 && board[x, b] == turnOpp())
            {
                x++;
                if (x <= 7 && board[x, b] == turn)
                    return true;
                else decision = false;
            }
            
            

            //vertical up
            x = a - 1;
            while (x >= 0 && board[x, b] == turnOpp())
            {
                x--;
                if (x >= 0 && board[x, b] == turn)
                    return true;
                else decision = false;
            }
           

            
            //diagonal left up
            x = a - 1; y = b - 1;
            while (x >=0 && y>=0 && board[x, y] == turnOpp())
            {
                x--; 
                y--;
                if (x >= 0 && y >= 0 && board[x, y] == turn)
                    return true;
                else decision = false;
            }
            

            //diagonal down right
            x = a + 1; y = b + 1;
            while (x <= 7 && y <= 7 && board[x, y] == turnOpp())
            {
                x++;
                y++;
                if (x <= 7 && y <= 7 && board[x, y] == turn)
                    return true;
                else decision = false;
            }
           

            //diagonal up right
            x = a - 1; y = b + 1;
            while (x >= 0 && y <= 7 && board[x, y] == turnOpp())
            {
                x--;
                y++;
                if (x >= 0 && y <= 7 && board[x, y] == turn)
                    return true;
                else decision = false;
            }
            
           //diagonal left down

            x = a + 1; y = b - 1;
            while (x <= 7 && y >= 0 && board[x, y] == turnOpp())
            {
                x++;
                y--;
                if (x <= 7 && y >= 0 && board[x, y] == turn)
                    return true;
                else decision = false;
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
                board[x, y] = 'b';
            else
                move(0);
        //    Trace.Assert(board[x, y] == 'O');
            return c;
        }

        //prints the current state fo the board
        public void currentBoard()
        {
            string temp = "";
            Console.WriteLine("   0 1 2 3 4 5 6 7 ");
            for (int i = 0; i < 8; i++)
            {
                temp=temp+ i+ "  ";
                for (int j = 0; j < 8; j++)
                {
                    temp = temp + board[i, j] + " ";
                    
                }
                temp = temp + "\n \n";
            }
            Console.WriteLine(temp); 
        }
        public char turnOpp()
        {
            if (turn == 'b')
                return 'w';
            else
                return 'b';
        }
        public void action(cell c, char turn)
        { 
            int a = c.x ; //c.x is x coordinate
            int b = c.y;
            int y=b+1;
            //horizontal right side(+ve)
            if (horRight(c))
            {
                while (y >= 0 && y <= 7 && board[a, y] == turnOpp())
                {
                    board[a, y] = turn;
                    y++;
                }
            }
          //  board[x, b] = turn;
            //horizontal left side(-ve)
            y = b - 1;
            if (horLeft(c))
            {
                while (y >= 0 && y <= 7 && board[a, y] == turnOpp())
                {
                    board[a, y] = turn;
                    y--;
                }
            }
        //    board[x, b] = turn;
            //vertical down(+ve)
            int x = a + 1;
            if (vertDown(c))
            {
                while (x >= 0 && x <= 7 && board[x, b] == turnOpp())
                {
                    board[x, b] = turn;
                    x++;

                }
            }
          //  board[a, y] = turn;
            //verticl up(-ve)
            x = a - 1;
            if (vertUp(c))
            {
                while (x >= 0 && x <= 7 && board[x, b] == turnOpp())
                {
                    board[x, b] = turn;
                    x--;
                }
            }
         //   board[a, y] = turn;

            //diagonal down right 
            x = a + 1; y = b + 1;
            if (DiagRightDown(c))
            {
                while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
                {
                    board[x, y] = turn;
                    x++; y++;
                }
            }
            //diagonal up left
            x = a - 1; y = b -1;
            if (DiagLeftUp(c))
            {
                while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
                {
                    board[x, y] = turn;
                    x--; y--;
                }
            }
            //diagonal down  left
            x = a + 1; y = b - 1;
            if (DiagDownLeft(c))
            {
                while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
                {
                    board[x, y] = turn;
                    x++; y--;
                }
            }
            //Diagnol up right
            x = a - 1; y = b + 1;
            if (DiagRightUp(c))
            {
                while (x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x, y] == turnOpp())
                {
                    board[x, y] = turn;
                    x--; y++;
                }
            }

        }
        //decides whose move is it going to be-computer's or user's 
        public void move(int i)
        {
            if (i % 2 == 0)
            {

                turn = 'b';
             cell c=   playerMove();
                action(c, turn);
                currentBoard();

            }
            else
            {
                turn = 'w';
                cell c= computerMove();
             //   Console.WriteLine("Moves: " + sum);
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
                    if (board[i, j] == '.')
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
                    g.board[i, j] = '.';
                }
            }
        //    g.currentBoard();
            g.board[3, 3] = 'w';
            g.board[3, 4] = 'b';
            g.board[4, 3] = 'b';
            g.board[4, 4] = 'w';

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










