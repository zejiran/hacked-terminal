# Hacked Terminal

My personal computer settings.

### Table of Contents

- [Linux](#linux)
  - [Arch Linux](#arch-linux)
  - [Ubuntu](#ubuntu)
- [macOS](#macos)
- [Recommended software](#recommended-software)
- [Moonlander Keyboard Layout](#zejiran-i-keyboard-layout)

## Linux
### Arch Linux

<img width="2557" height="1436" alt="2025-07-20-232842_hyprshot" src="https://github.com/user-attachments/assets/571d50e9-1eca-4e08-87c4-64a518cafc8a" />

When using Arch Linux, I recommend the following settings and programs:

**Applications:** [Catppuccin GTK Theme Macchiato Mauve](https://github.com/catppuccin/gtk).

**Cursor:** [Rose Pine Hyprcursor](https://github.com/rose-pine/rose-pine-hyprcursor) and [Rose Pine Cursor](https://github.com/rose-pine/rose-pine-cursor).

**Icons:** [Papirus Dark](https://github.com/PapirusDevelopmentTeam/papirus-icon-theme) with violet color.

**Terminal:** [Kitty](https://sw.kovidgoyal.net/kitty/) + [Catppuccin Macchiato](https://github.com/catppuccin/kitty) + [fish](https://fishshell.com/) + [starship](https://starship.rs/). Includes detailed Kitty configurations for fonts, opacity, and theme integration.

**Window Manager:** [Hyprland](https://hyprland.org/). Includes configurations for Hypridle (idle management), Hyprlock (screen locking), Hyprpaper (wallpaper management), and Hyprland itself.

**Status Bar:** [Waybar](https://github.com/Alexays/Waybar). Fully customized with modules, styling, and integration with Hyprland.

**Launcher:** [Rofi](https://github.com/davatorium/rofi). Configured with custom colors and settings for enhanced usability and appearance.

**File Manager:** [Thunar](https://docs.xfce.org/xfce/thunar/start).

**Image Viewer:** [Mirage](https://sourceforge.net/projects/mirageiv.berlios/).

**Spotify Customization:** [Spicetify](https://spicetify.app/).

**System Monitoring:** [btop](https://github.com/aristocratos/btop), [nvtop](https://github.com/Syllo/nvtop).

**Audio Tools:** [qpwgraph](https://gitlab.freedesktop.org/pipewire/qpwgraph), [SwayNC](https://github.com/ErikReider/SwayNotificationCenter).

**Gaming Tools:** [MangoHud](https://github.com/flightlessmango/MangoHud), [GOverlay](https://github.com/benjamimgois/goverlay).

**Other Utilities:** [btop](https://github.com/aristocratos/btop), [nvtop](https://github.com/Syllo/nvtop), [qpwgraph](https://gitlab.freedesktop.org/pipewire/qpwgraph), [hunspell](https://hunspell.github.io/), [openrgb](https://openrgb.org/).

### Ubuntu

When using Ubuntu, I recommend to use the following settings:

**Applications:** [Gtk](https://draculatheme.com/gtk).

**Cursor:** [SpaceKCursors](https://www.gnome-look.org/p/1398513/).

**Icons:** [Dracula](https://draculatheme.com/gtk).

**Titlebar:** I recommend to disable all buttons and instead use shortcuts for this.

**Terminal:** [Dracula]((https://draculatheme.com/gnome-terminal)) + [fish](https://fishshell.com/) + [starship](https://starship.rs/) + `#212337` for background color.

**Shortcuts:** Add shortcuts for open programs like your browser, file manager, music, or terminal.

**Dock:** Disable it, you really do not need it.

**Codecs & Microsoft Fonts:** install with `sudo apt install ubuntu-restricted-extras ubuntu-restricted-addons`.

**Swap:** decrease to 10 with `sudo gedit /etc/sysctl.conf` if you have enough RAM.

**GNOME Tweaks**: `sudo apt install gnome-tweaks`.

**Ubuntu Cleaner**: 
```
sudo add-apt-repository ppa:gerardpuig/ppa
sudo apt-get update
sudo apt-get install ubuntu-cleaner
```

## macOS
### Application Icons
Configure custom icons for your most used applications from [here](./mac-icons).

### Terminal
![](https://i.ibb.co/KKDw0mW/terminal.png)

For using this terminal:

1. Open the default macOs terminal.
2. Go to Preferences, then Profiles.
3. Import the [Purple Dragon profile](./mac-terminal/purple-dragon.terminal).
  <img width="300" src="https://user-images.githubusercontent.com/30379522/176507211-bd7f80e1-7269-4b93-a804-145cf08b007f.png">

4. Finally, update the background image of the profile with [this](./mac-terminal/terminal-background.png).
  <img width="450" src="https://user-images.githubusercontent.com/30379522/176507507-b6d6b4fb-90c2-4867-a43b-8d28033c2827.png">

## Recommended software
- [Authy](https://authy.com/): 2FA.
- [Bitwarden](https://bitwarden.com/): Password manager.
- [GIMP](https://www.gimp.org/): Image editor.
- [Krita](https://krita.org/): Digital painting and illustration software.
- [OBS](https://obsproject.com/): Recording and streaming software.
- [Kdenlive](https://kdenlive.org): Video editor.
- [Keybase](https://keybase.io/): Encrypted messages.
- [MuseScore](https://musescore.org/en): Music composition and notation.
- [Zed](https://zed.dev/): High-performance code editor.
- [Doom Emacs](https://github.com/hlissner/doom-emacs): Vim + Emacs.
- [Commit Mono](https://commitmono.com/): Anonymous and neutral coding font.
- [Spicetify](https://spicetify.app/): Spotify customization tool.
- [Mirage](https://sourceforge.net/projects/mirageiv.berlios/): Lightweight image viewer.
- [Waybar](https://github.com/Alexays/Waybar): Status bar for Wayland.
- [Hyprland](https://hyprland.org/): Dynamic tiling Wayland compositor.
- [Rofi](https://github.com/davatorium/rofi): Window switcher, application launcher, and more.
- [Fish](https://fishshell.com/): Friendly interactive shell.
- [Kitty](https://sw.kovidgoyal.net/kitty/): Fast, feature-rich, GPU-based terminal emulator.
- [SwayNC](https://github.com/ErikReider/SwayNotificationCenter): Notification center for Sway.
- [GOverlay](https://github.com/benjamimgois/goverlay): GUI for Vulkan/OpenGL overlays.
- [btop](https://github.com/aristocratos/btop): Resource monitor.
- [nvtop](https://github.com/Syllo/nvtop): GPU monitoring tool.
- [qpwgraph](https://gitlab.freedesktop.org/pipewire/qpwgraph): PipeWire graph manager.
- [Hunspell](https://hunspell.github.io/): Spell checker.
- [OpenRGB](https://openrgb.org/): Open-source RGB lighting control.

![image](https://user-images.githubusercontent.com/30379522/142906690-4e9a0fd5-9a26-430c-bd47-58523092309d.png)

## Zejiran I Keyboard Layout
This is my personal layout designed for the [Moonlander keyboard](https://www.zsa.io/moonlander/).

-> [Download this layout](https://configure.zsa.io/moonlander/layouts/jXRZ4/latest/0) <-

### Linux Colemak Layer
![Linux Layer](https://user-images.githubusercontent.com/30379522/142907226-73e0dbef-34fd-45d8-86c0-79bffa0cb12e.png)

### QWERTY Layer
![Qwerty Layer](https://user-images.githubusercontent.com/30379522/142907321-bf103b87-e3dd-419d-b5f4-641e9b118e4c.png)

### Special Layer
![Special Layer](https://user-images.githubusercontent.com/30379522/142907393-3b0acc48-a255-4844-95f8-70c2791c850f.png)

### macOS Colemak Layer
![Colemak Layer](https://user-images.githubusercontent.com/30379522/142907442-a3cd496e-ffa1-4166-ad08-91d228717b65.png)
