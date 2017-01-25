using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace MVVM
{
    class MainWindowViewModel : PropertyNotify
    {
        private string _text = string.Empty;
        private ICommand _onClickChangeText;
        private bool _canExecuteOnClickChangeText = true;

        public ICommand OnClickChangeText
        {
            get
            {
                return _onClickChangeText ?? (_onClickChangeText = new CommandHandler(() => ChangeText(), _canExecuteOnClickChangeText));
            }
        }

        /// <summary>
        /// Text
        /// Implement a property binding in the view model instead of the code behind.
        /// </summary>
        public string Text
        {
            get { return _text; }
            set 
            {
                if (_text == value)
                    return;

                _text = value;
                OnPropertyChanged("Text");
            }
        }

        public MainWindowViewModel()
        {

        }

        private void ChangeText()
        {
            Text = "foo";
        }

    }
}
