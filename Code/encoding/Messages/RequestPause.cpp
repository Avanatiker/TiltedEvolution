#include "RequestPause.h"

#include <TiltedCore/Serialization.hpp>

using TiltedPhoques::Serialization;

void RequestPause::SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept
{
    Serialization::WriteBool(aWriter, Paused);
}

void RequestPause::DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept
{
    ClientMessage::DeserializeRaw(aReader);

    Paused = Serialization::ReadBool(aReader);
}
