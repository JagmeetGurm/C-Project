using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RevisingWPF
{
  public static  class delegateClass
    {
        //delegate is a reference to a method.
        public delegate int Del(int firstNo, int secondNo, string operand);

        //create a method for the delegate
        public static int calculateResult(int firstNo, int secondNo, string operand)
        {
            int result = 0;
            if (operand == "+")
            {
               result= firstNo + secondNo;
            }
            else if (operand == "-")
            {
                result = firstNo - secondNo;
            }
            else
            {
                result = firstNo * secondNo;
            }
            return result;
        }
    }
}
