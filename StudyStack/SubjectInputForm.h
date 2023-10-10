#pragma once

#include "Subject.h"
#include "FolderManager.h"
#include "StudyManager.h"

namespace StudyStack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class SubjectInputForm : public System::Windows::Forms::Form
	{
	public:
		SubjectInputForm(void)
		{
			InitializeComponent();
		}

		/*property Subject^ NewSubject
		{
			Subject^ get() { return newSubject; }
		}*/


	protected:
		~SubjectInputForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Label^ subjectNameLabel;
		System::Windows::Forms::TextBox^ subjectNameTextBox;
		System::Windows::Forms::Label^ subjectDescriptionLabel;
		System::Windows::Forms::TextBox^ subjectDescriptionTextBox;
		System::Windows::Forms::Button^ okButton;

		//Subject^ newSubject;
		//StudyManager^ studyManager = gcnew StudyManager();

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->subjectNameLabel = (gcnew System::Windows::Forms::Label());
			this->subjectNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->subjectDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->subjectDescriptionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// subjectNameLabel
			// 
			this->subjectNameLabel->AutoSize = true;
			this->subjectNameLabel->Location = System::Drawing::Point(15, 12);
			this->subjectNameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->subjectNameLabel->Name = L"subjectNameLabel";
			this->subjectNameLabel->Size = System::Drawing::Size(289, 22);
			this->subjectNameLabel->TabIndex = 0;
			this->subjectNameLabel->Text = L"Введите название предмета: ";
			// 
			// subjectNameTextBox
			// 
			this->subjectNameTextBox->Location = System::Drawing::Point(19, 37);
			this->subjectNameTextBox->Name = L"subjectNameTextBox";
			this->subjectNameTextBox->Size = System::Drawing::Size(285, 28);
			this->subjectNameTextBox->TabIndex = 1;
			// 
			// subjectDescriptionLabel
			// 
			this->subjectDescriptionLabel->AutoSize = true;
			this->subjectDescriptionLabel->Location = System::Drawing::Point(15, 83);
			this->subjectDescriptionLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->subjectDescriptionLabel->Name = L"subjectDescriptionLabel";
			this->subjectDescriptionLabel->Size = System::Drawing::Size(289, 22);
			this->subjectDescriptionLabel->TabIndex = 2;
			this->subjectDescriptionLabel->Text = L"Введите описание предмета: ";
			// 
			// subjectDescriptionTextBox
			// 
			this->subjectDescriptionTextBox->Location = System::Drawing::Point(19, 108);
			this->subjectDescriptionTextBox->Multiline = true;
			this->subjectDescriptionTextBox->Name = L"subjectDescriptionTextBox";
			this->subjectDescriptionTextBox->Size = System::Drawing::Size(285, 102);
			this->subjectDescriptionTextBox->TabIndex = 3;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(125, 216);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(72, 51);
			this->okButton->TabIndex = 4;
			this->okButton->Text = L"ОК";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &SubjectInputForm::okButton_Click);
			// 
			// SubjectInputForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321, 275);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->subjectDescriptionTextBox);
			this->Controls->Add(this->subjectDescriptionLabel);
			this->Controls->Add(this->subjectNameTextBox);
			this->Controls->Add(this->subjectNameLabel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"SubjectInputForm";
			this->Text = L"Создание предмета";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ subjectName = subjectNameTextBox->Text;
		String^ subjectDescription = subjectDescriptionTextBox->Text;

		String^ folderName = FolderManager::ClearName(subjectName);

		if (String::IsNullOrEmpty(folderName))
		{
			MessageBox::Show("Неккоректно введено название предмета", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Subject^ subject = gcnew Subject(folderName, subjectDescription);
		
		FolderManager::CreateFolder(folderName);

		StudyManager::AddSubject(subject);

		this->Close();
	}
};
}
