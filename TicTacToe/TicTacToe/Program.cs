using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicTacToe
{

    public class node{
        public int turn;
        public int level;
        public int score;
     public   bool visited;
    public List<node>adjList=new List<node>();  
  

    }
  public  class game
    {
      public score(){
         //if game win score=10;
          //elseif game lose score=-10;
          //else return 0;
      }
      public Action(){

      }

      public string Player(string start, int currentLevel){

      //reurn the player who has return;
          if(start=="PC" && currentLevel%2==0)
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
    class Program
    {
        static void Main(string[] args)
        {
            string initialState = "";
            int player = 1;
            int opponent = 2;

        }
    }
}
