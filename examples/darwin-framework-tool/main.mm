/*
 *   Copyright (c) 2021 Project CHIP Authors
 *   All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#import <Matter/Matter.h>

#import "logging/logging.h"

#include "commands/bdx/Commands.h"
#include "commands/common/Commands.h"
#include "commands/configuration/Commands.h"
#include "commands/delay/Commands.h"
#include "commands/discover/Commands.h"
#include "commands/interactive/Commands.h"
#include "commands/pairing/Commands.h"
#include "commands/payload/Commands.h"
#include "commands/provider/Commands.h"
#include "commands/storage/Commands.h"

#include <zap-generated/cluster/Commands.h>

int main(int argc, const char * argv[])
{
    @autoreleasepool {
        dft::logging::Setup();

        Commands commands;
        registerCommandsBdx(commands);
        registerCommandsPairing(commands);
        registerCommandsDelay(commands);
        registerCommandsDiscover(commands);
        registerCommandsInteractive(commands);
        registerCommandsPayload(commands);
        registerClusterOtaSoftwareUpdateProviderInteractive(commands);
        registerCommandsStorage(commands);
        registerCommandsConfiguration(commands);
        registerClusters(commands);
        return commands.Run(argc, (char **) argv);
    }
}
