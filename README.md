# hydrala
A multi-channel, multi-player theremin installed at Palo Alto Code:Art 2021 by Nicolas Sowers, sound artist and architect, and Daniel Tran, sculptor. Our goal with the project was to engage with the public and encourage them to look up and discover a new means of togetherness. We suspended a sculpture of HPDE tubing fitted with ultrasonic distance detectors and audio transducers between a grove of trees in MLK Plaza. Beneath the sculpture, the audience and players form a singular collective.

Working in the public realm and interacting with visitors to the sculpture gave us many insights into how we behave around sound. We observed a willingness to explore and discover. The form of the sculpture is ambiguous - is it a molecular structure or a representation of neurons? Visitors of all ages were curious about how the sculpture worked, and we participated in numerous discussions of sound and the environment.

The repository consists of a Max patch and an arduino file. The Max patch drives four channels of audio, receiving serial input from an Arduino board that has four ultrasonic distance detectors and LEDs. Each channel of audio is controlled independantly by the corresponding distance detector. The arduino file drives four HC-SR04 distance detectors and also changes an LED placed inside the housing of the distance detector that adjusts brightness depdending on the distance readout.

More info at www.timbrearchitects.com/hydrala.html

Opportunities for further development:

The instruments that drive the sound are basic and simply change pitch with the change in distance. But there are so many interactive possibilities that could include "gestures" or that could react to fast changes in distance, altering the timbre of the sound. There is a lot of improvment to be made in the instrument and interactive design.
