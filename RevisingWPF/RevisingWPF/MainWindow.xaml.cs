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

  /*      private void myMouseUpEvent(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("you clicked me at " + e.GetPosition(this).ToString());
        }
*/
        private void myButtonClick(object sender, RoutedEventArgs e)
        {
            string tempString = null;
            //local exception handling
            try
            {
                tempString.Trim();
            }
            catch (Exception ex)
            {
                MessageBox.Show("A handled exception just occured: " + ex.Message,
                   " Exception Sample");

            }
        }
            private void Hyperlink_RequestNavigate(object sender, System.Windows.Navigation.RequestNavigateEventArgs e)
        {
            System.Diagnostics.Process.Start(e.Uri.AbsoluteUri);
        }

        private void myDockSelCh(object sender, RoutedEventArgs e)
        {
            TextBox tBox = (TextBox)sender;
            outputBox.Text = "selection starts at " + tBox.SelectionStart+Environment.NewLine;
            outputBox.Text += "selection: " + tBox.SelectedText;
        }

        private void allFeatures_changed(object sender, RoutedEventArgs e)
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




        //global exception handling
        // tempString.Trim();

    }
}
