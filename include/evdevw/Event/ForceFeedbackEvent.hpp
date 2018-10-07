#ifndef EVDEVW_FORCEFEEDBACKEVENT_HPP
#define EVDEVW_FORCEFEEDBACKEVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class ForceFeedbackEventCode {
    Rumble = FF_RUMBLE,
    Periodic = FF_PERIODIC,
    Constant = FF_CONSTANT,
    Spring = FF_SPRING,
    Friction = FF_FRICTION,
    Damper = FF_DAMPER,
    Inertia = FF_INERTIA,
    Ramp = FF_RAMP,
    EffectMin = FF_EFFECT_MIN,
    EffectMax = FF_EFFECT_MAX,
    Square = FF_SQUARE,
    Triangle = FF_TRIANGLE,
    Sine = FF_SINE,
    SawUp = FF_SAW_UP,
    SawDown = FF_SAW_DOWN,
    Custom = FF_CUSTOM,
    WaveformMin = FF_WAVEFORM_MIN,
    WaveformMax = FF_WAVEFORM_MAX,
    Gain = FF_GAIN,
    Autocenter = FF_AUTOCENTER,
    MaxEffects = FF_MAX_EFFECTS,
  };

  template <>
  int enum_to_raw<int, ForceFeedbackEventCode>(ForceFeedbackEventCode code) {
    using UT = std::underlying_type_t<ForceFeedbackEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  ForceFeedbackEventCode raw_to_enum<ForceFeedbackEventCode, int>(int code) {
    if (code < FF_MAX)
      return static_cast<ForceFeedbackEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct ForceFeedbackEvent : public Event<EV_FF, ForceFeedbackEventCode> {
    ForceFeedbackEvent(ForceFeedbackEventCode code, Value value)
      : Event(code, value)
    {
    }

    ForceFeedbackEvent(struct input_event event)
      : Event(event)
    {
    }
  };

}

bool operator==(evdevw::ForceFeedbackEventCode code1, evdevw::ForceFeedbackEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_FORCEFEEDBACKEVENT_HPP