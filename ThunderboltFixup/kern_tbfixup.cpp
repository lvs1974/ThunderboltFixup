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
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_earlySleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::earlySleep is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHIType3_earlySleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::earlySleep is called");
	return KERN_SUCCESS;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::lateSleep is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::lateSleep is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHI_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::lateSleep is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHI_lateSleepInternal(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::lateSleepInternal is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHIType3_lateSleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType::lateSleep is called");
	return KERN_SUCCESS;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_sleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::sleep is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHI_sleep(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::sleep is called");
	return KERN_SUCCESS;
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
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_prePCIWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::prePCIWake is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHI_prePCIWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::prePCIWake is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHIType3_prePCIWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::prePCIWake is called");
	return KERN_SUCCESS;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::earlyWake is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltGenericHAL_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltGenericHAL::earlyWake is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHI_earlyWake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::earlyWake is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHI_earlyWakeInternal(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::earlyWakeInternal is called");
	return KERN_SUCCESS;
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
	return KERN_SUCCESS;
}

//==============================================================================

IOReturn TBFixup::AppleThunderboltNHIIntelPCI_wake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIIntelPCI::wake is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHI_wake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHI::wake is called");
	return KERN_SUCCESS;
}

IOReturn TBFixup::AppleThunderboltNHIType3_wake(void *that)
{
	DBGLOG("TBFIXUP", "AppleThunderboltNHIType3::wake is called");
	return KERN_SUCCESS;
}

//==============================================================================

void TBFixup::processKext(KernelPatcher &patcher, size_t index, mach_vm_address_t address, size_t size)
{
	if (kextList.loadIndex == index) {
		DBGLOG("TBFIXUP", "%s", kextList.id);
		
		KernelPatcher::RouteRequest requests[] {
			{"__ZN27AppleThunderboltNHIIntelPCI10earlySleepEv", AppleThunderboltNHIIntelPCI_earlySleep, orgAppleThunderboltNHIIntelPCI_earlySleep},
			{"__ZN26AppleThunderboltGenericHAL10earlySleepEv", AppleThunderboltGenericHAL_earlySleep, orgAppleThunderboltGenericHAL_earlySleep},
			{"__ZN24AppleThunderboltNHIType310earlySleepEv", AppleThunderboltNHIType3_earlySleep, orgAppleThunderboltNHIType3_earlySleep},
			{"__ZN27AppleThunderboltNHIIntelPCI9lateSleepEv", AppleThunderboltNHIIntelPCI_lateSleep, orgAppleThunderboltNHIIntelPCI_lateSleep},
			{"__ZN26AppleThunderboltGenericHAL9lateSleepEv", AppleThunderboltGenericHAL_lateSleep, orgAppleThunderboltGenericHAL_lateSleep},
			{"__ZN19AppleThunderboltNHI9lateSleepEv", AppleThunderboltNHI_lateSleep, orgAppleThunderboltNHI_lateSleep},
			{"__ZN19AppleThunderboltNHI17lateSleepInternalEv", AppleThunderboltNHI_lateSleepInternal, orgAppleThunderboltNHI_lateSleepInternal},
			{"__ZN24AppleThunderboltNHIType39lateSleepEv", AppleThunderboltNHIType3_lateSleep, orgAppleThunderboltNHIType3_lateSleep},
			{"__ZN27AppleThunderboltNHIIntelPCI5sleepEv", AppleThunderboltNHIIntelPCI_sleep, orgAppleThunderboltNHIIntelPCI_sleep},
			{"__ZN19AppleThunderboltNHI5sleepEv", AppleThunderboltNHI_sleep, orgAppleThunderboltNHI_sleep},
			{"__ZN24AppleThunderboltNHIType35sleepEv", AppleThunderboltNHIType3_sleep, orgAppleThunderboltNHIType3_sleep},
			{"__ZN27AppleThunderboltNHIIntelPCI10prePCIWakeEv", AppleThunderboltNHIIntelPCI_prePCIWake, orgAppleThunderboltNHIIntelPCI_prePCIWake},
			{"__ZN26AppleThunderboltGenericHAL10prePCIWakeEv", AppleThunderboltGenericHAL_prePCIWake, orgAppleThunderboltGenericHAL_prePCIWake},
			{"__ZN19AppleThunderboltNHI10prePCIWakeEv", AppleThunderboltNHI_prePCIWake, orgAppleThunderboltNHI_prePCIWake},
			{"__ZN24AppleThunderboltNHIType310prePCIWakeEv", AppleThunderboltNHIType3_prePCIWake, orgAppleThunderboltNHIType3_prePCIWake},
			{"__ZN27AppleThunderboltNHIIntelPCI9earlyWakeEv", AppleThunderboltNHIIntelPCI_earlyWake, orgAppleThunderboltNHIIntelPCI_earlyWake},
			{"__ZN26AppleThunderboltGenericHAL9earlyWakeEv", AppleThunderboltGenericHAL_earlyWake, orgAppleThunderboltGenericHAL_earlyWake},
			{"__ZN19AppleThunderboltNHI9earlyWakeEv", AppleThunderboltNHI_earlyWake, orgAppleThunderboltNHI_earlyWake},
			{"__ZN19AppleThunderboltNHI17earlyWakeInternalEv", AppleThunderboltNHI_earlyWakeInternal, orgAppleThunderboltNHI_earlyWakeInternal},
			{"__ZN27AppleThunderboltIntelPCIHAL9earlyWakeEv", AppleThunderboltIntelPCIHAL_earlyWake, orgAppleThunderboltIntelPCIHAL_earlyWake},
			{"__ZN24AppleThunderboltNHIType39earlyWakeEv", AppleThunderboltNHIType3_earlyWake, orgAppleThunderboltNHIType3_earlyWake},
			{"__ZN27AppleThunderboltNHIIntelPCI4wakeEv", AppleThunderboltNHIIntelPCI_wake, orgAppleThunderboltNHIIntelPCI_wake},
			{"__ZN19AppleThunderboltNHI4wakeEv", AppleThunderboltNHI_wake, orgAppleThunderboltNHI_wake},
			{"__ZN24AppleThunderboltNHIType34wakeEv", AppleThunderboltNHIType3_wake, orgAppleThunderboltNHIType3_wake}
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
