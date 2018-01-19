//
// Created by ggonz on 3/9/2017.
//

#include <array>
#include <iostream>
#include <cstring>
#include "Rom.hpp"

RomMap *Rom::rom = (RomMap *) malloc(romSize);

void Rom::setRom(std::ifstream file){
	init();
	if(file){   // Opened
		// get length of file:
		file.seekg(0, file.end);
		long length = file.tellg();
		file.seekg(0, file.beg);
		if(length > romSize) throw std::overflow_error("File is larger than max rom size");
		file.read(reinterpret_cast<char *>(rom->s8), length);
		if(file){
			std::cout << "Filled buffer" << std::endl;
		} else{
			fill();
			std::cout << "File read failed, read \"" << file.gcount() << "\" bytes" << std::endl;
		}
	} else{     // Error
		std::cout << "Error opening file" << std::endl;
	}
}

void Rom::init(){
	//*rom = RomMap();
	fill();
}

void Rom::fill(){
	memset(rom->u32, 0, sizeof(rom->u32));
}