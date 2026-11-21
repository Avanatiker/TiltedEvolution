#pragma once

#include "Message.h"

/**
 * Sent when the local player opens or leaves a menu that pauses the game in single player.
 */
struct RequestPause final : ClientMessage
{
    static constexpr ClientOpcode Opcode = kRequestPause;

    RequestPause()
        : ClientMessage(Opcode)
    {
    }

    void SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept override;
    void DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept override;

    bool operator==(const RequestPause& acRhs) const noexcept { return GetOpcode() == acRhs.GetOpcode() && Paused == acRhs.Paused; }

    bool Paused{};
};
