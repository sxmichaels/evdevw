#ifndef EVDEVW_SWITCHEVENT_HPP
#define EVDEVW_SWITCHEVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class SwitchEventCode {
    Lid = SW_LID,
    TabletMode = SW_TABLET_MODE,
    HeadphoneInsert = SW_HEADPHONE_INSERT,
    RfkillAll = SW_RFKILL_ALL,
    Radio = SW_RADIO,
    MicrophoneInsert = SW_MICROPHONE_INSERT,
    Dock = SW_DOCK,
    LineoutInsert = SW_LINEOUT_INSERT,
    JackPhysicalInsert = SW_JACK_PHYSICAL_INSERT,
    VideooutInsert = SW_VIDEOOUT_INSERT,
    CameraLensCover = SW_CAMERA_LENS_COVER,
    KeypadSlide = SW_KEYPAD_SLIDE,
    FrontProximity = SW_FRONT_PROXIMITY,
    RotateLock = SW_ROTATE_LOCK,
    LineinInsert = SW_LINEIN_INSERT,
    MuteDevice = SW_MUTE_DEVICE,
    PenInserted = SW_PEN_INSERTED,
  };

  template <>
  int enum_to_raw<int, SwitchEventCode>(SwitchEventCode code) {
    using UT = std::underlying_type_t<SwitchEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  SwitchEventCode raw_to_enum<SwitchEventCode, int>(int code) {
    if (code < SW_MAX)
      return static_cast<SwitchEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct SwitchEvent : public Event<EV_SW, SwitchEventCode> {
    SwitchEvent(SwitchEventCode code, Value value)
    : Event(code, value)
    {
    }

    SwitchEvent(struct input_event event)
        : Event(event)
    {
    }
  };

}

bool operator==(evdevw::SwitchEventCode code1, evdevw::SwitchEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_SWITCHEVENT_HPP
