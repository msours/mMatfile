
#include "MatlabStruct.NET.h"
#include <msclr\marshal_cppstd.h>

namespace MathWorks
{
	namespace NET
	{
		MatlabStruct::MatlabStruct(int Rows, int Cols, array<System::String^>^ FieldNames)
		{
			this->FieldNames = FieldNames;
			this->Rows = Rows;
			this->Cols = Cols;

			std::vector<std::string> fieldNames;
			for (int k = 0; k < FieldNames->Length; k++)
			{
				System::String^ FieldName = FieldNames[k];
				fieldNames.push_back(msclr::interop::marshal_as<std::string>(FieldName));
			}

			this->MatlabStruct_ = new MathWorks::MatlabStruct(Rows, Cols, fieldNames);
		}
		MatlabStruct::~MatlabStruct()
		{
			this->MatlabStruct_->~MatlabStruct();
			delete this->MatlabStruct_;
		}
		void MatlabStruct::Add(CellArray^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);
			this->MatlabStruct_->Add(*Data->CellArray_, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(MatlabStruct^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);
			this->MatlabStruct_->Add(*Data->MatlabStruct_, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(System::String^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);
			const std::string &data = msclr::interop::marshal_as<std::string>(Data);

			this->MatlabStruct_->Add(data, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(double Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			this->MatlabStruct_->Add(Data, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(float Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			this->MatlabStruct_->Add(Data, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(int Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			this->MatlabStruct_->Add(Data, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(bool Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			this->MatlabStruct_->Add(Data, name, InsertRow, InsertCol);
		}

		void MatlabStruct::Add(array<double>^ Data, System::String^ FieldName, int InsertRow, int InsertCol) 
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<float>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<INT8>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<INT16>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<int>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<INT64>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT8>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT16>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT32>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT64>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			this->ReshapeAdd(Data, 1, Data->Length, 1, FieldName, InsertRow, InsertCol);
		}

		void MatlabStruct::Add(array<double, 2>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);

			std::vector<double> data;
			for (int k = 0; k < Cols; k++)
			{
				for (int j = 0; j < Rows; j++)
				{
					data.push_back((double)Data[j, k]);
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, 1, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<float, 2>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);

			std::vector<float> data;
			for (int k = 0; k < Cols; k++)
			{
				for (int j = 0; j < Rows; j++)
				{
					data.push_back((float)Data[j, k]);
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, 1, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT8, 2>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);

			std::vector<UINT8> data;
			for (int k = 0; k < Cols; k++)
			{
				for (int j = 0; j < Rows; j++)
				{
					data.push_back((UINT8)Data[j, k]);
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, 1, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT16, 2>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);

			std::vector<UINT16> data;
			for (int k = 0; k < Cols; k++)
			{
				for (int j = 0; j < Rows; j++)
				{
					data.push_back((UINT16)Data[j, k]);
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, 1, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<double, 3>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);
			const int Dim3 = Data->GetLength(2);

			std::vector<double> data;
			for (int p = 0; p < Dim3; p++)
			{
				for (int k = 0; k < Cols; k++)
				{
					for (int j = 0; j < Rows; j++)
					{
						data.push_back((double)Data[j, k, p]);
					}
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<float, 3>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);
			const int Dim3 = Data->GetLength(2);

			std::vector<float> data;
			for (int p = 0; p < Dim3; p++)
			{
				for (int k = 0; k < Cols; k++)
				{
					for (int j = 0; j < Rows; j++)
					{
						data.push_back((float)Data[j, k, p]);
					}
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT8, 3>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);
			const int Dim3 = Data->GetLength(2);

			std::vector<UINT8> data;
			for (int p = 0; p < Dim3; p++)
			{
				for (int k = 0; k < Cols; k++)
				{
					for (int j = 0; j < Rows; j++)
					{
						data.push_back((UINT8)Data[j, k, p]);
					}
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::Add(array<UINT16, 3>^ Data, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			const int Rows = Data->GetLength(0);
			const int Cols = Data->GetLength(1);
			const int Dim3 = Data->GetLength(2);

			std::vector<UINT16> data;
			for (int p = 0; p < Dim3; p++)
			{
				for (int k = 0; k < Cols; k++)
				{
					for (int j = 0; j < Rows; j++)
					{
						data.push_back((UINT16)Data[j, k, p]);
					}
				}
			}

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}

		void MatlabStruct::ReshapeAdd(array<double>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<double> data;
			for (int k = 0; k < Length; k++) data.push_back((double)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<float>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<float> data;
			for (int k = 0; k < Length; k++) data.push_back((float)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<INT8>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<INT8> data;
			for (int k = 0; k < Length; k++) data.push_back((INT8)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<INT16>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<INT16> data;
			for (int k = 0; k < Length; k++) data.push_back((INT16)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<INT32>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<INT32> data;
			for (int k = 0; k < Length; k++) data.push_back((INT32)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<INT64>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<INT64> data;
			for (int k = 0; k < Length; k++) data.push_back((INT64)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<UINT8>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<UINT8> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT8)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<UINT16>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<UINT16> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT16)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<UINT32>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<UINT32> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT32)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
		void MatlabStruct::ReshapeAdd(array<UINT64>^ Data, int Rows, int Cols, int Dim3, System::String^ FieldName, int InsertRow, int InsertCol)
		{
			const std::string &name = msclr::interop::marshal_as<std::string>(FieldName);

			int Length = Rows * Cols * Dim3;

			std::vector<UINT32> data;
			for (int k = 0; k < Length; k++) data.push_back((UINT32)Data[k]);

			this->MatlabStruct_->ReshapeAdd(data, Rows, Cols, Dim3, name, InsertRow, InsertCol);
		}
	}
}