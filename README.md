# ESP Starter Kit

A production-ready starter template for ESP32-based IoT projects, featuring reusable motor control components and extensible architecture.

## Purpose

This project serves as a **starter template** for developing custom ESP32 applications. It is designed to be **forked** to create new IoT node projects with a solid foundation.

**Architecture:** The project is structured around composable, git-submodule-based components:
- **`components/motor_controllers/`** — Reusable C++ library for Servo and Stepper motor control (LEDC and GPTimer peripherals)
- **`main/`** — Application entry point (customizable per fork)
- **`sdkconfig`** — ESP32 build configuration (auto-generated, managed via `idf.py menuconfig`)

**Future Vision:** Over time, this project's components will grow to include common building blocks needed for basic and mid-level ESP32 projects (WiFi, MQTT, sensors, etc.), allowing new forks to rapidly assemble functionality without reinventing the wheel.

## Quick Start (5 minutes)

### Prerequisites

**Ubuntu/Debian:**
```bash
sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
```

**Arch:**
```bash
sudo pacman -S gcc git make flex bison gperf python cmake ninja ccache dfu-util libusb python-pip
```

### Setup

**1. Clone and Initialize Submodules**
```bash
git clone <this-repo> esp-starter-kit
cd esp-starter-kit
git submodule update --init --recursive
```

**2. Install ESP-IDF**

```bash
mkdir -p ~/esp
cd ~/esp
git clone -b v5.5.3 --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
./install.sh esp32
```

**3. Activate ESP-IDF Environment**

Run this in every new terminal session (or add an alias to shell profile):

```bash
. $HOME/esp/esp-idf/export.sh
# Optional: Add alias to ~/.bashrc or ~/.zshrc
echo "alias get_idf='. \$HOME/esp/esp-idf/export.sh'" >> ~/.bashrc
```

**4. Build the Project**
```bash
cd esp-starter-kit
idf.py set-target esp32           # Set target chip (one-time)
idf.py build                      # Build project
```

**5. Flash to Device**

Find your serial port:
```bash
ls /dev/tty*                      # Look for /dev/ttyUSB0 or /dev/ttyACM0
```

Flash the device:
```bash
idf.py -p /dev/<device> flash monitor
```

**Ctrl + ]** to exit the serial monitor.


### Configuration (menuconfig)

```bash
idf.py menuconfig
```

Navigate with arrow keys. Key options for this project:
- **Component config** → **Motor Controllers** — Configure GPIO pins for motors
- **Component config** → **Common ESP-related** — Log level, Wi-Fi credentials, etc.
- **Example Configuration** → **WiFi SSID / Password** — Credentials (if needed)

Changes are saved to `sdkconfig`. **Never edit this file manually.**

## Extending the Project (For Forks)

### Adding a New Component

1. **Create the component directory:**
   ```bash
   mkdir -p components/my_component/include
   mkdir -p components/my_component/src
   ```

2. **Add CMakeLists.txt:**
   ```cmake
   idf_component_register(
       SRCS src/my_component.cpp
       INCLUDE_DIRS include/
       REQUIRES driver
   )
   ```

3. **Link in `main/CMakeLists.txt`:**
   ```cmake
   idf_component_register(
       SRCS main.cpp
       INCLUDE_DIRS "."
       REQUIRES motor_controllers my_component
   )
   ```


## References

- **Official ESP-IDF Documentation:** https://docs.espressif.com/projects/esp-idf/en/stable/esp32/
- **Get Started Guide:** https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/
- **idf.py Reference:** https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/tools/idf-py.html
- **IDF Monitor:** https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/tools/idf-monitor.html
- **Flashing Troubleshooting:** https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/flashing-troubleshooting.html

