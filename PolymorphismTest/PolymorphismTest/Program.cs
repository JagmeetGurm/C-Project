using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismTest
{

   public class Employee
    {
        public void CalculateWeeklySalary(int hours, int wage)
        {
            var salary = 40 * wage;
            Console.WriteLine("This employee is angry because he worked for {0} hrs." +
                "But got paid for 40 hrs at {1}/hrs={2} salary.", hours, wage, salary);
            Console.WriteLine("----------");

        }
    }
    public class Contractor: 


    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
