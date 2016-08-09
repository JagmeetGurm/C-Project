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

//This revision is done with the help of WPF tutorial referenced from:
// http://www.wpf-tutorial.com/
 
namespace RevisingWPF
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
        private void ValidateName()
       {
            if ((txtCompanyName.Text!="") || (txtFirstName.Text !="") && (txtLastName.Text!=""))
            {labelCompanyName.Content="Company Name";
                labelFirstName.Content = "First Name";
                labelLastName.Content = "Last Name";
            }
            else
            {
                labelCompanyName.Content = "Company Name*";
                labelFirstName.Content = "First Name*";
                labelLastName.Content = "Last Name*";
            }
        }
        private void txtFirstName_TextChanged(object sender, TextChangedEventArgs e)
        {
            ValidateName();
        }

        private void txtLastName_TextChanged(object sender, TextChangedEventArgs e)
        {
            ValidateName();
        }

        private void txtCompanyName_TextChanged(object sender, TextChangedEventArgs e)
        {
            ValidateName();
        }

        /*      private void myMouseUpEvent(object sender, MouseButtonEventArgs e)
              {
                  MessageBox.Show("you clicked me at " + e.GetPosition(this).ToString());
              }
      */




        /*     private void allFeatures_changed(object sender, RoutedEventArgs e)
             {
                 CheckBox enableAll = (CheckBox)sender;
                 if (enableAll.IsChecked==true)
                 {
                     firstOp.IsChecked = true;
                     secondOp.IsChecked = true;
                     thirdOp.IsChecked = true;

                 }
                 if (enableAll.IsChecked == false)
                 {
                     firstOp.IsChecked = false;
                     secondOp.IsChecked = false;
                     thirdOp.IsChecked = false;

                 }
             }

             private void singlecheck(object sender, RoutedEventArgs e)
             {
                 allFeatures.IsChecked = null;
                 if(firstOp.IsChecked==true && secondOp.IsChecked==true && thirdOp.IsChecked == true)
                 {
                     allFeatures.IsChecked = true;
                 }
                 if (firstOp.IsChecked == false && secondOp.IsChecked == false && thirdOp.IsChecked == false)
                 {
                     allFeatures.IsChecked = false;
                 }
             }


         */

        //global exception handling
        // tempString.Trim();

    }
}
