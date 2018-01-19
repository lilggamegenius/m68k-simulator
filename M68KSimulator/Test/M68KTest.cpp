#include <unicorn/unicorn.h>
#include <iostream>
#include "../Rom.hpp"
#include "../Ram.hpp"

template<typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
constexpr T align4k(T val){
	T aligned = 0;
	for(;aligned <= val;aligned += 0x4000);
	return aligned;
}

const uint32_t ramAddress = 0xFFFF0000u, romAddress = 0,
		ramSizeAligned = ramSize, romSizeAligned = romSize;
const uint8_t instructions[] = {
		0x13,
		0xFC,
		0x00,
		0xFF,
		0xFF,
		0xFF,
		0x00,
		0x00
};


int main(int argc, char *argv[], char *envp[]){
	uc_engine *uc;
	uc_err err;

	uint32_t d0 = 0;

	std::cout << "Emulating M68K" << std::endl;
	err = uc_open(UC_ARCH_M68K, UC_MODE_BIG_ENDIAN, &uc);
	if(err){
		std::cerr << "Failed on uc_open() with error returned: " << err << ": " << uc_strerror(err) << std::endl;
		return err;
	}

	err = uc_mem_map_ptr(uc, ramAddress, ramSizeAligned, UC_PROT_ALL, Ram::memory);
	if(err){
		std::cerr << "Failed to map ram: " << err << ": " << uc_strerror(err) << std::endl;
		return err;
	}
	err = uc_mem_map_ptr(uc, romAddress, romSizeAligned, UC_PROT_ALL, Rom::rom);
	if(err){
		std::cerr << "Failed to map rom: " << err << ": " << uc_strerror(err) << std::endl;
		return err;
	}
	uc_mem_region *regions;
	uint32_t count;
	uc_mem_regions(uc, &regions, &count);
	for(int i = 0;i < count;i++){
		uint64_t begin = regions[i].begin, end = regions[i].end;
		std::cout << "Memory Region " << i << ": Size: " << std::hex << std::uppercase
		          << end - begin << " Range: " << regions[i].begin << " - " << regions[i].end
		          << std::dec << std::nouppercase << " with permissions: ";
		if(regions[i].perms == UC_PROT_ALL){
			std::cout << "All" << std::endl;
		} else if(regions[i].perms == UC_PROT_READ){
			std::cout << "Read" << std::endl;
		} else if(regions[i].perms == UC_PROT_WRITE){
			std::cout << "Write" << std::endl;
		} else if(regions[i].perms == UC_PROT_EXEC){
			std::cout << "Exec" << std::endl;
		} else{
			std::cout << "None" << std::endl;
		}
	}

	// write machine code to be emulated to memory
	err = uc_mem_write(uc, romAddress, instructions, sizeof(instructions));
	if(err){
		std::cerr << "Failed to write emulation code to memory, quit! " << err << ": " << uc_strerror(err) << std::endl;
		return err;
	}
	// initialize machine registers
	uc_reg_write(uc, UC_M68K_REG_D0, &d0);

	// emulate code in infinite time & unlimited instructions
	err = uc_emu_start(uc, romAddress, romAddress + sizeof(instructions), 0, 0);
	if(err){
		std::cerr << "Failed on uc_emu_start() with error returned " << err << ": " << uc_strerror(err) << std::endl;
		return err;
	}

	// now print out some registers
	std::cout << "Emulation done. Below is the CPU context" << std::endl;

	uc_reg_read(uc, UC_M68K_REG_D0, &d0);
	std::cout << ">>> d0 = " << std::hex << d0 << std::endl;

	uc_close(uc);

	return 0;
}