using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


//this small game is build based on the tutorial: http://www.dreamincode.net/forums/topic/76122-c%23-tutorial-basic-gui-guessing-game/
//to create GUI in c# for beginners.
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
            if (wrong == true)

{

    label3.Text = (int.Parse(label3.Text) - 1).ToString();

    if (label3.Text == "0")

    {

    if (MessageBox.Show("You have lost! The randomized number was " + randomNumber + ". Would you like to play again ?", "You lost!", MessageBoxButtons.YesNo) == DialogResult.Yes)

    {

        randomNumber = number.Next(1, 10);

        label3.Text = "3";

        textBox1.Clear();

    }

    else

    {

        this.Close();

    }

    }

    else

    {

    if (guessedNumber > randomNumber)

    {

        MessageBox.Show("Lower!", "Wrong!");

        textBox1.Clear();

    }

    else

   {

        MessageBox.Show("Higher!", "Wrong!");

        textBox1.Clear();

    }

    }

}

else

{

    // Do nothing

}

                }
            }
        }
   

