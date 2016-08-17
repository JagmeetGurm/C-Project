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
            string expectedResponse = $"This employee is angry because he worked for {hours} hrs." +
                $"But got paid for 40 hrs at {wage}/hrs=$ {salary} salary.";
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
            string expectedResponse = $"\nThis HAPPY CONTRACTOR worked {hours} hrs. " +
                              $"Paid for {wage} hrs at $ {salary}" +$"/hr = ${2} ";
            //act
            string response = c.CalculateWeeklySalary(hours, wage);
            //assert
            Assert.AreEqual(response, expectedResponse);
        }
    }
}
