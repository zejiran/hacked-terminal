# Hacked Terminal

My personal computer settings.

### Table of Contents

- [Linux](#linux)
- [Recommended software](#recommended-software)
- [Moonlander Keyboard Layout](#zejiran-i-keyboard-layout)
- [macOS Terminal](#macos-terminal)

## Linux

### Ubuntu

When using Ubuntu, I recommend to use the following settings:

**Applications:** [Gtk](https://draculatheme.com/gtk)

**Cursor:** [SpaceKCursors](https://www.gnome-look.org/p/1398513/)

**Icons:** [Dracula](https://draculatheme.com/gtk)

**Titlebar:** I recommend to disable all buttons and instead use shortcuts for this.

**Terminal:** [Dracula]((https://draculatheme.com/gnome-terminal)) + [fish](https://fishshell.com/) + [starship](https://starship.rs/) + `#212337` for background color

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

## Recommended software

- [Authy](https://authy.com/): 2FA.
- [Bitwarden](https://bitwarden.com/): Password manager.
- [GIMP](https://www.gimp.org/): Image editor.
- [OBS](https://obsproject.com/): Recording and streaming software.
- [Kdenlive](https://kdenlive.org): Video editor.
- [Keybase](https://keybase.io/): Encrypted messages.
- [MuseScore](https://musescore.org/en): Music composition and notation.
- [Doom Emacs](https://github.com/hlissner/doom-emacs): Vim + Emacs.

![image](https://user-images.githubusercontent.com/30379522/142906690-4e9a0fd5-9a26-430c-bd47-58523092309d.png)

## Zejiran I Keyboard Layout
This is my personal layout designed for the [Moonlander keyboard](https://www.zsa.io/moonlander/)

-> [Download this layout](https://configure.zsa.io/moonlander/layouts/jXRZ4/latest/0) <-

### Linux Colemak Layer
![Linux Layer](https://user-images.githubusercontent.com/30379522/142907226-73e0dbef-34fd-45d8-86c0-79bffa0cb12e.png)

### QWERTY Layer
![Qwerty Layer](https://user-images.githubusercontent.com/30379522/142907321-bf103b87-e3dd-419d-b5f4-641e9b118e4c.png)

### Special Layer
![Special Layer](https://user-images.githubusercontent.com/30379522/142907393-3b0acc48-a255-4844-95f8-70c2791c850f.png)

### macOS Colemak Layer
![Colemak Layer](https://user-images.githubusercontent.com/30379522/142907442-a3cd496e-ffa1-4166-ad08-91d228717b65.png)

## macOS Terminal
![](https://i.ibb.co/KKDw0mW/terminal.png)

For using this terminal:

1. Open the default macOs terminal.
2. Go to Preferences, then Profiles.
3. Import the [Purple Dragon profile](./mac-terminal/purple-dragon.terminal).
  <img width="300" src="https://user-images.githubusercontent.com/30379522/176507211-bd7f80e1-7269-4b93-a804-145cf08b007f.png">
  
4. Finally, update the background image of the profile with [this](./mac-terminal/terminal-background.png).
  <img width="450" src="https://user-images.githubusercontent.com/30379522/176507507-b6d6b4fb-90c2-4867-a43b-8d28033c2827.png">
