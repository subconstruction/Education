#include "stdafx.h"
#include <string>

namespace YourAppName {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MainForm : public Form {
    public:
        MainForm() {
            InitializeComponents();
        }

    private:
        void InitializeComponents() {
            // TextBox
            textBox = gcnew TextBox();
            textBox->Multiline = true;
            textBox->Size = Drawing::Size(200, 100);
            textBox->Location = Drawing::Point(10, 10);
            this->Controls->Add(textBox);

            // Button
            button = gcnew Button();
            button->Text = "Toggle Text";
            button->Size = Drawing::Size(100, 30);
            button->Location = Drawing::Point(10, 120);
            button->Click += gcnew EventHandler(this, &MainForm::ToggleText);
            this->Controls->Add(button);
        }

        void ToggleText(Object^ sender, EventArgs^ e) {
            // Toggle visibility of the text
            textBox->Visible = !textBox->Visible;
        }

    private:
        TextBox^ textBox;
        Button^ button;
    };
}

[STAThread]
int main(array<System::String ^> ^args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    YourAppName::MainForm form;
    Application::Run(%form);
    return 0;
}