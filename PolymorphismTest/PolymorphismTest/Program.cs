using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolymorphismTest
{

    public class Employee
    {
        public virtual void CalculateWeeklySalary(int hours, int wage)
        {
            var salary = 40 * wage;
            Console.WriteLine("This employee is angry because he worked for {0} hrs." +
                "But got paid for 40 hrs at {1}/hrs=$ {2} salary.", hours, wage, salary);
            Console.WriteLine("----------");

        }
    }
    public class Contractor : Employee
    {
        public override void CalculateWeeklySalary(int hours, int wage)
        {
            var salary = hours * wage;
            Console.WriteLine("\nThis HAPPY CONTRACTOR worked {0} hrs. " +
                              "Paid for {0} hrs at $ {1}" +
                              "/hr = ${2} ", hours, wage, salary);
            Console.WriteLine("---------------------------------------------\n");
        }
    }


    class Program
    {
        private static void Main(string[] args)
        {
            const int hr = 55, wage = 70;

            List<Employee> listEmployees = GetEmployees();
            foreach (var e in listEmployees)
                e.CalculateWeeklySalary(hr, wage);
            Console.ReadKey();
        }
        private static List<Employee> GetEmployees()
        {
            var emp = new Employee();
            var cont = new Contractor();
            var everyone = new List<Employee> { emp, cont };
            return everyone;
        }
       
    }

}
