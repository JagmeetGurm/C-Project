using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateExample
{
   
    class Program
    {
        public delegate void MyDelegate(int a, ref int b);
        static void add(int a, int b)
        {
           Console.WriteLine( (a + b).ToString()+ " the first call");

        }
        static void changeValue(int a, ref int b)
        {
           string res = b.ToString();
            b = b + 100;
            Console.WriteLine("lets see if: {0} value changed", res);
        }
        static void prod(int a, int b)
        {
           Console.WriteLine( (a * b).ToString()+ " the second call");
        }
        static void Main(string[] args)
        {


            
    /*      MyDelegate  m = add;

            Console.WriteLine("Now call add via delegate:");
                m(4, 5);
            MyDelegate m2 = prod;
            Console.WriteLine($"Now call the product via delegate:");
            m2(4, 5) ;
            MyDelegate m3 = m+m2;
            Console.WriteLine($"Now call the chained delegate: ");
            m3(4, 5);

    */
            int a = 10, b = 20;
            MyDelegate ch = changeValue;
            Console.WriteLine($"b's value before: {b}");
            ch(a, ref b);
            Console.WriteLine($"b's value now: {b}");
            Console.ReadKey();
        }
    }
}
