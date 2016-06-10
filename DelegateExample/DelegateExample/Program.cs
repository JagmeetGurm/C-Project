using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateExample
{
   
    class Program
    {
        public delegate string MyDelegate(int a, int b);
        static string add(int a, int b)
        {
            return (a + b).ToString();

        }
        static string prod(int a, int b)
        {
            return (a * b).ToString();
        }
        static void Main(string[] args)
        {


            MyDelegate m = delegate (int a, int b){
                return (a / b).ToString();
            
            };
          Console.WriteLine( $"Now call the annon div via delegate: {m(4,5) }");
            m = prod;
            Console.WriteLine($"Now call the product via delegate: {m(4, 5) }");
            Console.ReadKey();
        }
    }
}
