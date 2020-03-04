#pragma once


namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Label^  lblOper;
	private: System::Windows::Forms::TextBox^  txt1;

	private: System::Windows::Forms::Label^  lbl1;
	private: System::Windows::Forms::Label^  lbl2;
	private: System::Windows::Forms::Label^  lblResult;
	private: System::Windows::Forms::TextBox^  txt2;
	private: System::Windows::Forms::TextBox^  txtResult;
	private: System::Windows::Forms::Button^  btnNoAdd;
	private: System::Windows::Forms::Button^  btnProd;
	private: System::Windows::Forms::Button^  btnNoProd;
	private: System::Windows::Forms::Label^  lblWarning;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->lblOper = (gcnew System::Windows::Forms::Label());
			this->txt1 = (gcnew System::Windows::Forms::TextBox());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->lbl2 = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->txt2 = (gcnew System::Windows::Forms::TextBox());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->btnNoAdd = (gcnew System::Windows::Forms::Button());
			this->btnProd = (gcnew System::Windows::Forms::Button());
			this->btnNoProd = (gcnew System::Windows::Forms::Button());
			this->lblWarning = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Silver;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold));
			this->btnClose->ForeColor = System::Drawing::Color::Black;
			this->btnClose->Location = System::Drawing::Point(14, 330);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(100, 100);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"�������";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &Form1::btnClose_Click);
			// 
			// btnReset
			// 
			this->btnReset->BackColor = System::Drawing::Color::Silver;
			this->btnReset->FlatAppearance->BorderSize = 0;
			this->btnReset->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnReset->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold));
			this->btnReset->ForeColor = System::Drawing::Color::Black;
			this->btnReset->Location = System::Drawing::Point(120, 330);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(100, 100);
			this->btnReset->TabIndex = 1;
			this->btnReset->Text = L"�����";
			this->btnReset->UseVisualStyleBackColor = false;
			this->btnReset->Click += gcnew System::EventHandler(this, &Form1::btnReset_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::Silver;
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnAdd->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnAdd->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnAdd->ForeColor = System::Drawing::Color::Black;
			this->btnAdd->Location = System::Drawing::Point(226, 12);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(100, 100);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->Text = L"+";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAdd_Click);
			// 
			// lblOper
			// 
			this->lblOper->AutoSize = true;
			this->lblOper->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblOper->ForeColor = System::Drawing::Color::Black;
			this->lblOper->Location = System::Drawing::Point(110, 10);
			this->lblOper->Name = L"lblOper";
			this->lblOper->Size = System::Drawing::Size(0, 20);
			this->lblOper->TabIndex = 3;
			this->lblOper->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt1
			// 
			this->txt1->BackColor = System::Drawing::SystemColors::Control;
			this->txt1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->txt1->Location = System::Drawing::Point(120, 12);
			this->txt1->Name = L"txt1";
			this->txt1->Size = System::Drawing::Size(100, 23);
			this->txt1->TabIndex = 4;
			this->txt1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txt1->TextChanged += gcnew System::EventHandler(this, &Form1::txt1_TextChanged);
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold));
			this->lbl1->ForeColor = System::Drawing::Color::Black;
			this->lbl1->Location = System::Drawing::Point(12, 16);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(111, 19);
			this->lbl1->TabIndex = 5;
			this->lbl1->Text = L"������ �����:";
			this->lbl1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lbl1->Click += gcnew System::EventHandler(this, &Form1::lbl1_Click);
			// 
			// lbl2
			// 
			this->lbl2->AutoSize = true;
			this->lbl2->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->lbl2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold));
			this->lbl2->ForeColor = System::Drawing::Color::Black;
			this->lbl2->Location = System::Drawing::Point(12, 122);
			this->lbl2->Name = L"lbl2";
			this->lbl2->Size = System::Drawing::Size(108, 19);
			this->lbl2->TabIndex = 6;
			this->lbl2->Text = L"������ �����:";
			this->lbl2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lbl2->Click += gcnew System::EventHandler(this, &Form1::lbl2_Click);
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->lblResult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold));
			this->lblResult->ForeColor = System::Drawing::Color::Black;
			this->lblResult->Location = System::Drawing::Point(12, 228);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(80, 19);
			this->lblResult->TabIndex = 7;
			this->lblResult->Text = L"���������:";
			this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lblResult->Click += gcnew System::EventHandler(this, &Form1::lblResult_Click);
			// 
			// txt2
			// 
			this->txt2->BackColor = System::Drawing::SystemColors::Control;
			this->txt2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->txt2->Location = System::Drawing::Point(120, 118);
			this->txt2->Name = L"txt2";
			this->txt2->Size = System::Drawing::Size(100, 23);
			this->txt2->TabIndex = 8;
			this->txt2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txt2->TextChanged += gcnew System::EventHandler(this, &Form1::txt2_TextChanged);
			// 
			// txtResult
			// 
			this->txtResult->BackColor = System::Drawing::SystemColors::Control;
			this->txtResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->txtResult->Location = System::Drawing::Point(120, 224);
			this->txtResult->Name = L"txtResult";
			this->txtResult->Size = System::Drawing::Size(100, 23);
			this->txtResult->TabIndex = 9;
			this->txtResult->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// btnNoAdd
			// 
			this->btnNoAdd->BackColor = System::Drawing::Color::Silver;
			this->btnNoAdd->FlatAppearance->BorderSize = 0;
			this->btnNoAdd->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnNoAdd->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnNoAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNoAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnNoAdd->ForeColor = System::Drawing::Color::Black;
			this->btnNoAdd->Location = System::Drawing::Point(226, 118);
			this->btnNoAdd->Name = L"btnNoAdd";
			this->btnNoAdd->Size = System::Drawing::Size(100, 100);
			this->btnNoAdd->TabIndex = 10;
			this->btnNoAdd->Text = L"-";
			this->btnNoAdd->UseVisualStyleBackColor = false;
			this->btnNoAdd->Click += gcnew System::EventHandler(this, &Form1::btnNoAdd_Click);
			// 
			// btnProd
			// 
			this->btnProd->BackColor = System::Drawing::Color::Silver;
			this->btnProd->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnProd->FlatAppearance->BorderSize = 0;
			this->btnProd->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnProd->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnProd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.5F, System::Drawing::FontStyle::Bold));
			this->btnProd->ForeColor = System::Drawing::Color::Black;
			this->btnProd->Location = System::Drawing::Point(226, 224);
			this->btnProd->Name = L"btnProd";
			this->btnProd->Size = System::Drawing::Size(100, 100);
			this->btnProd->TabIndex = 11;
			this->btnProd->Text = L"x";
			this->btnProd->UseVisualStyleBackColor = false;
			this->btnProd->Click += gcnew System::EventHandler(this, &Form1::btnProd_Click);
			// 
			// btnNoProd
			// 
			this->btnNoProd->BackColor = System::Drawing::Color::Silver;
			this->btnNoProd->FlatAppearance->BorderSize = 0;
			this->btnNoProd->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnNoProd->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), 
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnNoProd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNoProd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnNoProd->ForeColor = System::Drawing::Color::Black;
			this->btnNoProd->Location = System::Drawing::Point(226, 330);
			this->btnNoProd->Name = L"btnNoProd";
			this->btnNoProd->Size = System::Drawing::Size(100, 100);
			this->btnNoProd->TabIndex = 12;
			this->btnNoProd->Text = L":";
			this->btnNoProd->UseVisualStyleBackColor = false;
			this->btnNoProd->Click += gcnew System::EventHandler(this, &Form1::btnNoProd_Click);
			// 
			// lblWarning
			// 
			this->lblWarning->AutoSize = true;
			this->lblWarning->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblWarning->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblWarning->Location = System::Drawing::Point(12, 265);
			this->lblWarning->Name = L"lblWarning";
			this->lblWarning->Size = System::Drawing::Size(0, 19);
			this->lblWarning->TabIndex = 13;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(344, 465);
			this->Controls->Add(this->btnNoProd);
			this->Controls->Add(this->btnProd);
			this->Controls->Add(this->btnNoAdd);
			this->Controls->Add(this->txt1);
			this->Controls->Add(this->txtResult);
			this->Controls->Add(this->txt2);
			this->Controls->Add(this->lblResult);
			this->Controls->Add(this->lbl2);
			this->Controls->Add(this->lbl1);
			this->Controls->Add(this->lblOper);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->lblWarning);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"�����������";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->lblOper->Text = L"";
				 this->txt1->Text = L"";
				 this->txt2->Text = L"";
				 this->txtResult->Text = L"";
				 this->lblWarning->Text = L"";
			 }
private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			double  i1, i2, i3;
			if (txt1->Text->Length==0)
			   {this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}
			else {if (txt2->Text->Length==0)
			   {this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}};
			try {
			 double i1=Convert::ToDouble(txt1->Text);
			 double i2=Convert::ToDouble(txt2->Text);}
			catch(...){lblWarning->Text="������������ ����";
				return;};
			if ((txt1->Text->IndexOf(L",") == 0) || (txt2->Text->IndexOf(L",") == 0)) {lblWarning->Text="������������ ����";
				return;}
			if (((txt1->Text->IndexOf(L",") == txt1->Text->Length - 1))||(txt2->Text->IndexOf(L",") == txt2->Text->Length - 1)) {lblWarning->Text="������������ ����";
			return;}
			this->lblWarning->Text = L"";
			this->lblOper->Text=L"��������";
			  i1=Convert::ToDouble(txt1->Text);
			  i2=Convert::ToDouble(txt2->Text);
			  i3=i1 + i2;
			this->txtResult->Text = Convert::ToString(i3);


		 }
private: System::Void btnNoAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			 double  i1, i2, i3;
			if (txt1->Text->Length==0)
			{this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}
			else {if (txt2->Text->Length==0)
			   {this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}};
			try {
			 double i1=Convert::ToDouble(txt1->Text);
			 double i2=Convert::ToDouble(txt2->Text);}
			catch(...){lblWarning->Text="������������ ����";
				return;};
			if ((txt1->Text->IndexOf(L",") == 0) || (txt2->Text->IndexOf(L",") == 0)) {lblWarning->Text="������������ ����";
				return;}
			if (((txt1->Text->IndexOf(L",") == txt1->Text->Length - 1))||(txt2->Text->IndexOf(L",") == txt2->Text->Length - 1)) {lblWarning->Text="������������ ����";
			return;}
			this->lblWarning->Text = L"";
			this->lblOper->Text=L"���������";
			  i1=Convert::ToDouble(txt1->Text);
			  i2=Convert::ToDouble(txt2->Text);
			  i3=i1 - i2;
			this->txtResult->Text = Convert::ToString(i3);
		 }
private: System::Void btnProd_Click(System::Object^  sender, System::EventArgs^  e) {
			 double  i1, i2, i3;
			if (txt1->Text->Length==0)
			   {this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}
			else {if (txt2->Text->Length==0)
			   {this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}};
			try {
			 double i1=Convert::ToDouble(txt1->Text);
			 double i2=Convert::ToDouble(txt2->Text);}
			catch(...){lblWarning->Text="������������ ����";
				return;};
			if ((txt1->Text->IndexOf(L",") == 0) || (txt2->Text->IndexOf(L",") == 0)) {lblWarning->Text="������������ ����";
				return;}
			if (((txt1->Text->IndexOf(L",") == txt1->Text->Length - 1))||(txt2->Text->IndexOf(L",") == txt2->Text->Length - 1)) {lblWarning->Text="������������ ����";
			return;}
			this->lblWarning->Text = L"";
			this->lblOper->Text=L"���������";
			  i1=Convert::ToDouble(txt1->Text);
			  i2=Convert::ToDouble(txt2->Text);
			  i3=i1 * i2;
			this->txtResult->Text = Convert::ToString(i3);
		 }
private: System::Void btnNoProd_Click(System::Object^  sender, System::EventArgs^  e) {
			 double  i1, i2, i3;
			if (txt1->Text->Length==0)
			   {this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}
			else {if (txt2->Text->Length==0)
			   {this->lblWarning->Text="������!\n�� �� ����� ������ �����"; this->txtResult->Text = "";
			   return ;}};
			try {
			 double i1=Convert::ToDouble(txt1->Text);
			 double i2=Convert::ToDouble(txt2->Text);}
			catch(...){lblWarning->Text="������������ ����";
				return;};
			if ((txt1->Text->IndexOf(L",") == 0) || (txt2->Text->IndexOf(L",") == 0)) {lblWarning->Text="������������ ����";
				return;}
			if (((txt1->Text->IndexOf(L",") == txt1->Text->Length - 1))||(txt2->Text->IndexOf(L",") == txt2->Text->Length - 1)) {lblWarning->Text="������������ ����";
			return;}
			if (txt2->Text == L"0") {
				this->lblOper->Text=L"�������";
				txtResult->Text = L"";
				lblWarning->Text="������ �� 0 ������";
				return;
			}
			this->lblWarning->Text = L"";
			this->lblOper->Text=L"�������";
			  i1=Convert::ToDouble(txt1->Text);
			  i2=Convert::ToDouble(txt2->Text);
			  i3=i1 / i2;
			this->txtResult->Text = Convert::ToString(i3);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void txt1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 int i1 = txt1->Text->Length;
			 if (txt1->Text->IndexOf(L".") > -1) {
				   txt1->Text=txt1->Text->Replace(L".",L",");
				   txt1->SelectionStart = i1;
			 }
		 }
private: System::Void txt2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 int i1 = txt2->Text->Length;
			 if (txt2->Text->IndexOf(L".") > -1) {
				   txt2->Text=txt2->Text->Replace(L".",L",");
				   txt2->SelectionStart = i1;
			 }
		 }
private: System::Void lblResult_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbl2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void lbl1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
