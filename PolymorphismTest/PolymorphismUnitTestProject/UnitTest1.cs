using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using PolymorphismTest;

namespace PolymorphismUnitTestProject
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void SalaryTest()
        {
            //arrage
            int hours = 55;
            int wage = 70;
            int salary = 40*wage;
            Employee e = new Employee();
            string expectedResponse= String.Format("This employee is angry because he worked for {0} hrs." +
                "But got paid for 40 hrs at {1}/hrs=$ {2} salary.", hours, wage, salary);
            //act
            string response = e.CalculateWeeklySalary(hours, wage);
            //assert
            Assert.AreEqual(response, expectedResponse);
        }


        [TestMethod]
        public void SalaryContractorTest()
        {
            //arrage
            int hours = 55;
            int wage = 70;
            int salary = hours*wage;
            Contractor c= new Contractor();
            string expectedResponse = String.Format("\nThis HAPPY CONTRACTOR worked {0} hrs. " +
                              "Paid for {0} hrs at $ {1}" +
                              "/hr = ${2} ", hours, wage, salary);
            //act
            string response = c.CalculateWeeklySalary(hours, wage);
            //assert
            Assert.AreEqual(response, expectedResponse);
        }
    }
}
