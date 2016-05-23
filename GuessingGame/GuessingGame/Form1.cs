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

        private void button1_Click(object sender, EventArgs e)
        {
            guessedNumber = int.Parse(textBox1.Text);
            bool win = false;
            bool wrong = false;
            if (textBox1.Text == "")
            {
                MessageBox.Show("Error! Please enter a number between 1-10");
                textBox1.Clear();

            }
            else
            {
                if (guessedNumber > 0 && guessedNumber <= 10)
                {
                    if (guessedNumber == randomNumber)
                    {
                        win = true;
                        if (win)
                        {
                            if (MessageBox.Show("You have won! Would like to play another game?", "you win", MessageBoxButtons.YesNo) == DialogResult.Yes)
                            {
                                randomNumber = number.Next(1, 10);
                                label3.Text = "3";
                                textBox1.Clear();
                            }
                            else this.Close();
                        }
                        else { //do nothing
                        }
                    }
                        else

    {

       wrong = true;

    }

    }

                        else{
                            MessageBox.Show("Please enter an integer from 1-10!", "Error!");

    textBox1.Clear();

                        }
                    }
                }
            }
        }
    }
}
