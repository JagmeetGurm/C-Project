//this is based on the C# delegate tutorial from lynda.com referenced from: http://www.lynda.com/


﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegates
{
    class Program
    {
        public delegate double DelegateTest(int val);
        static double zone1(int val)
        {
            return .25 * val;
        }

        static double zone2(int val)
        {
            return (.12 * val)+25;
        }
        static double zone3(int val)
        {
            return .08 * val;
        }

        static double zone4(int val)
        {
            return (.04 * val) + 25;
        }
        static double shippingCost(string place, string itemCost)
        { int itemVal = Int32.Parse(itemCost);
            double result=0;
            DelegateTest dt;
            switch (place)
            {
                case "zone1":
                    dt = zone1;
                   result= dt(itemVal);
                    break;
                case "zone2":
                    dt = zone2;
                    result = dt(itemVal);
                    break;
                case "zone3":
                    dt = zone3;
                    result = dt(itemVal);
                    break;
                case "zone4":
                    dt = zone4;
                    result = dt(itemVal);
                    break;
                default:
                    break;
                    
            }
            return result;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("What is the destination?");
          string inputDestination=  Console.ReadLine();
            Console.WriteLine("What is the item price?");
string itemPrice = Console.ReadLine();
  Console.WriteLine(          shippingCost(inputDestination, itemPrice));
            Console.ReadKey();
        }
    }
}
