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

        private void myMouseUpEvent(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("you clicked me at " + e.GetPosition(this).ToString());
        }

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
        //global exception handling
        // tempString.Trim();
    
    }
}
