//
// Created by lil-g on 10/18/17.
//

#include "Address.hpp"

void Address::checkForOddAddress(){
	if(addr % 2) throw AddressException("Tried to write to address " + std::to_string(addr));
}
