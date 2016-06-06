using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BasicCalculator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        double result = 0;
        double operand1 = 0;
        double operand2 = 0;
        string input = "";
        string oper;
        public void calculation(double op1, double op2, string oper)
        {
            switch (oper)
            {
                case "+":
                    result = op1 + op2;
                    break;
                case "-":
                    result = op1 - op2;
                    break;
                case "*":
                    result = op1 * op2;
                    break;
                case "/":
                    result = op1 / op2;
                    break;
                default:
                    Console.WriteLine("Enter the correct operand, Please!");
                    break;

            }
            Result.Text= result.ToString();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        { Button button1 = (Button)sender;
            double temp = 0;
          string val=   button1.Content.ToString();
            if (Double.TryParse(val, out temp))
            {
                input += val;
                Result.Text = input;
            }
            else Result.Text = "please enter the correct value again!"; 
          /*  try
            {
                int intValue = 32;
                object objValue = intValue;
                string strValue;
                strValue = objValue.ToString();
            }
            catch(Exception ex)
            {
                Result.Text = ex.Message;
            }*/
        }

 

        private void buttonClear_Click(object sender, RoutedEventArgs e)
        {
            Button button1 = (Button)sender;
            input += button1.Content.ToString();
            input = "";
            Result.Text = "";
        }

        private void buttonAdd_Click(object sender, RoutedEventArgs e)
        {
            Button button1 = (Button)sender;
            input += button1.Content.ToString();
            Result.Text = input;
        }

 

        private void buttonMult_Click(object sender, RoutedEventArgs e)
        {
            Button button1 = (Button)sender;
            input += button1.Content.ToString();
            Result.Text = input;
        }

        private void buttonDiv_Click(object sender, RoutedEventArgs e)
        {
            Button button1 = (Button)sender;
            input += button1.Content.ToString();
            Result.Text = input;
        }

        private void buttonSub_Click(object sender, RoutedEventArgs e)
        {
            Button button1 = (Button)sender;
            input += button1.Content.ToString();
            Result.Text = input;
        }

        private void buttonDot_Click(object sender, RoutedEventArgs e)
        {
            Button button1 = (Button)sender;
            input += button1.Content.ToString();
            Result.Text = input;
        }

        private void buttonEqual_Click(object sender, RoutedEventArgs e)
        {
            //   Button button1 = (Button)sender;
            //  input += button1.Content.ToString();

            //    gettingOperators(input);
            char[] delimiters = { '+', '-', '/', '*' };
            string[] items = input.Split(delimiters);
            operand1 = Double.Parse(items[0]);
            operand2 = Double.Parse(items[1]);
            if (input.Contains('+'))
            {
                oper = "+";
            }
            else if (input.Contains('+'))
            {
                oper = "-";

            }
            else if (input.Contains('-'))
            {
                oper = "-";

            }

            else if (input.Contains('*'))
            {
                oper = "*";

            }
            else 
            {
                oper = "/";

            }
            calculation(operand1, operand2, oper);

        }
    }
}
