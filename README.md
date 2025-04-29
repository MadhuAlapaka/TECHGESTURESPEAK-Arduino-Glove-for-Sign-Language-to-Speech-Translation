# 🤖 TECHGESTURESPEAK: Arduino-Based Glove for Translating Sign Language into Speech

**TECHGESTURESPEAK** is an Arduino-based wearable technology designed to **translate sign language gestures into spoken words in real time**. This system empowers individuals with **speech and hearing impairments** to communicate seamlessly with those who may not understand sign language. It is a **low-cost**, **portable**, and **user-friendly** solution that combines **hardware prototyping** and **embedded systems programming** to create a powerful assistive communication device.

---

## 📝 Table of Contents

- [🎯 Project Overview](#-project-overview)
- [🧠 Abstract](#-abstract)
- [🔧 Features](#-features)
- [🛠️ Hardware Architecture](#️-hardware-architecture)
- [🧰 Technologies Used](#-technologies-used)
- [💡 How It Works](#-how-it-works)
- [📦 System Block Diagram](#-system-block-diagram)
- [🚀 Setup & Usage](#-setup--usage)
- [🔍 Results & Analysis](#-results--analysis)
- [📊 Accuracy Testing](#-accuracy-testing)
- [⚙️ Challenges & Limitations](#️-challenges--limitations)
- [🌱 Future Enhancements](#-future-enhancements)
- [📚 References](#-references)
- [👥 Team Members](#-team-members)
- [📬 Contact](#-contact)
- [📄 License](#-license)

---

## 🎯 Project Overview

The project aims to bridge the communication gap between sign language users and non-signers using an **Arduino Nano-powered glove**. The glove is embedded with **flex sensors** that detect finger movements and hand gestures. These gestures are then translated into spoken words using pre-recorded audio played via a **DFPlayer Mini module**.

This innovation can be used in:

- Hospitals and clinics 🏥
- Schools and colleges 🏫
- Public transportation 🚌
- Customer service settings 🧾
- Daily personal communication 💬

---

## 🧠 Abstract

TECHGESTURESPEAK provides a standalone solution for **gesture-to-speech translation**. Five flex sensors detect the bend of each finger and send analog signals to the Arduino Nano, which maps the gesture to a specific word or phrase. Upon recognition, the system triggers the **DFPlayer Mini** to play the corresponding audio through a speaker. The setup may also include a **16x2 LCD display** for text-based feedback.

This wearable system offers an **alternative to expensive, bulky, and non-portable assistive devices**, contributing to inclusive communication technology.

---

## 🔧 Features

- ✅ Real-time gesture recognition and translation
- ✅ Fully offline system; no internet required
- ✅ Simple and modular circuit design
- ✅ LCD feedback for visual verification
- ✅ Speaker-based audible output
- ✅ Battery-powered and fully portable
- ✅ Easy to modify and expand for more gestures/languages

---

## 🛠️ Hardware Architecture

| Component           | Purpose                                          |
|---------------------|--------------------------------------------------|
| **Arduino Nano**    | Main microcontroller that processes gestures     |
| **Flex Sensors**    | Detect finger movement and bending               |
| **DFPlayer Mini**   | Plays corresponding audio for recognized gestures|
| **8Ω Speaker**       | Outputs clear voice responses                    |
| **16x2 LCD Display**| Optional visual output for gestures              |
| **9V Battery**      | Powers the system for portability                |
| **Zero PCB**        | For final soldered circuit assembly              |
| **Breadboard**      | Used in prototyping stage                        |
| **Resistors & Wires** | Signal control and connectivity                |

---

## 🧰 Technologies Used

- ⚡ **Embedded C/C++** – Arduino programming
- 🧠 **DFPlayer Mini Library** – For easy audio file playback
- 🧪 **Flex Sensor Integration** – Gesture recognition
- 🔊 **Voice Output** – Using MP3/WAV files on microSD
- 🔌 **Serial Communication (UART)** – For Arduino ↔ DFPlayer data transfer
- 🧾 **LCD Integration** – For gesture confirmation

---

## 💡 How It Works

1. 🖐️ **User performs a hand gesture**
2. 📈 Flex sensors detect finger bend levels
3. 🧠 Arduino interprets analog sensor input
4. 🔁 Matches gesture to stored ID (e.g., `play(1)`)
5. 🔊 Sends command to DFPlayer Mini
6. 🗣️ Audio phrase is played through speaker
7. 🖥️ LCD optionally displays the text message

---

## 📦 System Block Diagram

[Flex Sensors (×5)] | [Arduino Nano] / [DFPlayer Mini] [LCD Display] | [Speaker] in Report detalied
## 🚧 System Architecture

- **Input**: 5 analog signals from flex sensors
- **Processing**: Arduino Nano reads and classifies gestures
- **Output**:
  - 🎧 Audio via DFPlayer Mini + speaker
  - 🖥️ Text via LCD Display (optional)
- **Power**: 9V battery powering the entire system

---

## 🔬 Methodology

- ✅ Breadboard prototyping and sensor calibration
- ✅ Code development and gesture-to-audio mapping
- ✅ Audio pre-recording and SD card management
- ✅ PCB integration and final glove design
- ✅ Testing with real users and fine-tuning

---

## 🚀 Setup & Usage

### 🔌 Hardware Assembly
- Connect 5 flex sensors to A0–A4 analog pins on Arduino
- Connect DFPlayer Mini via TX (D10) and RX (D9)
- Load audio files (001.mp3, 002.mp3...) into microSD card
- Hook up speaker to DFPlayer Mini
- Power the system using 9V battery

### 🧑‍💻 Code Upload
- Open Arduino IDE
- Install `DFPlayer Mini` library
- Upload `TECHGESTURESPEAK.ino` sketch
- Adjust sensor threshold values for calibration

---

## 🔍 Results & Analysis

- 🟢 95%+ accuracy in gesture detection under calibrated conditions
- ⏱️ Response time < 500ms from gesture to audio output
- 🔊 Clear voice output from 0.25W speaker
- 👥 Tested with 10+ sample gestures
- 🔁 Real-time gesture-to-speech achieved with minimal delay
- 🎯 High recognition accuracy for 10+ gestures
- 💬 Positive user feedback on audio clarity and usability
- ✅ Fully portable, comfortable, and standalone

---

## 📊 Accuracy Testing

- ✔️ Each gesture was tested 20+ times with different hand sizes
- 📉 Errors analyzed and thresholds fine-tuned
- 🔄 Iterative improvement led to more robust detection
- 🧪 Overall success rate: ~93% across multiple conditions

---

## ⚙️ Challenges & Limitations

| Challenge                     | Status          |
|------------------------------|-----------------|
| Sensor drift/variation       | Calibrated      |
| Hand size variability        | Adjusted thresholds |
| Serial delay (DFPlayer)      | Optimized code  |
| Complex gesture differentiation | Needs ML (future) |
| Flex sensor fragility        | Handled with care |

---

## 🌱 Future Enhancements

- 🧠 Use **Machine Learning (ML)** for gesture recognition
- 🔄 Add **dynamic gesture recognition**
- 🌍 Support **multi-language audio output**
- 📲 Integrate with **mobile apps via Bluetooth**
- 👟 Use **stretchable electronics** for better comfort
- 💬 Build **customizable user-defined gestures**
- 🤖 Integrate **machine learning** for adaptive gesture recognition
- 🌐 Add **Bluetooth/Wi-Fi** for mobile app communication
- 🧠 Expand to recognize **dynamic gestures**
- 🗣️ Add support for **multiple languages and dialects**
- 💡 Use **flexible OLED display** for better text visualization

---

## 📚 References

- IEEE, Elsevier, and Springer publications on sign-language tech
- [DFPlayer Mini Datasheet](https://wiki.dfrobot.com/DFPlayer_Mini_MP3_Player_SKU_DFR0299)
- Arduino documentation
- Assistive Technology journals

---

## 👥 Team Members

| Name               | Roll Number |
|--------------------|-------------|
| **Madhu Alapaka**  | 21MIS7022   |
| Krishna Mohan P.   | 21MIS7005   |
| Lakshman Rohit     | 21MIS7012   |
| Praneetha B.       | 21MIS7015   |
| Kaarthikeya K.     | 21MIS7039   |
| Nikhilesh P.       | 21MIS7087   |

**Institution:** School of Computer Science and Engineering (SCOPE),  
**VIT-AP University, Amaravati**  
**Guide:** Prof. Divya Meena Sundaram

## 🏫 Academic Contribution

- Developed under the **MTech Integrated Software Engineering** program at **VIT-AP University**
- Supervised by **Prof. Divya Meena Sundaram**, Head of Networking and Security
- Part of Engineering Clinic project (ECS ID: 240620)

---

## 📬 Contact

**Madhu Alapaka**  
📧 Email: [alapakamadhusudhanbabu786@gmail.com](mailto:alapakamadhusudhanbabu786@gmail.com)  
🔗 LinkedIn: [linkedin.com/in/madhusudhan7022786](https://www.linkedin.com/in/madhusudhan7022786/)

---

## 📄 License
This project is intended for academic use and learning purposes.  
This project is open-source and licensed under the **MIT License**.  
Feel free to use, modify, or contribute with proper attribution.

---

> “TECHGESTURESPEAK is more than a glove—it's a voice for those who go unheard.”



