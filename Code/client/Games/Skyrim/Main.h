#pragma once

struct Main
{
    static Main* Get() noexcept;

    char pad0[0x16];
    // The main loop advances the world only while this is clear and no open menu pauses the game.
    bool freezeTime; // 0x16
};

static_assert(offsetof(Main, freezeTime) == 0x16);
