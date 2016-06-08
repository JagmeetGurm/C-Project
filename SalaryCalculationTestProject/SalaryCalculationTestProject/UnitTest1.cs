using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Calculator;
namespace SalaryCalculationTestProject
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void AnnualSalaryTest()
        {
            //Arrange
            SalaryCalculator sc = new SalaryCalculator();

            //Act
            decimal annualSalary = sc.GetAnnualSalary(50);
            //Assert
            Assert.AreEqual(104000, annualSalary);
        }

        [TestMethod]
        public void HourlyWageTest()
        {
            SalaryCalculator sc = new SalaryCalculator();
            decimal hourlyWage = sc.GetHourlyWage(52000);

            Assert.AreEqual(25, hourlyWage);
        }
    }
}
