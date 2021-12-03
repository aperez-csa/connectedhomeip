/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#import "CHIPStructsObjc.h"

NS_ASSUME_NONNULL_BEGIN

@implementation CHIPScenesClusterSceneExtensionFieldSet
- (instancetype)init
{
    if (self = [super init]) {

        _clusterId = @(0);

        _length = @(0);

        _value = @(0);
    }
    return self;
}
@end

@implementation CHIPPowerProfileClusterPowerProfileRecord
- (instancetype)init
{
    if (self = [super init]) {

        _powerProfileId = @(0);

        _energyPhaseId = @(0);

        _powerProfileRemoteControl = @(0);

        _powerProfileState = @(0);
    }
    return self;
}
@end

@implementation CHIPPowerProfileClusterScheduledPhase
- (instancetype)init
{
    if (self = [super init]) {

        _energyPhaseId = @(0);

        _scheduledTime = @(0);
    }
    return self;
}
@end

@implementation CHIPPowerProfileClusterTransferredPhase
- (instancetype)init
{
    if (self = [super init]) {

        _energyPhaseId = @(0);

        _macroPhaseId = @(0);

        _expectedDuration = @(0);

        _peakPower = @(0);

        _energy = @(0);

        _maxActivationDelay = @(0);
    }
    return self;
}
@end

@implementation CHIPDescriptorClusterDeviceType
- (instancetype)init
{
    if (self = [super init]) {

        _type = @(0);

        _revision = @(0);
    }
    return self;
}
@end

@implementation CHIPBridgedActionsClusterActionStruct
- (instancetype)init
{
    if (self = [super init]) {

        _actionID = @(0);

        _name = @"";

        _type = @(0);

        _endpointListID = @(0);

        _supportedCommands = @(0);

        _status = @(0);
    }
    return self;
}
@end

@implementation CHIPBridgedActionsClusterEndpointListStruct
- (instancetype)init
{
    if (self = [super init]) {

        _endpointListID = @(0);

        _name = @"";

        _type = @(0);

        _endpoints = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPGeneralCommissioningClusterBasicCommissioningInfoType
- (instancetype)init
{
    if (self = [super init]) {

        _failSafeExpiryLengthMs = @(0);
    }
    return self;
}
@end

@implementation CHIPNetworkCommissioningClusterThreadInterfaceScanResult
- (instancetype)init
{
    if (self = [super init]) {

        _discoveryResponse = [NSData data];
    }
    return self;
}
@end

@implementation CHIPNetworkCommissioningClusterWiFiInterfaceScanResult
- (instancetype)init
{
    if (self = [super init]) {

        _security = @(0);

        _ssid = [NSData data];

        _bssid = [NSData data];

        _channel = @(0);

        _frequencyBand = @(0);
    }
    return self;
}
@end

@implementation CHIPGeneralDiagnosticsClusterNetworkInterfaceType
- (instancetype)init
{
    if (self = [super init]) {

        _name = @"";

        _fabricConnected = @(0);

        _offPremiseServicesReachableIPv4 = @(0);

        _offPremiseServicesReachableIPv6 = @(0);

        _hardwareAddress = [NSData data];

        _type = @(0);
    }
    return self;
}
@end

@implementation CHIPSoftwareDiagnosticsClusterSoftwareFault
- (instancetype)init
{
    if (self = [super init]) {

        _id = @(0);

        _name = @"";

        _faultRecording = [NSData data];
    }
    return self;
}
@end

@implementation CHIPSoftwareDiagnosticsClusterThreadMetrics
- (instancetype)init
{
    if (self = [super init]) {

        _id = @(0);

        _name = @"";

        _stackFreeCurrent = @(0);

        _stackFreeMinimum = @(0);

        _stackSize = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterNeighborTable
- (instancetype)init
{
    if (self = [super init]) {

        _extAddress = @(0);

        _age = @(0);

        _rloc16 = @(0);

        _linkFrameCounter = @(0);

        _mleFrameCounter = @(0);

        _lqi = @(0);

        _averageRssi = @(0);

        _lastRssi = @(0);

        _frameErrorRate = @(0);

        _messageErrorRate = @(0);

        _rxOnWhenIdle = @(0);

        _fullThreadDevice = @(0);

        _fullNetworkData = @(0);

        _isChild = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterOperationalDatasetComponents
- (instancetype)init
{
    if (self = [super init]) {

        _activeTimestampPresent = @(0);

        _pendingTimestampPresent = @(0);

        _masterKeyPresent = @(0);

        _networkNamePresent = @(0);

        _extendedPanIdPresent = @(0);

        _meshLocalPrefixPresent = @(0);

        _delayPresent = @(0);

        _panIdPresent = @(0);

        _channelPresent = @(0);

        _pskcPresent = @(0);

        _securityPolicyPresent = @(0);

        _channelMaskPresent = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterRouteTable
- (instancetype)init
{
    if (self = [super init]) {

        _extAddress = @(0);

        _rloc16 = @(0);

        _routerId = @(0);

        _nextHop = @(0);

        _pathCost = @(0);

        _lqiIn = @(0);

        _lqiOut = @(0);

        _age = @(0);

        _allocated = @(0);

        _linkEstablished = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterSecurityPolicy
- (instancetype)init
{
    if (self = [super init]) {

        _rotationTime = @(0);

        _flags = @(0);
    }
    return self;
}
@end

@implementation CHIPOperationalCredentialsClusterFabricDescriptor
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _rootPublicKey = [NSData data];

        _vendorId = @(0);

        _fabricId = @(0);

        _nodeId = @(0);

        _label = @"";
    }
    return self;
}
@end

@implementation CHIPOperationalCredentialsClusterNOCStruct
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _noc = [NSData data];
    }
    return self;
}
@end

@implementation CHIPFixedLabelClusterLabelStruct
- (instancetype)init
{
    if (self = [super init]) {

        _label = @"";

        _value = @"";
    }
    return self;
}
@end

@implementation CHIPUserLabelClusterLabelStruct
- (instancetype)init
{
    if (self = [super init]) {

        _label = @"";

        _value = @"";
    }
    return self;
}
@end

@implementation CHIPModeSelectClusterModeOptionStruct
- (instancetype)init
{
    if (self = [super init]) {

        _label = @"";

        _mode = @(0);

        _semanticTag = @(0);
    }
    return self;
}
@end

@implementation CHIPModeSelectClusterSemanticTag
- (instancetype)init
{
    if (self = [super init]) {

        _mfgCode = @(0);

        _value = @(0);
    }
    return self;
}
@end

@implementation CHIPDoorLockClusterDlCredential
- (instancetype)init
{
    if (self = [super init]) {

        _credentialType = @(0);

        _credentialIndex = @(0);
    }
    return self;
}
@end

@implementation CHIPIasAceClusterIasAceZoneStatusResult
- (instancetype)init
{
    if (self = [super init]) {

        _zoneId = @(0);

        _zoneStatus = @(0);
    }
    return self;
}
@end

@implementation CHIPTvChannelClusterTvChannelInfo
- (instancetype)init
{
    if (self = [super init]) {

        _majorNumber = @(0);

        _minorNumber = @(0);

        _name = @"";

        _callSign = @"";

        _affiliateCallSign = @"";
    }
    return self;
}
@end

@implementation CHIPTvChannelClusterTvChannelLineupInfo
- (instancetype)init
{
    if (self = [super init]) {

        _operatorName = @"";

        _lineupName = @"";

        _postalCode = @"";

        _lineupInfoType = @(0);
    }
    return self;
}
@end

@implementation CHIPTargetNavigatorClusterNavigateTargetTargetInfo
- (instancetype)init
{
    if (self = [super init]) {

        _identifier = @(0);

        _name = @"";
    }
    return self;
}
@end

@implementation CHIPMediaPlaybackClusterMediaPlaybackPosition
- (instancetype)init
{
    if (self = [super init]) {

        _updatedAt = @(0);

        _position = @(0);
    }
    return self;
}
@end

@implementation CHIPMediaInputClusterMediaInputInfo
- (instancetype)init
{
    if (self = [super init]) {

        _index = @(0);

        _inputType = @(0);

        _name = @"";

        _descriptionString = @"";
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterContentLaunchAdditionalInfo
- (instancetype)init
{
    if (self = [super init]) {

        _name = @"";

        _value = @"";
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterContentLaunchParamater
- (instancetype)init
{
    if (self = [super init]) {

        _type = @(0);

        _value = @"";

        _externalIDList = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterContentLaunchBrandingInformation
- (instancetype)init
{
    if (self = [super init]) {

        _providerName = @"";

        _background = @(0);

        _logo = @(0);

        _progressBar = @(0);

        _splash = @(0);

        _waterMark = @(0);
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterContentLaunchDimension
- (instancetype)init
{
    if (self = [super init]) {

        _width = @"";

        _height = @"";

        _metric = @(0);
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterContentLaunchStyleInformation
- (instancetype)init
{
    if (self = [super init]) {

        _imageUrl = @"";

        _color = @"";

        _size = @(0);
    }
    return self;
}
@end

@implementation CHIPAudioOutputClusterAudioOutputInfo
- (instancetype)init
{
    if (self = [super init]) {

        _index = @(0);

        _outputType = @(0);

        _name = @"";
    }
    return self;
}
@end

@implementation CHIPApplicationLauncherClusterApplicationLauncherApp
- (instancetype)init
{
    if (self = [super init]) {

        _catalogVendorId = @(0);

        _applicationId = @"";
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterSimpleStruct
- (instancetype)init
{
    if (self = [super init]) {

        _a = @(0);

        _b = @(0);

        _c = @(0);

        _d = [NSData data];

        _e = @"";

        _f = @(0);

        _g = @(0);

        _h = @(0);
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterNullablesAndOptionalsStruct
- (instancetype)init
{
    if (self = [super init]) {

        _nullableInt = nil;

        _optionalInt = nil;

        _nullableOptionalInt = nil;

        _nullableString = nil;

        _optionalString = nil;

        _nullableOptionalString = nil;

        _nullableStruct = nil;

        _optionalStruct = nil;

        _nullableOptionalStruct = nil;

        _nullableList = nil;

        _optionalList = nil;

        _nullableOptionalList = nil;
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterNestedStruct
- (instancetype)init
{
    if (self = [super init]) {

        _a = @(0);

        _b = @(0);

        _c = [CHIPTestClusterClusterSimpleStruct new];
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterNestedStructList
- (instancetype)init
{
    if (self = [super init]) {

        _a = @(0);

        _b = @(0);

        _c = [CHIPTestClusterClusterSimpleStruct new];

        _d = [NSArray array];

        _e = [NSArray array];

        _f = [NSArray array];

        _g = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterDoubleNestedStructList
- (instancetype)init
{
    if (self = [super init]) {

        _a = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterTestListStructOctet
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _operationalCert = [NSData data];
    }
    return self;
}
@end

@implementation CHIPGroupKeyManagementClusterGroupKey
- (instancetype)init
{
    if (self = [super init]) {

        _vendorId = @(0);

        _groupKeyIndex = @(0);

        _groupKeyRoot = [NSData data];

        _groupKeyEpochStartTime = @(0);

        _groupKeySecurityPolicy = @(0);
    }
    return self;
}
@end

@implementation CHIPGroupKeyManagementClusterGroupState
- (instancetype)init
{
    if (self = [super init]) {

        _vendorId = @(0);

        _vendorGroupId = @(0);

        _groupKeySetIndex = @(0);
    }
    return self;
}
@end

NS_ASSUME_NONNULL_END
