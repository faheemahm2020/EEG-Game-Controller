# EEG Game Controller 

An Arduino-based biosignal game controller that detects changes in electrical signals and converts them into keyboard inputs to control jumping and ducking in a game.

## Demo Video

Watch the project in action:

[Click here to watch the demo](https://drive.google.com/file/d/14UXvybMAt1gW0qITgYnpI7Eem1IcHlCk/view?usp=sharing)

##  Features

- **Jump Detection:** Triggers the Up Arrow key when a short signal event is detected.
- **Duck Detection:** Holds the Down Arrow key when a sustained signal event is detected.
- **Real-Time Monitoring:** Displays signal variations through the Serial Monitor.
- **Adjustable Threshold:** Allows tuning the sensitivity to suit different signal levels.

##  Hardware Requirements

- Compatible Arduino board with USB keyboard emulation support
- BioAmp EXG Pill or another suitable analog biosignal sensor
- Electrodes and connecting wires, if required by the sensor
- Computer and a compatible game

##  Software Requirements

- Arduino IDE
- Compatible `Keyboard.h` library and supported board

##  Working Principle

1. The Arduino reads an analog signal from pin A0.
2. A moving baseline is calculated to track slow changes in the signal.
3. The difference between the raw signal and baseline is used to detect signal events.
4. A short event triggers a jump, while a sustained event triggers ducking.
5. The keyboard input is released when the signal returns below the detection threshold.

##  Configuration

| Parameter | Value |
|---|---|
| Signal input | A0 |
| Detection threshold | 120 |
| Sampling delay | 2 ms |
| Jump key | Up Arrow |
| Duck key | Down Arrow |
| Serial baud rate | 115200 |

The threshold may need adjustment depending on the sensor, signal quality, and environment.

##  Getting Started

1. Clone or download this repository.
2. Open `EEG_Game_Controller.ino` in the Arduino IDE.
3. Connect your sensor output to A0 and connect the grounds.
4. Select the correct board and port.
5. Upload the code to the Arduino.
6. Open the Serial Monitor at 115200 baud to observe signal variations.
7. Open a compatible game and test the jump and duck controls.

**Note:** The standard Arduino Uno R4 Minima may require a different approach for USB keyboard emulation. Verify board compatibility before uploading.

## 🔬 Limitations

- The current implementation detects changes in signal amplitude; it does not independently classify brain commands.
- Muscle activity and eye movement artifacts may trigger actions.
- Detection performance depends on threshold tuning and signal quality.

## 🔮 Future Improvements

- Add digital filtering and noise reduction.
- Implement automatic signal calibration.
- Improve event detection and reduce false triggers.
- Evaluate performance across different signal conditions.
- Integrate with additional games and control actions.
