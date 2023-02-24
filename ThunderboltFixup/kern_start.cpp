//
//  kern_start.cpp
//  ThunderboltFixup
//
//  Copyright © 2022 lvs1974. All rights reserved.
//

#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>

#include "kern_tbfixup.hpp"

static TBFixup tbfixup;

static const char *bootargOff[] {
	"-tbfixupoff"
};

static const char *bootargDebug[] {
	"-tbfixupdbg"
};

static const char *bootargBeta[] {
	"-tbfixupbeta"
};

PluginConfiguration ADDPR(config) {
	xStringify(PRODUCT_NAME),
	parseModuleVersion(xStringify(MODULE_VERSION)),
	LiluAPI::AllowNormal | LiluAPI::AllowInstallerRecovery | LiluAPI::AllowSafeMode,
	bootargOff,
	arrsize(bootargOff),
	bootargDebug,
	arrsize(bootargDebug),
	bootargBeta,
	arrsize(bootargBeta),
	KernelVersion::MountainLion,
	KernelVersion::Ventura,
	[]() {
		tbfixup.init();
	}
};
