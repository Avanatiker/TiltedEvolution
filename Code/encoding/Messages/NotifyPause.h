#pragma once

#include "Message.h"

/**
 * Sent when the world pauses because every player is in a pausing menu, and again when it resumes.
 */
struct NotifyPause final : ServerMessage
{
    static constexpr ServerOpcode Opcode = kNotifyPause;

    NotifyPause()
        : ServerMessage(Opcode)
    {
    }

    void SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept override;
    void DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept override;

    bool operator==(const NotifyPause& acRhs) const noexcept { return GetOpcode() == acRhs.GetOpcode() && Paused == acRhs.Paused; }

    bool Paused{};
};
