#pragma once

#include <oc/common/Types.hpp>
#include <oc/hal/Types.hpp>

namespace oc::common {

struct ButtonDef {
    ButtonID id;
    hal::GpioPin pin;
    bool activeLow = true;
};

}  // namespace oc::common
