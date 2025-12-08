#pragma once

#include <cstdint>
#include <type_traits>

#include <oc/common/Types.hpp>

namespace oc::common {

/**
 * @brief Hardware definition for a rotary encoder
 *
 * Describes the mapping between a logical encoder ID and its physical
 * configuration. Used during hardware initialization to configure
 * the encoder subsystem.
 *
 * ## ID Types
 *
 * Supports both raw uint16_t IDs and enum class types. Using enum class
 * is recommended for IDE autocompletion and type safety:
 *
 * @code
 * // Define your encoder IDs
 * enum class EncoderID : uint16_t {
 *     VOLUME = 100,
 *     PAN = 101,
 *     NAV = 200
 * };
 *
 * // Use enum class (recommended)
 * constexpr EncoderDef encoders[] = {
 *     {EncoderID::VOLUME, 22, 23, 24, 270, 4, false},
 *     {EncoderID::PAN, 24, 25, 24, 270, 4, false},
 *     {EncoderID::NAV, 26, 27, 20, 360, 1, true}
 * };
 *
 * // Or use raw uint16_t
 * constexpr EncoderDef enc{100, 22, 23, 24, 270, 4, false};
 * @endcode
 *
 * ## Configuration Parameters
 *
 * - **ppr**: Pulses per revolution - physical encoder resolution
 * - **rangeAngle**: Total rotation angle in degrees (270° for most pots)
 * - **ticksPerEvent**: Number of ticks before emitting an event (detent count)
 * - **invertDirection**: Swap clockwise/counter-clockwise direction
 *
 * @see EncoderAPI
 * @see EncoderLogic
 */
struct EncoderDef {
    EncoderID id{};                 ///< Logical encoder identifier
    uint8_t pinA{};                 ///< GPIO pin for encoder channel A
    uint8_t pinB{};                 ///< GPIO pin for encoder channel B
    uint16_t ppr = 24;              ///< Pulses per revolution
    uint16_t rangeAngle = 270;      ///< Total rotation angle in degrees
    uint8_t ticksPerEvent = 4;      ///< Ticks per emitted event (detent)
    bool invertDirection = false;   ///< Invert rotation direction

    /// @brief Default constructor
    constexpr EncoderDef() = default;

    /**
     * @brief Construct with EncoderID type
     * @param encoderId Logical encoder identifier
     * @param pA GPIO pin for channel A
     * @param pB GPIO pin for channel B
     * @param pulses Pulses per revolution (default: 24)
     * @param range Total rotation angle in degrees (default: 270)
     * @param ticks Ticks per event (default: 4)
     * @param invert Invert direction (default: false)
     */
    constexpr EncoderDef(EncoderID encoderId, uint8_t pA, uint8_t pB,
                         uint16_t pulses = 24, uint16_t range = 270,
                         uint8_t ticks = 4, bool invert = false)
        : id(encoderId), pinA(pA), pinB(pB), ppr(pulses),
          rangeAngle(range), ticksPerEvent(ticks), invertDirection(invert) {}

    /**
     * @brief Construct with enum class ID (implicit conversion)
     *
     * Allows using custom enum class types without explicit cast:
     * @code
     * enum class MyEncoderID : uint16_t { VOL = 1 };
     * EncoderDef def{MyEncoderID::VOL, 22, 23};
     * @endcode
     *
     * @tparam EnumT Enum class with uint16_t underlying type
     * @param enumId Enum value to use as encoder ID
     * @param pA GPIO pin for channel A
     * @param pB GPIO pin for channel B
     * @param pulses Pulses per revolution (default: 24)
     * @param range Total rotation angle in degrees (default: 270)
     * @param ticks Ticks per event (default: 4)
     * @param invert Invert direction (default: false)
     */
    template <typename EnumT,
              typename = std::enable_if_t<std::is_enum_v<EnumT> &&
                                          std::is_same_v<std::underlying_type_t<EnumT>, uint16_t>>>
    constexpr EncoderDef(EnumT enumId, uint8_t pA, uint8_t pB,
                         uint16_t pulses = 24, uint16_t range = 270,
                         uint8_t ticks = 4, bool invert = false)
        : id(static_cast<EncoderID>(enumId)), pinA(pA), pinB(pB), ppr(pulses),
          rangeAngle(range), ticksPerEvent(ticks), invertDirection(invert) {}
};

}  // namespace oc::common
