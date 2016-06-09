using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateExample
{
    public delegate string MyDelegate(int a, int b);
    class Program
    {
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


            MyDelegate m = add;
          Console.WriteLine( $"First call the add via delegate: {m(4,5) }");
            Console.ReadKey();
        }
    }
}
