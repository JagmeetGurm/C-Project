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
public static int checkOperand(string operand)
        {

        }
        //create a method for the delegate
        public static int calculateResult(int firstNo, int secondNo, string operand)
        {
            int result = 0;
         result=   checkOperand(operand);
            return result;
        }
    }
}
