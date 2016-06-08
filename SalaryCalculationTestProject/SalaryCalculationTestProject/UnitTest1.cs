using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

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
        }
    }
}
