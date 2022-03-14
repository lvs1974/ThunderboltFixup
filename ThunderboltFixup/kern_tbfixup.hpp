//
//  kern_tbfixup.hpp
//  ThunderboltFixup
//
//  Copyright © 2022 lvs1974. All rights reserved.
//

#ifndef kern_tbfixup_hpp
#define kern_tbfixup_hpp

#include <Headers/kern_patcher.hpp>
#include <stdatomic.h>
#include <IOKit/pci/IOPCIDevice.h>

class TBFixup {
public:
	bool init();
	void deinit();
	
private:
	/**
	 *  Patch kext if needed and prepare other patches
	 *
	 *  @param patcher KernelPatcher instance
	 *  @param index   kinfo handle
	 *  @param address kinfo load address
	 *  @param size    kinfo memory size
	 */
	void processKext(KernelPatcher &patcher, size_t index, mach_vm_address_t address, size_t size);

	/**
	 *  Hooked methods / callbacks
	 */
	
	static IOReturn AppleThunderboltNHIIntelPCI_earlySleep(void *that);
	
	static IOReturn AppleThunderboltGenericHAL_earlySleep(void *that);
	
	static IOReturn AppleThunderboltNHIType3_earlySleep(void *that);
	
	static IOReturn AppleThunderboltNHIIntelPCI_lateSleep(void *that);
	
	static IOReturn AppleThunderboltGenericHAL_lateSleep(void *that);
	
	static IOReturn AppleThunderboltNHI_lateSleep(void *that);
	
	static IOReturn AppleThunderboltNHI_lateSleepInternal(void *that);
	
	static IOReturn AppleThunderboltNHIType3_lateSleep(void *that);
	
	static IOReturn AppleThunderboltNHIIntelPCI_sleep(void *that);
	
	static IOReturn AppleThunderboltNHI_sleep(void *that);
	
	static IOReturn AppleThunderboltNHIType3_sleep(void *that);
	
	static IOReturn AppleThunderboltNHIIntelPCI_prePCIWake(void *that);
	
	static IOReturn AppleThunderboltGenericHAL_prePCIWake(void *that);
	
	static IOReturn AppleThunderboltNHI_prePCIWake(void *that);
	
	static IOReturn AppleThunderboltNHIType3_prePCIWake(void *that);
	
	static IOReturn AppleThunderboltNHIIntelPCI_earlyWake(void *that);
	
	static IOReturn AppleThunderboltGenericHAL_earlyWake(void *that);
	
	static IOReturn AppleThunderboltNHI_earlyWake(void *that);
	
	static IOReturn AppleThunderboltNHI_earlyWakeInternal(void *that);
	
	static IOReturn AppleThunderboltIntelPCIHAL_earlyWake(void *that);
	
	static IOReturn AppleThunderboltNHIType3_earlyWake(void *that);
	
	static IOReturn AppleThunderboltNHIIntelPCI_wake(void *that);
	
	static IOReturn AppleThunderboltNHI_wake(void *that);
	
	static IOReturn AppleThunderboltNHIType3_wake(void *that);
	
	/**
	 *  Original method
	 */
	mach_vm_address_t orgAppleThunderboltNHIIntelPCI_earlySleep {};
	mach_vm_address_t orgAppleThunderboltGenericHAL_earlySleep {};
	mach_vm_address_t orgAppleThunderboltNHIType3_earlySleep {};
	mach_vm_address_t orgAppleThunderboltNHIIntelPCI_lateSleep {};
	mach_vm_address_t orgAppleThunderboltGenericHAL_lateSleep {};
	mach_vm_address_t orgAppleThunderboltNHI_lateSleep {};
	mach_vm_address_t orgAppleThunderboltNHI_lateSleepInternal {};
	mach_vm_address_t orgAppleThunderboltNHIType3_lateSleep {};
	mach_vm_address_t orgAppleThunderboltNHIIntelPCI_sleep {};
	mach_vm_address_t orgAppleThunderboltNHI_sleep {};
	mach_vm_address_t orgAppleThunderboltNHIType3_sleep {};
	mach_vm_address_t orgAppleThunderboltNHIIntelPCI_prePCIWake {};
	mach_vm_address_t orgAppleThunderboltGenericHAL_prePCIWake {};
	mach_vm_address_t orgAppleThunderboltNHI_prePCIWake {};
	mach_vm_address_t orgAppleThunderboltNHIType3_prePCIWake {};
	mach_vm_address_t orgAppleThunderboltNHI_earlyWake {};
	mach_vm_address_t orgAppleThunderboltGenericHAL_earlyWake {};
	mach_vm_address_t orgAppleThunderboltNHI_earlyWakeInternal {};
	mach_vm_address_t orgAppleThunderboltNHIIntelPCI_earlyWake {};
	mach_vm_address_t orgAppleThunderboltIntelPCIHAL_earlyWake {};
	mach_vm_address_t orgAppleThunderboltNHIType3_earlyWake {};
	mach_vm_address_t orgAppleThunderboltNHIIntelPCI_wake {};
	mach_vm_address_t orgAppleThunderboltNHI_wake {};
	mach_vm_address_t orgAppleThunderboltNHIType3_wake {};
};

#endif /* kern_tbfixup_hpp */
