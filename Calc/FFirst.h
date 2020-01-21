#pragma once

namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	int x1;     // Вспомогательная переменная (имеется ли минус в строке)
	double x3;  // Вводимое действительное число
	char ds;    // Символ десятичного разделителя

	// Функция защиты от дурака
	void Durak(System::Windows::Forms::TextBox^ txt, System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		// Если нажатая клавиша не цифровая.
		if (!Char::IsDigit(e->KeyChar))
			// Запрет на ввод более одного знака минуса.
			if (e->KeyChar != '-' || txt->Text->IndexOf('-') != -1)
			// Запрет на ввод более одного десятичного разделителя.
			if (e->KeyChar != ds || txt->Text->IndexOf(ds) != -1)
				// Если нажатая клавиша не является клавишей BackSpace.
				if (e->KeyChar != (char)Keys::Back)
					e->Handled = true;          // Запрет ввода

		// Запрет ввода повторных нулей в начале числа.
		if (e->KeyChar == (char)Keys::D0 ||
			e->KeyChar == (char)Keys::NumPad0)  // Если нажата клавиша 0
			if (txt->Text->Length >= 1)        // Если строка не пустая
			if (txt->Text[0] == '0' && txt->SelectionStart < 2)
				e->Handled = true;             // Запрет ввода

		// Замена десятичного разделителя в начале числа на "0,".
		if (e->KeyChar == ds) {    // Если введен десятичный разделитель
			x1 = 0;
			if (txt->Text != "" && txt->Text[0] == '-') { x1 = 1; }
			if (txt->Text->IndexOf(ds) == -1 &&
				txt->SelectionStart == x1) {
			// Если десятичный разделитель уже есть, то 0 вставлять не нужно
			txt->Text = txt->Text->Insert(x1, "0");  // Вставка 0
			txt->SelectionStart = x1 + 1;  // Текстовый курсор в конец
			}
		}

		// Перенос точки ввода минуса в начало (ввод минуса только спереди)
		if (e->KeyChar == '-' && txt->Text->IndexOf('-') == -1)
			txt->SelectionStart = 0;         // Текстовый курсор в начало

		// Запрет на ввод перед знаком минуса
		if (txt->Text->Length > 0)        // Если строка не пустая
		if (txt->Text[0] == '-' && txt->SelectionStart < 1) // Если в начале строки минус
			e->Handled = true;

		// Замена ввода первого нуля на '0,', если строка не нулевая
		if (e->KeyChar == (char)Keys::D0 ||
			e->KeyChar == (char)Keys::NumPad0) // если нажата 0
		// если строка не нулевая, курсор впереди, и нет разделителя
		if (txt->Text->Length > 0 && txt->SelectionStart == 0 && txt->Text->IndexOf('-') == -1)
		{
			if (txt->Text[0] != ds)
			{
				if (txt->Text->IndexOf(ds) != -1) // если уже есть десятичный разделитель
				{
					e->Handled = true; // запрещаем ввод
				}
				else // если десятичного разделителя нет
				{
					x1 = 0;
					e->KeyChar = ds; // меняем текущий вводимый символ на знак разделителя
					txt->Text = txt->Text->Insert(x1, "0"); // добавляем слева 0
					txt->SelectionStart = x1 + 1; // переводим курсор вперёд
				}
			}
		}

		// Запрет ввода на '0,' первого нуля, если впереди минус
		if (e->KeyChar == (char)Keys::D0 ||
			e->KeyChar == (char)Keys::NumPad0) // Если введён нуль
		if (txt->Text->Length > 1 && txt->SelectionStart == 1
			&& Char::IsDigit(txt->Text[1]) && txt->Text->IndexOf('-') != -1)
		{
			if (txt->Text[0] != ds)
			{
				if (txt->Text->IndexOf(ds) != -1) // если уже есть десятичный разделитель
				{
					e->Handled = true; // запрещаем ввод
				}
				else // если десятичного разделителя нет
				{
					x1 = 0;
					e->KeyChar = ds; // меняем текущий вводимый символ на знак разделителя
					txt->Text = txt->Text->Insert(x1+1, "0"); // добавляем слева 0
					txt->SelectionStart = x1 + 2; // переводим курсор вперёд
				}
			}
		}

		// Замена первого нуля на вводимую цифру, если дальше нет разделителя
		if ((txt->Text->Length > 0 && txt->Text[0] == '0') // если длина строки 1, и впереди "0"
			&& Char::IsDigit(e->KeyChar)
			&& txt->SelectionStart == 1)
		{
			if (e->KeyChar != '0') // если нажата не 0
			{
				txt->Text = txt->Text->Remove(0,1); // Удаление нуля в начале
				txt->SelectionStart = 0; // Перевод курсора в начало
			}
			else // если нажата 0
			{
				e->Handled = true; // запрещаем ввод
			}
		}

		// Запрет ввода повторного ввода нуля после минуса
		if (txt->Text->Length > 1 && txt->Text[0] == '-'
			&& txt->Text[1] == '0' && Char::IsDigit(e->KeyChar)
			&& txt->SelectionStart == 2 && txt->Text[1] != ds) // если длина строки 2, и впереди "-0"
		{
			if (e->KeyChar != '0') // если нажата не 0
			{
				txt->Text = txt->Text->Remove(1,1); // Удаление нуля после минуса
				txt->SelectionStart = 1; // Первод курсора на 1 позицию
			}
			else // если нажата 0
			{
				e->Handled = true; // запрещаем ввод
			}
		}

		// Запрет на ввод незначащих нулей после запятой
		if (e->KeyChar == (char)Keys::D0 ||
			e->KeyChar == (char)Keys::NumPad0) // если введён 0
		// если строка ненулевая, есть знак разделителя и курсор стоит в начале
		if (txt->Text->Length > 1 && txt->Text->IndexOf(ds) != -1 && txt->SelectionStart == txt->Text->Length)
		// если перед курсором стоит цифра, и эта цифра не 0
		if (Char::IsDigit(txt->Text[txt->Text->Length-1]) && txt->Text[txt->Text->Length-1] != '0')
		{
			e->Handled = true; // запрещаем ввод
		}


	}

	//Функция постобработки строки для проверки на корректность вводимого значения
	bool IsTrueNumber(String^ txt)
	{
		bool boolStr = true; // Строки корректные по умолчанию
		if (txt->Length == 1 && txt[0] == '-') // Если встречен единственный минус
		{
			boolStr = false; // Выдать ошибку
		}
		else if (txt[0] == '-' && txt[1] == ds) // Если встречен '-,'
		{
			boolStr = false; // Выдать ошибку
		}
		else if (txt[0] == ds || txt[txt->Length-1] == ds) // Если встречен разделитель вначале или конце
		{
			boolStr = false; // Выдать ошибку
		}
		return boolStr; // Вернуть ошибку или продолжить работу
	}

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Label^  lblOper;
	private: System::Windows::Forms::Label^  lbl1;
	private: System::Windows::Forms::Label^  lbl2;
	private: System::Windows::Forms::Label^  lblResult;
	private: System::Windows::Forms::TextBox^  txt1;
	private: System::Windows::Forms::TextBox^  txt2;
	private: System::Windows::Forms::TextBox^  txtResult;
	private: System::Windows::Forms::Button^  btnDifference;
	private: System::Windows::Forms::Button^  btnMultiplication;
	private: System::Windows::Forms::Button^  btnDivision;
	private: System::Windows::Forms::Label^  lblError;

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lblOper = (gcnew System::Windows::Forms::Label());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->lbl2 = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->txt1 = (gcnew System::Windows::Forms::TextBox());
			this->txt2 = (gcnew System::Windows::Forms::TextBox());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->btnDifference = (gcnew System::Windows::Forms::Button());
			this->btnMultiplication = (gcnew System::Windows::Forms::Button());
			this->btnDivision = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(320, 228);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(133, 37);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"Закрыть";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Form1::btnClose_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(320, 12);
			this->btnAdd->Margin = System::Windows::Forms::Padding(4);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(133, 37);
			this->btnAdd->TabIndex = 1;
			this->btnAdd->Text = L"Сложить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAdd_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(320, 185);
			this->btnReset->Margin = System::Windows::Forms::Padding(4);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(133, 37);
			this->btnReset->TabIndex = 2;
			this->btnReset->Text = L"Сброс";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &Form1::btnReset_Click);
			// 
			// lblOper
			// 
			this->lblOper->AutoSize = true;
			this->lblOper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblOper->Location = System::Drawing::Point(147, 12);
			this->lblOper->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblOper->Name = L"lblOper";
			this->lblOper->Size = System::Drawing::Size(0, 20);
			this->lblOper->TabIndex = 3;
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lbl1->Location = System::Drawing::Point(13, 74);
			this->lbl1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(104, 17);
			this->lbl1->TabIndex = 4;
			this->lbl1->Text = L"Первое число:";
			this->lbl1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbl2
			// 
			this->lbl2->AutoSize = true;
			this->lbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lbl2->Location = System::Drawing::Point(13, 111);
			this->lbl2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl2->Name = L"lbl2";
			this->lbl2->Size = System::Drawing::Size(103, 17);
			this->lbl2->TabIndex = 5;
			this->lbl2->Text = L"Второе число:";
			this->lbl2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblResult->Location = System::Drawing::Point(13, 148);
			this->lblResult->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(80, 17);
			this->lblResult->TabIndex = 6;
			this->lblResult->Text = L"Результат:";
			this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txt1
			// 
			this->txt1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->txt1->Location = System::Drawing::Point(147, 74);
			this->txt1->Margin = System::Windows::Forms::Padding(4);
			this->txt1->Name = L"txt1";
			this->txt1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->txt1->Size = System::Drawing::Size(119, 23);
			this->txt1->TabIndex = 7;
			this->txt1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txt1->WordWrap = false;
			this->txt1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txt1_KeyPress);
			this->txt1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::txt1_MouseDown);
			// 
			// txt2
			// 
			this->txt2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->txt2->Location = System::Drawing::Point(147, 111);
			this->txt2->Margin = System::Windows::Forms::Padding(4);
			this->txt2->Name = L"txt2";
			this->txt2->Size = System::Drawing::Size(119, 23);
			this->txt2->TabIndex = 8;
			this->txt2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txt2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txt2_KeyPress);
			// 
			// txtResult
			// 
			this->txtResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->txtResult->Location = System::Drawing::Point(147, 148);
			this->txtResult->Margin = System::Windows::Forms::Padding(4);
			this->txtResult->Name = L"txtResult";
			this->txtResult->ReadOnly = true;
			this->txtResult->Size = System::Drawing::Size(119, 23);
			this->txtResult->TabIndex = 9;
			this->txtResult->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// btnDifference
			// 
			this->btnDifference->Location = System::Drawing::Point(320, 54);
			this->btnDifference->Margin = System::Windows::Forms::Padding(4);
			this->btnDifference->Name = L"btnDifference";
			this->btnDifference->Size = System::Drawing::Size(133, 37);
			this->btnDifference->TabIndex = 10;
			this->btnDifference->Text = L"Вычесть";
			this->btnDifference->UseVisualStyleBackColor = true;
			this->btnDifference->Click += gcnew System::EventHandler(this, &Form1::btnDifference_Click);
			// 
			// btnMultiplication
			// 
			this->btnMultiplication->Location = System::Drawing::Point(320, 96);
			this->btnMultiplication->Margin = System::Windows::Forms::Padding(4);
			this->btnMultiplication->Name = L"btnMultiplication";
			this->btnMultiplication->Size = System::Drawing::Size(133, 37);
			this->btnMultiplication->TabIndex = 11;
			this->btnMultiplication->Text = L"Умножить";
			this->btnMultiplication->UseVisualStyleBackColor = true;
			this->btnMultiplication->Click += gcnew System::EventHandler(this, &Form1::btnMultiplication_Click);
			// 
			// btnDivision
			// 
			this->btnDivision->Location = System::Drawing::Point(320, 140);
			this->btnDivision->Margin = System::Windows::Forms::Padding(4);
			this->btnDivision->Name = L"btnDivision";
			this->btnDivision->Size = System::Drawing::Size(133, 37);
			this->btnDivision->TabIndex = 12;
			this->btnDivision->Text = L"Разделить";
			this->btnDivision->UseVisualStyleBackColor = true;
			this->btnDivision->Click += gcnew System::EventHandler(this, &Form1::btnDivision_Click);
			// 
			// lblError
			// 
			this->lblError->AutoSize = true;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblError->ForeColor = System::Drawing::Color::Red;
			this->lblError->Location = System::Drawing::Point(36, 215);
			this->lblError->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(0, 20);
			this->lblError->TabIndex = 13;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 284);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->btnDivision);
			this->Controls->Add(this->btnMultiplication);
			this->Controls->Add(this->btnDifference);
			this->Controls->Add(this->txtResult);
			this->Controls->Add(this->txt2);
			this->Controls->Add(this->txt1);
			this->Controls->Add(this->lblResult);
			this->Controls->Add(this->lbl2);
			this->Controls->Add(this->lbl1);
			this->Controls->Add(this->lblOper);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnClose);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Calc";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		// Определение десятичного разделителя (точки или запятой)
		// из региональных настроек.
		NumberFormatInfo^ nfi = NumberFormatInfo::CurrentInfo;
		ds = (char)nfi->NumberDecimalSeparator[0];
	}

	// Организация ввода в txt1 только действительных чисел.
	// Фильтрация вводимых с клавиатуры действительных чисел.
	private: System::Void txt1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		Durak(txt1, sender, e); // Вызов функции для защиты от дурака
	}

	// Организация ввода в txt2 только действительных чисел.
	// Фильтрация вводимых с клавиатуры действительных чисел.
	private: System::Void txt2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		Durak(txt2, sender, e); // Вызов функции для защиты от дурака
	}

	// Обработка кнопки "Закрыть"
	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close(); // Закрытие окна
	}

	// Обработка кнопки "Сложить"
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		if (txt1->Text->Length > 0 && txt2->Text->Length > 0) // провяем, пустые ли поля TextBox
		{
			if (IsTrueNumber(txt1->Text) == true && IsTrueNumber(txt2->Text) == true) // Если строки корректные
			{
				double i1, i2, i3; // Объявляем переменные для ввода и вывода
				i1 = Convert::ToDouble(txt1->Text); // Конвертируем первое значение
				i2 = Convert::ToDouble(txt2->Text); // Конвертируем второе значение
				i3 = i1 + i2; // Складываем i1 и i2 и присваиваем рез-ат i3

				this->lblOper->Text = L"Сложение"; // Показываем в label`е текущую операцию
				this->txtResult->Text = Convert::ToString(i3); // Конвертируем результат в String
				this->lblError->Text = L""; // Обнуляем Label ошибки
			}
			else
			{
				lblError->Text = "Введено некорректное\nзначение"; // Выводим в lblError сообщение об ошибке
			}
		}
		else // если строки не пустые
		{
			lblError->Text = "Одно из текстовых\nполей пустое!"; // Выводим в lblError сообщение об ошибке
		}
	}

	// Обработка кнопки "Вычесть"
	private: System::Void btnDifference_Click(System::Object^  sender, System::EventArgs^  e) {
		if (txt1->Text->Length > 0 && txt2->Text->Length > 0) // провяем, пустые ли поля TextBox
		{
			if (IsTrueNumber(txt1->Text) == true && IsTrueNumber(txt2->Text) == true) // Если строки корректные
			{
				double i1, i2, i3; // Объявляем переменные для ввода и вывода
				i1 = Convert::ToDouble(txt1->Text); // Конвертируем первое значение
				i2 = Convert::ToDouble(txt2->Text); // Конвертируем второе значение
				i3 = i1 - i2; // Вычитаем i2 из i1 и присваиваем рез-ат i3

				this->lblOper->Text = L"Вычитание";
				this->txtResult->Text = Convert::ToString(i3); // Конвертируем результат в String
				this->lblError->Text = L""; // Обнуляем Label ошибки
			}
			else
			{
				lblError->Text = "Введено некорректное\nзначение"; // Выводим в lblError сообщение об ошибке
			}
		}
		else // если строки не пустые
		{
			lblError->Text = "Одно из текстовых\nполей пустое!"; // Выводим в lblError сообщение об ошибке
		}
	}

	// Обработка кнопки "Умножить"
	private: System::Void btnMultiplication_Click(System::Object^  sender, System::EventArgs^  e) {
		if (txt1->Text->Length > 0 && txt2->Text->Length > 0) // провяем, пустые ли поля TextBox
		{
			if (IsTrueNumber(txt1->Text) == true && IsTrueNumber(txt2->Text) == true) // Если строки корректные
			{
				double i1, i2, i3; // Объявляем переменные для ввода и вывода
				i1 = Convert::ToDouble(txt1->Text); // Конвертируем первое значение
				i2 = Convert::ToDouble(txt2->Text); // Конвертируем второе значение
				i3 = i1 * i2; // Перемножаем i1 и i2 и присваиваем рез-ат i3

				this->lblOper->Text = L"Умножение"; // Показываем в label`е текущую операцию
				this->txtResult->Text = Convert::ToString(i3); // Конвертируем результат в String
				this->lblError->Text = L""; // Обнуляем Label ошибки
			}
			else
			{
				lblError->Text = "Введено некорректное\nзначение"; // Выводим в lblError сообщение об ошибке
			}
		}
		else // если строки не пустые
		{
			lblError->Text = "Одно из текстовых\nполей пустое!"; // Выводим в lblError сообщение об ошибке
		}
		}

	// Обработка кнопки "Разделить"
	private: System::Void btnDivision_Click(System::Object^  sender, System::EventArgs^  e) {
		if (txt1->Text->Length > 0 && txt2->Text->Length > 0) // провяем, пустые ли поля TextBox
		{
			if (IsTrueNumber(txt1->Text) == true && IsTrueNumber(txt2->Text) == true) // Если строки корректные
			{
				double i1, i2, i3; // Объявляем переменные для ввода и вывода
				i1 = Convert::ToDouble(txt1->Text); // Конвертируем первое значение
				i2 = Convert::ToDouble(txt2->Text); // Конвертируем второе значение
				this->lblOper->Text = L"Деление"; // Показываем в label`е текущую операцию
				if (i2 == 0) // проверяем, является ли делитель нулём
				{
					this->lblError->Text = L"На ноль делить нельзя!"; // Выводим в lblError сообщение об ошибке
					this->txtResult->Text = L""; // Обнуляем Label результата
				}
				else
				{
					i3 = i1/i2; // Делим i1 на i2 и записываем рез-ат в i3
					this->txtResult->Text = Convert::ToString(i3); // Конвертируем результат в String
					this->lblError->Text = L""; // Обнуляем Label ошибки
				}
			}
			else
			{
				lblError->Text = "Введено некорректное\nзначение"; // Выводим в lblError сообщение об ошибке
			}
		}
		else // если строки не пустые
		{
			lblError->Text = "Одно из текстовых\nполей пустое!"; // Выводим в lblError сообщение об ошибке
		}
	}

	// Обработка кнопки "Сброс"
	private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
		this->lblOper->Text = L""; // Обнуляем Label текущей операции
		this->txt1->Text = L""; // Обнуляем TextBox первого значения
		this->txt2->Text = L""; // Обнуляем TextBox второго значения
		this->txtResult-> Text = L""; // Обнуляем TextBox результата
		this->lblError->Text = L""; // Обнуляем Label ошибки
	}

	private: System::Void txt1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	}

};
}

