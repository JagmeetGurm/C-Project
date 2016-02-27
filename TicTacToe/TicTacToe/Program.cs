using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicTacToe
{
   

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
                                    nn.state[k, l] = ' ';
                                }
                            }
                                nn.state[i, j] = 'X';
                            nn.type = 'X';
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
                                    nn.state[k, l] = ' ';
                                }
                            }
                            nn.state[i, j] = 'O';
                            nn.type = 'O';
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

        }
    }
}
