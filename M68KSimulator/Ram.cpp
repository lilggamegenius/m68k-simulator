//
// Created by ggonz on 3/9/2017.
//

#include <memory>
#include "Ram.hpp"
#include "AddressTypes/RamAddress.hpp"

RamMap* Ram::memory = (RamMap*)malloc(ramSize);

Address *Ram::operator[](M68kAddr address){
	return new RamAddress(address);
}
