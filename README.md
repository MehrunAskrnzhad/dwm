# dwm - My Personal Fork
This is my customized version of the dynamic window manager (dwm), a minimalistic and efficient window manager for X11.

## Features
- **Minimized Keybindings** : Launching apps with keybindings done with sxhkd and not dwm
- **Patched Functionality** : Integrates various patches for enhanced usability and aesthetics
- **Aesthetic Tweaks**: Custom appearance settings

## Requirements 
To build this fork you need these extra libs
- **fribidi**: To support the bidi patch
- **sxhkd**: The keybindings mostly will need SXHKD since this build removed the spawn function (simplified the code a little!)

- **OPTIONALLY** you can install `FontAwesome 6` and `JetBrains Mono` to use the default fonts

## Installation
1. Clone the repo
   
   ```sh
   git clone https://github.com/MehrunAskrnzhad/dwm.git
   ```
   
2. Build & Install

   ```sh
   cd dwm/
   sudo make clean install
   ```

## Usage 
- Launch dwm with your X session manager or add `exec dwm` to your `~/.xinitrc`.
- Default keybindings and usage instructions can be found in the `config.h` file.

## Configuration

To customize dwm to your liking, edit `config.h` and recompile:

```sh
sudo make clean install
```

## Patches Included
This fork includes the following patches:

- **gaps**: Adds gaps between windows, providing a clean and organized look.
- **bidi**: Adds support for right-to-left (RTL) languages, enhancing usability for multilingual users.
- **barpadding**: Adds an outer padding (gap) to the bar, improving the visual separation and aesthetics.

## Patches Not Applied
The following patches are not applied but are considered for future integration:

- **combotags**: Allows viewing multiple tags at once with keybindings.
- **ewmhtags**: Makes dwm EWMH compliant, enhancing compatibility with desktop environments and utilities.
- **pwkl**: Enables per-window keyboard layout, allowing different keyboard layouts for different windows.
- **autostart**: Adds an autostart feature to run applications on startup.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributing

Feel free to fork this repository and submit pull requests. Any contributions are welcome!

