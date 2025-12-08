/**
 * @file main.cpp
 * @brief Compilation test for driver-common
 */
#include <Arduino.h>

#include <oc/common/Types.hpp>
#include <oc/common/ButtonDef.hpp>
#include <oc/common/EncoderDef.hpp>

static_assert(sizeof(oc::common::ButtonDef) > 0, "ButtonDef");
static_assert(sizeof(oc::common::EncoderDef) > 0, "EncoderDef");

void setup() {}
void loop() {}
