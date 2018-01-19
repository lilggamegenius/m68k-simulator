//
// Created by ggonz on 3/9/2017.
//

class M68KSimulator;

#pragma once

#if defined(_MSC_VER)
//  Microsoft
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC or CLANG
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
//  do nothing and hope for the best?
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

#define CEXPORT extern "C" EXPORT

#include <fstream>
#include "AddressSpace.hpp"

class M68KSimulator {
public:


	EXPORT static void init();

	EXPORT static int run(std::string path);

	EXPORT static int run(char path[]);

	//EXPORT static int run(FILE *file);

	EXPORT static int run(std::ifstream file);
};

