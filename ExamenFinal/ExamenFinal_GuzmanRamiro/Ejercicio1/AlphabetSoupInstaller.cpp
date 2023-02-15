#include "AlphabetSoupInstaller.h"



//string AlphabetSoupInstaller::openFileText(string path)
//{
//	string code;
//	const int buffer_size = 248;
//	char line[buffer_size];
//
//	try
//	{
//		ifstream inputStream = ifstream();
//
//		inputStream.open(path);
//
//		if (!inputStream.good())
//			throw ios::failure(" El archivo no se pudo abrir correctamente");
//
//
//		while (!inputStream.eof())
//		{
//			inputStream >> line;
//			code += (string)line + " ";
//		}
//
//		inputStream.close();
//
//		if (inputStream.is_open())
//			throw ios::failure("El archivo no se cerro correctamente!");
//
//		return code;
//	}
//
//	catch (const ios::failure& e)
//	{
//		cout << "Hubo problemas con la interaccion con el archivo, " << e.what() << endl;
//	}