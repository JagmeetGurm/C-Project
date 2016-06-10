using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateExample
{
    public delegate void BalanceEventHandler(decimal theValue);
    public delegate void MyDelegate(int a, ref int b);
    public delegate void EventHandler(string test);
    class Events
    {
        public event EventHandler ValueChanged;
        private string theValue;
        public string Val
        {
            set
            {

                this.theValue = value;


                this.ValueChanged(theValue);
            }
        }
    }

    class Balance
    {
        public event BalanceEventHandler balChanged;
        private decimal bankBalance;
        public decimal theBalance
        {
            set
            {
                this.bankBalance = value;
                balChanged(value);

            }
            get
            {
                return bankBalance;
            }
        }
        public void LogBalance(decimal amt)
        {
            Console.WriteLine("the bank bal is : {0}", amt);
        }
        public void balWatch(decimal amt)
        {
            if (amt >= 550)
                Console.WriteLine("you have reached goal! {0}", amt);
        }
}
    class Program
    {
       
       
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

            Balance b = new Balance();
            b.balChanged += b.LogBalance;
            b.balChanged += b.balWatch;

            /*      MyDelegate  m = add;

                    Console.WriteLine("Now call add via delegate:");
                        m(4, 5);
                    MyDelegate m2 = prod;
                    Console.WriteLine($"Now call the product via delegate:");
                    m2(4, 5) ;
                    MyDelegate m3 = m+m2;
                    Console.WriteLine($"Now call the chained delegate: ");
                    m3(4, 5);


                    int a = 10, b = 20;
                    MyDelegate ch = changeValue;
                    Console.WriteLine($"b's value before: {b}");
                    ch(a, ref b);
                    Console.WriteLine($"b's value now: {b}");
                                    
            Events obj = new Events();
            obj.ValueChanged += objValueChanged;
            Console.WriteLine("enter the value: ");
            string temp = Console.ReadLine();
            obj.Val = temp;

    */
            string str;
            Console.WriteLine("enter the amt : ");
            str = Console.ReadLine();
            decimal deposit = decimal.Parse(str);
            b.theBalance += deposit;
            Console.ReadKey();
        }
        static void objValueChanged(string val)
        {
            Console.WriteLine("value changed {0}", val);
        }
    }
}
