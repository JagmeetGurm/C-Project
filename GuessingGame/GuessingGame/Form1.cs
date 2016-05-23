using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GuessingGame
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //Global variables
        Random number = new Random();
        int randomNumber; //the random number
        int guessedNumber;//the guess number
        private void Form1_Load(object sender, EventArgs e)
        {
            
            randomNumber = number.Next(1, 10);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                try
                {
                    guessedNumber = int.Parse(textBox1.Text);


                }
                catch
                {
                    MessageBox.Show("Error! Please enter a number between 1-10");
                    textBox1.Clear();
                }
            }
        }
    }
}
