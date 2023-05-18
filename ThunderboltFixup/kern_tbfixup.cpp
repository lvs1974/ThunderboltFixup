//
//  kern_trimdisabler.cpp
//  ThunderboltFixup
//
//  Copyright © 2022 lvs1974. All rights reserved.
//

#include <Headers/kern_api.hpp>
#include <Headers/kern_util.hpp>

#include "kern_tbfixup.hpp"

static TBFixup *callbackTBFIXUP = nullptr;

static const char *kextPathThunderbolt[] { "/System/Library/Extensions/AppleThunderboltNHI.kext/Contents/MacOS/AppleThunderboltNHI" };

static KernelPatcher::KextInfo kextList { "com.apple.driver.AppleThunderboltNHI", kextPathThunderbolt, 1, {true}, {}, KernelPatcher::KextInfo::Unloaded };

bool TBFixup::init()
{
	callbackTBFIXUP = this;

	lilu.onKextLoadForce(&kextList, 1,
	[](void *user, KernelPatcher &patcher, size_t index, mach_vm_address_t address, size_t size) {
		callbackTBFIXUP->processKext(patcher, index, address, size);
	}, this);

	return true;
}

void TBFixup::deinit()
{
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_earlySleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::earlySleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIIntelPCI::earlySleep is called");
		result = FunctionCast(AppleThunderboltNHIIntelPCI_earlySleep, callbackTBFIXUP->orgAppleThunderboltNHIIntelPCI_earlySleep)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_earlySleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::earlySleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltGenericHAL::earlySleep is called");
		result = FunctionCast(AppleThunderboltGenericHAL_earlySleep, callbackTBFIXUP->orgAppleThunderboltGenericHAL_earlySleep)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHIType3_earlySleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::earlySleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIType3::earlySleep is called");
		result = FunctionCast(AppleThunderboltNHIType3_earlySleep, callbackTBFIXUP->orgAppleThunderboltNHIType3_earlySleep)(that);
		initial = false;
	}
	return result;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::lateSleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIIntelPCI::lateSleep is called");
		result = FunctionCast(AppleThunderboltNHIIntelPCI_lateSleep, callbackTBFIXUP->orgAppleThunderboltNHIIntelPCI_lateSleep)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::lateSleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltGenericHAL::lateSleep is called");
		result = FunctionCast(AppleThunderboltGenericHAL_lateSleep, callbackTBFIXUP->orgAppleThunderboltGenericHAL_lateSleep)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::lateSleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHI::lateSleep is called");
		result = FunctionCast(AppleThunderboltNHI_lateSleep, callbackTBFIXUP->orgAppleThunderboltNHI_lateSleep)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_lateSleepInternal(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::lateSleepInternal is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHI::lateSleepInternal is called");
		result = FunctionCast(AppleThunderboltNHI_lateSleepInternal, callbackTBFIXUP->orgAppleThunderboltNHI_lateSleepInternal)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHIType3_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType::lateSleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIType::lateSleep is called");
		result = FunctionCast(AppleThunderboltNHIType3_lateSleep, callbackTBFIXUP->orgAppleThunderboltNHIType3_lateSleep)(that);
		initial = false;
	}
	return result;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_sleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::sleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIIntelPCI::sleep is called");
		result = FunctionCast(AppleThunderboltNHIIntelPCI_sleep, callbackTBFIXUP->orgAppleThunderboltNHIIntelPCI_sleep)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_sleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::sleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHI::sleep is called");
		result = FunctionCast(AppleThunderboltNHI_sleep, callbackTBFIXUP->orgAppleThunderboltNHI_sleep)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHIType3_sleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::sleep is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIType3::sleep is called");
		result = FunctionCast(AppleThunderboltNHIType3_sleep, callbackTBFIXUP->orgAppleThunderboltNHIType3_sleep)(that);
		initial = false;
	}
	return result;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_prePCIWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::prePCIWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIIntelPCI::prePCIWake is called");
		result = FunctionCast(AppleThunderboltNHIIntelPCI_prePCIWake, callbackTBFIXUP->orgAppleThunderboltNHIIntelPCI_prePCIWake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_prePCIWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::prePCIWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltGenericHAL::prePCIWake is called");
		result = FunctionCast(AppleThunderboltGenericHAL_prePCIWake, callbackTBFIXUP->orgAppleThunderboltGenericHAL_prePCIWake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_prePCIWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::prePCIWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHI::prePCIWake is called");
		result = FunctionCast(AppleThunderboltNHI_prePCIWake, callbackTBFIXUP->orgAppleThunderboltNHI_prePCIWake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHIType3_prePCIWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::prePCIWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIType3::prePCIWake is called");
		result = FunctionCast(AppleThunderboltNHIType3_prePCIWake, callbackTBFIXUP->orgAppleThunderboltNHIType3_prePCIWake)(that);
		initial = false;
	}
	return result;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::earlyWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIIntelPCI::earlyWake is called");
		result = FunctionCast(AppleThunderboltNHIIntelPCI_earlyWake, callbackTBFIXUP->orgAppleThunderboltNHIIntelPCI_earlyWake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::earlyWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltGenericHAL::earlyWake is called");
		result = FunctionCast(AppleThunderboltGenericHAL_earlyWake, callbackTBFIXUP->orgAppleThunderboltGenericHAL_earlyWake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::earlyWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHI::earlyWake is called");
		result = FunctionCast(AppleThunderboltNHI_earlyWake, callbackTBFIXUP->orgAppleThunderboltNHI_earlyWake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_earlyWakeInternal(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::earlyWakeInternal is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHI::earlyWakeInternalis called");
		result = FunctionCast(AppleThunderboltNHI_earlyWakeInternal, callbackTBFIXUP->orgAppleThunderboltNHI_earlyWakeInternal)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltIntelPCIHAL_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltIntelPCIHAL::earlyWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltIntelPCIHAL::earlyWake is called");
		result = FunctionCast(AppleThunderboltIntelPCIHAL_earlyWake, callbackTBFIXUP->orgAppleThunderboltIntelPCIHAL_earlyWake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHIType3_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::earlyWake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIType3::earlyWake called");
		result = FunctionCast(AppleThunderboltNHIType3_earlyWake, callbackTBFIXUP->orgAppleThunderboltNHIType3_earlyWake)(that);
		initial = false;
	}
	return result;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_wake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::wake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIIntelPCI::wake called");
		result = FunctionCast(AppleThunderboltNHIIntelPCI_wake, callbackTBFIXUP->orgAppleThunderboltNHIIntelPCI_wake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_wake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::wake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHI::wake called");
		result = FunctionCast(AppleThunderboltNHI_wake, callbackTBFIXUP->orgAppleThunderboltNHI_wake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHIType3_wake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::wake is called");
	IOReturn result = KERN_SUCCESS;
	static bool initial = true;
	if (initial)
	{
		DBGLOG("TBFIXUP", "Original method AppleThunderboltNHIType3::wake called");
		result = FunctionCast(AppleThunderboltNHIType3_wake, callbackTBFIXUP->orgAppleThunderboltNHIType3_wake)(that);
		initial = false;
	}
	return result;
}

IOReturn TBFixup::AppleThunderboltNHI_resetNHI(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::resetNHI is called");
	return KERN_SUCCESS;
}

//==============================================================================

void TBFixup::processKext(KernelPatcher &patcher, size_t index, mach_vm_address_t address, size_t size)
{
	if (kextList.loadIndex == index) {
		DBGLOG("TBFIXUP", "%s", kextList.id);
		
		KernelPatcher::RouteRequest requests[] {
			{"__ZN26AppleThunderboltGenericHAL10earlySleepEv", AppleThunderboltGenericHAL_earlySleep, orgAppleThunderboltGenericHAL_earlySleep},
			{"__ZN26AppleThunderboltGenericHAL9lateSleepEv", AppleThunderboltGenericHAL_lateSleep, orgAppleThunderboltGenericHAL_lateSleep},
			{"__ZN26AppleThunderboltGenericHAL10prePCIWakeEv", AppleThunderboltGenericHAL_prePCIWake, orgAppleThunderboltGenericHAL_prePCIWake},
			{"__ZN26AppleThunderboltGenericHAL9earlyWakeEv", AppleThunderboltGenericHAL_earlyWake, orgAppleThunderboltGenericHAL_earlyWake},
			
			{"__ZN27AppleThunderboltIntelPCIHAL9earlyWakeEv", AppleThunderboltIntelPCIHAL_earlyWake, orgAppleThunderboltIntelPCIHAL_earlyWake},
			{"__ZN27AppleThunderboltNHIIntelPCI10earlySleepEv", AppleThunderboltNHIIntelPCI_earlySleep, orgAppleThunderboltNHIIntelPCI_earlySleep},
			{"__ZN27AppleThunderboltNHIIntelPCI9lateSleepEv", AppleThunderboltNHIIntelPCI_lateSleep, orgAppleThunderboltNHIIntelPCI_lateSleep},
			{"__ZN27AppleThunderboltNHIIntelPCI10prePCIWakeEv", AppleThunderboltNHIIntelPCI_prePCIWake, orgAppleThunderboltNHIIntelPCI_prePCIWake},
			{"__ZN27AppleThunderboltNHIIntelPCI9earlyWakeEv", AppleThunderboltNHIIntelPCI_earlyWake, orgAppleThunderboltNHIIntelPCI_earlyWake},
			{"__ZN27AppleThunderboltNHIIntelPCI5sleepEv", AppleThunderboltNHIIntelPCI_sleep, orgAppleThunderboltNHIIntelPCI_sleep},
			{"__ZN27AppleThunderboltNHIIntelPCI4wakeEv", AppleThunderboltNHIIntelPCI_wake, orgAppleThunderboltNHIIntelPCI_wake},
			
			{"__ZN19AppleThunderboltNHI10prePCIWakeEv", AppleThunderboltNHI_prePCIWake, orgAppleThunderboltNHI_prePCIWake},
			{"__ZN19AppleThunderboltNHI5sleepEv", AppleThunderboltNHI_sleep, orgAppleThunderboltNHI_sleep},
			{"__ZN19AppleThunderboltNHI9lateSleepEv", AppleThunderboltNHI_lateSleep, orgAppleThunderboltNHI_lateSleep},
			{"__ZN19AppleThunderboltNHI9earlyWakeEv", AppleThunderboltNHI_earlyWake, orgAppleThunderboltNHI_earlyWake},
			{"__ZN19AppleThunderboltNHI4wakeEv", AppleThunderboltNHI_wake, orgAppleThunderboltNHI_wake},
			{"__ZN24AppleThunderboltNHIType310earlySleepEv", AppleThunderboltNHIType3_earlySleep, orgAppleThunderboltNHIType3_earlySleep},
			{"__ZN24AppleThunderboltNHIType310prePCIWakeEv", AppleThunderboltNHIType3_prePCIWake, orgAppleThunderboltNHIType3_prePCIWake},
			{"__ZN19AppleThunderboltNHI17lateSleepInternalEv", AppleThunderboltNHI_lateSleepInternal, orgAppleThunderboltNHI_lateSleepInternal},
			{"__ZN19AppleThunderboltNHI17earlyWakeInternalEv", AppleThunderboltNHI_earlyWakeInternal, orgAppleThunderboltNHI_earlyWakeInternal},
			{"__ZN24AppleThunderboltNHIType39lateSleepEv", AppleThunderboltNHIType3_lateSleep, orgAppleThunderboltNHIType3_lateSleep},
			{"__ZN24AppleThunderboltNHIType39earlyWakeEv", AppleThunderboltNHIType3_earlyWake, orgAppleThunderboltNHIType3_earlyWake},
			{"__ZN24AppleThunderboltNHIType35sleepEv", AppleThunderboltNHIType3_sleep, orgAppleThunderboltNHIType3_sleep},
			{"__ZN24AppleThunderboltNHIType34wakeEv", AppleThunderboltNHIType3_wake, orgAppleThunderboltNHIType3_wake},
			{"__ZN19AppleThunderboltNHI8resetNHIEv", AppleThunderboltNHI_resetNHI, orgAppleThunderboltNHI_resetNHI}
		};
		patcher.routeMultiple(index, requests, address, size);
		if (patcher.getError() == KernelPatcher::Error::NoError) {
			DBGLOG("TBFIXUP", "routed %s", requests[0].symbol);
		} else {
			SYSLOG("TBFIXUP", "failed to resolve %s, error = %d", requests[0].symbol, patcher.getError());
			patcher.clearError();
		}
	}
}
