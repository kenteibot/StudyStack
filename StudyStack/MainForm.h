#pragma once
#include "Subject.h"
#include "Lecture.h"
#include "Task.h"
#include "FolderManager.h"
#include "SubjectInputForm.h"
#include "StudyManager.h"

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

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

        System::Windows::Forms::Panel^ leftPanel;
        System::Windows::Forms::Panel^ assignmentsPanel;
        System::Windows::Forms::Panel^ lecturesPanel;
        System::Windows::Forms::Panel^ titleBar;
        System::Windows::Forms::Button^ closeButton;
        System::Windows::Forms::Button^ minimizeButton;
        System::Windows::Forms::Button^ maximizeButton;
        System::Windows::Forms::ListBox^ subjectsList;
        System::Windows::Forms::Button^ addSubjectButton;
    private: System::Windows::Forms::ListView^ lecturesListView;
    private: System::Windows::Forms::Button^ addLectureButton;

    //private: StudyManager^ studyManager;














        Point lastPoint; //for mouse move

        
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->titleBar = (gcnew System::Windows::Forms::Panel());
            this->minimizeButton = (gcnew System::Windows::Forms::Button());
            this->maximizeButton = (gcnew System::Windows::Forms::Button());
            this->closeButton = (gcnew System::Windows::Forms::Button());
            this->leftPanel = (gcnew System::Windows::Forms::Panel());
            this->addSubjectButton = (gcnew System::Windows::Forms::Button());
            this->subjectsList = (gcnew System::Windows::Forms::ListBox());
            this->assignmentsPanel = (gcnew System::Windows::Forms::Panel());
            this->lecturesPanel = (gcnew System::Windows::Forms::Panel());
            this->lecturesListView = (gcnew System::Windows::Forms::ListView());
            this->addLectureButton = (gcnew System::Windows::Forms::Button());
            this->titleBar->SuspendLayout();
            this->leftPanel->SuspendLayout();
            this->lecturesPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // titleBar
            // 
            this->titleBar->BackColor = System::Drawing::Color::Gray;
            this->titleBar->Controls->Add(this->addLectureButton);
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
            this->leftPanel->BackColor = System::Drawing::SystemColors::ButtonHighlight;
            this->leftPanel->Controls->Add(this->addSubjectButton);
            this->leftPanel->Controls->Add(this->subjectsList);
            this->leftPanel->Dock = System::Windows::Forms::DockStyle::Left;
            this->leftPanel->Location = System::Drawing::Point(0, 90);
            this->leftPanel->Name = L"leftPanel";
            this->leftPanel->Size = System::Drawing::Size(182, 453);
            this->leftPanel->TabIndex = 1;
            // 
            // addSubjectButton
            // 
            this->addSubjectButton->Dock = System::Windows::Forms::DockStyle::Fill;
            this->addSubjectButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->addSubjectButton->Location = System::Drawing::Point(0, 375);
            this->addSubjectButton->Name = L"addSubjectButton";
            this->addSubjectButton->Size = System::Drawing::Size(182, 78);
            this->addSubjectButton->TabIndex = 1;
            this->addSubjectButton->Text = L"Создать предмет";
            this->addSubjectButton->UseVisualStyleBackColor = true;
            this->addSubjectButton->Click += gcnew System::EventHandler(this, &MainForm::addSubjectButton_Click);
            // 
            // subjectsList
            // 
            this->subjectsList->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->subjectsList->Dock = System::Windows::Forms::DockStyle::Top;
            this->subjectsList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->subjectsList->FormattingEnabled = true;
            this->subjectsList->ItemHeight = 25;
            this->subjectsList->Location = System::Drawing::Point(0, 0);
            this->subjectsList->Name = L"subjectsList";
            this->subjectsList->Size = System::Drawing::Size(182, 375);
            this->subjectsList->TabIndex = 0;
            this->subjectsList->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::subjectsList_SelectedIndexChanged);
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
            this->lecturesPanel->Controls->Add(this->lecturesListView);
            this->lecturesPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->lecturesPanel->Location = System::Drawing::Point(182, 323);
            this->lecturesPanel->Name = L"lecturesPanel";
            this->lecturesPanel->Size = System::Drawing::Size(686, 220);
            this->lecturesPanel->TabIndex = 3;
            // 
            // lecturesListView
            // 
            this->lecturesListView->Dock = System::Windows::Forms::DockStyle::Fill;
            this->lecturesListView->HideSelection = false;
            this->lecturesListView->Location = System::Drawing::Point(0, 0);
            this->lecturesListView->Name = L"lecturesListView";
            this->lecturesListView->Size = System::Drawing::Size(686, 220);
            this->lecturesListView->TabIndex = 0;
            this->lecturesListView->UseCompatibleStateImageBehavior = false;
            this->lecturesListView->View = System::Windows::Forms::View::Tile;
            // 
            // addLectureButton
            // 
            this->addLectureButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->addLectureButton->Location = System::Drawing::Point(12, 24);
            this->addLectureButton->Name = L"addLectureButton";
            this->addLectureButton->Size = System::Drawing::Size(111, 45);
            this->addLectureButton->TabIndex = 4;
            this->addLectureButton->Text = L"Создать лекцию";
            this->addLectureButton->UseVisualStyleBackColor = true;
            this->addLectureButton->Click += gcnew System::EventHandler(this, &MainForm::addLectureButton_Click);
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
            this->leftPanel->ResumeLayout(false);
            this->lecturesPanel->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion


    private: void SetRoundedForm()
    {
        int radius = 20;
        this->Region = gcnew System::Drawing::Region(GetRoundedPath(this->ClientRectangle, radius));
    }

    private: System::Drawing::Drawing2D::GraphicsPath^ GetRoundedPath(System::Drawing::Rectangle rect, int radius)
    {
        System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
        path->AddArc(rect.X, rect.Y, radius * 2, radius * 2, 180, 90);
        path->AddArc(rect.Right - radius * 2, rect.Y, radius * 2, radius * 2, 270, 90);
        path->AddArc(rect.Right - radius * 2, rect.Bottom - radius * 2, radius * 2, radius * 2, 0, 90);
        path->AddArc(rect.X, rect.Bottom - radius * 2, radius * 2, radius * 2, 90, 90);
        path->CloseFigure();
        return path;
    }

    private: void UpdateLecturesListView()
    {
        //lecturesListView->Items->Clear();
        //Subject^ activeSubject = dynamic_cast<Subject^>(subjectsList->SelectedItem);
        //List<Lecture^>^ lectures = StudyManager::GetLectures(activeSubject);
        //for each (Lecture^ lecture in lectures)
        //{
        //    lecturesListView->Items->Add(lecture);
        //}
    }

    private: void UpdateSubjectsList()
    {
        subjectsList->Items->Clear();
        List<Subject^>^ subjects = StudyManager::GetSubjects();
        for each (Subject ^ subject in subjects)
        {
            subjectsList->Items->Add(subject);
        }
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
    private: System::Void addSubjectButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        SubjectInputForm^ subjectInputForm = gcnew SubjectInputForm();
        subjectInputForm->ShowDialog();
        UpdateSubjectsList();
    }
    private: System::Void subjectsList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
    {
        UpdateLecturesListView();
    }
    private: System::Void addLectureButton_Click(System::Object^ sender, System::EventArgs^ e) 
    {
        
    }
};
}
