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

#include <cinttypes>
#include <cstdint>

#include "app/util/util.h"
#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/callback.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app-common/zap-generated/ids/Commands.h>

#include <app/InteractionModelEngine.h>

// Currently we need some work to keep compatible with ember lib.
#include <app/util/ember-compatibility-functions.h>

namespace chip {
namespace app {

namespace {
void ReportCommandUnsupported(Command * aCommandObj, EndpointId aEndpointId, ClusterId aClusterId, CommandId aCommandId)
{
    CommandPathParams returnStatusParam = { aEndpointId,
                                            0, // GroupId
                                            aClusterId, aCommandId, (CommandPathFlags::kEndpointIdValid) };
    aCommandObj->AddStatusCode(returnStatusParam, Protocols::SecureChannel::GeneralStatusCode::kNotFound,
                               Protocols::SecureChannel::Id, Protocols::InteractionModel::Status::UnsupportedCommand);
    ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI, ChipLogValueMEI(aCommandId),
                 ChipLogValueMEI(aClusterId));
}
} // anonymous namespace

// Cluster specific command parsing

namespace Clusters {

namespace OtaSoftwareUpdateProvider {

void DispatchServerCommand(CommandHandler * apCommandObj, CommandId aCommandId, EndpointId aEndpointId, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError          = CHIP_NO_ERROR;
    CHIP_ERROR TLVUnpackError    = CHIP_NO_ERROR;
    uint32_t validArgumentCount  = 0;
    uint32_t expectArgumentCount = 0;
    uint32_t currentDecodeTagId  = 0;
    bool wasHandled              = false;
    {
        switch (aCommandId)
        {
        case Commands::ApplyUpdateRequest::Id: {
            expectArgumentCount = 2;
            chip::ByteSpan updateToken;
            uint32_t newVersion;
            bool argExists[2];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 2)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(updateToken);
                    break;
                case 1:
                    TLVUnpackError = aDataTlv.Get(newVersion);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 2 == validArgumentCount)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterApplyUpdateRequestCallback(aEndpointId, apCommandObj,
                                                                                               updateToken, newVersion);
            }
            break;
        }
        case Commands::NotifyUpdateApplied::Id: {
            expectArgumentCount = 2;
            chip::ByteSpan updateToken;
            uint32_t softwareVersion;
            bool argExists[2];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 2)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(updateToken);
                    break;
                case 1:
                    TLVUnpackError = aDataTlv.Get(softwareVersion);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 2 == validArgumentCount)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterNotifyUpdateAppliedCallback(aEndpointId, apCommandObj,
                                                                                                updateToken, softwareVersion);
            }
            break;
        }
        case Commands::QueryImage::Id: {
            expectArgumentCount = 8;
            uint16_t vendorId;
            uint16_t productId;
            uint16_t hardwareVersion;
            uint32_t softwareVersion;
            uint8_t protocolsSupported;
            const uint8_t * location;
            bool requestorCanConsent;
            chip::ByteSpan metadataForProvider;
            bool argExists[8];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 8)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(vendorId);
                    break;
                case 1:
                    TLVUnpackError = aDataTlv.Get(productId);
                    break;
                case 2:
                    TLVUnpackError = aDataTlv.Get(hardwareVersion);
                    break;
                case 3:
                    TLVUnpackError = aDataTlv.Get(softwareVersion);
                    break;
                case 4:
                    TLVUnpackError = aDataTlv.Get(protocolsSupported);
                    break;
                case 5:
                    // TODO(#5542): The cluster handlers should accept a ByteSpan for all string types.
                    TLVUnpackError = aDataTlv.GetDataPtr(location);
                    break;
                case 6:
                    TLVUnpackError = aDataTlv.Get(requestorCanConsent);
                    break;
                case 7:
                    TLVUnpackError = aDataTlv.Get(metadataForProvider);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 8 == validArgumentCount)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterQueryImageCallback(
                    aEndpointId, apCommandObj, vendorId, productId, hardwareVersion, softwareVersion, protocolsSupported,
                    const_cast<uint8_t *>(location), requestorCanConsent, metadataForProvider);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            ReportCommandUnsupported(apCommandObj, aEndpointId, OtaSoftwareUpdateProvider::Id, aCommandId);
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || CHIP_NO_ERROR != TLVUnpackError || expectArgumentCount != validArgumentCount || !wasHandled)
    {
        CommandPathParams returnStatusParam = { aEndpointId,
                                                0, // GroupId
                                                OtaSoftwareUpdateProvider::Id, aCommandId, (CommandPathFlags::kEndpointIdValid) };
        apCommandObj->AddStatusCode(returnStatusParam, Protocols::SecureChannel::GeneralStatusCode::kBadRequest,
                                    Protocols::SecureChannel::Id, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl,
                        "Failed to dispatch command, %" PRIu32 "/%" PRIu32 " arguments parsed, TLVError=%" CHIP_ERROR_FORMAT
                        ", UnpackError=%" CHIP_ERROR_FORMAT " (last decoded tag = %" PRIu32,
                        validArgumentCount, expectArgumentCount, TLVError.Format(), TLVUnpackError.Format(), currentDecodeTagId);
        // A command with no arguments would never write currentDecodeTagId.  If
        // progress logging is also disabled, it would look unused.  Silence that
        // warning.
        UNUSED_VAR(currentDecodeTagId);
    }
}

} // namespace OtaSoftwareUpdateProvider

namespace OperationalCredentials {

void DispatchServerCommand(CommandHandler * apCommandObj, CommandId aCommandId, EndpointId aEndpointId, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError          = CHIP_NO_ERROR;
    CHIP_ERROR TLVUnpackError    = CHIP_NO_ERROR;
    uint32_t validArgumentCount  = 0;
    uint32_t expectArgumentCount = 0;
    uint32_t currentDecodeTagId  = 0;
    bool wasHandled              = false;
    {
        switch (aCommandId)
        {
        case Commands::AddNOC::Id: {
            expectArgumentCount = 5;
            chip::ByteSpan NOCValue;
            chip::ByteSpan ICACValue;
            chip::ByteSpan IPKValue;
            chip::NodeId CaseAdminNode;
            uint16_t AdminVendorId;
            bool argExists[5];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 5)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(NOCValue);
                    break;
                case 1:
                    TLVUnpackError = aDataTlv.Get(ICACValue);
                    break;
                case 2:
                    TLVUnpackError = aDataTlv.Get(IPKValue);
                    break;
                case 3:
                    TLVUnpackError = aDataTlv.Get(CaseAdminNode);
                    break;
                case 4:
                    TLVUnpackError = aDataTlv.Get(AdminVendorId);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 5 == validArgumentCount)
            {
                wasHandled = emberAfOperationalCredentialsClusterAddNOCCallback(aEndpointId, apCommandObj, NOCValue, ICACValue,
                                                                                IPKValue, CaseAdminNode, AdminVendorId);
            }
            break;
        }
        case Commands::AddTrustedRootCertificate::Id: {
            expectArgumentCount = 1;
            chip::ByteSpan RootCertificate;
            bool argExists[1];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 1)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(RootCertificate);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
            {
                wasHandled = emberAfOperationalCredentialsClusterAddTrustedRootCertificateCallback(aEndpointId, apCommandObj,
                                                                                                   RootCertificate);
            }
            break;
        }
        case Commands::AttestationRequest::Id: {
            expectArgumentCount = 1;
            chip::ByteSpan AttestationNonce;
            bool argExists[1];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 1)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(AttestationNonce);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterAttestationRequestCallback(aEndpointId, apCommandObj, AttestationNonce);
            }
            break;
        }
        case Commands::CertificateChainRequest::Id: {
            expectArgumentCount = 1;
            uint8_t CertificateType;
            bool argExists[1];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 1)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(CertificateType);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterCertificateChainRequestCallback(aEndpointId, apCommandObj, CertificateType);
            }
            break;
        }
        case Commands::OpCSRRequest::Id: {
            expectArgumentCount = 1;
            chip::ByteSpan CSRNonce;
            bool argExists[1];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 1)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(CSRNonce);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
            {
                wasHandled = emberAfOperationalCredentialsClusterOpCSRRequestCallback(aEndpointId, apCommandObj, CSRNonce);
            }
            break;
        }
        case Commands::RemoveFabric::Id: {
            expectArgumentCount = 1;
            uint8_t FabricIndex;
            bool argExists[1];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 1)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(FabricIndex);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
            {
                wasHandled = emberAfOperationalCredentialsClusterRemoveFabricCallback(aEndpointId, apCommandObj, FabricIndex);
            }
            break;
        }
        case Commands::UpdateFabricLabel::Id: {
            expectArgumentCount = 1;
            const uint8_t * Label;
            bool argExists[1];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 1)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    // TODO(#5542): The cluster handlers should accept a ByteSpan for all string types.
                    TLVUnpackError = aDataTlv.GetDataPtr(Label);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 1 == validArgumentCount)
            {
                wasHandled = emberAfOperationalCredentialsClusterUpdateFabricLabelCallback(aEndpointId, apCommandObj,
                                                                                           const_cast<uint8_t *>(Label));
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            ReportCommandUnsupported(apCommandObj, aEndpointId, OperationalCredentials::Id, aCommandId);
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || CHIP_NO_ERROR != TLVUnpackError || expectArgumentCount != validArgumentCount || !wasHandled)
    {
        CommandPathParams returnStatusParam = { aEndpointId,
                                                0, // GroupId
                                                OperationalCredentials::Id, aCommandId, (CommandPathFlags::kEndpointIdValid) };
        apCommandObj->AddStatusCode(returnStatusParam, Protocols::SecureChannel::GeneralStatusCode::kBadRequest,
                                    Protocols::SecureChannel::Id, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl,
                        "Failed to dispatch command, %" PRIu32 "/%" PRIu32 " arguments parsed, TLVError=%" CHIP_ERROR_FORMAT
                        ", UnpackError=%" CHIP_ERROR_FORMAT " (last decoded tag = %" PRIu32,
                        validArgumentCount, expectArgumentCount, TLVError.Format(), TLVUnpackError.Format(), currentDecodeTagId);
        // A command with no arguments would never write currentDecodeTagId.  If
        // progress logging is also disabled, it would look unused.  Silence that
        // warning.
        UNUSED_VAR(currentDecodeTagId);
    }
}

} // namespace OperationalCredentials

} // namespace Clusters

void DispatchSingleClusterCommand(ClusterId aClusterId, CommandId aCommandId, EndpointId aEndPointId, TLV::TLVReader & aReader,
                                  CommandHandler * apCommandObj)
{
    ChipLogDetail(Zcl, "Received Cluster Command: Cluster=" ChipLogFormatMEI " Command=" ChipLogFormatMEI " Endpoint=%" PRIx16,
                  ChipLogValueMEI(aClusterId), ChipLogValueMEI(aCommandId), aEndPointId);
    Compatibility::SetupEmberAfObjects(apCommandObj, aClusterId, aCommandId, aEndPointId);
    TLV::TLVType dataTlvType;
    SuccessOrExit(aReader.EnterContainer(dataTlvType));
    switch (aClusterId)
    {
    case Clusters::OtaSoftwareUpdateProvider::Id:
        Clusters::OtaSoftwareUpdateProvider::DispatchServerCommand(apCommandObj, aCommandId, aEndPointId, aReader);
        break;
    case Clusters::OperationalCredentials::Id:
        Clusters::OperationalCredentials::DispatchServerCommand(apCommandObj, aCommandId, aEndPointId, aReader);
        break;
    default:
        // Unrecognized cluster ID, error status will apply.
        CommandPathParams returnStatusParam = { aEndPointId,
                                                0, // GroupId
                                                aClusterId, aCommandId, (CommandPathFlags::kEndpointIdValid) };
        apCommandObj->AddStatusCode(returnStatusParam, Protocols::SecureChannel::GeneralStatusCode::kNotFound,
                                    Protocols::SecureChannel::Id, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogError(Zcl, "Unknown cluster %" PRIx32, aClusterId);
        break;
    }
exit:
    Compatibility::ResetEmberAfObjects();
    aReader.ExitContainer(dataTlvType);
}

void DispatchSingleClusterResponseCommand(ClusterId aClusterId, CommandId aCommandId, EndpointId aEndPointId,
                                          TLV::TLVReader & aReader, CommandSender * apCommandObj)
{
    ChipLogDetail(Zcl, "Received Cluster Command: Cluster=%" PRIx32 " Command=%" PRIx32 " Endpoint=%" PRIx16, aClusterId,
                  aCommandId, aEndPointId);
    Compatibility::SetupEmberAfObjects(apCommandObj, aClusterId, aCommandId, aEndPointId);
    TLV::TLVType dataTlvType;
    SuccessOrExit(aReader.EnterContainer(dataTlvType));
    switch (aClusterId)
    {
    default:
        // Unrecognized cluster ID, error status will apply.
        CommandPathParams returnStatusParam = { aEndPointId,
                                                0, // GroupId
                                                aClusterId, aCommandId, (CommandPathFlags::kEndpointIdValid) };
        apCommandObj->AddStatusCode(returnStatusParam, Protocols::SecureChannel::GeneralStatusCode::kNotFound,
                                    Protocols::SecureChannel::Id, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogError(Zcl, "Unknown cluster " ChipLogFormatMEI, ChipLogValueMEI(aClusterId));
        break;
    }
exit:
    Compatibility::ResetEmberAfObjects();
    aReader.ExitContainer(dataTlvType);
}

} // namespace app
} // namespace chip
