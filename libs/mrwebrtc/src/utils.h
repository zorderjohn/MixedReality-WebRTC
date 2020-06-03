// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include <cstdint>

#include "mrs_errors.h"
#include "tracked_object.h"

enum class mrsAudioTrackReadBufferPadBehavior;

inline absl::optional<bool> ToOptional(mrsOptBool optBool) noexcept {
  if (optBool == mrsOptBool::kUnset) {
    return absl::nullopt;
  }
  return absl::optional<bool>(optBool != mrsOptBool::kFalse);
}

inline bool IsStringNullOrEmpty(const char* str) noexcept {
  return ((str == nullptr) || (str[0] == '\0'));
}

enum class mrsShutdownOptions : uint32_t;

inline mrsShutdownOptions operator|(mrsShutdownOptions a,
                                    mrsShutdownOptions b) noexcept {
  return (mrsShutdownOptions)((uint32_t)a | (uint32_t)b);
}

inline mrsShutdownOptions operator&(mrsShutdownOptions a,
                                    mrsShutdownOptions b) noexcept {
  return (mrsShutdownOptions)((uint32_t)a & (uint32_t)b);
}

inline bool operator==(mrsShutdownOptions a, uint32_t b) noexcept {
  return ((uint32_t)a == b);
}

inline bool operator!=(mrsShutdownOptions a, uint32_t b) noexcept {
  return ((uint32_t)a != b);
}

namespace Microsoft {
namespace MixedReality {
namespace WebRTC {

Result ResultFromRTCErrorType(webrtc::RTCErrorType type);
Error ErrorFromRTCError(const webrtc::RTCError& error);
Error ErrorFromRTCError(webrtc::RTCError&& error);

mrsMediaKind MediaKindFromRtc(cricket::MediaType media_type);
cricket::MediaType MediaKindToRtc(mrsMediaKind media_kind);

const char* ToString(cricket::MediaType media_type);
const char* ToString(webrtc::RtpTransceiverDirection dir);
const char* ToString(bool value);

/// Utility to convert an ObjectType to a string, for debugging purpose. This
/// returns a view over a global constant buffer (static storage), which is
/// always valid, never deallocated.
absl::string_view ObjectTypeToString(ObjectType type);

/// Utility to format a tracked object into a string, for debugging purpose.
std::string ObjectToString(TrackedObject* obj);

bool IsValidAudioTrackBufferPadBehavior(
    mrsAudioTrackReadBufferPadBehavior pad_behavior);

}  // namespace WebRTC
}  // namespace MixedReality
}  // namespace Microsoft
