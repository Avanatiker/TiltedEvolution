#include <Main.h>

Main* Main::Get() noexcept
{
    POINTER_SKYRIMSE(Main*, s_instance, 403449);
    return *s_instance.Get();
}
