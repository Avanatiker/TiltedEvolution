#include "NotifyPause.h"

#include <TiltedCore/Serialization.hpp>

using TiltedPhoques::Serialization;

void NotifyPause::SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept
{
    Serialization::WriteBool(aWriter, Paused);
}

void NotifyPause::DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept
{
    ServerMessage::DeserializeRaw(aReader);

    Paused = Serialization::ReadBool(aReader);
}
