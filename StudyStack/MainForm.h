#pragma once
#include "Subject.h"
#include "Lecture.h"
#include "Task.h"
#include "FolderManager.h"
namespace StudyStack {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class MainForm : public System::Windows::Forms::Form
    {

    public:
        MainForm(void)
        {
            InitializeComponent();
            SetRoundedForm();
        }

    private:
        System::Windows::Forms::Panel^ leftPanel;
        System::Windows::Forms::Panel^ assignmentsPanel;
        System::Windows::Forms::Panel^ lecturesPanel;
        System::Windows::Forms::Panel^ titleBar;
        System::Windows::Forms::Button^ closeButton;
        System::Windows::Forms::Button^ minimizeButton;
        System::Windows::Forms::Button^ maximizeButton;

        Point lastPoint; //for mouse move

        void SetRoundedForm()
        {
            int radius = 20;
            this->Region = gcnew System::Drawing::Region(GetRoundedPath(this->ClientRectangle, radius));
        }

        System::Drawing::Drawing2D::GraphicsPath^ GetRoundedPath(System::Drawing::Rectangle rect, int radius)
        {
            System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
            path->AddArc(rect.X, rect.Y, radius * 2, radius * 2, 180, 90);
            path->AddArc(rect.Right - radius * 2, rect.Y, radius * 2, radius * 2, 270, 90);
            path->AddArc(rect.Right - radius * 2, rect.Bottom - radius * 2, radius * 2, radius * 2, 0, 90);
            path->AddArc(rect.X, rect.Bottom - radius * 2, radius * 2, radius * 2, 90, 90);
            path->CloseFigure();
            return path;
        }

        void InitializeComponent(void)
        {
            this->titleBar = (gcnew System::Windows::Forms::Panel());
            this->minimizeButton = (gcnew System::Windows::Forms::Button());
            this->maximizeButton = (gcnew System::Windows::Forms::Button());
            this->closeButton = (gcnew System::Windows::Forms::Button());
            this->leftPanel = (gcnew System::Windows::Forms::Panel());
            this->assignmentsPanel = (gcnew System::Windows::Forms::Panel());
            this->lecturesPanel = (gcnew System::Windows::Forms::Panel());
            this->titleBar->SuspendLayout();
            this->SuspendLayout();
            // 
            // titleBar
            // 
            this->titleBar->BackColor = System::Drawing::Color::Gray;
            this->titleBar->Controls->Add(this->minimizeButton);
            this->titleBar->Controls->Add(this->maximizeButton);
            this->titleBar->Controls->Add(this->closeButton);
            this->titleBar->Dock = System::Windows::Forms::DockStyle::Top;
            this->titleBar->Location = System::Drawing::Point(0, 0);
            this->titleBar->Name = L"titleBar";
            this->titleBar->Size = System::Drawing::Size(868, 90);
            this->titleBar->TabIndex = 0;
            this->titleBar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::titleBar_MouseDown);
            this->titleBar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::titleBar_MouseMove);
            this->titleBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::titleBar_MouseUp);
            // 
            // minimizeButton
            // 
            this->minimizeButton->Dock = System::Windows::Forms::DockStyle::Right;
            this->minimizeButton->FlatAppearance->BorderSize = 0;
            this->minimizeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->minimizeButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->minimizeButton->ForeColor = System::Drawing::Color::White;
            this->minimizeButton->Location = System::Drawing::Point(743, 0);
            this->minimizeButton->Name = L"minimizeButton";
            this->minimizeButton->Size = System::Drawing::Size(40, 90);
            this->minimizeButton->TabIndex = 2;
            this->minimizeButton->Text = L"-";
            this->minimizeButton->UseVisualStyleBackColor = true;
            this->minimizeButton->Click += gcnew System::EventHandler(this, &MainForm::minimizeButton_Click);
            // 
            // maximizeButton
            // 
            this->maximizeButton->Dock = System::Windows::Forms::DockStyle::Right;
            this->maximizeButton->FlatAppearance->BorderSize = 0;
            this->maximizeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->maximizeButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->maximizeButton->ForeColor = System::Drawing::Color::White;
            this->maximizeButton->Location = System::Drawing::Point(783, 0);
            this->maximizeButton->Name = L"maximizeButton";
            this->maximizeButton->Size = System::Drawing::Size(44, 90);
            this->maximizeButton->TabIndex = 3;
            this->maximizeButton->Text = L"□";
            this->maximizeButton->UseVisualStyleBackColor = true;
            this->maximizeButton->Click += gcnew System::EventHandler(this, &MainForm::maximizeButton_Click);
            // 
            // closeButton
            // 
            this->closeButton->Dock = System::Windows::Forms::DockStyle::Right;
            this->closeButton->FlatAppearance->BorderSize = 0;
            this->closeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->closeButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->closeButton->ForeColor = System::Drawing::Color::White;
            this->closeButton->Location = System::Drawing::Point(827, 0);
            this->closeButton->Name = L"closeButton";
            this->closeButton->Size = System::Drawing::Size(41, 90);
            this->closeButton->TabIndex = 1;
            this->closeButton->Text = L"X";
            this->closeButton->UseVisualStyleBackColor = true;
            this->closeButton->Click += gcnew System::EventHandler(this, &MainForm::closeButton_Click);
            // 
            // leftPanel
            // 
            this->leftPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->leftPanel->Dock = System::Windows::Forms::DockStyle::Left;
            this->leftPanel->Location = System::Drawing::Point(0, 90);
            this->leftPanel->Name = L"leftPanel";
            this->leftPanel->Size = System::Drawing::Size(182, 453);
            this->leftPanel->TabIndex = 1;
            // 
            // assignmentsPanel
            // 
            this->assignmentsPanel->BackColor = System::Drawing::Color::Chocolate;
            this->assignmentsPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->assignmentsPanel->Location = System::Drawing::Point(182, 90);
            this->assignmentsPanel->Name = L"assignmentsPanel";
            this->assignmentsPanel->Size = System::Drawing::Size(686, 220);
            this->assignmentsPanel->TabIndex = 2;
            // 
            // lecturesPanel
            // 
            this->lecturesPanel->BackColor = System::Drawing::Color::Chocolate;
            this->lecturesPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->lecturesPanel->Location = System::Drawing::Point(182, 323);
            this->lecturesPanel->Name = L"lecturesPanel";
            this->lecturesPanel->Size = System::Drawing::Size(686, 220);
            this->lecturesPanel->TabIndex = 3;
            // 
            // MainForm
            // 
            this->ClientSize = System::Drawing::Size(868, 543);
            this->Controls->Add(this->lecturesPanel);
            this->Controls->Add(this->assignmentsPanel);
            this->Controls->Add(this->leftPanel);
            this->Controls->Add(this->titleBar);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"MainForm";
            this->Text = L"StudyStack";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint);
            this->titleBar->ResumeLayout(false);
            this->ResumeLayout(false);

        }

    private: System::Void titleBar_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        lastPoint = Point(e->X, e->Y);
    }

    private: System::Void titleBar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        if (e->Button == System::Windows::Forms::MouseButtons::Left)
        {
            this->Left += e->X - lastPoint.X;
            this->Top += e->Y - lastPoint.Y;
        }
    }

    private: System::Void titleBar_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        //pass
    }

    private: System::Void closeButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }

    private: System::Void minimizeButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
    }

    private: System::Void maximizeButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (this->WindowState == System::Windows::Forms::FormWindowState::Normal)
        {
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
        }
        else
        {
            this->WindowState = System::Windows::Forms::FormWindowState::Normal;
        }
    }

    private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        //pass
    }

    private: System::Void MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
    {
        //pass
    }
    };
}
