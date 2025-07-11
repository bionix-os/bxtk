extends App

var theme: Theme

# Called when the node enters the scene tree for the first time.
func _init() -> void:
	init_state(false)
	if (DisplayServer.is_dark_mode()):
		theme = load("res://addons/lite/dark.tres")
	else:
		theme = load("res://addons/lite/light.tres")
	set_theme(theme)
	var args = OS.get_cmdline_args()
	var sbx_path = ""
	for arg in args:
		if (arg.ends_with(".bxe") and (arg.is_absolute_path() || arg.is_relative_path())):
			sbx_path = arg
	if not sbx_path.is_empty():
		load_and_execute_sbx(sbx_path)
	else:
		load_and_execute_sbx("res://test5.bxe")

func _ready() -> void:
	get_tree().root.theme = theme
	var window = get_window()
	var displayScale = DisplayServer.screen_get_dpi(window.current_screen)
	var fractionalScale: float = 0.01 * displayScale
	window.content_scale_factor = fractionalScale
