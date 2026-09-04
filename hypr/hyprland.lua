-- This is my Hyprland config file.
-- Refer to the wiki for more information.
-- https://wiki.hypr.land/Configuring/

-- Please note not all available settings / options are set here.
-- For a full list, see the wiki

-- You can split this configuration into multiple files
-- Create your files separately and then require them like this:
-- require("myColors")


------------------
---- MONITORS ----
------------------

-- See https://wiki.hypr.land/Configuring/Basics/Monitors/
hl.monitor({ output = "DP-2", mode = "3840x2160@240", position = "0x0", scale = 2, transform = 0, bitdepth = 10, vrr = 1 })
-- hl.monitor({ output = "DP-2",     mode = "2560x1440@240", position = "0x0",       scale = 1.25, transform = 0, bitdepth = 10, vrr = 1 })
hl.monitor({ output = "HDMI-A-1", mode = "2560x1080@60", position = "1925x-250", scale = 1.25, transform = 3 })

hl.config({
    xwayland = {
        force_zero_scaling = true,
    },
})


---------------------
---- MY PROGRAMS ----
---------------------

-- Set programs that you use
local terminal    = "kitty"
local fileManager = "thunar"
local menu        = "rofi -show drun -dpi 1"
local ide         = os.getenv("HOME") .. "/.local/bin/zed"


-------------------
---- AUTOSTART ----
-------------------

-- See https://wiki.hypr.land/Configuring/Basics/Autostart/

-- Same semantics as the old `exec-once`: runs once, through `sh -c`, so `&` and
-- quoting work as before. Unlike exec-once, a plain hl.exec_cmd() would also hand
-- HL_INITIAL_WORKSPACE_TOKEN to its children (windows that open within 10s get
-- pinned to the workspace focused at startup); unsetting it keeps the old behavior.
local function exec_once(cmd)
    hl.exec_cmd("unset HL_INITIAL_WORKSPACE_TOKEN; " .. cmd)
end

-- Autostart necessary processes (like notifications daemons, status bars, etc.)
hl.on("hyprland.start", function()
    exec_once("hyprlock")
    exec_once("hyprpaper")
    exec_once("waybar & swaync")

    exec_once("hypridle & udiskie")
    exec_once("dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_CURRENT_DESKTOP")
    exec_once('gsettings set org.gnome.desktop.interface color-scheme "prefer-dark"')
    exec_once("systemctl --user start hyprpolkitagent")
    exec_once("wl-paste --watch cliphist store & cliphist wipe")

    -- Workspace rules for autostart apps (workaround for env var clearing).
    -- Created here rather than at top level: `hyprland.start` fires only once,
    -- so a config reload cannot re-create them after the timers below disable them.
    local autostartBraveRule = hl.window_rule({
        name  = "autostart-brave",
        match = { class = "^(brave-browser)$" },

        workspace = "2 silent",
    })
    local autostartSpotifyRule = hl.window_rule({
        name  = "autostart-spotify",
        match = { class = "^(Spotify)$" },

        workspace = "7 silent",
    })

    -- Launch apps and disable rules after they open
    exec_once("brave")
    exec_once("bash -c 'for i in {1..10}; do ping -q -c 1 -W 1 8.8.8.8 && break || sleep 1; done && spotify-launcher'")
    hl.timer(function() autostartBraveRule:set_enabled(false) end,   { timeout = 5000, type = "oneshot" })
    hl.timer(function() autostartSpotifyRule:set_enabled(false) end, { timeout = 12000, type = "oneshot" })

    exec_once("steam -silent")
    -- hl.exec_cmd("slack", { workspace = "7 silent" })
end)


-------------------------------
---- ENVIRONMENT VARIABLES ----
-------------------------------

-- See https://wiki.hypr.land/Configuring/Advanced-and-Cool/Environment-variables/

hl.env("XCURSOR_SIZE",     "28")
hl.env("GDK_SCALE",        "1.75")
hl.env("HYPRCURSOR_SIZE",  "28")
hl.env("HYPRCURSOR_THEME", "rose-pine-hyprcursor")
hl.env("HYPRSHOT_DIR",     "alhart/pictures/screenshots")
hl.env("AQ_DRM_DEVICES",   "/dev/dri/card1:/dev/dri/card0")


-----------------------
---- LOOK AND FEEL ----
-----------------------

-- Refer to https://wiki.hypr.land/Configuring/Basics/Variables/

hl.config({
    -- https://wiki.hypr.land/Configuring/Basics/Variables/#general
    general = {
        gaps_in  = 5,
        gaps_out = 20,

        border_size = 2,

        -- https://wiki.hypr.land/Configuring/Basics/Variables/#variable-types for info about colors
        col = {
            active_border   = { colors = { "rgba(4800ffee)", "rgba(ae00ffee)" }, angle = 45 },
            inactive_border = "rgba(595959aa)",
        },

        -- Set to true enable resizing windows by clicking and dragging on borders and gaps
        resize_on_border = false,

        -- Please see https://wiki.hypr.land/Configuring/Advanced-and-Cool/Tearing/ before you turn this on
        allow_tearing = false,

        layout = "dwindle",
    },

    -- https://wiki.hypr.land/Configuring/Basics/Variables/#decoration
    decoration = {
        rounding       = 10,
        rounding_power = 2,

        -- Change transparency of focused and unfocused windows
        active_opacity   = 1.0,
        inactive_opacity = 1.0,

        shadow = {
            enabled      = true,
            range        = 4,
            render_power = 3,
            color        = "rgba(1a1a1aee)",
        },

        -- https://wiki.hypr.land/Configuring/Basics/Variables/#blur
        blur = {
            enabled = true,
            size    = 3,
            passes  = 1,

            vibrancy = 0.1696,
        },
    },

    -- https://wiki.hypr.land/Configuring/Basics/Variables/#animations
    animations = {
        enabled = true, -- yes, please :)
    },
})

-- Default curves, see https://wiki.hypr.land/Configuring/Advanced-and-Cool/Animations/#curves
local curves = {
    -- NAME             X0    Y0    X1    Y1
    { "easeOutQuint",   0.23, 1,    0.32, 1 },
    { "easeInOutCubic", 0.65, 0.05, 0.36, 1 },
    { "linear",         0,    0,    1,    1 },
    { "almostLinear",   0.5,  0.5,  0.75, 1 },
    { "quick",          0.15, 0,    0.1,  1 },
}
for _, c in ipairs(curves) do
    local name, x0, y0, x1, y1 = table.unpack(c)
    hl.curve(name, { type = "bezier", points = { { x0, y0 }, { x1, y1 } } })
end

-- Default animations, see https://wiki.hypr.land/Configuring/Advanced-and-Cool/Animations/
local animations = {
    -- NAME            ONOFF SPEED  CURVE           STYLE
    { "global",        true, 10,   "default" },
    { "border",        true, 5.39, "easeOutQuint" },
    { "windows",       true, 4.79, "easeOutQuint" },
    { "windowsIn",     true, 4.1,  "easeOutQuint", "popin 87%" },
    { "windowsOut",    true, 1.49, "linear",       "popin 87%" },
    { "fadeIn",        true, 1.73, "almostLinear" },
    { "fadeOut",       true, 1.46, "almostLinear" },
    { "fade",          true, 3.03, "quick" },
    { "layers",        true, 3.81, "easeOutQuint" },
    { "layersIn",      true, 4,    "easeOutQuint", "fade" },
    { "layersOut",     true, 1.5,  "linear",       "fade" },
    { "fadeLayersIn",  true, 1.79, "almostLinear" },
    { "fadeLayersOut", true, 1.39, "almostLinear" },
    { "workspaces",    true, 1.94, "almostLinear", "fade" },
    { "workspacesIn",  true, 1.21, "almostLinear", "fade" },
    { "workspacesOut", true, 1.94, "almostLinear", "fade" },
    { "zoomFactor",    true, 7,    "quick" },
}
for _, a in ipairs(animations) do
    local leaf, enabled, speed, bezier, style = table.unpack(a)
    hl.animation({ leaf = leaf, enabled = enabled, speed = speed, bezier = bezier, style = style })
end

-- Ref https://wiki.hypr.land/Configuring/Basics/Workspace-Rules/
-- "Smart gaps" / "No gaps when only"
-- uncomment all if you wish to use that.
-- hl.workspace_rule({ workspace = "w[tv1]", gaps_out = 0, gaps_in = 0 })
-- hl.workspace_rule({ workspace = "f[1]",   gaps_out = 0, gaps_in = 0 })
-- hl.window_rule({
--     name  = "no-gaps-wtv1",
--     match = { float = false, workspace = "w[tv1]" },
--
--     border_size = 0,
--     rounding    = 0,
-- })
-- hl.window_rule({
--     name  = "no-gaps-f1",
--     match = { float = false, workspace = "f[1]" },
--
--     border_size = 0,
--     rounding    = 0,
-- })

-- See https://wiki.hypr.land/Configuring/Layouts/Dwindle-Layout/ for more
hl.config({
    dwindle = {
        preserve_split = true, -- You probably want this
    },
})

-- See https://wiki.hypr.land/Configuring/Layouts/Master-Layout/ for more
hl.config({
    master = {
        new_status = "master",
    },
})

-- https://wiki.hypr.land/Configuring/Basics/Variables/#misc
hl.config({
    misc = {
        force_default_wallpaper  = 0,    -- Set to 0 or 1 to disable the anime mascot wallpapers
        disable_hyprland_logo    = true, -- If true disables the random hyprland logo / anime girl background. :(
        disable_splash_rendering = true,
        background_color         = "0x101023",
    },
})


---------------
---- INPUT ----
---------------

-- https://wiki.hypr.land/Configuring/Basics/Variables/#input
hl.config({
    input = {
        kb_layout  = "us",
        kb_variant = "altgr-intl",
        kb_model   = "",
        kb_options = "",
        kb_rules   = "",

        follow_mouse = 1,

        sensitivity = 0, -- -1.0 - 1.0, 0 means no modification.

        touchpad = {
            natural_scroll = false,
        },
    },
})

-- https://wiki.hypr.land/Configuring/Basics/Binds/#gestures
-- No gestures configured. Example:
-- hl.gesture({ fingers = 3, direction = "horizontal", action = "workspace" })

-- Example per-device config
-- See https://wiki.hypr.land/Configuring/Advanced-and-Cool/Devices/ for more
hl.device({
    name        = "epic-mouse-v1",
    sensitivity = -0.5,
})


---------------------
---- KEYBINDINGS ----
---------------------

-- See https://wiki.hypr.land/Configuring/Basics/Binds/
local mainMod = "SUPER" -- Sets "Windows" key as main modifier

-- Example binds, see https://wiki.hypr.land/Configuring/Basics/Binds/ for more
hl.bind(mainMod .. " + T",         hl.dsp.exec_cmd(terminal))
hl.bind(mainMod .. " + Q",         hl.dsp.window.close())
hl.bind(mainMod .. " + C",         hl.dsp.window.close())
hl.bind(mainMod .. " + M",         hl.dsp.exec_cmd("command -v hyprshutdown >/dev/null 2>&1 && hyprshutdown || hyprctl dispatch 'hl.dsp.exit()'"))
hl.bind(mainMod .. " + G",         hl.dsp.window.fullscreen({ mode = "fullscreen" }))
hl.bind(mainMod .. " + F",         hl.dsp.exec_cmd(fileManager))
hl.bind(mainMod .. " + W",         hl.dsp.window.float({ action = "toggle" }))
hl.bind(mainMod .. " + B",         hl.dsp.exec_cmd("brave"))
hl.bind(mainMod .. " + SPACE",     hl.dsp.exec_cmd(menu))
hl.bind(mainMod .. " + P",         hl.dsp.window.pseudo())
hl.bind(mainMod .. " + D",         hl.dsp.layout("togglesplit")) -- dwindle only
hl.bind(mainMod .. " + Z",         hl.dsp.exec_cmd(ide))
hl.bind(mainMod .. " + V",         hl.dsp.exec_cmd("cliphist list | rofi -dmenu -dpi 1 -display-columns 2 | cliphist decode | wl-copy"))
hl.bind(mainMod .. " + SHIFT + L", hl.dsp.exec_cmd("hyprlock"))

-- Screenshotting with hyprshot
hl.bind(mainMod .. " + SHIFT + PRINT", hl.dsp.exec_cmd("hyprshot -m region"))
hl.bind(mainMod .. " + PRINT",         hl.dsp.exec_cmd("hyprshot -m window"))

-- Move focus with mainMod + arrow keys
hl.bind(mainMod .. " + left",  hl.dsp.focus({ direction = "left" }))
hl.bind(mainMod .. " + right", hl.dsp.focus({ direction = "right" }))
hl.bind(mainMod .. " + up",    hl.dsp.focus({ direction = "up" }))
hl.bind(mainMod .. " + down",  hl.dsp.focus({ direction = "down" }))

-- Switch workspaces with mainMod + [0-9]
-- Move active window to a workspace with mainMod + SHIFT + [0-9]
for i = 1, 10 do
    local key = i % 10 -- 10 maps to key 0
    hl.bind(mainMod .. " + " .. key,         hl.dsp.focus({ workspace = i }))
    hl.bind(mainMod .. " + SHIFT + " .. key, hl.dsp.window.move({ workspace = i }))
end

-- Workspace switching with MX Ergo tilt
hl.bind("mouse_right", hl.dsp.focus({ workspace = "e+1" })) -- Tilt left
hl.bind("mouse_left",  hl.dsp.focus({ workspace = "e-1" })) -- Tilt right

-- Scroll through existing workspaces with mainMod + scroll
hl.bind(mainMod .. " + mouse_down", hl.dsp.focus({ workspace = "e+1" }))
hl.bind(mainMod .. " + mouse_up",   hl.dsp.focus({ workspace = "e-1" }))

-- Move/resize windows with mainMod + LMB/RMB and dragging
hl.bind(mainMod .. " + mouse:272", hl.dsp.window.drag(),   { mouse = true })
hl.bind(mainMod .. " + mouse:273", hl.dsp.window.resize(), { mouse = true })

-- Laptop multimedia keys for volume and LCD brightness
hl.bind("XF86AudioRaiseVolume",  hl.dsp.exec_cmd("wpctl set-volume -l 1 @DEFAULT_AUDIO_SINK@ 5%+"), { locked = true, repeating = true })
hl.bind("XF86AudioLowerVolume",  hl.dsp.exec_cmd("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-"),      { locked = true, repeating = true })
hl.bind("XF86AudioMute",         hl.dsp.exec_cmd("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle"),     { locked = true, repeating = true })
hl.bind("XF86AudioMicMute",      hl.dsp.exec_cmd("wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle"),   { locked = true, repeating = true })
hl.bind("XF86MonBrightnessUp",   hl.dsp.exec_cmd("brightnessctl s 10%+"),                           { locked = true, repeating = true })
hl.bind("XF86MonBrightnessDown", hl.dsp.exec_cmd("brightnessctl s 10%-"),                           { locked = true, repeating = true })

-- Requires playerctl
hl.bind("XF86AudioNext",  hl.dsp.exec_cmd("playerctl next"),       { locked = true })
hl.bind("XF86AudioPause", hl.dsp.exec_cmd("playerctl play-pause"), { locked = true })
hl.bind("XF86AudioPlay",  hl.dsp.exec_cmd("playerctl play-pause"), { locked = true })
hl.bind("XF86AudioPrev",  hl.dsp.exec_cmd("playerctl previous"),   { locked = true })


--------------------------------
---- WINDOWS AND WORKSPACES ----
--------------------------------

-- See https://wiki.hypr.land/Configuring/Basics/Window-Rules/ for more
-- See https://wiki.hypr.land/Configuring/Basics/Workspace-Rules/ for workspace rules

-- Example window rules that are useful

hl.window_rule({
    -- Ignore maximize requests from all apps. You'll probably like this.
    name  = "suppress-maximize-events",
    match = { class = ".*" },

    suppress_event = "maximize",
})

hl.window_rule({
    -- Fix some dragging issues with XWayland
    name  = "fix-xwayland-drags",
    match = {
        class      = "^$",
        title      = "^$",
        xwayland   = true,
        float      = true,
        fullscreen = false,
        pin        = false,
    },

    no_focus = true,
})

-- Hyprland-run windowrule
hl.window_rule({
    name  = "move-hyprland-run",
    match = { class = "hyprland-run" },

    move  = "20 monitor_h-120",
    float = true,
})

-- Assigning workspace to a certain monitor.
for ws = 1, 10 do
    hl.workspace_rule({ workspace = tostring(ws), monitor = ws <= 5 and "DP-2" or "HDMI-A-1" })
end
