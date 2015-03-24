#include "Gamepad.h"

// Link the 'Xinput' library - Important!
//#pragma comment(lib, "libxinput.a");

// Default constructor
Gamepad::Gamepad() {}
// Overloaded constructor
Gamepad::Gamepad(int a_iIndex)
{
    // Set gamepad index
    m_iGamepadIndex = a_iIndex - 1;

    // Iterate through all gamepad buttons
    for (int i = 0; i < ButtonCount; i++)
    {
          bPrev_ButtonStates[i]   = false;
          bButtonStates[i]        = false;
          bGamepad_ButtonsDown[i] = false;
    }
}

// Update button states for next frame
void Gamepad::RefreshState()
{
       memcpy(bPrev_ButtonStates, bButtonStates,
         sizeof(bPrev_ButtonStates));
}

// Return gamepad state
XINPUT_STATE Gamepad::GetState()
{
      // Temporary XINPUT_STATE to return
      XINPUT_STATE GamepadState;

      // Zero memory
      ZeroMemory(&GamepadState, sizeof(XINPUT_STATE));

      // Get the state of the gamepad
      XInputGetState(m_iGamepadIndex, &GamepadState);

      // Return the gamepad state
      return GamepadState;
}
// Return gamepad index
int Gamepad::GetIndex()
{
      return m_iGamepadIndex;
}
// Return true if the gamepad is connected
bool Gamepad::Connected()
{
      // Zero memory
      ZeroMemory(&m_State, sizeof(XINPUT_STATE));

      // Get the state of the gamepad
      DWORD Result = XInputGetState(m_iGamepadIndex, &m_State);

      if (Result == ERROR_SUCCESS)
            return true;  // The gamepad is connected
      else
            return false; // The gamepad is not connected
}
// Update gamepad state
void Gamepad::Update()
{
    m_State = GetState(); // Obtain current gamepad state

    // Iterate through all gamepad buttons
    for (int i = 0; i < ButtonCount; i++)
    {
          // Set button state for current frame
          bButtonStates[i] = (m_State.Gamepad.wButtons &
             XINPUT_Buttons[i]) == XINPUT_Buttons[i];

          // Set 'DOWN' state for current frame
          bGamepad_ButtonsDown[i] = !bPrev_ButtonStates[i] &&
            bButtonStates[i];
    }
}
//// The left stick is outside of its deadzone
//if (!LStick_InDeadzone())
//{
//    // Use left stick input here...
//}

// Deadzone check for Left Thumbstick
bool Gamepad::LStick_InDeadzone()
{
       // Obtain the X & Y axes of the stick
       short sX = m_State.Gamepad.sThumbLX;
       short sY = m_State.Gamepad.sThumbLY;

       // X axis is outside of deadzone
       if (sX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
           sX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
           return false;

       // Y axis is outside of deadzone
       if (sY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
           sY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
           return false;

       // One (or both axes) axis is inside of deadzone
       return true;
}

// Deadzone check for Right Thumbstick
bool Gamepad::RStick_InDeadzone()
{
       // Obtain the X & Y axes of the stick
       short sX = m_State.Gamepad.sThumbRX;
       short sY = m_State.Gamepad.sThumbRY;

       // X axis is outside of deadzone
       if (sX > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
           sX < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
           return false;

       // Y axis is outside of deadzone
       if (sY > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
           sY < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
           return false;

       // One (or both axes) axis is inside of deadzone
       return true;
}

// Return X axis of left stick
float Gamepad::LeftStick_X()
{
        // Obtain X axis of left stick
        short sX = m_State.Gamepad.sThumbLX;

        // Return axis value, converted to a float
        return (static_cast<float>(sX) / 32768.0f);
}

// Return Y axis of left stick
float Gamepad::LeftStick_Y()
{
        // Obtain Y axis of left stick
        short sY = m_State.Gamepad.sThumbLY;

        // Return axis value, converted to a float
        return (static_cast<float>(sY) / 32768.0f);
}

// Return X axis of right stick
float Gamepad::RightStick_X()
{
        // Obtain X axis of right stick
        short sX = m_State.Gamepad.sThumbRX;

        // Return axis value, converted to a float
        return (static_cast<float>(sX) / 32768.0f);
}

// Return Y axis of right stick
float Gamepad::RightStick_Y()
{
        // Obtain the Y axis of the left stick
        short sY = m_State.Gamepad.sThumbRY;

        // Return axis value, converted to a float
        return (static_cast<float>(sY) / 32768.0f);
}
// Return value of left trigger
float Gamepad::LeftTrigger()
{
        // Obtain value of left trigger
        BYTE Trigger = m_State.Gamepad.bLeftTrigger;

        if (Trigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
              return Trigger / 255.0f;

        return 0.0f; // Trigger was not pressed
}

// Return value of right trigger
float Gamepad::RightTrigger()
{
        // Obtain value of right trigger
        BYTE Trigger = m_State.Gamepad.bRightTrigger;

        if (Trigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
              return Trigger / 255.0f;

        return 0.0f; // Trigger was not pressed
}

void Gamepad::Rumble(float a_fLeftMotor, float a_fRightMotor)
{
       // Vibration state
       XINPUT_VIBRATION VibrationState;

       // Zero memory
       ZeroMemory(&VibrationState, sizeof(XINPUT_VIBRATION));

       // Calculate vibration values
       int iLeftMotor  = int(a_fLeftMotor * 65535.0f);
       int iRightMotor = int(a_fRightMotor * 65535.0f);

       // Set vibration values
       VibrationState.wLeftMotorSpeed  = iLeftMotor;
       VibrationState.wRightMotorSpeed = iRightMotor;

       // Set the vibration state
       XInputSetState(m_iGamepadIndex, &VibrationState);
}

// Define the 'XButtonIDs' struct as 'XButtons'
XButtonIDs XButtons;

// 'XButtonIDs' - Default constructor
XButtonIDs::XButtonIDs()
{
      // These values are used to index the XINPUT_Buttons array,
      // accessing the matching XINPUT button value

      A = 0;
      B = 1;
      X = 2;
      Y = 3;

      DPad_Up    = 4;
      DPad_Down  = 5;
      DPad_Left  = 6;
      DPad_Right = 7;

      L_Shoulder = 8;
      R_Shoulder = 9;

      L_Thumbstick = 10;//if white controller -> 13 and R_Thumbstick -> 14
      R_Thumbstick = 11;

      Start = 12; // white controller > 10 and back -> 11
      Back  = 13;
}
// Return true if button is pressed, false if not
bool Gamepad::GetButtonPressed(int a_iButton)
{
      if (m_State.Gamepad.wButtons & XINPUT_Buttons[a_iButton])
      {
            return true; // The button is pressed
      }

      return false; // The button is not pressed
}

// Frame-specific version of 'GetButtonPressed' function
bool Gamepad::GetButtonDown(int a_iButton)
{
       return bGamepad_ButtonsDown[a_iButton];
}
