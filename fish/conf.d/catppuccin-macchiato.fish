# Catppuccin Macchiato palette for fish syntax highlighting.
# Delete this file to revert to fish defaults.

set -l rosewater f4dbd6
set -l flamingo  f0c6c6
set -l pink      f5bde6
set -l mauve     c6a0f6
set -l red       ed8796
set -l maroon    ee99a0
set -l peach     f5a97f
set -l yellow    eed49f
set -l green     a6da95
set -l teal      8bd5ca
set -l sky       91d7e3
set -l sapphire  7dc4e4
set -l blue      8aadf4
set -l lavender  b7bdf8
set -l text      cad3f5
set -l subtext1  b8c0e0
set -l subtext0  a5adcb
set -l overlay2  939ab7
set -l overlay1  8087a2
set -l overlay0  6e738d
set -l surface2  5b6078
set -l surface1  494d64
set -l surface0  363a4f
set -l base      24273a
set -l mantle    1e2030
set -l crust     181926

# Syntax highlighting
set -gx fish_color_normal          $text
set -gx fish_color_command         $blue
set -gx fish_color_keyword         $pink
set -gx fish_color_quote           $green
set -gx fish_color_redirection     $pink --bold
set -gx fish_color_end             $peach
set -gx fish_color_error           $red
set -gx fish_color_param           $flamingo
set -gx fish_color_comment         $overlay1 --italics
set -gx fish_color_selection       --background=$surface0
set -gx fish_color_search_match    --background=$surface0
set -gx fish_color_operator        $sky
set -gx fish_color_escape          $teal
set -gx fish_color_autosuggestion  $overlay0
set -gx fish_color_cancel          $red --reverse
set -gx fish_color_option          $mauve
set -gx fish_color_valid_path      --underline

# Pager (tab completion menu)
set -gx fish_pager_color_progress       $overlay0
set -gx fish_pager_color_prefix         $sky --bold
set -gx fish_pager_color_completion     $text
set -gx fish_pager_color_description    $overlay0
set -gx fish_pager_color_selected_background --background=$surface0
