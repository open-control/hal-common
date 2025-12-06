/**
 * @file main.cpp
 * @brief Compilation test for driver-common
 */
#include <oc/common/ButtonDef.hpp>
#include <oc/common/EncoderDef.hpp>

// Verify types compile correctly
static_assert(sizeof(oc::common::ButtonDef) > 0, "ButtonDef must be defined");
static_assert(sizeof(oc::common::EncoderDef) > 0, "EncoderDef must be defined");

void setup() {}
void loop() {}
